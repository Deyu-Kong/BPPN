#pragma warning(disable:4996)
#include<iostream>
#include<chrono>
#include<string>
#include<ctime>
#include<sstream>
#include"methods.h"
using namespace std;


int main() {
	// 欢迎界面
	welcome();
	// 获取用户生日
	date userBirthday = getUserBirthday();
	// 获取当前日期
	date curDate = getCurDate();
	// 将用户生日日期更新到下一个生日
	getNextBirthday(curDate, userBirthday);	
	cout << "您的下一个生日日期为：";
	showdate(userBirthday);
	int days = dayDis(userBirthday, curDate);
	cout << "\n距离您的生日还剩：" << days << endl;
	cout << "按任意键进入“生日聚会计划制定日期”的确定环节\n";
	system("pause");
	do {
		cout << "=======================生日聚会计划日期制定=========================\n";
		// 生日聚会计划指定日期
		date planDate = getplan(curDate, userBirthday);
		date partyDate = plan2party(planDate);
		// 结束界面
		endMenu(userBirthday, days, planDate, partyDate);
	} while (rePlan());
	cout << "===================退出任务========================";
}
