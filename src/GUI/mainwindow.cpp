#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addlistingdialog.h"

MainWindow::MainWindow(const User& user, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_user(user)
{
    ui->setupUi(this);

    setWindowTitle("Marketplace - " + m_user.getUsername());

    ui->cmbCategory->addItems({"All", "Electronics", "Furniture", "Clothing"});

    m_manager.loadSampleListings();
    displayListings(m_manager.getAllListings());
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

    QVector<Listing> filtered = m_manager.filterListings(search, category);
    displayListings(filtered);
}

void MainWindow::on_btnAdd_clicked()
{
    AddListingDialog dialog(m_user, this);

    if (dialog.exec() == QDialog::Accepted)
    {
        Listing newListing = dialog.getListing();
        m_manager.addListing(newListing);

        QVector<Listing> filtered = m_manager.filterListings(
            ui->txtSearch->text(),
            ui->cmbCategory->currentText()
        );

        displayListings(filtered);
    }
}
