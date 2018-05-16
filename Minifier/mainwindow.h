#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>

#include <vector>
#include <string>

#include "codescompressor.h"
#include "loadprofil.h"
#include "manageprofil.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    /**
     * @brief launchCodeCompressorlaunch code compressor
     */
    void launchCodeCompressor();

private slots:
    /**
     * @brief setConfigInfo slot use during profile loading to change ui
     * @param info list(cssFolder,jsFolder)
     */
    void setConfigInfo(const QStringList &info);

    void on_js_browser_clicked();

    void on_css_browser_clicked();

    void on_launchCode_clicked();

    void on_jsCheck_stateChanged(int arg1);

    void on_cssCheck_stateChanged(int arg1);

    void on_create_config_triggered();

    void on_load_config_triggered();

    void on_manage_config_triggered();

    void on_actionRun_triggered();

    void on_actionStop_triggered();

private:
    Ui::MainWindow *ui;
    LoadProfil p;
    ManageProfil m;

    QString css_folder, js_folder;
    bool css_selected, js_selected;

    code_compressor::CodesCompressor * codeCompressor;
};

#endif // MAINWINDOW_H
