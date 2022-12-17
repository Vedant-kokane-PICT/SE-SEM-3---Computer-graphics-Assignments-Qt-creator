#include "mainwindow.h"
#include "./ui_mainwindow.h"
QImage img(300,300,QImage::Format_RGB888);
QImage img_1(300,300,QImage::Format_RGB888);
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

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
}

MainWindow::~MainWindow()
{
    delete ui;
}

// before clip
void MainWindow::window()
{
    dda(100,100,200,100);
    dda(200,100,200,200);
    dda(200,200,100,200);
    dda(100,200,100,100);
}

// before clip
void MainWindow::on_pushButton_clicked()
{
    x1 = ui->textEdit->toPlainText().toInt();
    y1 = ui->textEdit_2->toPlainText().toInt();
    x2 = ui->textEdit_3->toPlainText().toInt();
    y2 = ui->textEdit_4->toPlainText().toInt();
    dda(x1,y1,x2,y2);
    window();
    ui->label->setPixmap(QPixmap::fromImage(img));
}


void MainWindow::outcode_init(int a[], int x, int y)
{
    if(y>200){
        a[0] = 1;
    }
    if(y<100){
        a[1] = 1;
    }
    if(x>200){
        a[2] = 1;
    }
    if(x<100){
        a[3] = 1;
    }

}

void MainWindow::dda_1(int x1, int y1, int x2, int y2)
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
        img_1.setPixel(x,y,qRgb(255,255,255));
        x = x + x_inc;
        y = y + y_inc;
        i++;
    }
}


void MainWindow::window_1()
{
    dda_1(100,100,200,100);
    dda_1(200,100,200,200);
    dda_1(200,200,100,200);
    dda_1(100,200,100,100);
}


void MainWindow::on_pushButton_2_clicked()
{
    window_1();
    float x,y,m;
    int outcode[4] = {0,0,0,0};
    int outcode_1[4] = {0,0,0,0};
    outcode_init(outcode,x1,y1);
    outcode_init(outcode_1,x2,y2);
    m = (y2-y1)/(x2-x1);
    if((outcode[0]&outcode_1[0])!=0 or (outcode[1]&outcode_1[1])!=0 or (outcode[2]&outcode_1[2])!=0 or (outcode[3]&outcode_1[3])!=0)
    {
        dda_1(x1,y1,x2,y2);
    }
    else{

        if(outcode[3] == 1){
            y = m * (100-x2) + y2;
            dda_1(100,y,x2,y2);
        }
        else if(outcode_1[3] == 1){
            y = m * (100-x2) + y2;
            dda_1(100,y,x1,y1);
        }
        else if(outcode[2] == 1){
            y = m * (200-x2) + y2;
            dda_1(200,y,x2,y2);
        }
        else if(outcode_1[2] == 1){
            y = m * (200-x2) + y2;
            dda_1(200,y,x1,y1);
        }
        else if(outcode[1] == 1){
            x = x2 + (100-y2) / m;
            dda_1(x,100,x2,y2);
        }
        else if(outcode_1[1] == 1){
            x = x2 + (100-y2) / m;
            dda_1(x,100,x1,y1);
        }
        else if(outcode[0] == 1){
            x = x2 + (200-y2) / m;
            dda_1(x,200,x2,y2);
        }
        else if(outcode_1[0] == 1){
            x = x2 + (200-y2) / m;
            dda_1(x,200,x1,y1);
        }
    }

    ui->label_2->setPixmap(QPixmap::fromImage(img_1));
}




/*
 Co-ordinates
 100,100,250,250
 80,120,120,120
 80,80,150,150

*/

