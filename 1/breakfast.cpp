/*
小扣在秋日市集选择了一家早餐摊位，一维整型数组 staple 中记录了每种主食的价格，一维整型数组 drinks 中记录了每种饮料的价格。
小扣的计划选择一份主食和一款饮料，且花费不超过 x 元。请返回小扣共有多少种购买方案。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/2vYnGI
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/*
题解：利用排序，得到一个升序，在主食的价格决定的情况下，只需判断饮料的价格在花费的界限的下标就可得出种类数，而不需要去比较所有组合的价格。。 
*/ 
#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	Solution(){
		sum=0;
	}
	int breakfastNumber(vector<int>& staple, vector<int>& drinks, int x); 
private:
 	int sum;
};

int Solution::breakfastNumber(vector<int>& staple, vector<int>& drinks, int x) 
{
    const int mod = 1e9 + 7;
    int ans = 0;
    int cout=0;
    sort(staple.begin(), staple.end());
    sort(drinks.begin(), drinks.end());
    int j = drinks.size() - 1;
    for (int i = 0; i < staple.size(); i++) //如果饮料种类过于庞大，或主食的价格大于x的种类过于庞大，可添加 staple[i]<x的条件判断，节省循环时间，这由于测试数据问题未加，减少比较次数运行的时间
    {
        cout=x-staple[i];    //减少进行判断时相加运算的次数
        while (j >= 0 &&   cout < drinks[j] ) 
        {
             j--;
            //  if(cout < drinks[j/2])
            //     j=j/2;
        }
           
        if (j == -1)
             break;
        sum += j + 1;
        sum %= mod;
    }
    return sum;
}

int main()
{
	vector<int> staple = {10,20,5};
	vector<int> drinks = {5,5,2};
	int x = 15;
	
	Solution *solution = new Solution();
	cout<<solution->breakfastNumber(staple,drinks,x) ;
}
