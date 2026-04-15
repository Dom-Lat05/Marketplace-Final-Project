#include "addlistingdialog.h"
#include "ui_addlistingdialog.h"
#include <QMessageBox>

AddListingDialog::AddListingDialog(const User& user, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddListingDialog)
    , m_user(user)
{
    ui->setupUi(this);

    ui->cmbCategory->addItems({"Electronics", "Furniture", "Clothing"});
    ui->spnPrice->setDecimals(2);
    ui->spnPrice->setMinimum(0.0);
    ui->spnPrice->setMaximum(100000.0);
}

AddListingDialog::~AddListingDialog()
{
    delete ui;
}

Listing AddListingDialog::getListing() const
{
    return m_listing;
}

void AddListingDialog::on_btnSave_clicked()
{
    QString title = ui->txtTitle->text().trimmed();
    QString category = ui->cmbCategory->currentText();
    double price = ui->spnPrice->value();
    QString description = ui->txtDescription->toPlainText().trimmed();

    if (title.isEmpty())
    {
        QMessageBox::warning(this, "Error", "Please enter a title.");
        return;
    }

    if (price <= 0)
    {
        QMessageBox::warning(this, "Error", "Price must be greater than 0.");
        return;
    }

    m_listing = Listing(title, category, price, description, m_user.getUsername());
    accept();
}

void AddListingDialog::on_btnCancel_clicked()
{
    reject();
}
