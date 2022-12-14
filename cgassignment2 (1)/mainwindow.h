#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QMouseEvent>
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
    void on_label_linkActivated(const QString &link);
    void dda(int x1,int y1 , int x2, int y2);  // step-1
    void mousePressEvent(QMouseEvent *event); // step-2
    void on_pushButton_clicked();
    void bresenham_line(int x1,int y1, int x2, int y2);
    int sign(int p);
private:
    Ui::MainWindow *ui;
    // step-3
    bool start;
    long long vertex,i,j,k,array_1[20000],array_2[20000];
    double xi[20000],temp,dx,dy;
    double slope_array[20000];
};
#endif // MAINWINDOW_H
