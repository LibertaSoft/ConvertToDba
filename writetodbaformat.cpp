#include "writetodbaformat.h"

QDomElement makeElement(      QDomDocument& domDoc,
                        const QString&      strName,
                        const QString&      strAttr = QString::null,
                        const QString&      strText = QString::null
                       )
{
    QDomElement domElement = domDoc.createElement(strName);

    if (!strAttr.isEmpty()) {
        QDomAttr domAttr = domDoc.createAttribute("number");
        domAttr.setValue(strAttr);
        domElement.setAttributeNode(domAttr);
    }

    if (!strText.isEmpty()) {
        QDomText domText = domDoc.createTextNode(strText);
        domElement.appendChild(domText);
    }
    return domElement;
}

namespace Export{
    QDomElement anime(  QDomDocument& domDoc,
                        const QMap<QString, QString> &data
                        )
    {
        QDomElement domElement = makeElement(domDoc,
                                             "item"
                                             );
        domElement.appendChild(makeElement(domDoc, "isHaveLooked",  "", data["isHaveLooked"]));
        domElement.appendChild(makeElement(domDoc, "isEditingDone", "", data["isEditingDone"]));
        domElement.appendChild(makeElement(domDoc, "isAdult",       "", data["isAdult"]));
        domElement.appendChild(makeElement(domDoc, "Title",         "", data["Title"]));
        domElement.appendChild(makeElement(domDoc, "OrigTitle",     "", data["OrigTitle"]));
        domElement.appendChild(makeElement(domDoc, "Director",      "", data["Director"]));
        domElement.appendChild(makeElement(domDoc, "PostScoring",   "", data["PostScoring"]));
        domElement.appendChild(makeElement(domDoc, "SeriesTV",      "", data["SeriesTV"]));
        domElement.appendChild(makeElement(domDoc, "SeriesOVA",     "", data["SeriesOVA"]));
        domElement.appendChild(makeElement(domDoc, "SeriesONA",     "", data["SeriesONA"]));
        domElement.appendChild(makeElement(domDoc, "SeriesSpecial", "", data["SeriesSpecial"]));
        domElement.appendChild(makeElement(domDoc, "SeriesMovie",   "", data["SeriesMovie"]));
        domElement.appendChild(makeElement(domDoc, "vSeriesTV",     "", data["vSeriesTV"]));
        domElement.appendChild(makeElement(domDoc, "vSeriesOVA",    "", data["vSeriesOVA"]));
        domElement.appendChild(makeElement(domDoc, "vSeriesONA",    "", data["vSeriesONA"]));
        domElement.appendChild(makeElement(domDoc, "vSeriesSpecial","", data["vSeriesSpecial"]));
        domElement.appendChild(makeElement(domDoc, "vSeriesMovie",  "", data["vSeriesMovie"]));
        domElement.appendChild(makeElement(domDoc, "Score",         "", data["Score"]));
        domElement.appendChild(makeElement(domDoc, "Year",          "", data["Year"]));
        domElement.appendChild(makeElement(domDoc, "Season",        "", data["Season"]));
        domElement.appendChild(makeElement(domDoc, "Studios",       "", data["Studios"]));
        domElement.appendChild(makeElement(domDoc, "Tags",          "", data["Tags"]));
        domElement.appendChild(makeElement(domDoc, "Description",   "", data["Description"]));
        domElement.appendChild(makeElement(domDoc, "URL",           "", data["URL"]));
        domElement.appendChild(makeElement(domDoc, "Dir",           "", data["Dir"]));
        domElement.appendChild(makeElement(domDoc, "ImagePath",     "", data["ImagePath"]));

        return domElement;
    }
    QDomElement manga(  QDomDocument& domDoc,
                        const QMap<QString, QString> &data
                        )
    {
        QDomElement domElement = makeElement(domDoc,
                                             "item"
                                             );
        domElement.appendChild(makeElement(domDoc, "isHaveLooked",  "", data["isHaveLooked"]));
        domElement.appendChild(makeElement(domDoc, "isEditingDone", "", data["isEditingDone"]));
        domElement.appendChild(makeElement(domDoc, "isAdult",       "", data["isAdult"]));
        domElement.appendChild(makeElement(domDoc, "Title",         "", data["Title"]));
        domElement.appendChild(makeElement(domDoc, "AltTitle",      "", data["AltTitle"]));
        domElement.appendChild(makeElement(domDoc, "Author",        "", data["Author"]));
        domElement.appendChild(makeElement(domDoc, "Translation",   "", data["Translation"]));
        domElement.appendChild(makeElement(domDoc, "Vol",           "", data["Vol"]));
        domElement.appendChild(makeElement(domDoc, "Ch",            "", data["Ch"]));
        domElement.appendChild(makeElement(domDoc, "Pages",         "", data["Pages"]));
        domElement.appendChild(makeElement(domDoc, "vVol",          "", data["vVol"]));
        domElement.appendChild(makeElement(domDoc, "vCh",           "", data["vCh"]));
        domElement.appendChild(makeElement(domDoc, "vPages",        "", data["vPages"]));
        domElement.appendChild(makeElement(domDoc, "Score",         "", data["Score"]));
        domElement.appendChild(makeElement(domDoc, "Year",          "", data["Year"]));
        domElement.appendChild(makeElement(domDoc, "Tags",          "", data["Tags"]));
        domElement.appendChild(makeElement(domDoc, "Description",   "", data["Description"]));
        domElement.appendChild(makeElement(domDoc, "URL",           "", data["URL"]));
        domElement.appendChild(makeElement(domDoc, "Dir",           "", data["Dir"]));
        domElement.appendChild(makeElement(domDoc, "ImagePath",     "", data["ImagePath"]));

        return domElement;
    }
    QDomElement amv(  QDomDocument& domDoc,
                        const QMap<QString, QString> &data
                        )
    {
        QDomElement domElement = makeElement(domDoc,
                                             "item"
                                             );
        domElement.appendChild(makeElement(domDoc, "isEditingDone",   "", data["isEditingDone"]));
        domElement.appendChild(makeElement(domDoc, "isAdult",         "", data["isAdult"]));
        domElement.appendChild(makeElement(domDoc, "Title",           "", data["Title"]));
        domElement.appendChild(makeElement(domDoc, "Author",          "", data["Author"]));
        domElement.appendChild(makeElement(domDoc, "Сontestant",      "", data["Сontestant"]));
        domElement.appendChild(makeElement(domDoc, "Score",           "", data["Score"]));
        domElement.appendChild(makeElement(domDoc, "Year",            "", data["Year"]));
        domElement.appendChild(makeElement(domDoc, "Tags",            "", data["Tags"]));
        domElement.appendChild(makeElement(domDoc, "ContainingMusic", "", data["ContainingMusic"]));
        domElement.appendChild(makeElement(domDoc, "ContainingAnime", "", data["ContainingAnime"]));
        domElement.appendChild(makeElement(domDoc, "AuthorComment",   "", data["AuthorComment"]));
        domElement.appendChild(makeElement(domDoc, "URL",             "", data["URL"]));
        domElement.appendChild(makeElement(domDoc, "Dir",             "", data["Dir"]));
        domElement.appendChild(makeElement(domDoc, "ImagePath",       "", data["ImagePath"]));

        return domElement;
    }

