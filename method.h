#ifndef METHOD_H
#define METHOD_H
/*
    定义日期格式
*/

#include<iostream>
#include<chrono>
#include<string>
#include<ctime>
#include<sstream>
#include<QDate>
struct MyDate {
    int year;
    int month;
    int day;
    int week;
    MyDate(){}
    MyDate(int y,int m, int d ,int w){
        this->year=y;
        this->month=m;
        this->day=d;
        this->week=w;
    }
    MyDate(int y,int m,int d){
        this->year=y;
        this->month=m;
        this->day=d;
    }
};
bool isLeapYear(int year);
bool isLegalDate(MyDate& d);
MyDate getCurDate();
MyDate days2Date(int days);
int date2Days(const MyDate& aDate);
int dayDis(MyDate& date1, MyDate& date2);
void CaculateWeekDay(MyDate& date1);
void showWeekDay(MyDate d);
void showdate(MyDate d);
//void welcome();
MyDate getUserBirthday();
QDate getNextBirthday(const QDate& curDate,const QDate& userBirth);
MyDate getAdvancedDate(const MyDate& birth, int advance);
MyDate getplan(const MyDate curDate, const MyDate userBirth);
MyDate plan2party(MyDate planDate);
void endMenu(MyDate& birthday, int days, MyDate& planDate, MyDate& partyDate);
bool rePlan();
#endif // METHOD_H
