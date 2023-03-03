#pragma warning(disable:4996)
#include<iostream>
#include<chrono>
#include<string>
#include<ctime>
#include <sstream>
#include"date.h"

using namespace std;

/*
	用户欢迎页面
*/
void welcome() {
	cout << "====================欢迎来到生日聚会计划便签软件====================\n";
	//cout << "按任意键继续……\n";
	system("pause");       //实现按任意键继续
}

/*
	根据用户输入获得用户生日日期
*/
date getUserBirthday() {
	date userBirthday;
	bool first = true;
	do {
		if (!first) {
			cout << "您输入的日期不合法，请重新输入！\n";
		}
		cout << "请输入您的出生年份\n";
		cin >> userBirthday.year;
		cout << "请输入您的出生月份\n";
		cin >> userBirthday.month;
		cout << "请输入您的出生日期\n";
		cin >> userBirthday.day;
		first = false;
	} while (!isLegalDate(userBirthday));
	return userBirthday;
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

/*
	当前日期减去advance，计算开party的时间
	advance可以为负数
*/
date getAdvancedDate(const date& birth, int advance) {
	int days = date2Days(birth);
	days -= advance;
	return days2Date(days);
}

/*
	生日聚会计划制定日期
*/
date getplan(const date curDate, const date userBirth) {
	cout << "下次生日日期：";
	showdate(userBirth);
	cout << endl;
	int advanced;
	cout << "请输入希望提前聚会的天数: ";
	cin >> advanced;
	//advanced = 2;
	date planDate = getAdvancedDate(userBirth, advanced);
	CaculateWeekDay(planDate);	//计算plan的日期是星期几，0对应星期一
	return planDate;
}

date plan2party(date planDate) {
	date partyDate;
	if (planDate.week < 5) {
		cout << "计划当天是";
		showWeekDay(planDate);
		cout << "，已为您自动调整为最近的周六……" << endl;
		if (planDate.week <= 1) { //周一周二
			partyDate = getAdvancedDate(planDate, planDate.week + 2);
		}
		else {	//周三周四周五
			partyDate = getAdvancedDate(planDate, planDate.week - 6);
		}
	}
	else {
		partyDate = planDate;
	}
	cout << "为您准备的生日聚会时间为：\n";
	showdate(partyDate);
	cout << "  ";
	showWeekDay(partyDate);
	return partyDate;
}

void endMenu(date& birthday, int days, date& planDate, date& partyDate) {
	cout << "\n============================结束界面================================\n";
	cout << "下次生日日期：";
	showdate(birthday);
	cout << endl;
	cout << "下次生日距离今天的天数：" << days << endl;
	cout << "距离下次生日前n天的日期：";
	showdate(planDate);
	cout << endl;
	cout << "预计准备生日的日期：";
	showdate(partyDate);
	cout << endl;
}

bool rePlan() {
	char flag = '0';
	while (flag != 'y'&&flag != 'n') {
		cout << "是否重新确定计划日期？(y/n)";
		cin >> flag;
	}
	return flag == 'y';
}