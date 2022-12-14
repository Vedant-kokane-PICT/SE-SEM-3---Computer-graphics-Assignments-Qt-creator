#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMouseEvent>
#include<iostream>
using namespace std;
// step-7 for adding image label
QImage img(500,500,QImage::Format_RGB888);
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    // step-5
    ui->setupUi(this);
    vertex = 0;
    start = true;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_label_linkActivated(const QString &link)
{

}


// Impementation of dda line algorithm
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
    ui->label->setPixmap(QPixmap::fromImage(img));
}


// mousePressEvent function definition step-6
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    // step-6
    if(start){
        int p = event->pos().x();
        int q = event->pos().y();
        array_1[vertex] = p;
        array_2[vertex] = q;
        if(event->button()==Qt::RightButton){
            bresenham_line(array_1[vertex-1],array_2[vertex-1],array_1[0],array_2[0]);
            //dda use here -> dda(array_1[vertex-1],array_2[vertex-1],array_1[0],array_2[0]);
            start = false;
        }
        else {
            if(vertex>0){
                bresenham_line(array_1[vertex],array_2[vertex],array_1[vertex-1],array_2[vertex-1]);
                //dda use here -> dda(array_1[vertex],array_2[vertex],array_1[vertex-1],array_2[vertex-1]);
            }
        }
        vertex = vertex + 1;
    }
}

// this button will be used for color filling
void MainWindow::on_pushButton_clicked()
{
    int ymax=0, ymin = 500;
    cout<<"vertex is "<<vertex<<endl;
    // for sorting
        for (i=0;i<vertex-1;i++)
        {

            if (array_2[i]>ymax)
            {
                ymax = array_2[i];
            }
            if (array_2[i] < ymin)
            {
                ymin = array_2[i];
            }
        }
        array_1[vertex-1] = array_1[0];
        array_2[vertex-1] = array_2[0];
        cout<<"y-max = "<<ymax<<" "<<"y-min = "<<ymin<<endl;

        for (i=0;i<vertex-1;i++)
        {
            dx = array_1[i+1] - array_1[i];
            dy = array_2[i+1] - array_2[i];
            if(dy==0.0){
                slope_array[i] = 1;
            }
            if(dx==0.0){
                slope_array[i] = 0;
            }
            if((dy != 0.0) && (dx != 0.0)){
                slope_array[i] = (dx/dy);
                cout<<"slope of line -  "<<i<<" is "<<slope_array[i]<<endl;
            }


        }
        for(i=0;i<vertex-1;i++){
            cout<<slope_array[i]<<endl;
        }
}
// this function will be used to returning sign of the increment va;lue
int MainWindow::sign(int p)
{
    if(p<0){
        return -1;
    }
    else if(p>0){
        return 1;
    }
    return 0;
}


// Impementation of bresenham's line algorithm
void MainWindow::bresenham_line(int x1, int y1, int x2, int y2)
{
    int x,y,dx,dy,i=0,p;
    dx = abs(x2-x1);
    x = x1;
    dy = abs(y2-y1);
    y = y1;
    if(dx>=dy){
        p = (2*dy)-dx;
        while(i<=dx){
            img.setPixel(x,y,qRgb(255,255,255));
            if(p<0){
                p = p + (2*dy);
            }
            else{
                p = p + 2*(dy-dx);
                y = y + sign(y2-y1);
            }
            x = x + sign(x2-x1);
            i++;
        }
    }
    else{
        p = (2*dx)-dy;
        while(i<=dy){
            img.setPixel(x,y,qRgb(255,255,255));
            if(p<0){
                p = p + (2*dx);
            }
            else{
                p = p + 2*(dx-dy);
                x = x + sign(x2-x1);
            }
            y = y + sign(y2-y1);
            i++;
        }
    }
    ui->label->setPixmap(QPixmap::fromImage(img));
}


