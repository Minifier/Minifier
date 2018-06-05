#include "compressimagesdialog.h"
#include "ui_compressimagesdialog.h"

CompressImagesDialog::CompressImagesDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CompressImagesDialog)
{
    this->imageCompressor = new image_compressor::ImageCompressor();
    ui->setupUi(this);

    ui->index->setText("0");
    ui->currentTxt->setText("");

    QCoreApplication::processEvents();
}

CompressImagesDialog::~CompressImagesDialog()
{
    delete ui;
}

/**
 * @brief CompressImagesDialog::processImages process an image
 * @param imgPath image path
 * @param outputFilePath output filepath for compressor
 * @param i index for refresh screen display
 * @param quality picture quality to output
 */
void CompressImagesDialog::processImage(const QString &imgPath, QString &outputFilePath, const int & i, const int & quality)
{
    ui->index->setText(QString::number(i+1));
    ui->currentTxt->setText(imgPath.split('/').last());
    ui->progressBar->setValue(this->dt * (i+1));

    QStringList tmp = outputFilePath.split('.');
    QStringList tmp_2;
    for(int i =0; i < tmp.size() -1 ; i++)
    {
        tmp_2 << tmp.at(i);
    }

    outputFilePath = tmp_2.join('.') + ".jpg";

    this->imageCompressor->convert(imgPath, outputFilePath, quality);
    QCoreApplication::processEvents();
}

/**
 * @brief CompressImagesDialog::processImages process an image
 * @param imgPath image path
 * @param i index for refresh screen display
 * @param quality picture quality to output
 */
void CompressImagesDialog::processImage(const QString &imgPath, const int & i, const int & quality)
{
    ui->index->setText(QString::number(i+1));
    ui->currentTxt->setText(imgPath.split('/').last());
    ui->progressBar->setValue(this->dt * (i+1));
    this->imageCompressor->convert(imgPath, quality);
    QCoreApplication::processEvents();
}

/**
 * @brief CompressImagesDialog::run launch loop to process each img in imgPathList
 * @param imgPathList list of image path
 * @param outputPath where to output the file after compression
 * @param quality quality level
 */
void CompressImagesDialog::run(const QStringList* imgPathList , const QString & outputPath , const int & quality)
{
    this->s = (*imgPathList).size();
    this->dt = 100/s;

    ui->total->setText("/" + QString::number(s));

    for(int i =0; i < s; i++)
    {
        QString pf_in = (*imgPathList).at(i);
        QString pf_out = outputPath + pf_in.split('/').last();
        this->processImage(pf_in, pf_out, i , quality);
    }
}

/**
 * @brief CompressImagesDialog::run launch loop to process each img in imgPathList
 * @param imgPathList list of image path
 * @param quality quality level
 */
void CompressImagesDialog::run(const QStringList* imgPathList , const int & quality)
{
    this->s = (*imgPathList).size();
    this->dt = 100/s;

    ui->total->setText("/" + QString::number(s));

    for(int i =0; i < s; i++)
    {
        this->processImage((*imgPathList).at(i), i , quality);
    }
}
