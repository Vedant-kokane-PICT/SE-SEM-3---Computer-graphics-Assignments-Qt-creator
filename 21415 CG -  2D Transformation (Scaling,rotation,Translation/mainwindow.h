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
    void on_label_linkActivated(const QString &link);

    void on_pushButton_3_clicked();

    void on_textEdit_copyAvailable(bool b);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    void dda(int x1, int y1, int x2, int y2);

    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H


/* MAINWINDOW CONSTRUCTOR
 * DRAW 4 QUADTRANTS
 * DDA(0,200,
 * X1,Y1,X2,Y2 --4 INPUTS
 * TX,TY -- TRANSLATION FACTORS --  2 INPUT
 * DDA , TRANSLATED LINE -- BUTTONS
 * SHIFT OF ORIGIN 200,200 EX
 * TO TRANSLATE GIVE TRANSLATION FACTOR X1=X1+TX,Y1=Y1+TY,X2=X2+TX,Y2=Y2+TY -- DEFINITON OF BUTTON

for scaling put any one pixel to origin like (x1,y1..) {put x1 to 0}
*/
