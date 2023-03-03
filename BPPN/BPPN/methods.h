/*
	定义日期格式
*/
struct date {
	int year;
	int month;
	int day;
	int week;
};
bool isLeapYear(int year);
bool isLegalDate(date& d);
date getCurDate();
date days2Date(int days);
int date2Days(const date& aDate);
int dayDis(date& date1, date& date2);
void CaculateWeekDay(date& date1);
void showWeekDay(date d);
void showdate(date d);
void welcome();
date getUserBirthday();
void getNextBirthday(const date& curDate, date& userBirth);
date getAdvancedDate(const date& birth, int advance);
date getplan(const date curDate, const date userBirth);
date plan2party(date planDate);
void endMenu(date& birthday, int days, date& planDate, date& partyDate);
bool rePlan();