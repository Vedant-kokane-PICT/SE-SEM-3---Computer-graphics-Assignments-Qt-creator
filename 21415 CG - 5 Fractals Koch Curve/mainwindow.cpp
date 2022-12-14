// 21415 - Vedant Kokane
// Class - SE-4 , Batch - E4

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <math.h>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}
QImage img(500,500,QImage::Format_RGB888);


// dda line
void MainWindow::dda(int x1, int y1, int x2, int y2)
{
    // step-4
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
   // ui->label->setPixmap(QPixmap::fromImage(img));
}

MainWindow::~MainWindow()
{
    delete ui;
}

// fractal function
void MainWindow::Fractal(int x1,int y1,int x2, int y2,int order)
{
    int x3,y3,x4,y4,x,y;
    float t = 3.14/3;
    if(order==0)
    {
        dda(x1,y1,x2,y2);

    }
    else
    {
        x3 = (2*x1+x2)/3;
        y3 =  (2*y1+y2)/3;
        x4 = (x1+2*x2)/3;
        y4 = (y1+2*y2)/3;
        x = x3+(x4-x3) * cos(t) + (y4-y3) * sin(t);
        y = y3-(x4-x3) * sin(t) + (y4-y3) * cos(t);
        Fractal(x1,y1,x3,y3,order-1);
        Fractal(x3,y3,x,y,order-1);
        Fractal(x,y,x4,y4,order-1);
        Fractal(x4,y4,x2,y2,order-1);
    }
}

// button to draw pattern
void MainWindow::on_pushButton_clicked()
{
    int x1,y1,x2,y2,order;
    order = ui->textEdit_5->toPlainText().toInt();
    Fractal(100,200,400,200,order);
    //  100,200,400,200,10
    ui->label->setPixmap(QPixmap::fromImage(img));
    //ui->label->show();
}
