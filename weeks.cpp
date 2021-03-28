/*
给你一个日期，请你设计一个算法来判断它是对应一周中的哪一天。

输入为三个整数：day、month 和?year，分别表示日、月、年。

您返回的结果必须是这几个值中的一个?{"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"}。

?

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/day-of-the-week
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

//题解：计算输入日期距离1970年1月1号的天数，用其+4（1970年1月1为星期四）  对400求余得到星期几

#include <iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool isLeep(int year);
    int month_days(int month, int year);
    int distance(int day, int month, int year);
    string choose(int distance);
    string dayOfTheWeek(int day, int month, int year);
    void init();


private:
    vector<string> weeks;
};

void Solution::init()  //初始化星期列表
{    
    this->weeks.push_back("Monday");
    this->weeks.push_back("Tuesday");
    this->weeks.push_back("Wednesday");
    this->weeks.push_back("Thursday");
    this->weeks.push_back("Friday");
    this->weeks.push_back("Saturday");
    this->weeks.push_back("Sunday");
}

bool Solution::isLeep(int year)//判断是否是闰年
{
    if(year%4!=0)
        return false;
    if(year%400==0)
        return true;
    if(year%100==0&&year%400!=0)
        return false;
    return true;
}

int Solution::month_days(int month, int year)//计算每个月的天数
{
    if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)
        return 31;
    if(month==4||month==6||month==8||month==9||month==8||month==11)
        return 30;
    if(month==2&&isLeep(year)==true)
        return 29;
    else return 28;     
}

int Solution::distance(int day, int month, int year)//计算该日期距离1970年1月1号的天数
{
    int dis = 0;
    vector<int> years;

    for(int y=year-1;y>=1970;y--)
        years.push_back(y);

    for(int i=0;i<=years.size()-1;i++)
    {
        if( isLeep(years[i]) == true )
            dis+=366;
        else 
            dis+=365;
    }

    for(int m=month-1;m>=1;m--)
        dis+=month_days(m, year);
    dis+=(day-1);
    
    return dis;
}

string Solution::dayOfTheWeek(int day, int month, int year) //计算该日期是星期几 
{
    init();
    int dis = distance(day,month,year);
    string ans = weeks[(dis-4)%7];
    return ans;
}

int main()
{
	int day = 31, month = 8, year = 2019;
	Solution *solution = new Solution();
	cout<<solution->dayOfTheWeek(day,month,year);
 } 
