#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QMouseEvent>
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
    void mousePressEvent(QMouseEvent *event);
    void dda(int x1,int y1,int x2,int y2);
private:
    Ui::MainWindow *ui;
    long long i,j,k,a[20000],b[20000],v;
    double s[20000],xi[20000],temp,dx,dy;
    bool start;
};
#endif // MAINWINDOW_H
