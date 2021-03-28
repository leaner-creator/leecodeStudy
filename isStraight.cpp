/*
���˿����������5���ƣ��ж��ǲ���һ��˳�ӣ�����5�����ǲ��������ġ�2��10Ϊ���ֱ���AΪ1��JΪ11��QΪ12��KΪ13������С��Ϊ 0 �����Կ����������֡�A ������Ϊ 14��

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/bu-ke-pai-zhong-de-shun-zi-lcof
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/ 

//��⣺ �ж��Ƿ���˳�ӣ�ֻ���ж����ظ��� ������ƺ���С�ƵĲ�ֵ������4���ɣ�������� 0 �ĸ��� 

#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    bool isStraight(vector<int>& nums)
	{
		int  isNum[14]={0}; 
        sort(nums.begin(),nums.end());
        for( auto it : nums)
        {
            if( it == 0)
                continue;
            if(nums.back()-it > 4) //�ж�����ƺ���С�ƵĲ�ֵ��������3����˳��
                return false;
            if(isNum[it] == 1)  //�ж������ظ����ƣ���������˳��
                return false; 
            else
                isNum[it]=1;    //��¼���ֵ���   
        }
        return true;
    }

}; 
int main()
{
	vector<int> num={0,0,2,3,5};
	Solution *solution = new Solution();
	cout<<solution->isStraight(num) ;
} 
