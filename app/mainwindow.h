#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include "mydialog.h"
#include "playDialog.h"

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

    void on_barra_valueChanged(int value);

    void on_slider_valueChanged(int value);

    void on_actionNova_Janela_triggered();

    void on_actionPlay_Audio_triggered();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    int count;
    MyDialog *mDialog;
    Dialog *mPlayDialog;
};
#endif // MAINWINDOW_H
