#include "playDialog.h"
#include "ui_playDialog.h"
#include <QFileDialog>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    // Inicializa o caminho para a pasta vazio
    this->localFile = "";

    // Instancia objeto de QMediaPlayer
    player = new QMediaPlayer(this);

    // Conecta as funções de posição e duração para as funções implementadas na classe
    connect(player, &QMediaPlayer::positionChanged, this, &Dialog::on_positionChanged);
    connect(player, &QMediaPlayer::durationChanged, this, &Dialog::on_durationChanged);
}

Dialog::~Dialog()
{
    delete ui;
}

// Função chamada quando slider da duração for movido
void Dialog::on_durationSlider_sliderMoved(int position)
{
    // Muda a posição de reprodução da mídia para a posição referente a do slider
    player->setPosition(position);
}

// Função chamada quando o slider de volume for movido
void Dialog::on_volumeSlider_sliderMoved(int position)
{
    // Altera o volume da mídia de 0 a 100% confirme a posição do slider
    player->setVolume(position);
}

void Dialog::on_startButton_clicked()
{
    // Carrega o arquivo de áudio no objeto player
    player->setMedia(QUrl::fromLocalFile(localFile));

    // Inicia mídia de áudio
    player->play();

    // Printa possível erro, caso ocorra
    qDebug() << player->errorString();
}

void Dialog::on_stopButton_clicked()
{
    // Para reprodução da mídia
    player->stop();
}

// Conforme a mídia reproduzida executa, atualiza barra de duração para sua posição atual
void Dialog::on_positionChanged(quint64 position)
{
    ui->durationSlider->setValue(position);
}

// Seta a posição máxima do slider de duração com o máximo da mídia em execução
void Dialog::on_durationChanged(quint64 position)
{
    ui->durationSlider->setMaximum(position);
}

// Abre diálogo de arquivos para adquirir o caminho para a mídia a ser executada
void Dialog::on_pushButton_clicked()
{
    this->localFile = QFileDialog::getOpenFileName(this, "Abrindo música", "C://");
    qDebug() << "Local do arquivo: .." << this->localFile;
}
