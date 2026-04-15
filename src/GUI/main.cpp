#include "mainwindow.h"
#include "logindialog.h"
#include "databasemanager.h"

#include <QApplication>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    a.setStyleSheet(R"(
    QWidget {
        background-color: #f5f7fb;
        font-family: Segoe UI;
        font-size: 10pt;
        color: #222;
    }

    QMainWindow, QDialog {
        background-color: #f5f7fb;
    }

    QLabel {
        color: #222;
    }

    QLineEdit, QComboBox, QDoubleSpinBox, QTextEdit, QListWidget {
        background: white;
        border: 1px solid #d0d7e2;
        border-radius: 8px;
        padding: 6px;
    }

    QPushButton {
        background-color: #2563eb;
        color: white;
        border: none;
        border-radius: 8px;
        padding: 8px 14px;
        font-weight: 600;
    }

    QPushButton:hover {
        background-color: #1d4ed8;
    }

    QPushButton:pressed {
        background-color: #1e40af;
    }

    QListWidget {
        border-radius: 25px;
        padding: 20px;
    }
)");

    DatabaseManager db;

    if (!db.openDatabase())
    {
        QMessageBox::critical(nullptr, "Database Error", "Could not open database.");
        return -1;
    }

    db.createTables();

    LoginDialog login(&db);

    if (login.exec() == QDialog::Accepted)
    {
        User user = login.getUser();

        MainWindow w(user, &db);
        w.show();

        return a.exec();
    }

    return 0;
}
