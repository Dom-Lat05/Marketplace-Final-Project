#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->cmbCategory->addItems({"All", "Electronics", "Furniture", "Clothing"});

    ui->lstListings->addItem("Laptop | Electronics | $900");
    ui->lstListings->addItem("Chair | Furniture | $120");
    ui->lstListings->addItem("Hoodie | Clothing | $40");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnFilter_clicked()
{
    QString search = ui->txtSearch->text().toLower();
    QString category = ui->cmbCategory->currentText();

    ui->lstListings->clear();

    if ((category == "All" || category == "Electronics") &&
        (search.isEmpty() || QString("Laptop").toLower().contains(search)))
    {
        ui->lstListings->addItem("Laptop | Electronics | $900");
    }

    if ((category == "All" || category == "Furniture") &&
        (search.isEmpty() || QString("Chair").toLower().contains(search)))
    {
        ui->lstListings->addItem("Chair | Furniture | $120");
    }

    if ((category == "All" || category == "Clothing") &&
        (search.isEmpty() || QString("Hoodie").toLower().contains(search)))
    {
        ui->lstListings->addItem("Hoodie | Clothing | $40");
    }
}

void MainWindow::on_btnAdd_clicked()
{
    ui->lstListings->addItem("New Item | Electronics | $100");
}
