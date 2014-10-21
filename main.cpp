#include <iostream>
#include <unistd.h>
#include <QDebug>
#include "readanimelist.h"
#include "writetodbaformat.h"

QMap<QString, QString> convertEncode( QByteArray codecName, QMap<QString, QByteArray> data ){
    QTextDecoder decoder( QTextCodec::codecForName(codecName) );
    QMap<QString, QString> newData;

    QMap<QString, QByteArray>::iterator i;
    for(i = data.begin(); i != data.end(); ++i){
        newData[ i.key() ] = decoder.toUnicode( i.value() );
    }

    return newData;
}

void printHelp(){
    std::cout << "Use: " << std::endl;
    std::cout << "  " << "ConvertToDba -i /path/to/file/AnimeList.anime -o /path/to/new/file.xml" << std::endl << std::endl;
    std::cout << "Options:" << std::endl;
    std::cout << "  " << "-i " << "\t" << "Input file. The file exported from the program AnimeList" << std::endl;
    std::cout << "  " << "-o " << "\t" << "Output file. The file in which you want to export data" << std::endl;
    std::cout << "  " << "-e " << "\t" << "Endoding. The encoding of the input file. Default use a windows-1251" << std::endl;
    std::cout << "  " << "-h " << "\t" << "Help. Pring help and exit" << std::endl;
    std::cout << "  " << "-v " << "\t" << "Version. Print version and exit" << std::endl;
}

void printVersion(){
    const char* version = "0.0.6 Alpha";
    std::cout << "ConvertToDba" << " " << version << std::endl;
    std::cout << "License: " << "GNU GPLv3+" << std::endl;
    std::cout << "This is free software, you can modify and distribute it." << std::endl;
    std::cout << "Authors program: LibertaSoft/Demetri0 (LibertaSoft@yandex.ru)" << std::endl;
}

int main(int argc, char *argv[])
{
    if(argc < 2){
        printHelp();
    }else{
        QString fileName;
        QString outputFileName;
        QByteArray codecName("Windows-1251");

        {
            short initComplete(0);
            const char *opts = "i:o:e:hv";
            int opt;
            while((opt = getopt(argc, argv, opts)) != -1) {
                switch(opt) {
                 case 'i':
                    fileName = QString(optarg);
                    initComplete++;
                    break;
                 case 'o':
                    outputFileName = QString(optarg);
                    initComplete++;
                    break;
                 case 'e':
                    codecName = QByteArray(optarg);
                    break;
                case 'v':
                    printVersion();
                    return 0;
                case 'h':
                    printHelp();
                    return 0;
                }
             }
            if( initComplete < 2 ){
                std::cerr << "Error: Lost 1 or more required arguments." << std::endl;
                printHelp();
                return 1;
            }
        }

        ReadAnimeList AnimeList(fileName);
        WriteToDbaFormat DBA( outputFileName );
        if( AnimeList.readHeader() ){
            while( AnimeList.isEnd() == false ){
                if( AnimeList.getSection() == sections::anime ){
                    DBA.appendAnime( convertEncode(codecName, AnimeList.readNext() ) );
                }else{
                    DBA.appendManga( convertEncode(codecName, AnimeList.readNext() ) );
                }
            }
            DBA.writeToFile();
        }
    }
    return 0;
}
