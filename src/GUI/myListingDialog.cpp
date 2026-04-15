#include "mylistingdialog.h"
#include "ui_mylistingdialog.h"

#include <QInputDialog>
#include <QMessageBox>

MyListingDialog::MyListingDialog(const User& user, DatabaseManager *db, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MyListingDialog)
    , m_user(user)
    , m_db(db)
{
    ui->setupUi(this);
    loadListings();
}

MyListingDialog::~MyListingDialog()
{
    delete ui;
}

void MyListingDialog::loadListings()
{
    ui->lstMyListings->clear();
    m_listings = m_db->getListingsBySeller(m_user.getUsername());

    for (const Listing& listing : m_listings)
    {
        ui->lstMyListings->addItem(listing.toDisplayString());
    }
}

void MyListingDialog::on_btnEdit_clicked()
{
    int index = ui->lstMyListings->currentRow();

    if (index < 0)
    {
        QMessageBox::warning(this, "Error", "Please select a listing to edit.");
        return;
    }

    Listing listing = m_listings[index];

    bool ok = false;

    QString newTitle = QInputDialog::getText(
        this, "Edit Title", "Title:",
        QLineEdit::Normal, listing.getTitle(), &ok
        );
    if (!ok || newTitle.trimmed().isEmpty())
        return;

    QStringList categories;
    categories << "Electronics" << "Furniture" << "Clothing";

    QString newCategory = QInputDialog::getItem(
        this, "Edit Category", "Category:",
        categories, categories.indexOf(listing.getCategory()), false, &ok
        );
    if (!ok || newCategory.isEmpty())
        return;

    double newPrice = QInputDialog::getDouble(
        this, "Edit Price", "Price:",
        listing.getPrice(), 0.01, 100000.0, 2, &ok
        );
    if (!ok)
        return;

    QString newDescription = QInputDialog::getMultiLineText(
        this, "Edit Description", "Description:",
        listing.getDescription(), &ok
        );
    if (!ok)
        return;

    if (!m_db->updateListing(
            listing.getId(),
            newTitle.trimmed(),
            newCategory,
            newPrice,
            newDescription.trimmed()))
    {
        QMessageBox::warning(this, "Error", "Could not update listing.");
        return;
    }

    QMessageBox::information(this, "Success", "Listing updated.");
    loadListings();
}

void MyListingDialog::on_btnMarkSold_clicked()
{
    int index = ui->lstMyListings->currentRow();

    if (index < 0)
    {
        QMessageBox::warning(this, "Error", "Please select a listing first.");
        return;
    }

    Listing listing = m_listings[index];

    if (!m_db->markListingSold(listing.getId()))
    {
        QMessageBox::warning(this, "Error", "Could not mark listing as sold.");
        return;
    }

    QMessageBox::information(this, "Success", "Listing marked as sold.");
    loadListings();
}

void MyListingDialog::on_btnClose_clicked()
{
    close();
}
