#ifndef COMPRESSIMAGESDIALOG_H
#define COMPRESSIMAGESDIALOG_H

#include <QDialog>
#include <QString>
#include <QStringList>

#include "imagecompressor.h"

namespace Ui {
class CompressImagesDialog;
}

class CompressImagesDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CompressImagesDialog(QWidget *parent);
    ~CompressImagesDialog();

    /**
     * @brief CompressImagesDialog::processImages process an image
     * @param imgPath image path
     * @param outputFilePath output filepath for compressor
     * @param i index for refresh screen display
     * @param quality picture quality to output
     */
    void processImage(const QString &imgPath, QString &outputFilePath, const int & i, const int & quality);
    void processImage(const QString &imgPath, const int & i, const int & quality);

    /**
     * @brief CompressImagesDialog::run launch loop to process each img in imgPathList
     * @param imgPathList list of image path
     * @param outputPath where to output the file after compression
     * @param quality quality level
     */
    void run(const QStringList* imgPathList , const QString & outputPath , const int & quality);
    void run(const QStringList* imgPathList , const int & quality);

private:
    Ui::CompressImagesDialog *ui;

    int dt , s;

    image_compressor::ImageCompressor * imageCompressor;
};

#endif // COMPRESSIMAGESDIALOG_H
