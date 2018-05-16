#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->js_folder = " ";
    this->css_folder = " ";

    this->js_selected = true;
    this->css_selected = false;

    this->codeCompressor = new code_compressor::CodesCompressor();
    p.setCompressor(this->codeCompressor);
    m.setCompressor(this->codeCompressor);

    // Connect between LoadProfil and MainWindow to change ui
    QObject::connect(&p, SIGNAL(loadConfig(QStringList)) , this, SLOT(setConfigInfo(QStringList)));

    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * @brief launchCodeCompressorlaunch code compressor
 */
void MainWindow::launchCodeCompressor()
{
    QStringList folder;
    folder << this->css_folder << this->js_folder;

    this->codeCompressor->launchCompressor(folder);
    ui->actionStop->setEnabled(true);
    ui->create_config->setEnabled(true);
    QMessageBox::information(this,"Lancement du compresseur","Le compresseur est bien lancé. \nPour le stop, cliquez sur le bouton stop.");
}

/**
 * @brief setConfigInfo slot use during profile loading to change ui
 * @param info list(cssFolder,jsFolder)
 */
void MainWindow::setConfigInfo(const QStringList &info)
{
    if(info.at(0) != " ")
    {
        this->css_folder = info.at(0);
        // set css checkBox at selected
        this->css_selected = true;
        ui->cssCheck->setCheckState(Qt::Checked);
        ui->cssPath->setText(this->css_folder);

        // Change css_browser style to notify that a directory is set
        ui->css_browser->setStyleSheet("background-color: #0b94d1;border: none;");
    } else {
        this->css_selected = false;
        ui->cssCheck->setCheckState(Qt::Unchecked);
        ui->cssPath->setText("");
        ui->css_browser->setStyleSheet("background-color:#fff;border:0 solid #0b94d1;border-bottom: 2px solid #0b94d1;");
    }

    if(info.at(1) != " ")
    {
        this->js_folder = info.at(1);
        this->js_selected = true;
        ui->jsCheck->setCheckState(Qt::Checked);
        ui->jsPath->setText(this->js_folder);

        // Change js_browser style to notify that a directory is set
        ui->js_browser->setStyleSheet("background-color: #0b94d1;border: none;");
    } else {
        this->js_selected = false;
        ui->jsCheck->setCheckState(Qt::Unchecked);
        ui->jsPath->setText("");
        ui->js_browser->setStyleSheet("background-color:#fff;border:0 solid #0b94d1;border-bottom: 2px solid #0b94d1;");

    }

    ui->actionStop->setEnabled(true);

    QMessageBox::information(this,"Chargement du profil","Le profil a bien été chargé.");
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
    this->css_folder = QFileDialog::getExistingDirectory(this, "Choix du dossier CSS", "C:\\")+ '/';

    // set css checkBox at selected
    this->css_selected = true;
    ui->cssCheck->setCheckState(Qt::Checked);
    ui->cssPath->setText(this->css_folder);

    // Change css_browser style to notify that a directory is set
    ui->css_browser->setStyleSheet("background-color: #0b94d1;border: none;");
}

void MainWindow::on_launchCode_clicked()
{
    int error = 0;
    QString emsg = " ";
    if( this->js_folder == " " && this->js_selected){
        error++;
        emsg = "Veuillez selectionner un dossier JS.";
    }
    if( this->css_folder == " " && this->css_selected){
        error++;
        emsg = "Veuillez selectionner un dossier CSS.";
    }
    if(!this->css_selected && !this->js_selected )
    {
        error++;
        emsg = "Veuillez selectionner un compresseur.";
    }

    switch (error)
    {
        case 3:
            QMessageBox::warning(this,"Remplissage invalide","Veuillez selectionner un compresseur.");
            break;
        case 2:
            QMessageBox::warning(this,"Remplissage invalide","Veuillez selectionner un dossier CSS et JS.");
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
    if(arg1 == 2){
        this->js_selected = true;
    }else{
        this->js_selected = false;
        ui->js_browser->setStyleSheet("background-color:#fff;border:0 solid #0b94d1;border-bottom: 2px solid #0b94d1;");
        ui->jsPath->setText("");
    }
}

void MainWindow::on_cssCheck_stateChanged(int arg1)
{
    if(arg1 == 2){
        this->css_selected = true;
    }else{
        this->css_selected = false;
        ui->css_browser->setStyleSheet("background-color:#fff;border:0 solid #0b94d1;border-bottom: 2px solid #0b94d1;");
        ui->jsPath->setText("");
    }
}

void MainWindow::on_create_config_triggered()
{
    if(this->codeCompressor->_profil == nullptr){
        QMessageBox::warning(this,"Erreur","Veuillez lancer le compresseur avant de sauvegarder sa configuration.");
    }else{
        bool ok;
        bool exist = false;
        QString text;
        do{
            text = QInputDialog::getText(this, "Sauvegarde d'une configuration." , "Entrer un nom pour sauvegarder la configuration:" , QLineEdit::Normal,QDir::home().dirName(), &ok);
            if(this->codeCompressor->checkExist(text))
            {
                exist = true;
                QMessageBox::warning(this,"Nom de configuration","Ce nom de configuration est déjà utilisé.");
            }else{
                exist = false;
            }
            if(!ok){
                return;
            }
        }
        while(text.isEmpty() || exist);
        this->codeCompressor->saveProfil(text);
        QMessageBox::information(this,"Sauvegarde du profil","Le profil a bien été sauvegardé.");
    }
}

void MainWindow::on_load_config_triggered()
{
    p.setProfils();
    p.show();
}

void MainWindow::on_manage_config_triggered()
{
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
        QMessageBox::information(this,"Lancement du compresseur","Le compresseur est bien lancé. \nPour le stop, cliquez sur le bouton stop.");
    }
}

void MainWindow::on_actionStop_triggered()
{
    this->codeCompressor->stop();
    ui->actionStop->setEnabled(false);
    ui->actionRun->setEnabled(true);
    QMessageBox::information(this,"Arrêt du compresseur","Le compresseur est bien stoppé. \nPour le relancer, cliquez sur le bouton run.");
}
