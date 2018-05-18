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

#ifndef MANAGEPROFIL_H
#define MANAGEPROFIL_H

#include <QDialog>
#include <QListWidget>
#include <QMessageBox>

#include "codescompressor.h"

namespace Ui {
class ManageProfil;
}

class ManageProfil : public QDialog
{
    Q_OBJECT

public:
    explicit ManageProfil(QWidget *parent = 0);
    ~ManageProfil();

    void setCompressor( code_compressor::CodesCompressor * c);
    void setProfils();

private slots:
    void on_listProfils_itemClicked(QListWidgetItem *item);

    void on_deleteBtn_clicked();

    void on_renameBtn_clicked();

    void on_cancelBtn_clicked();

private:
    Ui::ManageProfil *ui;
    QListWidgetItem * selected;
    code_compressor::CodesCompressor * compressor;
};

#endif // MANAGEPROFIL_H
