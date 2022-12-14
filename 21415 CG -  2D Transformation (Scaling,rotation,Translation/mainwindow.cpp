#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cmath"
QImage img(400,400,QImage::Format_RGB888);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::dda(int x1, int y1, int x2, int y2)
{
    float dx,dy,x_inc,y_inc,step,x,y;
    dx = x2 - x1;
    dy = y2 - y1;
    if(abs(dx)>=abs(dy)){
        step = abs(dx);
    }
    else{
        step = abs(dy);
    }
    x_inc = (dx/step);
    y_inc = (dy/step);
    x = x1;
    y = y1;
    int i = 0;
    while(i<=step){
        img.setPixel(x,y,qRgb(255,255,255));
        x = x + x_inc;
        y = y + y_inc;
        i++;
    }
    ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::on_label_linkActivated(const QString &link)
{

}


// to draw quadrants
void MainWindow::on_pushButton_3_clicked()
{
    dda(0,200,400,200);
    dda(200,0,200,400);
}

void MainWindow::on_textEdit_copyAvailable(bool b)
{

}

// to draw line for dda button
void MainWindow::on_pushButton_clicked()
{
    int x1,y1,x2,y2;
    x1 = ui->textEdit->toPlainText().toInt();
    y1 = ui->textEdit_2->toPlainText().toInt();
    x2 = ui->textEdit_3->toPlainText().toInt();
    y2 = ui->textEdit_4->toPlainText().toInt();

    dda(200+x1,200+y1,200+x2,200+y2);
}

// translation
void MainWindow::on_pushButton_2_clicked()
{
    int x1,y1,x2,y2,tx,ty;
    x1 = ui->textEdit->toPlainText().toInt();
    y1 = ui->textEdit_2->toPlainText().toInt();
    x2 = ui->textEdit_3->toPlainText().toInt();
    y2 = ui->textEdit_4->toPlainText().toInt();
    tx = ui->textEdit_5->toPlainText().toInt();
    ty = ui->textEdit_6->toPlainText().toInt();
    x1 = x1 + tx;
    y1 = y1 + ty;
    x2 = x2 + tx;
    y2 = y2 + ty;
    dda(x1+200,y1+200,x2+200,y2+200);
}

// for scaling
void MainWindow::on_pushButton_4_clicked()
{
    int x1,y1,x2,y2;
    float tx,ty;
    x1 = ui->textEdit->toPlainText().toInt();
    y1 = ui->textEdit_2->toPlainText().toInt();
    x2 = ui->textEdit_3->toPlainText().toInt();
    y2 = ui->textEdit_4->toPlainText().toInt();
    tx = ui->textEdit_5->toPlainText().toInt();
    ty = ui->textEdit_6->toPlainText().toInt();
    x1 = x1 * tx;
    y1 = y1  * ty;
    x2 = x2  * tx;
    y2 = y2 * ty;
    dda(x1+200,y1+200,x2+200,y2+200);
}

// for rotation
void MainWindow::on_pushButton_5_clicked()
{
    int x1,y1,x2,y2,x11,y11,x22,y22;
    float t1,t;
    x1 = ui->textEdit->toPlainText().toInt();
    y1 = ui->textEdit_2->toPlainText().toInt();
    x2 = ui->textEdit_3->toPlainText().toInt();
    y2 = ui->textEdit_4->toPlainText().toInt();
    t1 = ui->textEdit_7->toPlainText().toInt();
    t = t1 * (3.14/180); // for converting theta in radian
    x11 = x1 * cos(t) - y1 * sin(t);
    y11 = x1 * sin(t) + y1 * cos(t);
    x22 = x2 * cos(t) - y2 * sin(t);
    y22 = x2 * sin(t) + y2 * cos(t);

     dda(x11+200,y11+200,x22+200,y22+200);
}




