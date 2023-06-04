/**
 * @file global.cpp
 * @brief 用于存储全局变量
 * @date 2023/5/28
 * @author 孔德昱
 */
#include <QStringList>
#include <QListWidgetItem>
/**
 * @brief 用于存储亲友信息，包括姓名、关系、生日日期，中间用\t分隔
 */
QStringList gRelativeList;
/**
 * @brief 用于存储当前选中的亲友的指针
 */
QListWidgetItem *curRelative;
