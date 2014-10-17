#ifndef READANIMELIST_H
#define READANIMELIST_H

#include <QString>
#include <QFile>
#include <QMap>

namespace sections{
    enum Section{none, anime, manga};
}

class ReadAnimeList
{
private:
    QFile _file;
    unsigned long long _recordCount;
    unsigned long long _currentRecordCount;
    sections::Section _section;
public:
    ReadAnimeList(QString fileName);
    bool readHeader();
    bool isEnd()const;
    unsigned long long getRecordCount()const;
    unsigned long long getCurrentRecordNumber()const;
    QMap<QString,QByteArray> readNext();
};

#endif // READANIMELIST_H
