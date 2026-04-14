#include "mainwindow.h"
#include "logindialog.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    LoginDialog login;

    if (login.exec() == QDialog::Accepted)
    {
        User user = login.getUser();

        MainWindow w(user);
        w.show();

        return a.exec();
    }

    return 0;
}
