#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QInputDialog>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include "getfile.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

public slots:
    void calculatePercent(qint64 current);
    void receiptFile(QStringList list_file);
    void showNameSong(QMediaContent);
    void pause();
    void play();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::Dialog *ui;
    QMediaPlayer* player;
    QMediaPlaylist* playlist;

    bool isPlaying;

    void setUpPlayer();
    void setUpPlayButton();
};

#endif // DIALOG_H
