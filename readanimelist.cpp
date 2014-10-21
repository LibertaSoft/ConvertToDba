#include "readanimelist.h"
#include <QFile>

#include <QDebug>

QMap<QString, QByteArray> ReadAnimeList::readAnime()
{
    QStringList key;
    QList<QByteArray> value;

    key << "Title";         value << "Name:";
    key << "OrigTitle";     value << "Origname:";
    key << "Director";      value << "Author:";
    key << "Studios";       value << "Studi:";
    key << "Year";          value << "Year:";
    key << "Season";        value << "Sezon:";
    key << "SeriesSpecial"; value << "Speshl:";
    key << "vSeriesTV";     value << "Ser:";
    key << "SeriesTV";      value << "AllSer:";
    key << "Score";         value << "Rait:";
    key << "Tags";          value << "Janr:";
    key << "Type";          value << "Type:";
    key << "Description";   value << "StartMemo:";
    key << "URL";           value << "Link:";
    key << "ImagePath";     value << "Logo:";

    QMap<QString, QByteArray> data;
    const QString sectionName("Anime");

    QByteArray string;
    do{
        string = _file.readLine();
    }while( string == "\n" );


    if( string != "---Start "+sectionName+"---\n" ){
        qCritical() << "Start of an "+sectionName+" element is not found. Data is clear"
                    << "String: " << string;
        return data;
    }

    for(int i = 0; i < key.size(); ++i){
        string = _file.readLine();

        if( string.startsWith( "StartMemo:" ) ){
            QByteArray memo = string.right( string.length() - 10 );
            if( string.endsWith( ":EndMemo\n" ) ){
                memo = memo.left( memo.length() - 9 );
            }else{
                do{
                    string = _file.readLine();
                    memo += string;
                }while( !string.endsWith( ":EndMemo\n" ) );
                memo = memo.left( memo.length() - 9 );
            }
            data["Description"] = memo;
            continue;
        }
        if( string.startsWith( value[i] ) )
            data[ key[i] ] = string.right( string.length() - value[i].length() ).left( string.length() - value[i].length()-1 );
    }

    string = _file.readLine();
    if( string != "---End "+sectionName+"---\n" ){
        qCritical() << "End of an "+sectionName+" element is not found. Data is clear."
                    << "String: " << string;
        data.clear();
    }

    return data;
}

QMap<QString, QByteArray> ReadAnimeList::readManga()
{
    QStringList key;
    QList<QByteArray> value;

    key << "Title";         value << "Name:";
    key << "AltTitle";      value << "OrigName:";
    key << "Translation";   value << "Perevod:";
    key << "Author";        value << "Avtor:";
    key << "Year";          value << "Year:";
    key << "Vol";           value << "Tom:";
    key << "Vipusk";        value << "Vipusk:";
    key << "vCh";           value << "Glav:";
    key << "Ch";            value << "AllGlav:";
    key << "vVol";          value << "NowTom:";
    key << "Score";         value << "Raiting:";
    key << "Tags";          value << "Janrs:";
    key << "Type";          value << "Type:";
    key << "Description";   value << "StartMemo:";
    key << "URL";           value << "Link:";
    key << "ImagePath";     value << "Logos:";

    QMap<QString, QByteArray> data;
    const QString sectionName("Manga");

    QByteArray string;
    do{
        string = _file.readLine();
    }while( string == "\n" );


    if( string != "---Start "+sectionName+"---\n" ){
        qCritical() << "Start of an "+sectionName+" element is not found. Data is clear"
                    << "String: " << string;
        return data;
    }

    for(int i = 0; i < key.size(); ++i){
        string = _file.readLine();

        if( string.startsWith( QByteArray("StartMemo:") ) ){
            QByteArray memo = string.right( string.length() - 10 );
            if( string.endsWith( QByteArray(":EndMemo\n") ) ){
                memo = memo.left( memo.length() - 9 );
            }else{
                do{
                    string = _file.readLine();
                    memo += string;
                }while( !string.endsWith( QByteArray(":EndMemo\n") ) );
                memo = memo.left( memo.length() - 9 );
            }
            data["Description"] = memo;
            continue;
        }
        if( string.startsWith( value[i] ) )
            data[ key[i] ] = string.right( string.length() - value[i].length() ).left( string.length() - value[i].length()-1 );
    }

    string = _file.readLine();
    if( string != "---End "+sectionName+"---\n" ){
        qCritical() << "End of an "+sectionName+" element is not found. Data is clear."
                    << "String: " << string;
        data.clear();
    }

    return data;
}

ReadAnimeList::ReadAnimeList(QString fileName)
    :_recordCount(0), _section(sections::none)
{
    _file.setFileName( fileName );
    if( _file.exists() ){
        _file.open(QFile::ReadOnly | QFile::Text);
    }else{
        qDebug() << "File is not exists";
    }
}

bool ReadAnimeList::readHeader(){
    if( _file.isOpen() == false ){
        qDebug() << "File is not open";
        return false;
    }
    QByteArray data;
    data = _file.readLine(); // Line 1
    if( ! data.startsWith("Anime List v2.4") ){
        qDebug() << "[Line 1] is not start with: 'Anime List v2.4'";
        return false;
    }

    data = _file.readLine(); // Line 2
    data = data.left( data.length()-1 ); // Strip '\n' of end line

    bool isOkRecordCount(false);
    _recordCount = data.toULongLong(&isOkRecordCount);

    if( !isOkRecordCount ){
        qDebug() << "[Line 2] is uncorrect record count";
        return false;
    }

    data = _file.readLine(); // Line 3
    if( data == QByteArray("---Anime---\n") )
        _section = sections::anime;
    else if( data == QByteArray("---Manga---\n") )
        _section = sections::manga;

    if( _section == sections::none ){
        qDebug() << "[Line 3] section is uncorrect section";
        return false;
    }

    return true;
}

bool ReadAnimeList::isEnd() const
{
//    return (_currentRecordCount == _recordCount)? true : false;
    return _file.atEnd();
}

sections::Section ReadAnimeList::getSection() const
{
    return _section;
}

unsigned long long ReadAnimeList::getRecordCount() const
{
    return _recordCount;
}

unsigned long long ReadAnimeList::getCurrentRecordNumber() const
{
    return _currentRecordCount;
}

QMap<QString, QByteArray> ReadAnimeList::readNext()
{
    QMap<QString, QByteArray> data;

    switch ( _section ) {
    case sections::anime:
        data = readAnime();
        break;
    case sections::manga:
        data = readManga();
        break;
    default:
        return data;
    }

    _currentRecordCount++;
    return data;
}
