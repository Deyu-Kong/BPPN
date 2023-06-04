/**
 * @file persinfo.h
 * @author 孔德昱 杜忠璠
 * @date 2023/5/28
 * @brief 定义亲属信息的结构体
 */
#ifndef PERSINFO_H
#define PERSINFO_H

#include <string>
#include <string.h>
#include <QDate>
#include <vector>
/**
 * @brief PersInfo类，用于存储亲属信息
 */
class PersInfo
{
public:
    QString name, relationship; // 亲属姓名，亲属关系
    QDate birth;                // 亲属生日

    /**
     * @brief PersInfo类的构造函数，用于初始化亲属信息
     * @param name 亲属姓名
     * @param relationship 亲属关系
     * @param birth 亲属生日
     */
    PersInfo(QString name, QString relationship, QDate birth);
};

// std::vector<PersInfo> vec_pers;

#endif // PERSINFO_H
