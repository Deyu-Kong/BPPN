/**
 * @file   persinfo.cpp
 * @brief  实现亲属信息的结构体
 * @date   2023/5/28
 * @author 孔德昱 杜忠璠
 */
#include <persinfo.h>
PersInfo::PersInfo(QString name, QString relationship, QDate birth)
{
    this->relationship = relationship;
    this->name = name;
    this->birth = birth;
}
