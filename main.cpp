#include <QCoreApplication>
#include <iostream>
#include <QDebug>
#include "readanimelist.h"
#include "writetodbaformat.h"

QMap<QString, QString> convertEncode( const char* codecName, QMap<QString, QByteArray> data ){
    QTextDecoder decoder( QTextCodec::codecForName(codecName) );
    QMap<QString, QString> newData;

    QMap<QString, QByteArray>::iterator i = data.begin();
    while( i != data.end() ){
        newData[ i.key() ] = decoder.toUnicode( i.value() );
        ++i;
    }

    return newData;
}

int main(int argc, char *argv[])
{
    //QCoreApplication a(argc, argv);
    if(argc < 2){
        std::cout << "Use: " << std::endl;
        std::cout << "ConvertFromAnimeList /path/to/fileName.anime" << std::endl;
    }else{
        QString fileName( argv[1] );
        ReadAnimeList AnimeList(fileName);

        WriteToDbaFormat DBA( QString("/tmp/DBA/1/") );
        if( AnimeList.readHeader() ){
            while( AnimeList.isEnd() == false ){
                DBA.appendAnime( convertEncode("Windows-1251", AnimeList.readNext() ) );
            }
            DBA.writeToFile();
        }
    }
    return 0;//a.exec();
}
