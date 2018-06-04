#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    // Initialize empty js_folder and css_folder
    this->js_folder = " ";
    this->css_folder = " ";

    // Set default state for js and css checkBox
    this->js_selected = true;
    this->css_selected = false;

    // Create an empty codes compressor manager
    this->codeCompressor = new code_compressor::CodesCompressor();
    this->imageCompressor = new image_compressor::ImageCompressor();

    // Set link to the compressor for manageProfil (m) and loadProfil (p) ui
    p.setCompressor(this->codeCompressor);
    m.setCompressor(this->codeCompressor);

    // Connect between LoadProfil and MainWindow to change ui
    QObject::connect(&p, SIGNAL(loadConfig(QStringList)) , this, SLOT(setConfigInfo(QStringList)));

    this->setupSystemTray();

    // Qt function
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
    // Clear tmp directory of files create during code compression
    QProcess p;
    p.start(ExePath() + "clear_tmp.bat");
    if( p.waitForFinished() )
    {
        return;
    }
}

/**
 * @brief launchCodeCompressorlaunch code compressor
 */
void MainWindow::launchCodeCompressor()
{
    // Create an empty param list and set css and js path to folder
    QStringList folder;
    folder << this->css_folder << this->js_folder;

    // Launch manager on param
    this->codeCompressor->launchCompressor(folder);

    // Set stop and create action enable in ui
    ui->actionStop->setEnabled(true);
    ui->create_config->setEnabled(true);
    this->_stop->setEnabled(true);

    // Show message box success
    QMessageBox::information(this,"Lancement du compresseur","Le compresseur est bien lancé. \nPour le stop, cliquez sur le bouton stop.");
}

/**
 * @brief setConfigInfo slot use during profile loading to change ui
 * @param info list(cssFolder,jsFolder)
 */
void MainWindow::setConfigInfo(const QStringList &info)
{
    if(info.at(0) != " ") // info.at(0) <=> css_folder
    {
        // If isset
        this->css_folder = info.at(0);
        // set css checkBox at selected
        this->css_selected = true;
        ui->cssCheck->setCheckState(Qt::Checked);
        ui->cssPath->setText(this->css_folder);

        // Change css_browser style to notify that a directory is set
        ui->css_browser->setStyleSheet("background-color: #0b94d1;border: none;");
    } else {
        // If empty
        this->css_selected = false;
        ui->cssCheck->setCheckState(Qt::Unchecked);
        ui->cssPath->setText("");
        ui->css_browser->setStyleSheet("background-color:#fff;border:0 solid #0b94d1;border-bottom: 2px solid #0b94d1;");
    }

    if(info.at(1) != " ") // info.at(0) <=> js_folder
    {
        //If isset
        this->js_folder = info.at(1);
        this->js_selected = true;
        ui->jsCheck->setCheckState(Qt::Checked);
        ui->jsPath->setText(this->js_folder);

        // Change js_browser style to notify that a directory is set
        ui->js_browser->setStyleSheet("background-color: #0b94d1;border: none;");
    } else {
        // If empty
        this->js_selected = false;
        ui->jsCheck->setCheckState(Qt::Unchecked);
        ui->jsPath->setText("");
        ui->js_browser->setStyleSheet("background-color:#fff;border:0 solid #0b94d1;border-bottom: 2px solid #0b94d1;");

    }

    // Set stop action enable in ui
    ui->actionStop->setEnabled(true);
    this->_stop->setEnabled(true);

    QMessageBox::information(this,"Chargement du profil","Le profil a bien été chargé.");
}

/**
 * @brief setupSystemTray setup system tray for windows
 */
void MainWindow::setupSystemTray()
{
    this->_sysTray = new QSystemTrayIcon(this);

    // Initialize menu
    this->_menu = new QMenu(this);

    // Initialize actions
    this->_start = new QAction("Launch compressor",this);
    this->_stop = new QAction("Stop compressor",this);
    this->_open = new QAction("Open Main Window",this);
    this->_exit = new QAction("Exit application",this);

    // Connect action
    QObject::connect(this->_start,SIGNAL(triggered()),this,SLOT(runFromStray()));
    QObject::connect(this->_stop,SIGNAL(triggered()),this,SLOT(stopFromStray()));
    QObject::connect(this->_open,SIGNAL(triggered()),this,SLOT(show()));
    QObject::connect(this->_exit,SIGNAL(triggered()),this,SLOT(close()));

    // Add actions to menu
    this->_menu->addAction(this->_start);
    this->_menu->addAction(this->_stop);
    this->_menu->addAction(this->_open);
    this->_menu->addSeparator();
    this->_menu->addAction(this->_exit);

    this->_start->setEnabled(false);
    this->_stop->setEnabled(false);

    // Set icon to system tray
    this->_sysTray->setIcon(QIcon(":/pics/img/icon.png"));

    // Set menu to system tray
    this->_sysTray->setContextMenu(this->_menu);
    this->show();
}

