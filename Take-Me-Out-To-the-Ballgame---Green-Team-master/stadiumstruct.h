#ifndef STADIUMSTRUCT_H
#define STADIUMSTRUCT_H

#include <QString>
#include <QDateTime>

//WE NEED ALL STADIUM INFORMATION!!!
struct StadiumInfo
{
    QString   teamName;
    QString   stadiumName;
    int       capacity;
    QString   typology;
    QString   surface;
    QString   address;
    QString   phoneNumber;
    QDateTime dateOpen;
    QString   leagueType;
};


struct SouvenirInfoTemporary
{
    QString teamName1;
    QString itemName1;
    double price1;
};

struct SouvenirInfo
{
    QString itemName;
    double price;
};

struct DistanceInfo
{
    QString startStad;
    QString endStad;
    int distance;
};

struct TeamSouvenirs
{
    QString teamName;
    QVector<SouvenirInfo> mySouvenirs;
};



typedef QMap<QString, TeamSouvenirs> SouvenirMap;
typedef QPair<QString, TeamSouvenirs> SouvenirTeamPair;
#endif // STADIUMSTRUCT_H
