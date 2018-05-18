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

#ifndef LOADPROFIL_H
#define LOADPROFIL_H

#include <QDialog>
#include <QListWidget>
#include <QMessageBox>

#include "codescompressor.h"

namespace Ui {
class LoadProfil;
}

class LoadProfil : public QDialog
{
    Q_OBJECT

public:
    explicit LoadProfil(QWidget *parent = 0);
    ~LoadProfil();

    void setCompressor( code_compressor::CodesCompressor * c);
    void setProfils();

private slots:
    void on_listProfils_itemClicked(QListWidgetItem *item);

    void on_buttonBox_accepted();

signals:
    void loadConfig(const QStringList &info);

private:
    Ui::LoadProfil *ui;
    QListWidgetItem * selected;
    code_compressor::CodesCompressor * compressor;
};

#endif // LOADPROFIL_H
