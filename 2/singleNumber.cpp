/*
只出现一次的数字

给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。

说明：

你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？
*/ 

/* 题解：看到题目，可以直接根据题目的意思，想到最简单的双重循环 ，第一重循环取一个数，第二重循环遍历数组，查找除此之外是否还存在一个相同的元素，时间复杂度为O(n)，弃用；
*另外，可以用hash表，两次循环（不是两重），第一次为记录每个数字出现的次数，第二次为遍历hash表寻找出现1此的元素，但是hash表会降低运算速度，消耗太多额外的空间。 
*第三种为，利用sort()将元素排序后,遍历一次数组，每个元素与前后的元素比较，查看是否相等，这方法调用了sort()函数，为快排算法，实际内部经历了双重循环，
*最后想到异或的特性，a^a=0;a^0=a; a^a^b=b ，通过位运算不仅可以加快运算速度，同时也不需要消耗额外的空间。 
*
*/

#include <iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int number=0;
        for(auto iter : nums)
        {
            number^=iter;
        }
        return number;
    }
};
int  main()
{
	vector<int> nums= {4,1, 2, 1, 2};
	Solution *solution = new Solution();
	cout<<solution->singleNumber(nums);
} 
