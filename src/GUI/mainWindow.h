#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "user.h"
#include "databasemanager.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(const User& user, DatabaseManager *db, QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnFilter_clicked();
    void on_btnAdd_clicked();

private:
    void displayListings(const QVector<Listing>& listings);

    Ui::MainWindow *ui;
    User m_user;
    DatabaseManager *m_db;
};

#endif // MAINWINDOW_H
