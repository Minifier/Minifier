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
