#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addlistingdialog.h"
#include "logindialog.h"

MainWindow::MainWindow(const User& user, DatabaseManager *db, QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), m_user(user), m_db(db)
{
    ui->setupUi(this);

    ui->lblWelcome->setText("Welcome, " + m_user.getUsername());
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

    for (const Listing& l : listings)
        ui->lstListings->addItem(l.toDisplayString());
}

void MainWindow::on_btnFilter_clicked()
{
    displayListings(m_db->filterListings(
        ui->txtSearch->text(),
        ui->cmbCategory->currentText()
    ));
}

void MainWindow::on_btnAdd_clicked()
{
    AddListingDialog dialog(m_user, this);

    if (dialog.exec() == QDialog::Accepted)
    {
        m_db->addListing(dialog.getListing());
        displayListings(m_db->getAllListings());
    }
}

void MainWindow::on_btnLogout_clicked()
{
    this->hide();

    LoginDialog login(m_db);

    if (login.exec() == QDialog::Accepted)
    {
        MainWindow *w = new MainWindow(login.getUser(), m_db);
        w->show();
    }

    this->close();
}
