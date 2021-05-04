/*
给定两个整数数组，请交换一对数值（每个数组中取一个数值），使得两个数组所有元素的和相等。

返回一个数组，第一个元素是第一个数组中要交换的元素，第二个元素是第二个数组中要交换的元素。若有多个答案，返回任意一个均可。若无满足条件的数值，返回空数组。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sum-swap-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/*
*题解：根据题意，可知道题目种隐含着数学运算，即两个数组分别是arr1、arr2  ,两个数组元素数值的和分别是sum1、sum2，arr1提供的元素为a1、arr2提供的元素为a2;
* 发生交换后   sum1-a1+a2 == sum2-a2+a1 , 两个数组的差值为dis=sum1 -sum2= 2a1-2a2，差值为偶数；
* (dis/2)=（sum1 -sum2）/2 == a1-a2,差值的一半为提供的两个元素的差值，则在arr2中找到值为(a1 - dis/2)的元素即可,
*根据上面得出的公式，实现代码即可 
*/

#include <iostream>
#include<vector>
 #include <set>
 
using namespace std;

class Solution {
public:
    vector<int> findSwapValues(vector<int>& array1, vector<int>& array2) {
        
        int sum1 = 0;//数组1元素数值的和
        int sum2 = 0;
        int dis = 0;//两 数组  的差值
        vector<int> v;
        set<int> set;
        for(auto iter : array1) //分别计算两数组的和 
        {
            sum1 += iter;
        }

        for(auto iter : array2)
        {
            sum2 += iter;
            set.insert(iter);  //set中查找是使用二分查找,速度比 vector 的查找快，之前使用  vector的find()函数，但时间超出限制 
        }
     
        dis = sum1 - sum2;
        if((dis & 1 )== 1) //如果两个数组之和的差为奇数，则返回[]
        {
            return v;
        }
        dis=dis/2;
        for(auto iter : array1)
        {
            if(set.find(iter-dis) != set.end())
            {
                v.push_back(iter);
                v.push_back(iter-dis);
                break;
            }
        }

        return v;
    }
};
int  main()
{

	Solution *solution = new Solution();
	vector<int> nums1= {4, 1, 2, 1, 1, 2};
	vector<int> nums2= {3, 6, 3, 3};
	vector<int>  show= solution->findSwapValues(nums1,nums2);
	
	for(auto iter : show)
		cout<<iter<<" ";
} 

