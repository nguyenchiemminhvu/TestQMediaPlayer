#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    setUpPlayer();

    ui->progressBar->setValue(0);
    ui->verticalSlider->setMinimum(0);
    ui->verticalSlider->setMaximum(100);
    ui->verticalSlider->setValue(100);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::calculatePercent(qint64 current)
{
    ui->progressBar->setMaximum(player->duration());
    ui->progressBar->setValue(current);
}

void Dialog::setUpPlayer()
{
    player = new QMediaPlayer(this);
    connect(ui->verticalSlider,SIGNAL(valueChanged(int)),player,SLOT(setVolume(int)));
    connect(player,SIGNAL(positionChanged(qint64)),this,SLOT(calculatePercent(qint64)));

    playlist = new QMediaPlaylist(this);
    connect(playlist,SIGNAL(loadFailed()),player,SLOT(stop()));
    connect(playlist,SIGNAL(loaded()),player,SLOT(play()));
    connect(playlist,SIGNAL(loadFailed()),playlist,SLOT(next()));

    playlist->addMedia(QMediaContent(QUrl("http://dl2.hot2.cache11.vcdn.vn/fsdd1131lwwjA/63e671c0c4f05dbfb63bb9159f02f09b/558bb500/2011/07/12/f/6/f65a55bd3ec10ae688c48d97fe30792d.mp3?filename=Tam%20Anh%20Khong%20Hon%20-%20Quang%20Linh.mp3")));
    playlist->addMedia(QMediaContent(QUrl("http://dl.mp3.zdn.vn/fsfsdfdsfdserwrwq3/67b4043de921b1616e4b3258089e74f3/558bb500/f/be/fbe57c39812b8cf07a0d8657142b4fde.mp3?filename=Mua%20Dem%20Tinh%20Nho%20-%20Quang%20Le.mp3")));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);

    player->setPlaylist(playlist);
    player->play();
}

void Dialog::on_pushButton_clicked()
{
    playlist->next();
    if(playlist->currentMedia().isNull())
        playlist->next();
}

void Dialog::on_pushButton_2_clicked()
{
    if(playlist->isEmpty())
        return;

    playlist->removeMedia(playlist->currentIndex());
    if(playlist->isEmpty())
        player->stop();
}

void Dialog::on_pushButton_3_clicked()
{
    QString url = QInputDialog::getText(this,"get URL","URL: ");
    playlist->addMedia(QUrl(url));

    player->play();
}
