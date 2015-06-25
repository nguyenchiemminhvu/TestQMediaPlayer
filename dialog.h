#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QInputDialog>
#include <QMediaPlayer>
#include <QMediaPlaylist>

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

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Dialog *ui;
    QMediaPlayer* player;
    QMediaPlaylist* playlist;

    void setUpPlayer();
};

#endif // DIALOG_H
