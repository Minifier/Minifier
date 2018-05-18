/*******************************************************************
Copyright (C) 2018 Oscar MARIE--TAILLEFER   <o5mariet@enib.fr>
Copyright (C) 2018 Nils JEGOU-GERGAUD       <n5jegoug@enib.fr>
Copyright (C) 2018 Nicols FRANCIS           <n4franci@enib.fr>
Copyright (C) 2018 Corentin LAMBERT         <c4lamber@enib.fr>

This file is part of Minifier.

Minifier is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Minifier is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Minifier.  If not, see <http://www.gnu.org/licenses/>.
*******************************************************************/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>

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
