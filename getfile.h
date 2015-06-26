#ifndef GETFILE_H
#define GETFILE_H

#include <QDialog>
#include <QFileDialog>

namespace Ui {
class getFile;
}

class getFile : public QDialog
{
    Q_OBJECT

public:
    explicit getFile(QWidget *parent = 0);
    ~getFile();

signals:
    void getURL(QStringList);

private slots:
    void on_pushButton_4_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_clicked();

private:
    Ui::getFile *ui;
    QStringList list_file;
};

#endif // GETFILE_H
