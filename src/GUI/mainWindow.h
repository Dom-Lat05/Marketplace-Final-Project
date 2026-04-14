#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "user.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(const User& user, QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnFilter_clicked();
    void on_btnAdd_clicked();

private:
    Ui::MainWindow *ui;
    User m_user;
};

#endif // MAINWINDOW_H
