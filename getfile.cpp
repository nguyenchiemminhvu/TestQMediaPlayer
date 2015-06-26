#include "getfile.h"
#include "ui_getfile.h"

getFile::getFile(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::getFile)
{
    ui->setupUi(this);
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
    emit getURL(ui->lineEdit->text());
    this->close();
}

void getFile::on_pushButton_clicked()
{
    QString file = QFileDialog::getOpenFileName(this,"Search file",QString(),"Music (*.mp3)");
    ui->lineEdit->setText(file);
}
