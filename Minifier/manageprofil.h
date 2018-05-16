#ifndef MANAGEPROFIL_H
#define MANAGEPROFIL_H

#include <QDialog>
#include <QListWidget>
#include <QMessageBox>

#include "codescompressor.h"

namespace Ui {
class ManageProfil;
}

class ManageProfil : public QDialog
{
    Q_OBJECT

public:
    explicit ManageProfil(QWidget *parent = 0);
    ~ManageProfil();

    void setCompressor( code_compressor::CodesCompressor * c);
    void setProfils();

private:
    Ui::ManageProfil *ui;
    QListWidgetItem * selected;
    code_compressor::CodesCompressor * compressor;
};

#endif // MANAGEPROFIL_H
