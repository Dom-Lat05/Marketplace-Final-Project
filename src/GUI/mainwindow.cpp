#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addlistingdialog.h"
#include "logindialog.h"
#include "mylistingdialog.h"

#include <QPushButton>
#include <QApplication>

MainWindow::MainWindow(const User& user, DatabaseManager *db, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_user(user)
    , m_db(db)
{
    ui->setupUi(this);

    connect(ui->btnFilter, &QPushButton::clicked, this, &MainWindow::on_btnFilter_clicked);
    connect(ui->btnAdd, &QPushButton::clicked, this, &MainWindow::on_btnAdd_clicked);
    connect(ui->btnLogout, &QPushButton::clicked, this, &MainWindow::on_btnLogout_clicked);

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
    QString search = ui->txtSearch->text().trimmed();
    QString category = ui->cmbCategory->currentText();

    QVector<Listing> filteredListings = m_db->filterListings(search, category);
    displayListings(filteredListings);
}

void MainWindow::on_btnAdd_clicked()
{
    AddListingDialog dialog(m_user, this);

    if (dialog.exec() == QDialog::Accepted)
    {
        Listing listing = dialog.getListing();
        m_db->addListing(listing);

        QVector<Listing> filteredListings = m_db->filterListings(
            ui->txtSearch->text().trimmed(),
            ui->cmbCategory->currentText()
            );

        displayListings(filteredListings);
    }
}

void MainWindow::on_btnLogout_clicked()
{
    this->hide();

    LoginDialog login(m_db);

    if (login.exec() == QDialog::Accepted)
    {
        User newUser = login.getUser();

        MainWindow *newWindow = new MainWindow(newUser, m_db);
        newWindow->show();

        this->close();
    }
    else
    {
        qApp->quit();
    }
}

void MainWindow::on_btnMyListings_clicked()
{
    MyListingDialog dialog(m_user, m_db, this);
    dialog.exec();

    QVector<Listing> filteredListings = m_db->filterListings(
        ui->txtSearch->text().trimmed(),
        ui->cmbCategory->currentText()
        );

    displayListings(filteredListings);
}


void MainWindow::on_txtSearch_textChanged(const QString &text)
{
    // Search by title only, across all categories
    QVector<Listing> searchedListings = m_db->filterListings(text, "All");
    displayListings(searchedListings);
}
