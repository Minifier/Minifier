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

private slots:
    void on_listProfils_itemClicked(QListWidgetItem *item);

    void on_deleteBtn_clicked();

    void on_renameBtn_clicked();

    void on_cancelBtn_clicked();

private:
    Ui::ManageProfil *ui;
    QListWidgetItem * selected;
    code_compressor::CodesCompressor * compressor;
};

#endif // MANAGEPROFIL_H
