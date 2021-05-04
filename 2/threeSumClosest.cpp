/*
16. 最接近的三数之和

给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。返回这三个数的和。假定每组输入只存在唯一答案。
*/ 
/*题解：1、可用三重循环，遍历所有的组合. 2 利用排序+双指针的方法
* 三重循环时间复杂度为O（n^3）,空间复杂度为O(1) ;排序+双指针 时间复杂度为O（n^2）,空间复杂度为O(n) ;
*题目有时间限制，采用 排序+双指针的方法 
*首先将向量表排序，把一个数作为固定，取本数右端 最小的数和最大的数，
*将三数的和 与 目标值比较，若小于则左端的数往右移动，增大三数的和；
*若大于则右端的数右移动，减小三数的和
*遍历向量表中每一个数作为固定值时，三数的和 最靠近 target 的值
*/
#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int start=0;
        int end=0;
        int sum =0;
        sort(nums.begin(),nums.end());
        int ans = nums[0] + nums[1] + nums[2];
        for(int i=0;i<nums.size();++i)
        {
            start = i+1;
            end = nums.size() - 1;
            while(start < end)
            {
                sum = nums[start] + nums[end] + nums[i];
                if(abs(target - sum) < abs(target - ans))//记录差值 最小的值
                    ans = sum;

                if(sum > target) //和 大于目标值，将和减小
                    end--;
                else if(sum < target)//和 小于目标值，将和增大
                    start++;
                else
                    return ans;
            }
        }
        return ans;
    }
};
int  main()
{
	vector<int> nums= {-1,2,1,-4};
	int target = 1;
	Solution *solution = new Solution();
	cout<<solution->threeSumClosest(nums,target);
} 
