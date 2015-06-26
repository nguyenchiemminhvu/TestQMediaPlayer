#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    setUpPlayer();

    ui->label->setText("");

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

void Dialog::receiptFile(QStringList list_file)
{
    foreach (QString url, list_file) {

        playlist->addMedia(QUrl(url));
    }


    player->play();
}

void Dialog::showNameSong(QMediaContent media)
{
    ui->label->setText(media.canonicalUrl().fileName());
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
    connect(playlist,SIGNAL(currentMediaChanged(QMediaContent)),this,SLOT(showNameSong(QMediaContent)));

    playlist->setPlaybackMode(QMediaPlaylist::Loop);

    player->setPlaylist(playlist);
    player->play();
}

void Dialog::on_pushButton_clicked()
{
    playlist->next();
    if(playlist->currentMedia().isNull())   {

        playlist->removeMedia(playlist->currentIndex());
        playlist->next();
    }
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
    getFile* openfile = new getFile(this);
    connect(openfile,SIGNAL(getURL(QStringList)),this,SLOT(receiptFile(QStringList)));
    openfile->exec();
}
