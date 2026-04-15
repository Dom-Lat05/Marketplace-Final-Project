#include "mylistingsdialog.h"
#include "ui_mylistingsdialog.h"
#include "editlistingdialog.h"
#include <QMessageBox>

MyListingsDialog::MyListingsDialog(const User& user, DatabaseManager *db, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MyListingsDialog)
    , m_user(user)
    , m_db(db)
{
    ui->setupUi(this);
    loadListings();
}

MyListingsDialog::~MyListingsDialog()
{
    delete ui;
}

void MyListingsDialog::loadListings()
{
    ui->lstMyListings->clear();
    m_listings = m_db->getListingsBySeller(m_user.getUsername());

    for (const Listing& l : m_listings)
    {
        ui->lstMyListings->addItem(l.toDisplayString());
    }
}

void MyListingsDialog::on_btnEdit_clicked()
{
    int index = ui->lstMyListings->currentRow();

    if (index < 0)
    {
        QMessageBox::warning(this, "Error", "Select a listing first.");
        return;
    }

    Listing listing = m_listings[index];

    EditListingDialog dialog(listing, this);

    if (dialog.exec() == QDialog::Accepted)
    {
        Listing updated = dialog.getUpdatedListing();

        m_db->updateListing(
            listing.getId(),
            updated.getTitle(),
            updated.getCategory(),
            updated.getPrice(),
            updated.getDescription()
        );

        loadListings();
    }
}

void MyListingsDialog::on_btnMarkSold_clicked()
{
    int index = ui->lstMyListings->currentRow();

    if (index < 0)
    {
        QMessageBox::warning(this, "Error", "Select a listing first.");
        return;
    }

    Listing listing = m_listings[index];

    m_db->markListingSold(listing.getId());

    loadListings();
}

void MyListingsDialog::on_btnClose_clicked()
{
    close();
}
