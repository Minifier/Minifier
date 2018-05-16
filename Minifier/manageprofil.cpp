#include "manageprofil.h"
#include "ui_manageprofil.h"

ManageProfil::ManageProfil(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ManageProfil)
{
    this->selected = nullptr;
    this->compressor = nullptr;
    ui->setupUi(this);
}

ManageProfil::~ManageProfil()
{
    delete ui;
}

void ManageProfil::setCompressor( code_compressor::CodesCompressor * c)
{
    this->compressor = c;
}

void ManageProfil::setProfils()
{
    if(this->compressor != nullptr)
    {
        ui->listProfils->clear();
        for( int i = 0; i < this->compressor->_profilsName.size() ; i++)
        {
            new QListWidgetItem(this->compressor->_profilsName.at(i), ui->listProfils);
        }
    }
}

void ManageProfil::on_listProfils_itemClicked(QListWidgetItem *item)
{
    this->selected = item;
}

void ManageProfil::on_deleteBtn_clicked()
{
    if(this->selected == nullptr)
    {
        QMessageBox::warning(this,"Selection d'un profil.","Aucune profil n'a été selectionné.");
    }else{
        for( int i = 0; i < this->compressor->_profilsName.size() ; i++)
        {
            if(this->selected->text() == this->compressor->_profilsName.at(i)){
                this->compressor->deleteProfilByIndex(i);
                break;
            }
        }
        this->setProfils();
    }
}

void ManageProfil::on_renameBtn_clicked()
{
    if(this->selected == nullptr)
    {
        QMessageBox::warning(this,"Selection d'un profil.","Aucune profil n'a été selectionné.");
    }else{
        bool ok;
        bool exist = false;
        QString text;
        do{
            text = QInputDialog::getText(this, "Sauvegarde d'une configuration." , "Entrer un nom pour sauvegarder la configuration:" , QLineEdit::Normal,QDir::home().dirName(), &ok);
            if(this->compressor->checkExist(text))
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
        for( int i = 0; i < this->compressor->_profilsName.size() ; i++)
        {
            if(this->selected->text() == this->compressor->_profilsName.at(i)){
                this->compressor->renameProfilByIndex(i,text);
                break;
            }
        }
        this->setProfils();
    }
}

void ManageProfil::on_cancelBtn_clicked()
{
    QMetaObject::invokeMethod(this, "close", Qt::QueuedConnection);
}
