/*
从扑克牌中随机抽5张牌，判断是不是一个顺子，即这5张牌是不是连续的。2～10为数字本身，A为1，J为11，Q为12，K为13，而大、小王为 0 ，可以看成任意数字。A 不能视为 14。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/bu-ke-pai-zhong-de-shun-zi-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/ 

//题解： 判断是否是顺子，只需判断无重复牌 ，最大牌和最小牌的差值不超过4即可，无需关心 0 的个数 

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
            if(nums.back()-it > 4) //判断最大牌和最小牌的差值，若超过3则不是顺子
                return false;
            if(isNum[it] == 1)  //判断有无重复的牌，若有则不是顺子
                return false; 
            else
                isNum[it]=1;    //记录出现的牌   
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
