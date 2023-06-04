/**
 * @file method.h
 * @author 孔德昱
 * @date 2023/3/3
 * @brief 定义与日期计算相关的结构体和方法
 */
#ifndef METHOD_H
#define METHOD_H

#include <iostream>
#include <chrono>
#include <string>
#include <ctime>
#include <sstream>
#include <QDate>
/**
 * @brief MyDate结构体，定义日期的数据结构
 */
struct MyDate
{
    int year;  // 年
    int month; // 月
    int day;   // 日
    int week;  // 星期

    /**
     * @brief MyDate结构体的默认构造函数
     */
    MyDate() {}

    /**
     * @brief MyDate结构体的构造函数重载
     * @param y 年
     * @param m 月
     * @param d 日
     * @param w 星期
     */
    MyDate(int y, int m, int d, int w)
    {
        this->year = y;
        this->month = m;
        this->day = d;
        this->week = w;
    }

    /**
     * @brief MyDate结构体的构造函数重载
     * @param y 年
     * @param m 月
     * @param d 日
     */
    MyDate(int y, int m, int d)
    {
        this->year = y;
        this->month = m;
        this->day = d;
    }
};
/**
 * @brief 判断是否为闰年
 * @param year 年
 */
bool isLeapYear(int year);

/**
 * @brief 判断是否为合法日期
 * @param d 日期
 */
bool isLegalDate(MyDate &d);

/**
 * @brief 获取当前日期
 */
MyDate getCurDate();

/**
 * @brief 获取当前日期的MyDate结构体
 */
MyDate days2Date(int days);

/**
 * @brief 获取当前日期的天数
 */
int date2Days(const MyDate &aDate);

/**
 * @brief 获取两个日期之间的天数
 * @param date1 日期1
 * @param date2 日期2
 */
int dayDis(MyDate &date1, MyDate &date2);
/**
 * @brief 获取当前日期的星期
 */
void CaculateWeekDay(MyDate &date1);

/**
 * @brief 输出当前日期的星期
 */
void showWeekDay(MyDate d);

/**
 * @brief 输出当前日期
 */
void showdate(MyDate d);

/**
 * @brief 获取用户输入的生日
 */
MyDate getUserBirthday();

/**
 * @brief 判断是否为特殊假期
 * @param date 日期
 */
bool isSpecialVacation(MyDate date);

/**
 * @brief 获取下一个生日
 * @param curDate 当前日期
 * @param userBirth 用户生日
 */
QDate getNextBirthday(const QDate &curDate, const QDate &userBirth);

/**
 * @brief 获取提前后的日期
 * @param  birth 生日
 * @param  advance 提前天数
 */
MyDate getAdvancedDate(const MyDate &birth, int advance);

/**
 * @brief 获取计划日期
 * @param curDate 当前日期
 * @param userBirth 用户生日
 */
MyDate getplan(const MyDate curDate, const MyDate userBirth);

/**
 * @获取正式开Party的日期
 * @param planDate 计划日期
 */
MyDate plan2party(MyDate planDate);

/**
 * @brief 结束菜单
 * @param birthday 生日
 * @param days 天数
 * @param planDate 计划日期
 * @param partyDate 开Party日期
 */
void endMenu(MyDate &birthday, int days, MyDate &planDate, MyDate &partyDate);
/**
 * @brief 是否重新规划
 */
bool rePlan();
#endif // METHOD_H
