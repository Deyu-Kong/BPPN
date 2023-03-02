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
	用户欢迎页面
*/
void welcome() {
	cout << "欢迎来到生日聚会计划便签软件\n";
	//cout << "按任意键继续……\n";
	system("pause");       //实现按任意键继续
}
/*
	根据用户输入获得用户生日日期
*/
date getUserBirthday() {
	date userBirthday;
	cout << "请输入您的出生年份\n";
	cout << "请输入您的出生月份\n";
	cout << "请输入您的出生日期\n";
	//cin >> userBirthday.year;
	//cin >> userBirthday.month;
	//cin >> userBirthday.day;
	userBirthday.year = 2002;
	userBirthday.month = 3;
	userBirthday.day = 17;
	return userBirthday;
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
	is=istringstream(curDateStr.substr(5, 2));
	is >> curDate.month;
	is=istringstream(curDateStr.substr(8, 2));
	is >> curDate.day;
	//cout << curDate.year << endl;
	return curDate;
}

/*
	判断是否闰年
*/
bool isLeapYear(int year)
{
	return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}

/*
	以公元 1900 年 1 月 1 日为基准，计算经过的日期 
*/
int getDays(date& aDate)
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
int dayDis(date& date1,date& date2)
{
	return abs(getDays(date1) - getDays(date2));
}

/*
	计算用户下一个生日的日期
*/
void getNextBirthday(const date& curDate, date& userBirth) {
	if (curDate.month > userBirth.month) {
		userBirth.year = curDate.year + 1;
	}
	else if (curDate.month == userBirth.month&&curDate.day >= userBirth.day) {
		if (curDate.day == userBirth.day) {
			cout << "今天就是您的生日，您无需计划";
			exit(0);
		}
		userBirth.year = curDate.year + 1;
	}
	else {
		userBirth.year = curDate.year;
	}
}

void showWeekDay(date d) {
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

void showdate(date d) {
	cout << d.year << '-' << d.month <<'-'<< d.day;
}

/*
	生日聚会计划制定日期
*/
void getplan(date curDate,date userBirth) {
	cout << "下次生日日期：";
	showdate(userBirth);
	cout << endl;
	int advanced;
	cout << "请输入希望提前聚会的天数: ";
	//cin >> advanced;
	advanced = 2;


}

int main() {
	welcome();
	date userBirthday = getUserBirthday();
	date curDate = getCurDate();
	getNextBirthday(curDate, userBirthday);	// 将用户生日日期更新到下一个生日
	cout << "距离您的生日还剩：" << dayDis(userBirthday, curDate) << endl;
	cout << "按任意键进入“生日聚会计划制定日期”的确定环节\n";
	system("pause");
	getplan(curDate, userBirthday);
	//end
}
