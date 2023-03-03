#pragma warning(disable:4996)
#include<iostream>
#include<chrono>
#include<string>
#include<ctime>
#include <sstream>
#include"date.h"

using namespace std;

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
	do {
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
	} while (!isLegalDate(userBirthday));
	return userBirthday;
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
	��ǰ���ڼ�ȥadvance�����㿪party��ʱ��
	advance����Ϊ����
*/
date getAdvancedDate(const date& birth, int advance) {
	int days = date2Days(birth);
	days -= advance;
	return days2Date(days);
}

/*
	���վۻ�ƻ��ƶ�����
*/
date getplan(const date curDate, const date userBirth) {
	cout << "�´��������ڣ�";
	showdate(userBirth);
	cout << endl;
	int advanced;
	cout << "������ϣ����ǰ�ۻ������: ";
	cin >> advanced;
	//advanced = 2;
	date planDate = getAdvancedDate(userBirth, advanced);
	CaculateWeekDay(planDate);	//����plan�����������ڼ���0��Ӧ����һ
	return planDate;
}

date plan2party(date planDate) {
	date partyDate;
	if (planDate.week < 5) {
		cout << "�ƻ�������";
		showWeekDay(planDate);
		cout << "����Ϊ���Զ�����Ϊ�������������" << endl;
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

void endMenu(date& birthday, int days, date& planDate, date& partyDate) {
	cout << "\n============================��������================================\n";
	cout << "�´��������ڣ�";
	showdate(birthday);
	cout << endl;
	cout << "�´����վ�������������" << days << endl;
	cout << "�����´�����ǰn������ڣ�";
	showdate(planDate);
	cout << endl;
	cout << "Ԥ��׼�����յ����ڣ�";
	showdate(partyDate);
	cout << endl;
}

bool rePlan() {
	char flag = '0';
	while (flag != 'y'&&flag != 'n') {
		cout << "�Ƿ�����ȷ���ƻ����ڣ�(y/n)";
		cin >> flag;
	}
	return flag == 'y';
}