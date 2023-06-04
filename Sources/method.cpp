
//#pragma warning(disable:4996)
#include"method.h"

using namespace std;

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
bool isLegalDate(MyDate& d)
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
MyDate getCurDate() {
    auto now = chrono::system_clock::now();		//获取当前时间
    time_t curTime = chrono::system_clock::to_time_t(now);	//将当前时间转换为time_t类型

    //cout << "当前时间：" << ctime(&curTime) << endl;
    char curDateChars[16];
    strftime(curDateChars, sizeof(curDateChars), "%Y-%m-%d", localtime(&curTime));	// 转化为指定格式字符串
    string curDateStr(curDateChars);	// char* 转string
    //cout << curDateStr;
    MyDate curDate;
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
MyDate days2Date(int days) {
    MyDate d;
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
int date2Days(const MyDate& aDate)
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
int dayDis(MyDate& date1, MyDate& date2)
{
    return abs(date2Days(date1) - date2Days(date2));
}



/*
    根据日期计算出当天是星期几
*/
void CaculateWeekDay(MyDate& date1)
{
    int y = date1.year, m = date1.month, d = date1.day;
    if (m == 1 || m == 2) {
        m += 12;
        y--;
    }
    date1.week = (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400) % 7;
}

void showWeekDay(MyDate d) {
    if (d.week < 0 || d.week>6) {
        CaculateWeekDay(d);
    }
    switch (d.week)
    {
    case 0: cout << "星期一 " << endl; break;
    case 1: cout << "星期二 " << endl; break;
    case 2: cout << "星期三 " << endl; break;
    case 3: cout << "星期四 " << endl; break;
    case 4: cout << "星期五 " << endl; break;
    case 5: cout << "星期六 " << endl; break;
    case 6: cout << "星期日 " << endl; break;
    }
}


void showdate(MyDate d) {
    cout << d.year << '-' << d.month << '-' << d.day;
}



/*
    用户欢迎页面
*/
//void welcome() {
//    cout << "====================欢迎来到生日聚会计划便签软件====================\n";
//    //cout << "按任意键继续……\n";
//    system("pause");       //实现按任意键继续
//}

/*
    根据用户输入获得用户生日日期
*/
MyDate getUserBirthday() {
    MyDate userBirthday;
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
QDate getNextBirthday(const QDate& curDate, const QDate& userBirth) {
    if (curDate.month() > userBirth.month()) {
        return QDate(curDate.year() + 1,userBirth.month(),userBirth.day());
    }
    else if (curDate.month() == userBirth.month()&&curDate.day() >= userBirth.day()) {
        if (curDate.day() == userBirth.day()) {
            return QDate(curDate.year(),userBirth.month(),userBirth.day());
        }
        else return QDate(curDate.year() + 1,userBirth.month(),userBirth.day());
    }
    else {
        return QDate(curDate.year(),userBirth.month(),userBirth.day());
    }
}

/*
    当前日期减去advance，计算开party的时间
    advance可以为负数
*/
MyDate getAdvancedDate(const MyDate& birth, int advance) {
    int days = date2Days(birth);
    days -= advance;
    return days2Date(days);
}

/*
    生日聚会计划制定日期
*/
MyDate getplan(const MyDate curDate, const MyDate userBirth) {
    cout << "下次生日日期：";
    showdate(userBirth);
    cout << endl;
    int advanced;
    cout << "请输入希望提前聚会的天数: ";
    cin >> advanced;
    //advanced = 2;
    MyDate planDate = getAdvancedDate(userBirth, advanced);
    CaculateWeekDay(planDate);	//计算plan的日期是星期几，0对应星期一
    return planDate;
}

bool isSpecialVacation(MyDate date){
    if (date.month==5&&date.day<=3){// 5.1--5.3期间
        return true;
    }else if(date.month==10&&date.day<=7){ //10.1--10.7期间
        return true;
    }
    return false;
}

MyDate plan2party(MyDate planDate) {
    MyDate partyDate;
    if(isSpecialVacation(planDate)){
        partyDate = planDate;
    }
    else if (planDate.week < 5) {
//        cout << "计划当天是";
//        showWeekDay(planDate);
//        cout << "，已为您自动调整为最近的周六……" << endl;
        if (planDate.week <= 1) { //周一周二
            partyDate = getAdvancedDate(planDate, planDate.week + 2);
        }
        else {	//周三周四周五
            partyDate = getAdvancedDate(planDate, planDate.week - 5);
        }
    }
    else {
        partyDate = planDate;
    }
//    cout << "为您准备的生日聚会时间为：\n";
//    showdate(partyDate);
//    cout << "  ";
//    showWeekDay(partyDate);
    return partyDate;
}

void endMenu(MyDate& birthday, int days,MyDate& planDate, MyDate& partyDate) {
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

//int main() {
//    // 欢迎界面
//    welcome();
//    // 获取用户生日
//    date userBirthday = getUserBirthday();
//    // 获取当前日期
//    date curDate = getCurDate();
//    // 将用户生日日期更新到下一个生日
//    getNextBirthday(curDate, userBirthday);
//    cout << "您的下一个生日日期为：";
//    showdate(userBirthday);
//    int days = dayDis(userBirthday, curDate);
//    cout << "\n距离您的生日还剩：" << days << endl;
//    cout << "按任意键进入“生日聚会计划制定日期”的确定环节\n";
//    system("pause");
//    do {
//        cout << "=======================生日聚会计划日期制定=========================\n";
//        // 生日聚会计划指定日期
//        date planDate = getplan(curDate, userBirthday);
//        date partyDate = plan2party(planDate);
//        // 结束界面
//        endMenu(userBirthday, days, planDate, partyDate);
//    } while (rePlan());
//    cout << "===================退出任务========================";
//}
