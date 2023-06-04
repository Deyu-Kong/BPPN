/**
 * @file method.cpp
 * @brief 实现与日期计算相关的结构体和方法
 * @date 2023/3/3
 * @author 孔德昱
 */
#include "method.h"

using namespace std;

/**
 * @brief 判断是否为闰年
 * @param year 年份
 */
bool isLeapYear(int year)
{
    return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}

/**
 * @brief 判断输入的日期是否合法
 * @param d 日期
 * @return 是否合法
 */
bool isLegalDate(MyDate &d)
{
    int year = d.year, mon = d.month, day = d.day;
    // 大：1 3 5 7 8 10 12
    // 小：4 6 9 11
    // 平：2

    if (year < 0 || mon <= 0 || mon > 12 || day <= 0 || day > 31)
        return false;

    if (1 == mon || 3 == mon || 5 == mon || 7 == mon || 8 == mon || 10 == mon || 12 == mon)
    {
        return true;
    }
    if (isLeapYear(year))
    {
        if (2 == mon && (28 == day || 30 == day || 31 == day))
            return false;
        return true;
    }
    else
    {
        if (2 == mon && (29 == day || 30 == day || 31 == day))
            return false;
        return true;
    }
}

/**
 * @brief 获取当前日期，不需要用户自己输入
 * @return 当前日期
 */
MyDate getCurDate()
{
    auto now = chrono::system_clock::now();                // 获取当前时间
    time_t curTime = chrono::system_clock::to_time_t(now); // 将当前时间转换为time_t类型
    char curDateChars[16];
    strftime(curDateChars, sizeof(curDateChars), "%Y-%m-%d", localtime(&curTime)); // 转化为指定格式字符串
    string curDateStr(curDateChars);                                               // char* 转string
    MyDate curDate;
    istringstream is(curDateStr.substr(0, 4)); // string 转int
    is >> curDate.year;
    is = istringstream(curDateStr.substr(5, 2));
    is >> curDate.month;
    is = istringstream(curDateStr.substr(8, 2));
    is >> curDate.day;
    return curDate;
}

/**
 * @brief 以公元 1900 年 1 月 1 日为基准，通过天数计算出当前的时间
 * @param days 天数
 * @return 日期
 */
