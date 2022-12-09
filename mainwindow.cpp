#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QString>
#include<QIntValidator>
#include<QMessageBox>

double A, B, C, Discriminant, X1, X2;
QString a, b, c, d, x1, x2;
QString defaultEquation = "Ax²+ bx + c = 0";
QString dynamicEquation = a+"x²+"+b+"x+"+c+"="+d;
QList<QString> *history;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

//warning for discriminant less than 0
void MainWindow::showWarning()
{
      QMessageBox warning;
      warning.setText("WARNING!\nDiscriminant lower than 0, Please input greater values");
      warning.setIcon(QMessageBox::Warning);
      warning.setWindowTitle("Warning");
      warning.exec();
}


//warning for empty field a,b,c
void MainWindow::showWarning2()
{
      QMessageBox warning2;
      warning2.setText("WARNING!\nField's can not be left empty and must be in correct format");
      warning2.setIcon(QMessageBox::Warning);
      warning2.setWindowTitle("Warning");
      warning2.exec();
}


//calculate discriminant
double MainWindow:: calcDiscri(){
    Discriminant = B*B - 4*A*C;

    if(Discriminant < 0){
        showWarning();
    }

    return Discriminant;

}

// calculate roots X1 and X2
double MainWindow:: calcRoots(){

    if(Discriminant>=0)
      {
        X1 = (-B + sqrt(Discriminant))/ (2* A);
        X2 = (-B - sqrt(Discriminant))/ (2* A);
      }

    ui->le_discriminant->setText(QString::number(Discriminant));
    ui->le_x1->setText(QString::number(X1));
    ui->le_x2->setText(QString::number(X2));
}


MainWindow::~MainWindow()
{
    delete ui;
}


//implement button calculate
void MainWindow::on_btn_calc_clicked()
{
    a = ui->le_a->text();
    b = ui->le_b->text();
    c = ui->le_c->text();

    //check if a, b and c are  not empty
    if(a.isEmpty() || b.isEmpty() || c.isEmpty()){
        ui->lbl_quad_eq->setText(defaultEquation);
        showWarning2();
    }else{

        //discriminant b²-4ac
        B = b.toDouble();
        A = a.toDouble();
        C = c.toDouble();
        Discriminant = d.toDouble();
        
        
        calcDiscri();
        calcRoots();

        //set discriminant to the line edit.
        ui->le_discriminant->setText(QString::number(Discriminant));

        x1 = QString::number(X1);
        x2 = QString::number(X2);
        d = QString::number(Discriminant);
        dynamicEquation = a+"x²+"+b+"x+"+c+"="+d;
        ui->lbl_quad_eq->setText(dynamicEquation);
        ui->txt_history->insertPlainText(dynamicEquation + "     Discriminant = " + d +"        X1 = " + x1 + "      X2 = " + x2);

    }

}