/**
 * @brief runFromStray slot use to run compressor from system tray
 */
void MainWindow::runFromStray()
{
    this->codeCompressor->compress();
    this->_stop->setEnabled(true);
    this->_start->setEnabled(false);
    ui->actionRun->setEnabled(false);
    ui->actionStop->setEnabled(true);
}

/**
 * @brief stopFromStray slot use to stop compressor from system tray
 */
void MainWindow::stopFromStray()
{
    this->codeCompressor->stop();
    this->_stop->setEnabled(false);
    this->_start->setEnabled(true);
    ui->actionRun->setEnabled(true);
    ui->actionStop->setEnabled(false);
}

void MainWindow::closeEvent (QCloseEvent *event)
{
    if(this->isVisible() && this->codeCompressor->running()){
        event->ignore();
        QMessageBox::information(this, "Minifier" , tr("Le programme continue de compresser en tâches de fond.\n"
                                                 "Vous pouvez le fermer dans la zone de notification."));
        this->hide();
        QCoreApplication::processEvents();
    }
}

void MainWindow::on_js_browser_clicked()
{
    // Let user choose his js directory
    this->js_folder = QFileDialog::getExistingDirectory(this, "Choix du dossier JS", "C:\\") + '/';

    // set js checkBox at selected
    this->js_selected = true;
    ui->jsCheck->setCheckState(Qt::Checked);
    ui->jsPath->setText(this->js_folder);

    // Change js_browser style to notify that a directory is set
    ui->js_browser->setStyleSheet("background-color: #0b94d1;border: none;");
}

void MainWindow::on_css_browser_clicked()
{
    // Let user choose his css directory
    this->css_folder = QFileDialog::getExistingDirectory(this, "Choix du dossier CSS.", "C:\\")+ '/';

    // set css checkBox at selected
    this->css_selected = true;
    ui->cssCheck->setCheckState(Qt::Checked);
    ui->cssPath->setText(this->css_folder);

    // Change css_browser style to notify that a directory is set
    ui->css_browser->setStyleSheet("background-color: #0b94d1;border: none;");
}

/**
 * @brief MainWindow::on_launchCode_clicked launch compressor after check on users'inputs
 */
void MainWindow::on_launchCode_clicked()
{
    int error = 0;
    QString emsg = " ";
    if( this->js_folder == " " && this->js_selected){
        error++;
        emsg = "Veuillez sélectionner un dossier JS.";
    }
    if( this->css_folder == " " && this->css_selected){
        error++;
        emsg = "Veuillez sélectionner un dossier CSS.";
    }
    if(!this->css_selected && !this->js_selected )
    {
        error++;
        emsg = "Veuillez sélectionner un compresseur.";
    }

    switch (error)
    {
        case 3:
            QMessageBox::warning(this,"Remplissage invalide","Veuillez sélectionner un compresseur.");
            break;
        case 2:
            QMessageBox::warning(this,"Remplissage invalide","Veuillez sélectionner un dossier CSS et JS.");
            break;
        case 1:
            QMessageBox::warning(this,"Remplissage invalide",emsg);
            break;
        case 0:
            this->launchCodeCompressor();
            break;
        default:
            break;
    }
}

void MainWindow::on_jsCheck_stateChanged(int arg1)
{
    if(arg1 == Qt::Checked){
        this->js_selected = true;
    }else{
        this->js_selected = false;
        ui->js_browser->setStyleSheet("background-color:#fff;border:0 solid #0b94d1;border-bottom: 2px solid #0b94d1;");
        ui->jsPath->setText("");
    }
}

void MainWindow::on_cssCheck_stateChanged(int arg1)
{
    if(arg1 == Qt::Checked){
        this->css_selected = true;
    }else{
        this->css_selected = false;
        ui->css_browser->setStyleSheet("background-color:#fff;border:0 solid #0b94d1;border-bottom: 2px solid #0b94d1;");
        ui->cssPath->setText("");
    }
}

