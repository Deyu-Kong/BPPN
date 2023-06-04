#ifndef PERSINFO_H
#define PERSINFO_H

#include<string>
#include<string.h>
#include<QDate>
#include<vector>

class PersInfo{
public:
    QString name,relationship;
    QDate birth;
    PersInfo(QString name,QString relationship,QDate birth);
};

//std::vector<PersInfo> vec_pers;

#endif // PERSINFO_H

