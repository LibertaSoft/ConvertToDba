#include "readanimelist.h"
#include <QFile>

#include <QDebug>

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
    if( data != QByteArray("Anime List v2.4 (Anime Base)\n") ){
        qDebug() << "[Line 1] is not <Anime List v2.4 (Anime Base)\n>";
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
    QString sectionName;
    switch ( _section ) {
    case sections::anime:
        sectionName = "Anime";
        break;
    case sections::manga:
        sectionName = "Manga";
        break;
    default:
        return data;
    }


    QByteArray string;
    do{
        string = _file.readLine();
    }while( string == "\n" );

    if( string != "---Start "+sectionName+"---\n" ){
        return data;
    }

    string = _file.readLine();
    if( string.startsWith( QByteArray("Name:") ) )
        data["Title"] = string.right( string.length() - 5 ).left( string.length() - 6 );

    string = _file.readLine();
    if( string.startsWith( QByteArray("Origname:") ) )
        data["OrigTitle"] = string.right( string.length() - 9 ).left( string.length() - 10 );

    string = _file.readLine();
    if( string.startsWith( QByteArray("Author:") ) )
        data["Director"] = string.right( string.length() - 7 ).left( string.length() - 8 );

    string = _file.readLine();
    if( string.startsWith( QByteArray("Studi:") ) )
        data["Studios"] = string.right( string.length() - 6 ).left( string.length() - 7 );

    string = _file.readLine();
    if( string.startsWith( QByteArray("Year:") ) )
        data["Year"] = string.right( string.length() - 5 ).left( string.length() - 6 );

    string = _file.readLine();
    if( string.startsWith( QByteArray("Sezon:") ) )
        data["Season"] = string.right( string.length() - 6 ).left( string.length() - 7 );

    string = _file.readLine();
    if( string.startsWith( QByteArray("Speshl:") ) )
        data["SeriesSpecial"] = string.right( string.length() - 7 ).left( string.length() - 8 );

    string = _file.readLine();
    if( string.startsWith( QByteArray("Ser:") ) )
        data["vSeriesTV"] = string.right( string.length() - 4 ).left( string.length() - 5 );

    string = _file.readLine();
    if( string.startsWith( QByteArray("AllSer:") ) )
        data["SeriesTV"] = string.right( string.length() - 7 ).left( string.length() - 8 );

    string = _file.readLine();
    if( string.startsWith( QByteArray("Rait:") ) )
        data["Score"] = string.right( string.length() - 5 ).left( string.length() - 6 );

    string = _file.readLine();
    if( string.startsWith( QByteArray("Janr:") ) )
        data["Ganre"] = string.right( string.length() - 5 ).left( string.length() - 6 );

    string = _file.readLine();
    if( string.startsWith( QByteArray("Type:") ) )
        data["Type"] = string.right( string.length() - 5 ).left( string.length() - 6 );

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
    }

    string = _file.readLine();
    if( string.startsWith( QByteArray("Link:") ) )
        data["URL"] = string.right( string.length() - 5 ).left( string.length() - 6 );

    string = _file.readLine();
    if( string.startsWith( QByteArray("Logo:") ) )
        data["ImagePath"] = string.right( string.length() - 5 ).left( string.length() - 6 );

    string = _file.readLine();
    if( string != "---End "+sectionName+"---\n" )
        data.clear();

    _currentRecordCount++;
    return data;
}