void MainWindow::on_create_config_triggered()
{
    if(this->codeCompressor->_profil == nullptr){
        QMessageBox::warning(this,"Erreur","Veuillez lancer le compresseur avant de sauvegarder sa configuration.");
    }else{
        bool ok;
        QString text;
        do{
            text = QInputDialog::getText(this, "Sauvegarde d'une configuration." , "Entrer un nom pour sauvegarder la configuration:" , QLineEdit::Normal,QDir::home().dirName(), &ok);
            if(!ok){
                return;
            }
            if(this->codeCompressor->checkExist(text))
            {
                ok = true;
                QMessageBox::warning(this,"Nom de configuration","Ce nom de configuration est déjà utilisé.");
            }else{
                ok = false;
            }
        }
        while(text.isEmpty() || ok);
        this->codeCompressor->saveProfil(text);
        QMessageBox::information(this,"Sauvegarde du profil","Le profil a bien été sauvegardé.");
    }
}

void MainWindow::on_load_config_triggered()
{
    // Refresh profils list and show
    p.setProfils();
    p.show();
}

void MainWindow::on_manage_config_triggered()
{
    // Refresh profils list and show
    m.setProfils();
    m.show();
}

void MainWindow::on_actionRun_triggered()
{
    if(this->codeCompressor->_profil == nullptr){
        QMessageBox::warning(this,"Erreur","Aucune configuration n'a pas été chargée.");
    }else{
        this->codeCompressor->compress();
        ui->actionStop->setEnabled(true);
        this->_stop->setEnabled(true);
        this->_start->setEnabled(false);
        QMessageBox::information(this,"Lancement du compresseur","Le compresseur est bien lancé. \nPour le stopper, cliquez sur le bouton stop.");
    }
}

void MainWindow::on_actionStop_triggered()
{
    this->codeCompressor->stop();
    ui->actionStop->setEnabled(false);
    ui->actionRun->setEnabled(true);
    this->_stop->setEnabled(false);
    this->_start->setEnabled(true);
    QMessageBox::information(this,"Arrêt du compresseur","Le compresseur est bien stoppé. \nPour le relancer, cliquez sur le bouton run.");
}

void MainWindow::on_loadImg_clicked()
{
    QString filter = "Fichiers images (*.png *.jpg *.bmp);;Fichiers png (*.png);;Fichiers tiff (*.tif *.tiff);;Fichiers psd (*.psd);;Fichiers bmp (*.bmp);;Fichiers gif (*.gif);;Fichiers ico (*.ico)";
    this->img_path = QFileDialog::getOpenFileName(this, tr("Charger une image"), "C:\\" , filter);
}

void MainWindow::on_qualitySlider_valueChanged(int value)
{
    ui->qualtiySpinBox->setValue(value);
}

void MainWindow::on_qualtiySpinBox_valueChanged(int arg1)
{
    ui->qualitySlider->setValue(arg1);
}

void MainWindow::iconActivated(QSystemTrayIcon::ActivationReason reason)
{
    switch (reason){
    case QSystemTrayIcon::Trigger:
        if(!this->isVisible()){
            this->show();
        } else {
            this->hide();
        }
        break;
    default:
        break;
    }
}

void MainWindow::on_launchImage_clicked()
{
    // Get fileName
    QString fileName = ui->fileName->text().simplified();


    QRegExp re_1("jpeg", Qt::CaseInsensitive);
    QRegExp re_2("jpg", Qt::CaseInsensitive);
    re_1.setPatternSyntax(QRegExp::Wildcard);
    re_2.setPatternSyntax(QRegExp::Wildcard);
    // Kill extension if user enter ".jpg"
    QStringList c = fileName.split('.');
    while(re_1.exactMatch(c.last()) or re_2.exactMatch(c.last()))
    {
        QStringList path;
        int sl = c.size();
        if (sl != 1) {
            path.clear();
            for (int i = 0; i < sl - 1; i++) {
                path << c.at(i);
            }
            fileName = path.join('.');
        }
        c = fileName.split('.');
    }

    this->imageCompressor->convert(this->img_path, fileName, ui->qualitySlider->value());
    QMessageBox::information(this,"Compression d'image","L'image " + this->img_path.split('/').last() + " a été compressée.");

}
