/*
����һ�����ڣ��������һ���㷨���ж����Ƕ�Ӧһ���е���һ�졣

����Ϊ����������day��month ��?year���ֱ��ʾ�ա��¡��ꡣ

�����صĽ���������⼸��ֵ�е�һ��?{"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"}��

?

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/day-of-the-week
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

//��⣺�����������ھ���1970��1��1�ŵ�����������+4��1970��1��1Ϊ�����ģ�  ��400����õ����ڼ�

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

void Solution::init()  //��ʼ�������б�
{    
    this->weeks.push_back("Monday");
    this->weeks.push_back("Tuesday");
    this->weeks.push_back("Wednesday");
    this->weeks.push_back("Thursday");
    this->weeks.push_back("Friday");
    this->weeks.push_back("Saturday");
    this->weeks.push_back("Sunday");
}

bool Solution::isLeep(int year)//�ж��Ƿ�������
{
    if(year%4!=0)
        return false;
    if(year%400==0)
        return true;
    if(year%100==0&&year%400!=0)
        return false;
    return true;
}

int Solution::month_days(int month, int year)//����ÿ���µ�����
{
    if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)
        return 31;
    if(month==4||month==6||month==8||month==9||month==8||month==11)
        return 30;
    if(month==2&&isLeep(year)==true)
        return 29;
    else return 28;     
}

int Solution::distance(int day, int month, int year)//��������ھ���1970��1��1�ŵ�����
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

string Solution::dayOfTheWeek(int day, int month, int year) //��������������ڼ� 
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
