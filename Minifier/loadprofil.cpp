#include "loadprofil.h"
#include "ui_loadprofil.h"

LoadProfil::LoadProfil(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoadProfil)
{
    this->selected = nullptr;
    this->compressor = nullptr;
    ui->setupUi(this);
}

LoadProfil::~LoadProfil()
{
    delete ui;
}

void LoadProfil::on_listProfils_itemClicked(QListWidgetItem *item)
{
    this->selected = item;
}

void LoadProfil::on_buttonBox_accepted()
{
    if(this->selected == nullptr)
    {
        QMessageBox::warning(this,"Selection d'une configuration","Aucune configuration n'a été chargée.");
    }else{
        for( int i = 0; i < this->compressor->_profilsName.size() ; i++)
        {
            if(this->selected->text() == this->compressor->_profilsName.at(i)){
                this->loadConfig(this->compressor->getProfilInfoByIndex(i));
                this->compressor->launchCompressorByIndex(i);
                break;
            }
        }
    }
}

void LoadProfil::setCompressor( code_compressor::CodesCompressor * c)
{
    this->compressor = c;
}

void LoadProfil::setProfils()
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
