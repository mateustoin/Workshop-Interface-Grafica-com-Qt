#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mydialog.h"
#include "playDialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pushButton->setText("Contador");
    this->count = 0;

    // Conecta o slider para mover a barra de progresso junto com sua alteração de valor
    connect(ui->slider, SIGNAL(valueChanged(int)),
            ui->barra, SLOT(setValue(int)));

    // Modifica o intervalo do slider para encaixar do 0 a 100 da barra de progresso
    ui->slider->setRange(-1, 100);
    // Inicia barra de progresso com valor 0
    ui->barra->setValue(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Conta quantas vezes o botão foi clicado
void MainWindow::on_pushButton_clicked()
{
    // Incrementa o atibuto 'count' da classe
    this->count++;
    qDebug() << "Botão clicado " << count << " vezes!";
}

// Quando o valor do Slider muda, chama essa função e printa o valor atual da barra de progresso
void MainWindow::on_barra_valueChanged(int value)
{
    qDebug() << "Valor atual é: " << value;
}

// Quando mover slider, altera o valor da barra de progresso com seu valor + 1, para chegar aos 100%
void MainWindow::on_slider_valueChanged(int value)
{
    ui->barra->setValue(value + 1);
}

// Quando clica na ação "Arquivo > Nova Janela"
void MainWindow::on_actionNova_Janela_triggered()
{
    mDialog = new MyDialog(this);
    mDialog->setModal(false);
    mDialog->show();
}

// Quando clica na ação "Arquivo > Play Audio"
void MainWindow::on_actionPlay_Audio_triggered()
{
    mPlayDialog = new Dialog(this);
    mPlayDialog->show();
}

// Quando clica no botão 'Fechar', fecha a aplicação
void MainWindow::on_pushButton_2_clicked()
{
    QApplication::quit();
}
