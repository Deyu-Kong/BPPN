#pragma warning(disable:4996)
#include<iostream>
#include<chrono>
#include<string>
#include<ctime>
#include<sstream>
#include"methods.h"
using namespace std;


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
