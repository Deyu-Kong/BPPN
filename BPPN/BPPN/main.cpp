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
	�û���ӭҳ��
*/
void welcome() {
	cout << "��ӭ�������վۻ�ƻ���ǩ���\n";
	//cout << "���������������\n";
	system("pause");       //ʵ�ְ����������
}
/*
	�����û��������û���������
*/
date getUserBirthday() {
	date userBirthday;
	cout << "���������ĳ������\n";
	cout << "���������ĳ����·�\n";
	cout << "���������ĳ�������\n";
	//cin >> userBirthday.year;
	//cin >> userBirthday.month;
	//cin >> userBirthday.day;
	userBirthday.year = 2002;
	userBirthday.month = 3;
	userBirthday.day = 17;
	return userBirthday;
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
	is=istringstream(curDateStr.substr(5, 2));
	is >> curDate.month;
	is=istringstream(curDateStr.substr(8, 2));
	is >> curDate.day;
	//cout << curDate.year << endl;
	return curDate;
}

/*
	�ж��Ƿ�����
*/
bool isLeapYear(int year)
{
	return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}

/*
	�Թ�Ԫ 1900 �� 1 �� 1 ��Ϊ��׼�����㾭�������� 
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
	���㻹�ж����쵽�û�����
*/
int dayDis(date& date1,date& date2)
{
	return abs(getDays(date1) - getDays(date2));
}

/*
	�����û���һ�����յ�����
*/
void getNextBirthday(const date& curDate, date& userBirth) {
	if (curDate.month > userBirth.month) {
		userBirth.year = curDate.year + 1;
	}
	else if (curDate.month == userBirth.month&&curDate.day >= userBirth.day) {
		if (curDate.day == userBirth.day) {
			cout << "��������������գ�������ƻ�";
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
	case 0: cout << "����һ" << endl; break;
	case 1: cout << "���ڶ�" << endl; break;
	case 2: cout << "������" << endl; break;
	case 3: cout << "������" << endl; break;
	case 4: cout << "������" << endl; break;
	case 5: cout << "������" << endl; break;
	case 6: cout << "������" << endl; break;
	}
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

void showdate(date d) {
	cout << d.year << '-' << d.month <<'-'<< d.day;
}

/*
	���վۻ�ƻ��ƶ�����
*/
void getplan(date curDate,date userBirth) {
	cout << "�´��������ڣ�";
	showdate(userBirth);
	cout << endl;
	int advanced;
	cout << "������ϣ����ǰ�ۻ������: ";
	//cin >> advanced;
	advanced = 2;


}

int main() {
	welcome();
	date userBirthday = getUserBirthday();
	date curDate = getCurDate();
	getNextBirthday(curDate, userBirthday);	// ���û��������ڸ��µ���һ������
	cout << "�����������ջ�ʣ��" << dayDis(userBirthday, curDate) << endl;
	cout << "����������롰���վۻ�ƻ��ƶ����ڡ���ȷ������\n";
	system("pause");
	getplan(curDate, userBirthday);
	//end
}
