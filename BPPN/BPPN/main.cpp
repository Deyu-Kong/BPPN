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
	�û���ӭҳ��
*/
void welcome() {
	cout << "====================��ӭ�������վۻ�ƻ���ǩ���====================\n";
	//cout << "���������������\n";
	system("pause");       //ʵ�ְ����������
}
/*
	�����û��������û���������
*/
date getUserBirthday() {
	date userBirthday;
	bool first = true;
	do{
		if (!first) {
			cout << "����������ڲ��Ϸ������������룡\n";
		}
		cout << "���������ĳ������\n";
		cin >> userBirthday.year;
		cout << "���������ĳ����·�\n";
		cin >> userBirthday.month;
		cout << "���������ĳ�������\n";
		cin >> userBirthday.day;
		first = false;
	}while(!isLegalDate(userBirthday));
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
	�Թ�Ԫ 1900 �� 1 �� 1 ��Ϊ��׼��ͨ�������������ǰ��ʱ��
*/
date days2Date(int days) {
	date d;
	int m[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31};
	for (d.year = 1900; days>365+isLeapYear(d.year); d.year++)
	{
		days -= 365;
		if (isLeapYear(d.year))
			days--;
	}
	for (d.month = 1;  days>m[d.month]; d.month++)
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
int dayDis(date& date1,date& date2)
{
	return abs(date2Days(date1) - date2Days(date2));
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
	cout << d.year << '-' << d.month <<'-'<< d.day;
}


/*
	��ǰ���ڼ�ȥadvance�����㿪party��ʱ��
	advance����Ϊ����
*/
date getAdvancedDate(const date& birth, int advance){
	int days = date2Days(birth);
	days -= advance;
	return days2Date(days);
}

/*
	���վۻ�ƻ��ƶ�����
*/
date getplan(const date curDate,const date userBirth) {
	cout << "�´��������ڣ�";
	showdate(userBirth);
	cout << endl;
	int advanced;
	cout << "������ϣ����ǰ�ۻ������: ";
	cin >> advanced;
	//advanced = 2;
	date planDate= getAdvancedDate(userBirth, advanced);
	CaculateWeekDay(planDate);	//����plan�����������ڼ���0��Ӧ����һ
	return planDate;
}

date plan2party(date planDate) {
	date partyDate;
	if (planDate.week < 5) {
		cout << "�ƻ�������";
		showWeekDay(planDate);
		cout<<"����Ϊ���Զ�����Ϊ�������������" << endl;
		if (planDate.week <= 1) { //��һ�ܶ�
			partyDate = getAdvancedDate(planDate, planDate.week + 2);
		}
		else {	//������������
			partyDate = getAdvancedDate(planDate, planDate.week - 6);
		}
	}
	else {
		partyDate = planDate;
	}
	cout << "Ϊ��׼�������վۻ�ʱ��Ϊ��\n";
	showdate(partyDate);
	cout << "  ";
	showWeekDay(partyDate);
	return partyDate;
}

void endMenu(date& birthday,int days, date& planDate, date& partyDate) {
	cout << "\n============================��������================================\n";
	cout << "�´��������ڣ�";
	showdate(birthday);
	cout<<endl;
	cout << "�´����վ�������������" << days << endl;
	cout << "�����´�����ǰn������ڣ�";
	showdate(planDate);
	cout << endl;
	cout << "Ԥ��׼�����յ����ڣ�";
	showdate(partyDate);
	cout << endl;
}

bool rePlan() {
	char flag='0';
	while (flag != 'y'&&flag != 'n') {
		cout << "�Ƿ�����ȷ���ƻ����ڣ�(y/n)";
		cin >> flag;
	}
	return flag == 'y';
}

int main() {
	// ��ӭ����
	welcome();
	// ��ȡ�û�����
	date userBirthday = getUserBirthday();
	// ��ȡ��ǰ����
	date curDate = getCurDate();
	// ���û��������ڸ��µ���һ������
	getNextBirthday(curDate, userBirthday);	
	cout << "������һ����������Ϊ��";
	showdate(userBirthday);
	int days = dayDis(userBirthday, curDate);
	cout << "\n�����������ջ�ʣ��" << days << endl;
	cout << "����������롰���վۻ�ƻ��ƶ����ڡ���ȷ������\n";
	system("pause");
	do {
		cout << "=======================���վۻ�ƻ������ƶ�=========================\n";
		// ���վۻ�ƻ�ָ������
		date planDate = getplan(curDate, userBirthday);
		date partyDate = plan2party(planDate);
		// ��������
		endMenu(userBirthday, days, planDate, partyDate);
	} while (rePlan());
	cout << "===================�˳�����========================";
}