    QDomElement dorama(  QDomDocument& domDoc,
                        const QMap<QString, QString> &data
                        )
    {
        QDomElement domElement = makeElement(domDoc,
                                             "item"
                                             );
        domElement.appendChild(makeElement(domDoc, "isHaveLooked",  "", data["isHaveLooked"]));
        domElement.appendChild(makeElement(domDoc, "isEditingDone", "", data["isEditingDone"]));
        domElement.appendChild(makeElement(domDoc, "isAdult",       "", data["isAdult"]));
        domElement.appendChild(makeElement(domDoc, "Title",         "", data["Title"]));
        domElement.appendChild(makeElement(domDoc, "AltTitle",      "", data["AltTitle"]));
        domElement.appendChild(makeElement(domDoc, "Director",      "", data["Director"]));
        domElement.appendChild(makeElement(domDoc, "SeriesTV",      "", data["SeriesTV"]));
        domElement.appendChild(makeElement(domDoc, "SeriesSpecial", "", data["SeriesSpecial"]));
        domElement.appendChild(makeElement(domDoc, "SeriesMovie",   "", data["SeriesMovie"]));
        domElement.appendChild(makeElement(domDoc, "vSeriesTV",     "", data["vSeriesTV"]));
        domElement.appendChild(makeElement(domDoc, "vSeriesSpecial","", data["vSeriesSpecial"]));
        domElement.appendChild(makeElement(domDoc, "vSeriesMovie",  "", data["vSeriesMovie"]));
        domElement.appendChild(makeElement(domDoc, "Score",         "", data["Score"]));
        domElement.appendChild(makeElement(domDoc, "Year",          "", data["Year"]));
        domElement.appendChild(makeElement(domDoc, "Season",        "", data["Season"]));
        domElement.appendChild(makeElement(domDoc, "Tags",          "", data["Tags"]));
        domElement.appendChild(makeElement(domDoc, "Description",   "", data["Description"]));
        domElement.appendChild(makeElement(domDoc, "Actors",        "", data["Actors"]));
        domElement.appendChild(makeElement(domDoc, "URL",           "", data["URL"]));
        domElement.appendChild(makeElement(domDoc, "Dir",           "", data["Dir"]));
        domElement.appendChild(makeElement(domDoc, "ImagePath",     "", data["ImagePath"]));

        return domElement;
    }
}
WriteToDbaFormat::WriteToDbaFormat()
{
    _doc = QDomDocument("DatabaseAnime");
    _dom = _doc.createElement("DatabaseAnime");
    _doc.appendChild(_dom);

    _domAnime = _doc.createElement("Anime");
    _dom.appendChild(_domAnime);
    _domManga = _doc.createElement("Manga");
    _dom.appendChild(_domManga);
    _domAmv = _doc.createElement("Amv");
    _dom.appendChild(_domAmv);
    _domDorama = _doc.createElement("Dorama");
    _dom.appendChild(_domDorama);
}
WriteToDbaFormat::WriteToDbaFormat(QString filePath)
{
    _filePath = filePath;

    _doc = QDomDocument("DatabaseAnime");
    _dom = _doc.createElement("DatabaseAnime");
    _doc.appendChild(_dom);

    _domAnime = _doc.createElement("Anime");
    _dom.appendChild(_domAnime);
    _domManga = _doc.createElement("Manga");
    _dom.appendChild(_domManga);
    _domAmv = _doc.createElement("Amv");
    _dom.appendChild(_domAmv);
    _domDorama = _doc.createElement("Dorama");
    _dom.appendChild(_domDorama);
}

