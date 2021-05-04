//找数组的中心下标
//
//给你一个整数数组 nums，请编写一个能够返回数组 “中心下标” 的方法。
//
//数组 中心下标 是数组的一个下标，其左侧所有元素相加的和等于右侧所有元素相加的和。
//
//如果数组不存在中心下标，返回 -1 。如果数组有多个中心下标，应该返回最靠近左边的那一个。
//
//注意：中心下标可能出现在数组的两端。

/*
*题解：把数组当成一根笔，寻找中心支点使其达到平衡； 首先计算整支笔的重量，支点从笔的左端开始移动 ，计算支点左端的重量和右端的重量，当两者相等时，即找到平衡点。 
* 同理，计算下标的  左边元素的和 ，利用数组元素的额总和减去左边元素的和得到右边元素的和，下表逐渐从左往右移动， 当左边元素的和与右边元素的和相等时，即找到中心下标 
*/
#include <iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int totalSum = 0;
        int leftSum = 0;
        for (auto iter : nums) 
            totalSum += iter;
        for (int i=0; i < nums.size(); i++)
        {
            if (leftSum != (totalSum - leftSum - nums[i])) 
                leftSum += nums[i];
            else
                return i; 
        }
        return -1;
    }
};

int main()
{
	vector<int> nums= {1, 7, 3, 6, 5, 6};
	Solution *solution = new Solution();
	cout<<solution->pivotIndex(nums);
} 
