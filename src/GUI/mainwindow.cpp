#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addlistingdialog.h"

MainWindow::MainWindow(const User& user, DatabaseManager *db, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_user(user)
    , m_db(db)
{
    ui->setupUi(this);

    setWindowTitle("Marketplace - " + m_user.getUsername());
    ui->lblWelcome->setText("Welcome, " + m_user.getUsername());

    ui->cmbCategory->clear();
    ui->cmbCategory->addItems({"All", "Electronics", "Furniture", "Clothing"});

    displayListings(m_db->getAllListings());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::displayListings(const QVector<Listing>& listings)
{
    ui->lstListings->clear();

    for (const Listing& listing : listings)
    {
        ui->lstListings->addItem(listing.toDisplayString());
    }
}

void MainWindow::on_btnFilter_clicked()
{
    QString search = ui->txtSearch->text();
    QString category = ui->cmbCategory->currentText();

    QVector<Listing> filtered = m_db->filterListings(search, category);
    displayListings(filtered);
}

void MainWindow::on_btnAdd_clicked()
{
    AddListingDialog dialog(m_user, this);

    if (dialog.exec() == QDialog::Accepted)
    {
        Listing listing = dialog.getListing();
        m_db->addListing(listing);

        QVector<Listing> filtered = m_db->filterListings(
            ui->txtSearch->text(),
            ui->cmbCategory->currentText()
        );

        displayListings(filtered);
    }
}
