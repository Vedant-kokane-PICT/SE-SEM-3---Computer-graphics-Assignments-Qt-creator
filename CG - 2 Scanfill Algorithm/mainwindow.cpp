#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include<QMouseEvent>
QImage img(500,500,QImage::Format_RGB888);
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    start = true;
    v = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

// mouse press
void MainWindow :: mousePressEvent(QMouseEvent *event){
    if(start){
        int p = event->pos().x();
        int q = event->pos().y();
        a[v] = p;
        b[v] = q;
        if(event->button()==Qt::RightButton){
            dda(a[v-1],b[v-1],a[0],b[0]);
            start = false;
        }
        else{
            if(v>0){
                dda(a[v],b[v],a[v-1],b[v-1]);
            }
        }
        v = v+1;
    }
}

// dda
void MainWindow :: dda(int x1,int y1,int x2,int y2){
    float dx,dy,x,y,x_inc,y_inc,step;
    dx = x2 - x1;
    dy = y2 - y1;
    if(abs(dx)>=abs(dy)){
        step = abs(dx);
    }
    else{
        step = abs(dy);
    }
    int i =0;
    x = x1;
    y = y1;
    x_inc  = dx/step;
    y_inc = dy/step;
    while(i<=step){
        img.setPixel(x,y,qRgb(255,255,255));
        x = x + x_inc;
        y = y + y_inc;
        i++;

    }
    ui->label->setPixmap(QPixmap::fromImage(img));
}

// to fill  color
void MainWindow::on_pushButton_clicked()
{
    int ymax = 0,ymin = 500;
    for(i=0;i<v-1;i++){
        if(b[i]>ymax){
            ymax = b[i];
        }
        if(b[i]<ymin){
            ymin = b[i];
        }
        a[v-1] = a[0];
        b[v-1] = b[0];
    }

    for(i=0;i<v-1;i++){
        dx = a[i+1] - a[i];
        dy = b[i+1] - b[i];

        if(dx == 0.0){
            s[i] = 0.0;
        }
        if(dy == 0.0){
            s[i] = 1.0;
        }

        if((dx != 0.0) && (dy != 0.0)){
            s[i] = float(dx/dy);
        }
    }

    for(int y=ymin;y<ymax;y++){
        k=0;
        for(i=0;i<v-1;i++){
            if((b[i]<=y && b[i+1]>y) || (b[i]>y && b[i+1]<=y)){
                xi[k] = int(a[i] + (s[i] * (y-b[i])));
                k++;
            }
        }

        for(j=0;j<k-1;j++){
            for(i=0;i<k-1;i++){
                if(xi[i]>xi[i+1]){
                    temp = xi[i];
                    xi[i] = xi[i+1];
                    xi[i+1] = temp;
                }
            }
        }

        for(i=0;i<k;i=i+2){
            dda(xi[i],y,xi[i+1]+1,y);
        }
    }
}

