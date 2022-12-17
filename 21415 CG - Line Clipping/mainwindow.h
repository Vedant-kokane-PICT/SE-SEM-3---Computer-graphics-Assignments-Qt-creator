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
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void dda(int,int,int,int);
    void dda_1(int,int,int,int);
    void window();
    void window_1();
    void outcode_init(int a[],int x,int y);

private:
    Ui::MainWindow *ui;
    int x1,y1,x2,y2;
};
#endif // MAINWINDOW_H
