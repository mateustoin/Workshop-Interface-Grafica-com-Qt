#include "mydialog.h"
#include "ui_mydialog.h"
#include <QDebug>

MyDialog::MyDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MyDialog)
{
    ui->setupUi(this);
}

MyDialog::~MyDialog()
{
    delete ui;
}

// SLOT que será chamado quando o botão "Ok" for clicado
void MyDialog::on_pushButton_clicked()
{
    // Printa no console o texto digitado no campo "lineEdit"
    qDebug() << "Nome inserido na caixinha: " << ui->lineEdit->text();
}

// SLOT que será chamado quando o botão "Cancel" for clicado
void MyDialog::on_pushButton_2_clicked()
{
    // Printa no console a palavra Desistiu
    qDebug() << "Desistiu";
}
