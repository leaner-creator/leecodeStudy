/*
 在排序数组中查找元素的第一个和最后一个位置

给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。

如果数组中不存在目标值 target，返回 [-1, -1]。

进阶：

    你可以设计并实现时间复杂度为 O(log n) 的算法解决此问题吗？

*/

/*题解：时间复杂度为 O(log n) 
*1、使用二分法寻找目标值在数组中的开始位置和结束位置
*2、将元素复制到set 容器，通过正向查找和反向查找，找出 开始位置和结束位置
*3、遍历一次数组，记录 开始位置和拥有的元素个数， 开始位置+元素个数=结束位置
*第1种方法，速度快，但是代码多； 第2种方法，消耗额外的空间；第3种方法，简洁明了，但速度较第一种慢 
*/
//2. 
//class Solution {
//public:
//    vector<int> searchRange(vector<int>& nums, int target)
//    {
//        int index=0;
//        int cout =0;
//        vector<int>::iterator result = find(nums.begin(), nums.end(), target); //查找target
//        if(result == nums.end())
//            return {-1,-1};
//            
//	    index = distance(nums.begin(), result);
//        cout= count(nums.begin(),nums.end(),target);
//
//        return {index, index + cout -1};
//    }
//};

/*
*1.使用二分法寻找目标值在数组中的开始位置和结束位置
*/
#include <iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int leftBound(vector<int> &nums, int target)//寻找target的左边界
    {
        int left = 0;
        int right = nums.size()-1;
        while (left <= right)
        {
            int mid = left + (right-left)/2;
            if (nums[mid] == target)//如果等于target，范围的右边界左移，缩小范围，寻找开始位置
            {
                right = mid - 1;  
            } 
            else if (nums[mid] < target)//如果小于target，target在右边，范围的左边界右移，缩小范围，
            {
                left = mid + 1;
            } 
            else if (nums[mid] > target)//如果大于target，target在左边，范围的右边界左移，缩小范围，
            {
                right = mid - 1;
            }
        }
        if (left >= nums.size() || nums[left] != target)//因为数组为从小到大，寻找的是开始位置，防止范围的左边界超出数组范围
        {
            return -1;
        }
        return left;
    }

    int rightBound(vector<int> &nums, int target) //寻找target的右边界
    {
        int left = 0;
        int right = nums.size()-1;
        while (left <= right)
        {
            int mid = left + (right-left)/2;
            if (nums[mid] == target)
            {
                left = mid + 1;
            } else if (nums[mid] > target)
            {
                right = mid - 1;
            } else if (nums[mid] < target)
            {
                left = mid + 1;
            }
        }
        if (right < 0 || nums[right] != target)
        {
            return -1;
        }
        return right;
    }

    vector<int> searchRange(vector<int>& nums, int target)
    {
        int left = leftBound(nums, target);
        int right = rightBound(nums, target);
        return {left, right};
    }
};

int  main()
{
	vector<int> nums= {5,7,7,8,8,10};
	int  target = 8; 
	Solution *solution = new Solution();
	vector<int> show=solution->searchRange(nums,target);
	for(int i=0;i<2;++i)
	{
		cout<<show[i]<<" ";
	}
} 
