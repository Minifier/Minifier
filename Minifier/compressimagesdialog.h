#ifndef COMPRESSIMAGESDIALOG_H
#define COMPRESSIMAGESDIALOG_H

#include <QDialog>

namespace Ui {
class CompressImagesDialog;
}

class CompressImagesDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CompressImagesDialog(QWidget *parent = 0);
    ~CompressImagesDialog();

private:
    Ui::CompressImagesDialog *ui;
};

#endif // COMPRESSIMAGESDIALOG_H
