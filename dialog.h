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
    void receiptFile(QString file);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Dialog *ui;
    QString url;
    QMediaPlayer* player;
    QMediaPlaylist* playlist;

    void setUpPlayer();
};

#endif // DIALOG_H
