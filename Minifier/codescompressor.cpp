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

#include "codescompressor.h"

template<typename T, typename... Args>
std::unique_ptr<T> make_unique(Args&&... args) {
    return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}

code_compressor::CodesCompressor::CodesCompressor()
{
    this->availableProfil = this->loadProfils();
    this->_profil = nullptr;
    this->_state = false;
}

code_compressor::CodesCompressor::~CodesCompressor()
{
    this->stop();
}

/**
 * @brief loadFiles load file after directory definition
 */
void code_compressor::CodesCompressor::loadFiles()
{
    // Define QDir for search in good path
    QDir dir_js;
    dir_js.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
    dir_js.setPath(this->_profil->getJsFolder());
    QDir dir_css;
    dir_css.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
    dir_css.setPath(this->_profil->getCssFolder());

    // Define regex to find .js but not .min.js file
    QRegExp re_js_1("*.js", Qt::CaseInsensitive);
    QRegExp re_js_2("*.min.js", Qt::CaseInsensitive);
    re_js_1.setPatternSyntax(QRegExp::Wildcard);
    re_js_2.setPatternSyntax(QRegExp::Wildcard);

    // Define regex to find .css but not .min.css file
    QRegExp re_css_1("*.css", Qt::CaseInsensitive);
    QRegExp re_css_2("*.min.css", Qt::CaseInsensitive);
    re_css_1.setPatternSyntax(QRegExp::Wildcard);
    re_css_2.setPatternSyntax(QRegExp::Wildcard);

    // Load files'list
    QFileInfoList list_js = dir_js.entryInfoList();
    QFileInfoList list_css = dir_css.entryInfoList();

    // Browse files' list and launch file's compressor
    for (int i = 0; i < list_js.size(); ++i) {
        QFileInfo fileInfo = list_js.at(i);
        if(re_js_1.exactMatch(fileInfo.fileName()) && !re_js_2.exactMatch(fileInfo.fileName())){
            this->addCompressorFile(this->_profil->getJsFolder() + fileInfo.fileName());
        }
        else if(re_css_1.exactMatch(fileInfo.fileName()) && !re_css_2.exactMatch(fileInfo.fileName())){
            this->addCompressorFile(this->_profil->getJsFolder() + fileInfo.fileName());
        }
    }

    for (int i = 0; i < list_css.size(); ++i) {
        QFileInfo fileInfo = list_css.at(i);
        if(re_js_1.exactMatch(fileInfo.fileName()) && !re_js_2.exactMatch(fileInfo.fileName())){
            this->addCompressorFile(this->_profil->getCssFolder() + fileInfo.fileName());
        }
        else if(re_css_1.exactMatch(fileInfo.fileName()) && !re_css_2.exactMatch(fileInfo.fileName())){
            this->addCompressorFile(this->_profil->getCssFolder() + fileInfo.fileName());
        }
    }
    this->_state = true;
}

/**
 * @brief compress launch function compress on each files
 */
void code_compressor::CodesCompressor::compress()
{
    this->_state = true;
    for (size_t i = 0; i < this->_files.size(); i++){
        (this->_files[i])->compress();
    }
}

/**
 * @brief stop launch function stop on each files
 */
void code_compressor::CodesCompressor::stop()
{
    this->_state = false;
    for (size_t i = 0; i < this->_files.size(); i++){
        (this->_files[i])->stop();
    }
}

/**
 * @brief loadProfils load all profil from profil.txt
 * @return true|false file exist
 */
bool code_compressor::CodesCompressor::loadProfils()
{
    bool retval = false;
    QStringList p = readFile((ExePath() + PROFIL_FILE ));
    for(int i = 0; i < p.size(); i+=3)
    {
        this->_profilsName << p.at(i);
        this->_profils.push_back(make_unique<code_compressor::Profil>( * new code_compressor::Profil(p.at(i+1), p.at(i+2) , p.at(i))));
        retval = true;
    }
    return retval;
}

/**
 * @brief setProfil set profil using folder list
 * @param filePath list (cssFolder,jsFolder)
 */
void code_compressor::CodesCompressor::setProfil(const QStringList &filePath)
{
    code_compressor::Profil* p = new code_compressor::Profil(filePath);
    this->_profil = make_unique<code_compressor::Profil>(*p);
}

/**
 * @brief setProfil set profil using jsFolder and cssFolder params
 * @param jsFolder path to JS folder
 * @param cssFolder path to CSS folder
 */
void code_compressor::CodesCompressor::setProfil(const QString &cssFolder, const QString &jsFolder)
{
    code_compressor::Profil* p = new code_compressor::Profil(cssFolder , jsFolder);
    this->_profil = make_unique<code_compressor::Profil>(*p);
}

/**
 * @brief saveProfil launch profil's save function
 * @param cfgName name for saving cfg
 */
void code_compressor::CodesCompressor::saveProfil(const QString &cfgName)
{
    this->_profil->save(cfgName);
    this->_profilsName << cfgName;
    this->_profils.push_back(make_unique<code_compressor::Profil>( * new code_compressor::Profil( this->_profil->fileName() , cfgName )));
}

/**
 * @brief deleteProfilByIndex
 * @param index
 */
void code_compressor::CodesCompressor::deleteProfilByIndex(const int &index)
{
    this->_profils.erase(this->_profils.begin() + index);
    this->_profilsName.removeAt(index);
    QStringList ctn;
    for(int i = 0; i < (int)(this->_profils.size()) ; i++){
        ctn << this->_profils[i]->getCfgName() << this->_profils[i]->fileName();
    }
    writeFile((ExePath() + PROFIL_FILE ), ctn);
}

/**
 * @brief renameProfilByIndex
 * @param index
 * @param newName
 */
void code_compressor::CodesCompressor::renameProfilByIndex(const int &index, const QString &newName)
{
    this->_profils[index]->setCfgName(newName);
    this->_profilsName.replace(index, newName);
    QStringList ctn;
    for(int i = 0; i < (int)(this->_profils.size()) ; i++){
        ctn << this->_profils[i]->getCfgName() << this->_profils[i]->fileName();
    }
    writeFile((ExePath() + PROFIL_FILE ), ctn);
}

/**
 * @brief checkExist
 * @param cfgName
 * @return true|false name exist
 */
bool code_compressor::CodesCompressor::checkExist(const QString& cfgName)
{
    if(this->_profilsName.contains(cfgName, Qt::CaseSensitive))
    {
        return true;
    }
    return false;
}

/**
 * @brief launchCompressor launch compressor and set profil
 * @param filePath list (cssFolder,jsFolder)
 */
void code_compressor::CodesCompressor::launchCompressor(const QStringList& filePath)
{
    this->setProfil(filePath);
    this->loadFiles();
}

/**
 * @brief setProfilByIndex
 * @param i index of profil in profils'list
 */
void code_compressor::CodesCompressor::launchCompressorByIndex(const int &i)
{
    this->launchCompressor(this->_profils[i]->fileName());
}

QStringList code_compressor::CodesCompressor::getProfilInfoByIndex(const int &i)
{
    return this->_profils.at(i)->fileName();
}

/**
 * @brief addCompressorFile use to add CompressFile to files
 * @param filePath way to access to the file
 */
void code_compressor::CodesCompressor::addCompressorFile(const QString &filePath)
{
    this->_files.push_back(new code_compressor::CompressFile(filePath));
}

/**
 * @brief running use to know if compressors are running
 * @return true|false running state
 */
bool code_compressor::CodesCompressor::running()
{
    return this->_state;
}
