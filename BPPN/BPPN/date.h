#pragma warning(disable:4996)
#include<iostream>
#include<chrono>
#include<string>
#include<ctime>
#include <sstream>

using namespace std;

/*
	�������ڸ�ʽ
*/
struct date {
	int year;
	int month;
	int day;
	int week;
};


/*
	�ж��Ƿ�����
*/
bool isLeapYear(int year)
{
	return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}


/*
	�ж�����������Ƿ�Ϸ�
*/
bool isLegalDate(date& d)
{
	int year = d.year, mon = d.month, day = d.day;
	//��1 3 5 7 8 10 12
	//С��4 6 9 11
	//ƽ��2

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
	��ȡ��ǰ���ڣ�����Ҫ�û��Լ�����
*/
date getCurDate() {
	auto now = chrono::system_clock::now();		//��ȡ��ǰʱ��
	time_t curTime = chrono::system_clock::to_time_t(now);	//����ǰʱ��ת��Ϊtime_t����

	//cout << "��ǰʱ�䣺" << ctime(&curTime) << endl;
	char curDateChars[16];
	strftime(curDateChars, sizeof(curDateChars), "%Y-%m-%d", localtime(&curTime));	// ת��Ϊָ����ʽ�ַ���
	string curDateStr(curDateChars);	// char* תstring
	//cout << curDateStr;
	date curDate;
	istringstream is(curDateStr.substr(0, 4));	//string תint
	is >> curDate.year;
	is = istringstream(curDateStr.substr(5, 2));
	is >> curDate.month;
	is = istringstream(curDateStr.substr(8, 2));
	is >> curDate.day;
	//cout << curDate.year << endl;
	return curDate;
}


/*
	�Թ�Ԫ 1900 �� 1 �� 1 ��Ϊ��׼��ͨ�������������ǰ��ʱ��
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
	�Թ�Ԫ 1900 �� 1 �� 1 ��Ϊ��׼�����㾭��������
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
	���㻹�ж����쵽�û�����
*/
int dayDis(date& date1, date& date2)
{
	return abs(date2Days(date1) - date2Days(date2));
}



/*
	�������ڼ�������������ڼ�
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
	case 0: cout << "����һ" << endl; break;
	case 1: cout << "���ڶ�" << endl; break;
	case 2: cout << "������" << endl; break;
	case 3: cout << "������" << endl; break;
	case 4: cout << "������" << endl; break;
	case 5: cout << "������" << endl; break;
	case 6: cout << "������" << endl; break;
	}
}


void showdate(date d) {
	cout << d.year << '-' << d.month << '-' << d.day;
}


