/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *create_config;
    QAction *load_config;
    QAction *manage_config;
    QWidget *mainWidget;
    QTabWidget *tabWidget;
    QWidget *codeTab;
    QLabel *titleCode;
    QCheckBox *jsCheck;
    QCheckBox *cssCheck;
    QTextBrowser *jsBrowser;
    QTextBrowser *cssBrowser;
    QPushButton *launchCode;
    QWidget *imgTab;
    QLabel *titleImg;
    QPushButton *launchImage;
    QPushButton *loadImg;
    QLabel *labelPath;
    QLabel *labelQuality;
    QSlider *qualitySlider;
    QTextEdit *qualityField;
    QTextBrowser *fileName;
    QMenuBar *menuBar;
    QMenu *menuConfig;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(348, 374);
        MainWindow->setMinimumSize(QSize(348, 374));
        MainWindow->setMaximumSize(QSize(348, 374));
        create_config = new QAction(MainWindow);
        create_config->setObjectName(QStringLiteral("create_config"));
        load_config = new QAction(MainWindow);
        load_config->setObjectName(QStringLiteral("load_config"));
        load_config->setEnabled(false);
        manage_config = new QAction(MainWindow);
        manage_config->setObjectName(QStringLiteral("manage_config"));
        manage_config->setEnabled(false);
        mainWidget = new QWidget(MainWindow);
        mainWidget->setObjectName(QStringLiteral("mainWidget"));
        mainWidget->setMinimumSize(QSize(348, 353));
        mainWidget->setMaximumSize(QSize(348, 353));
        mainWidget->setStyleSheet(QLatin1String("QWidget{\n"
"	background-color: #fff;\n"
"}"));
        tabWidget = new QTabWidget(mainWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(6, -1, 341, 351));
        tabWidget->setMinimumSize(QSize(341, 351));
        tabWidget->setMaximumSize(QSize(341, 351));
        QFont font;
        font.setStyleStrategy(QFont::PreferDefault);
        tabWidget->setFont(font);
        tabWidget->setContextMenuPolicy(Qt::DefaultContextMenu);
        tabWidget->setStyleSheet(QLatin1String("QTabWidget{\n"
"	background-color: #fff;\n"
"}\n"
"\n"
"QWidget{\n"
"	background-color: #fff;\n"
"}"));
        tabWidget->setDocumentMode(true);
        codeTab = new QWidget();
        codeTab->setObjectName(QStringLiteral("codeTab"));
        codeTab->setStyleSheet(QLatin1String("QWidget{\n"
"color:#01293d;\n"
"}"));
        titleCode = new QLabel(codeTab);
        titleCode->setObjectName(QStringLiteral("titleCode"));
        titleCode->setGeometry(QRect(30, 20, 271, 41));
        QFont font1;
        font1.setFamily(QStringLiteral("Meiryo UI"));
        font1.setPointSize(16);
        font1.setBold(false);
        font1.setWeight(50);
        titleCode->setFont(font1);
        titleCode->setStyleSheet(QLatin1String("QLabel{\n"
"color:#01293d;\n"
"}"));
        jsCheck = new QCheckBox(codeTab);
        jsCheck->setObjectName(QStringLiteral("jsCheck"));
        jsCheck->setGeometry(QRect(30, 90, 81, 21));
        QFont font2;
        font2.setFamily(QStringLiteral("Meiryo UI"));
        font2.setPointSize(12);
        jsCheck->setFont(font2);
        jsCheck->setCursor(QCursor(Qt::PointingHandCursor));
        jsCheck->setStyleSheet(QLatin1String("QCheckBox{\n"
"color:#01293d;\n"
"}\n"
"QCheckBox::indicator:checked\n"
"{\n"
"height: 25px;\n"
"width: 25px;\n"
"background-color: #0b94d1;\n"
"background-image: url(:/pics/img/check.png);\n"
"background-repeat:no-repeat;\n"
"background-position:center center;\n"
"}\n"
"QCheckBox::indicator:unchecked\n"
"{\n"
"height: 25px;\n"
"width: 25px;\n"
"background-color: #eee;\n"
"}\n"
"QCheckBox::indicator:checked:hover\n"
"{\n"
"background-color: rgb(9, 136, 190);\n"
"}\n"
"QCheckBox::indicator:unchecked:hover\n"
"{\n"
"background-color: rgb(203, 203, 203);\n"
"}\n"
"QCheckBox::indicator:checked:pressed\n"
"{\n"
"background-color: rgb(9, 136, 190);\n"
"}\n"
"QCheckBox::indicator:unchecked:pressed\n"
"{\n"
"background-color: rgb(203, 203, 203);\n"
"}"));
        jsCheck->setChecked(true);
        cssCheck = new QCheckBox(codeTab);
        cssCheck->setObjectName(QStringLiteral("cssCheck"));
        cssCheck->setGeometry(QRect(30, 150, 81, 21));
        cssCheck->setFont(font2);
        cssCheck->setCursor(QCursor(Qt::PointingHandCursor));
        cssCheck->setStyleSheet(QLatin1String("QCheckBox{\n"
"color:#01293d;\n"
"}\n"
"QCheckBox::indicator:checked\n"
"{\n"
"height: 25px;\n"
"width: 25px;\n"
"background-color: #0b94d1;\n"
"background-image: url(:/pics/img/check.png);\n"
"background-repeat:no-repeat;\n"
"background-position:center center;\n"
"}\n"
"QCheckBox::indicator:unchecked\n"
"{\n"
"height: 25px;\n"
"width: 25px;\n"
"background-color: #eee;\n"
"}\n"
"QCheckBox::indicator:checked:hover\n"
"{\n"
"background-color: rgb(9, 136, 190);\n"
"}\n"
"QCheckBox::indicator:unchecked:hover\n"
"{\n"
"background-color: rgb(203, 203, 203);\n"
"}\n"
"QCheckBox::indicator:checked:pressed\n"
"{\n"
"background-color: rgb(9, 136, 190);\n"
"}\n"
"QCheckBox::indicator:unchecked:pressed\n"
"{\n"
"background-color: rgb(203, 203, 203);\n"
"}"));
        jsBrowser = new QTextBrowser(codeTab);
        jsBrowser->setObjectName(QStringLiteral("jsBrowser"));
        jsBrowser->setGeometry(QRect(130, 90, 171, 31));
        jsBrowser->setStyleSheet(QLatin1String("QTextEdit{\n"
"background-color:#fff;\n"
"border:0 solid #0b94d1;\n"
"border-bottom: 2px solid #0b94d1;\n"
"}"));
        jsBrowser->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        jsBrowser->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        cssBrowser = new QTextBrowser(codeTab);
        cssBrowser->setObjectName(QStringLiteral("cssBrowser"));
        cssBrowser->setGeometry(QRect(130, 150, 171, 31));
        cssBrowser->setStyleSheet(QLatin1String("QTextEdit{\n"
"background-color:#fff;\n"
"border:0 solid #0b94d1;\n"
"border-bottom: 2px solid #0b94d1;\n"
"}"));
        cssBrowser->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        cssBrowser->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        launchCode = new QPushButton(codeTab);
        launchCode->setObjectName(QStringLiteral("launchCode"));
        launchCode->setGeometry(QRect(150, 240, 151, 41));
        QFont font3;
        font3.setPointSize(10);
        font3.setBold(true);
        font3.setWeight(75);
        launchCode->setFont(font3);
        launchCode->setStyleSheet(QLatin1String("QPushButton {\n"
"border: 2px solid #0b94d1;\n"
"border-radius:20px;\n"
"color:#01293d;\n"
"}\n"
"QPushButton:hover{\n"
"background-color: #0b94d1;\n"
"color: white;\n"
"}"));
        tabWidget->addTab(codeTab, QString());
        imgTab = new QWidget();
        imgTab->setObjectName(QStringLiteral("imgTab"));
        imgTab->setStyleSheet(QLatin1String("QWidget{\n"
"color:#01293d;\n"
"}"));
        titleImg = new QLabel(imgTab);
        titleImg->setObjectName(QStringLiteral("titleImg"));
        titleImg->setGeometry(QRect(30, 20, 271, 41));
        titleImg->setFont(font1);
        titleImg->setStyleSheet(QLatin1String("QLabel{\n"
"color:#01293d;\n"
"}"));
        launchImage = new QPushButton(imgTab);
        launchImage->setObjectName(QStringLiteral("launchImage"));
        launchImage->setGeometry(QRect(150, 240, 151, 41));
        launchImage->setFont(font3);
        launchImage->setStyleSheet(QLatin1String("QPushButton {\n"
"border: 2px solid #0b94d1;\n"
"border-radius:20px;\n"
"color:#01293d;\n"
"}\n"
"QPushButton:hover{\n"
"background-color: #0b94d1;\n"
"color: white;\n"
"}"));
        loadImg = new QPushButton(imgTab);
        loadImg->setObjectName(QStringLiteral("loadImg"));
        loadImg->setGeometry(QRect(40, 70, 261, 41));
        loadImg->setFont(font3);
        loadImg->setStyleSheet(QLatin1String("QPushButton {\n"
"border: 2px solid #0b94d1;\n"
"background-color: #0b94d1;\n"
"border-radius:20px;\n"
"color: white;\n"
"}\n"
"QPushButton:hover{\n"
"background-color: #fff;\n"
"color:#01293d;\n"
"}"));
        labelPath = new QLabel(imgTab);
        labelPath->setObjectName(QStringLiteral("labelPath"));
        labelPath->setGeometry(QRect(40, 130, 61, 21));
        labelPath->setFont(font2);
        labelPath->setStyleSheet(QLatin1String("QLabel{\n"
"color:#01293d;\n"
"}"));
        labelQuality = new QLabel(imgTab);
        labelQuality->setObjectName(QStringLiteral("labelQuality"));
        labelQuality->setGeometry(QRect(40, 170, 71, 21));
        labelQuality->setFont(font2);
        labelQuality->setStyleSheet(QLatin1String("QLabel{\n"
"color:#01293d;\n"
"}"));
        qualitySlider = new QSlider(imgTab);
        qualitySlider->setObjectName(QStringLiteral("qualitySlider"));
        qualitySlider->setGeometry(QRect(40, 200, 221, 19));
        qualitySlider->setStyleSheet(QLatin1String("QSlider::groove:horizontal {\n"
"border: 1px solid #01293d;\n"
"background: white;\n"
"height: 10px;\n"
"border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::sub-page:horizontal {\n"
"background: qlineargradient(x1: 0, y1: 0,    x2: 0, y2: 1,\n"
"    stop: 0 #0b94d1, stop: 1 rgb(12, 177, 247));\n"
"background: qlineargradient(x1: 0, y1: 0.2, x2: 1, y2: 1,\n"
"    stop: 0 rgb(12, 177, 247), stop: 1 #0b94d1);\n"
"border: 1px solid #01293d;\n"
"height: 10px;\n"
"border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::add-page:horizontal {\n"
"background: #fff;\n"
"border: 1px solid #01293d;\n"
"height: 10px;\n"
"border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::handle:horizontal {\n"
"background: qlineargradient(x1:0, y1:0, x2:1, y2:1,\n"
"    stop:0 #eee, stop:1 #ccc);\n"
"border: 1px solid #01293d;\n"
"width: 13px;\n"
"margin-top: -2px;\n"
"margin-bottom: -2px;\n"
"border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::handle:horizontal:hover {\n"
"background: qlineargradient(x1:0, y1:0, x2:1, y2:1,\n"
"    stop:0 #fff, stop:1 #ddd);\n"
"border: 1p"
                        "x solid #01293d;\n"
"border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::sub-page:horizontal:disabled {\n"
"background: #bbb;\n"
"border-color: #01293d;\n"
"}\n"
"\n"
"QSlider::add-page:horizontal:disabled {\n"
"background: #eee;\n"
"border-color: #01293d;\n"
"}\n"
"\n"
"QSlider::handle:horizontal:disabled {\n"
"background: #eee;\n"
"border: 1px solid #0b94d1;\n"
"border-radius: 4px;\n"
"}"));
        qualitySlider->setValue(70);
        qualitySlider->setOrientation(Qt::Horizontal);
        qualityField = new QTextEdit(imgTab);
        qualityField->setObjectName(QStringLiteral("qualityField"));
        qualityField->setGeometry(QRect(270, 200, 31, 21));
        QFont font4;
        font4.setPointSize(8);
        qualityField->setFont(font4);
        qualityField->setStyleSheet(QLatin1String("QTextEdit{\n"
"background-color:#fff;\n"
"border:0 solid #0b94d1;\n"
"border-bottom: 2px solid #0b94d1;\n"
"}"));
        qualityField->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        qualityField->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        fileName = new QTextBrowser(imgTab);
        fileName->setObjectName(QStringLiteral("fileName"));
        fileName->setGeometry(QRect(120, 130, 181, 31));
        fileName->setStyleSheet(QLatin1String("QTextEdit{\n"
"background-color:#fff;\n"
"border:0 solid #0b94d1;\n"
"border-bottom: 2px solid #0b94d1;\n"
"}"));
        fileName->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        fileName->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tabWidget->addTab(imgTab, QString());
        MainWindow->setCentralWidget(mainWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 348, 21));
        menuConfig = new QMenu(menuBar);
        menuConfig->setObjectName(QStringLiteral("menuConfig"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuConfig->menuAction());
        menuConfig->addAction(create_config);
        menuConfig->addAction(load_config);
        menuConfig->addAction(manage_config);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        create_config->setText(QApplication::translate("MainWindow", "Ajouter une sauvegarde", nullptr));
        load_config->setText(QApplication::translate("MainWindow", "Charger une sauvegarde", nullptr));
        manage_config->setText(QApplication::translate("MainWindow", "G\303\251rer les sauvegarde", nullptr));
        titleCode->setText(QApplication::translate("MainWindow", "Compresseur de code:", nullptr));
        jsCheck->setText(QApplication::translate("MainWindow", "   JS", nullptr));
        cssCheck->setText(QApplication::translate("MainWindow", "   CSS", nullptr));
        jsBrowser->setPlaceholderText(QApplication::translate("MainWindow", "path_to_js", nullptr));
        cssBrowser->setPlaceholderText(QApplication::translate("MainWindow", "path_to_css", nullptr));
        launchCode->setText(QApplication::translate("MainWindow", "Compresser", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(codeTab), QApplication::translate("MainWindow", "Compresseur de code", nullptr));
        titleImg->setText(QApplication::translate("MainWindow", "Compresseur d'images:", nullptr));
        launchImage->setText(QApplication::translate("MainWindow", "Compresser", nullptr));
        loadImg->setText(QApplication::translate("MainWindow", "Charger une image", nullptr));
        labelPath->setText(QApplication::translate("MainWindow", "Image :", nullptr));
        labelQuality->setText(QApplication::translate("MainWindow", "Qualit\303\251 :", nullptr));
        qualityField->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        qualityField->setPlaceholderText(QApplication::translate("MainWindow", "70", nullptr));
        fileName->setPlaceholderText(QApplication::translate("MainWindow", "nom fichier transformer", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(imgTab), QApplication::translate("MainWindow", "Compresseur d'images", nullptr));
        menuConfig->setTitle(QApplication::translate("MainWindow", "Config", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
