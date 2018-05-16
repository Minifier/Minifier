#ifndef LOADPROFIL_H
#define LOADPROFIL_H

#include <QDialog>
#include <QListWidget>
#include <QMessageBox>

#include "codescompressor.h"

namespace Ui {
class LoadProfil;
}

class LoadProfil : public QDialog
{
    Q_OBJECT

public:
    explicit LoadProfil(QWidget *parent = 0);
    ~LoadProfil();

    void setCompressor( code_compressor::CodesCompressor * c);
    void setProfils();

private slots:
    void on_listProfils_itemClicked(QListWidgetItem *item);

    void on_buttonBox_accepted();

signals:
    void loadConfig(const QStringList &info);

private:
    Ui::LoadProfil *ui;
    QListWidgetItem * selected;
    code_compressor::CodesCompressor * compressor;
};

#endif // LOADPROFIL_H
