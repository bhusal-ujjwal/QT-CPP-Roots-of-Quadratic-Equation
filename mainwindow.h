#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_btn_calc_clicked();
    double calcRoots();
    double calcDiscri();
    void showWarning();
    void showWarning2();


private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