bool WriteToDbaFormat::appendAnime(QMap<QString, QString> data)
{
    _domAnime.appendChild( Export::anime(_doc, data) );
    return true;
}

bool WriteToDbaFormat::appendManga(QMap<QString, QString> data)
{
    _domManga.appendChild( Export::manga(_doc, data) );
    return true;
}

bool WriteToDbaFormat::appendAmv(QMap<QString, QString> data)
{
    _domAmv.appendChild( Export::amv(_doc, data) );
    return true;
}

bool WriteToDbaFormat::appendDorama(QMap<QString, QString> data)
{
    _domDorama.appendChild( Export::dorama(_doc, data) );
    return true;
}

bool WriteToDbaFormat::writeToFile()
{
    if( _filePath.isEmpty() ){
        return false;
    }

    return writeToFile(_filePath);
}

bool WriteToDbaFormat::writeToFile(QString &filePath)
{
    QDir().mkpath( QDir(filePath).path() );
    QFile file( filePath + QDir::separator() + "DatabaseAnime.xml" );
//    QFile file( QDir(ui->LineEdit_ExDir->text()).path() + QDir::separator() + "DatabaseAnime.xml" );

    if( file.open( QIODevice::WriteOnly | QIODevice::Text ) ) {
        QTextStream fstream(&file);
        _doc.save( fstream, 4 );
        file.close();
        /* images
        if( ui->CBox_ExAnime->isChecked()  && ui->CBox_ExportImages->isChecked() ){
            QDirIterator it( MngrQuerys::getAnimeCoversPath() );
            QString animeCoversExportPath( ui->LineEdit_ExDir->text() + QDir::separator() + "animeCovers" + QDir::separator() );
            QDir().mkpath( animeCoversExportPath );
            while( it.hasNext() ){
                it.next();
                if( it.fileName() == "." || it.fileName() == ".." )
                    continue;
                QFile( it.filePath() ).copy( animeCoversExportPath + it.fileName() );
                QCoreApplication::processEvents();
            }
        }
        if( ui->CBox_ExManga->isChecked()  && ui->CBox_ExportImages->isChecked() ){
            QDirIterator it( MngrQuerys::getMangaCoversPath() );
            QString mangaCoversExportPath( ui->LineEdit_ExDir->text() + QDir::separator() + "mangaCovers" + QDir::separator() );
            QDir().mkpath( mangaCoversExportPath );
            while( it.hasNext() ){
                it.next();
                if( it.fileName() == "." || it.fileName() == ".." )
                    continue;
                QFile( it.filePath() ).copy( mangaCoversExportPath + it.fileName() );
                QCoreApplication::processEvents();
            }
        }
        if( ui->CBox_ExAmv->isChecked()    && ui->CBox_ExportImages->isChecked() ){
            QDirIterator it( MngrQuerys::getAmvCoversPath() );
            QString amvCoversExportPath( ui->LineEdit_ExDir->text() + QDir::separator() + "amvCovers" + QDir::separator() );
            QDir().mkpath( amvCoversExportPath );
            while( it.hasNext() ){
                it.next();
                if( it.fileName() == "." || it.fileName() == ".." )
                    continue;
                QFile( it.filePath() ).copy( amvCoversExportPath + it.fileName() );
                QCoreApplication::processEvents();
            }
        }
        if( ui->CBox_ExDorama->isChecked() && ui->CBox_ExportImages->isChecked() ){
            QDirIterator it( MngrQuerys::getDoramaCoversPath() );
            QString doramaCoversExportPath( ui->LineEdit_ExDir->text() + QDir::separator() + "doramaCovers" + QDir::separator() );
            QDir().mkpath( doramaCoversExportPath );
            while( it.hasNext() ){
                it.next();
                if( it.fileName() == "." || it.fileName() == ".." )
                    continue;
                QFile( it.filePath() ).copy( doramaCoversExportPath + it.fileName() );
                QCoreApplication::processEvents();
            }
        }
        */
    }else{
        qCritical() << file.errorString()
                    << "\nFileName: " << file.fileName();
        return false;
    }

    return true;
}
