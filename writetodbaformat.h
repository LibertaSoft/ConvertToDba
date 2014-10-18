#ifndef WRITETODBAFORMAT_H
#define WRITETODBAFORMAT_H

#include <QString>
#include <QFile>
#include <QMap>

#include <QtXml>

class WriteToDbaFormat
{
private:
    QString _filePath;
    QDomDocument _doc;
    QDomElement  _dom;

    QDomElement  _domAnime;
    QDomElement  _domManga;
    QDomElement  _domAmv;
    QDomElement  _domDorama;
public:
    WriteToDbaFormat();
    WriteToDbaFormat(QString filePath);
    bool appendAnime(  QMap<QString,QString> );
    bool appendManga(  QMap<QString,QString> );
    bool appendAmv(    QMap<QString,QString> );
    bool appendDorama( QMap<QString,QString> );

    bool writeToFile();
    bool writeToFile(QString& filePath);
};

#endif // WRITETODBAFORMAT_H
