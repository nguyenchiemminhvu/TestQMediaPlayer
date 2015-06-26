#include "getfile.h"
#include "ui_getfile.h"

getFile::getFile(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::getFile)
{
    ui->setupUi(this);
    this->setMaximumSize(this->size());
    this->setMinimumSize(this->size());
}

getFile::~getFile()
{
    delete ui;
}

void getFile::on_pushButton_4_clicked()
{
    this->close();
}

void getFile::on_pushButton_3_clicked()
{
    emit getURL(list_file);
    this->close();
}

void getFile::on_pushButton_clicked()
{
    ui->lineEdit->setEnabled(false);
    list_file = QFileDialog::getOpenFileNames(this,"Search file",QString(),"Music (*.mp3)");
    if(list_file.size() == 1)
        ui->lineEdit->setText(list_file.at(0));
    else if(list_file.size() == 0)
        ui->lineEdit->setText("Empty");
    else
        ui->lineEdit->setText("Got a list of song");
}
