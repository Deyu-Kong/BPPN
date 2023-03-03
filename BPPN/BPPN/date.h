#pragma warning(disable:4996)
#include<iostream>
#include<chrono>
#include<string>
#include<ctime>
#include <sstream>

using namespace std;

/*
	定义日期格式
*/
struct date {
	int year;
	int month;
	int day;
	int week;
};


/*
	判断是否闰年
*/
bool isLeapYear(int year)
{
	return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}


/*
	判断输入的日期是否合法
*/
bool isLegalDate(date& d)
{
	int year = d.year, mon = d.month, day = d.day;
	//大：1 3 5 7 8 10 12
	//小：4 6 9 11
	//平：2

	if (year < 0 || mon <= 0 || mon > 12 || day <= 0 || day > 31)return false;

	if (1 == mon || 3 == mon || 5 == mon || 7 == mon || 8 == mon || 10 == mon || 12 == mon) {
		return true;
	}
	if (isLeapYear(year)) {
		if (2 == mon && (28 == day || 30 == day || 31 == day))return false;
		return true;
	}
	else {
		if (2 == mon && (29 == day || 30 == day || 31 == day))return false;
		return true;
	}
}


/*
	获取当前日期，不需要用户自己输入
*/
date getCurDate() {
	auto now = chrono::system_clock::now();		//获取当前时间
	time_t curTime = chrono::system_clock::to_time_t(now);	//将当前时间转换为time_t类型

	//cout << "当前时间：" << ctime(&curTime) << endl;
	char curDateChars[16];
	strftime(curDateChars, sizeof(curDateChars), "%Y-%m-%d", localtime(&curTime));	// 转化为指定格式字符串
	string curDateStr(curDateChars);	// char* 转string
	//cout << curDateStr;
	date curDate;
	istringstream is(curDateStr.substr(0, 4));	//string 转int
	is >> curDate.year;
	is = istringstream(curDateStr.substr(5, 2));
	is >> curDate.month;
	is = istringstream(curDateStr.substr(8, 2));
	is >> curDate.day;
	//cout << curDate.year << endl;
	return curDate;
}


/*
	以公元 1900 年 1 月 1 日为基准，通过天数计算出当前的时间
*/
date days2Date(int days) {
	date d;
	int m[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	for (d.year = 1900; days > 365 + isLeapYear(d.year); d.year++)
	{
		days -= 365;
		if (isLeapYear(d.year))
			days--;
	}
	for (d.month = 1; days > m[d.month]; d.month++)
	{
		days -= m[d.month];
	}
	d.day = days;

	return d;
}

/*
	以公元 1900 年 1 月 1 日为基准，计算经过的日期
*/
int date2Days(const date& aDate)
{
	int m[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	if (isLeapYear(aDate.year))
		m[2]++;
	int result = 0;
	for (int i = 1900; i < aDate.year; i++)
	{
		result += 365;
		if (isLeapYear(i))
			result++;
	}
	for (int i = 1; i < aDate.month; i++)
	{
		result += m[i];
	}
	result += aDate.day;

	return result;
}

/*
	计算还有多少天到用户生日
*/
int dayDis(date& date1, date& date2)
{
	return abs(date2Days(date1) - date2Days(date2));
}



/*
	根据日期计算出当天是星期几
*/
void CaculateWeekDay(date& date1)
{
	int y = date1.year, m = date1.month, d = date1.day;
	if (m == 1 || m == 2) {
		m += 12;
		y--;
	}
	date1.week = (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400) % 7;
}

void showWeekDay(date d) {
	if (d.week < 0 || d.week>6) {
		CaculateWeekDay(d);
	}
	switch (d.week)
	{
	case 0: cout << "星期一" << endl; break;
	case 1: cout << "星期二" << endl; break;
	case 2: cout << "星期三" << endl; break;
	case 3: cout << "星期四" << endl; break;
	case 4: cout << "星期五" << endl; break;
	case 5: cout << "星期六" << endl; break;
	case 6: cout << "星期日" << endl; break;
	}
}


void showdate(date d) {
	cout << d.year << '-' << d.month << '-' << d.day;
}


