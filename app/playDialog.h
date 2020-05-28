#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QMediaPlayer>
#include <QDebug>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_durationSlider_sliderMoved(int position);

    void on_volumeSlider_sliderMoved(int position);

    void on_startButton_clicked();

    void on_stopButton_clicked();

    void on_positionChanged(quint64 position);

    void on_durationChanged(quint64 position);

    void on_pushButton_clicked();

private:
    Ui::Dialog *ui;
    QMediaPlayer *player;
    QString localFile;
};

#endif // DIALOG_H