MyDate days2Date(int days)
{
    MyDate d;
    int m[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

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

/**
 * @brief 以公元 1900 年 1 月 1 日为基准，计算经过的天数
 * @param aDate 日期
 * @return 天数
 */
int date2Days(const MyDate &aDate)
{
    int m[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
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

/**
 * @brief 计算还有多少天到用户生日
 * @param date1 当前日期
 * @param date2 用户生日
 * @return 天数
 */
int dayDis(MyDate &date1, MyDate &date2)
{
    return abs(date2Days(date1) - date2Days(date2));
}

/**
 * @brief 计算当前日期是星期几
 * @param date1 当前日期
 */
void CaculateWeekDay(MyDate &date1)
{
    int y = date1.year, m = date1.month, d = date1.day;
    if (m == 1 || m == 2)
    {
        m += 12;
        y--;
    }
    date1.week = (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400) % 7; // 0对应星期一
}

/**
 * @brief 显示当前日期是星期几，调试用
 * @param d 当前日期
 */
void showWeekDay(MyDate d)
{
    if (d.week < 0 || d.week > 6)
    {
        CaculateWeekDay(d);
    }
    switch (d.week)
    {
    case 0:
        cout << "星期一 " << endl;
        break;
    case 1:
        cout << "星期二 " << endl;
        break;
    case 2:
        cout << "星期三 " << endl;
        break;
    case 3:
        cout << "星期四 " << endl;
        break;
    case 4:
        cout << "星期五 " << endl;
        break;
    case 5:
        cout << "星期六 " << endl;
        break;
    case 6:
        cout << "星期日 " << endl;
        break;
    }
}

/**
 * @brief 显示日期，调试用
 * @param d 日期
 */
void showdate(MyDate d)
{
    cout << d.year << '-' << d.month << '-' << d.day;
}

/**
 * @brief 获取用户生日,调试用
 * @return 用户生日
 */
MyDate getUserBirthday()
{
    MyDate userBirthday;
    bool first = true;
    do
    {
        if (!first)
        {
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

/**
 * @brief 计算用户下一个生日的日期
 * @param curDate 当前日期
 * @param userBirth 用户生日
 * @return 下一个生日的日期
 */
QDate getNextBirthday(const QDate &curDate, const QDate &userBirth)
{
    // 如果当前日期大于用户生日，那么下一个生日就是明年的生日
    if (curDate.month() > userBirth.month())
    {
        return QDate(curDate.year() + 1, userBirth.month(), userBirth.day());
    }
    // 如果当前日期等于用户生日，那么下一个生日就是明年的生日
    else if (curDate.month() == userBirth.month() && curDate.day() >= userBirth.day())
    {
        if (curDate.day() == userBirth.day())
        {
            return QDate(curDate.year(), userBirth.month(), userBirth.day());
        }
        else
            return QDate(curDate.year() + 1, userBirth.month(), userBirth.day());
    }
    // 如果当前日期小于用户生日，那么下一个生日就是今年的生日
    else
    {
        return QDate(curDate.year(), userBirth.month(), userBirth.day());
    }
}

/**
 * @brief 计算提前advance天后的日期
 * @param birth 用户生日
 * @param advance 提前天数
 * @return 提前后的日期
 */
MyDate getAdvancedDate(const MyDate &birth, int advance)
{
    int days = date2Days(birth);
    days -= advance;
    return days2Date(days);
}

/**
 * @brief 获取计划日期
 * @param curDate 当前日期
 * @param userBirth 用户生日
 * @return 计划日期
 */
MyDate getplan(const MyDate curDate, const MyDate userBirth)
{
    cout << "下次生日日期：";
    showdate(userBirth);
    cout << endl;
    int advanced;
    cout << "请输入希望提前聚会的天数: ";
    cin >> advanced;
    // advanced = 2;
    MyDate planDate = getAdvancedDate(userBirth, advanced);
    CaculateWeekDay(planDate); // 计算plan的日期是星期几，0对应星期一
    return planDate;
}

/**
 * @brief 判断是否为特殊假期
 * @param date 日期
 * @return 是否为特殊假期
 */
bool isSpecialVacation(MyDate date)
{
    // 5.1--5.3期间
    if (date.month == 5 && date.day <= 3)
    {
        return true;
    }

    // 10.1--10.7期间
    else if (date.month == 10 && date.day <= 7)
    {
        return true;
    }
    return false;
}

/**
 * @brief 修改后的计划聚会日期
 * @param planDate 计划日期
 * @return 聚会日期
 *
 */
MyDate plan2party(MyDate planDate)
{
    MyDate partyDate;
    if (isSpecialVacation(planDate))
    {
        partyDate = planDate;
    }
    else if (planDate.week < 5)
    {
        // 周一周二
        if (planDate.week <= 1)
        {
            partyDate = getAdvancedDate(planDate, planDate.week + 2);
        }

        // 周三周四周五
        else
        {
            partyDate = getAdvancedDate(planDate, planDate.week - 5);
        }
    }
    else
    {
        partyDate = planDate;
    }
    return partyDate;
}

/**
 * @brief 结束界面，调试用
 * @param birthday 用户生日
 * @param days 距离下次生日的天数
 * @param planDate 计划日期
 * @param partyDate 聚会日期
 */
void endMenu(MyDate &birthday, int days, MyDate &planDate, MyDate &partyDate)
{
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

/**
 * @brief 重新确定计划日期,调试用
 * @return 是否重新确定计划日期
 */
bool rePlan()
{
    char flag = '0';
    while (flag != 'y' && flag != 'n')
    {
        cout << "是否重新确定计划日期？(y/n)";
        cin >> flag;
    }
    return flag == 'y';
}