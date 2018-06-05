#include "compressimagesdialog.h"
#include "ui_compressimagesdialog.h"

CompressImagesDialog::CompressImagesDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CompressImagesDialog)
{
    ui->setupUi(this);
}

CompressImagesDialog::~CompressImagesDialog()
{
    delete ui;
}
