/*
 �����������в���Ԫ�صĵ�һ�������һ��λ��

����һ�������������е��������� nums����һ��Ŀ��ֵ target���ҳ�����Ŀ��ֵ�������еĿ�ʼλ�úͽ���λ�á�

��������в�����Ŀ��ֵ target������ [-1, -1]��

���ף�

    �������Ʋ�ʵ��ʱ�临�Ӷ�Ϊ O(log n) ���㷨�����������

*/

/*��⣺ʱ�临�Ӷ�Ϊ O(log n) 
*1��ʹ�ö��ַ�Ѱ��Ŀ��ֵ�������еĿ�ʼλ�úͽ���λ��
*2����Ԫ�ظ��Ƶ�set ������ͨ��������Һͷ�����ң��ҳ� ��ʼλ�úͽ���λ��
*3������һ�����飬��¼ ��ʼλ�ú�ӵ�е�Ԫ�ظ����� ��ʼλ��+Ԫ�ظ���=����λ��
*��1�ַ������ٶȿ죬���Ǵ���ࣻ ��2�ַ��������Ķ���Ŀռ䣻��3�ַ�����������ˣ����ٶȽϵ�һ���� 
*/
//2. 
//class Solution {
//public:
//    vector<int> searchRange(vector<int>& nums, int target)
//    {
//        int index=0;
//        int cout =0;
//        vector<int>::iterator result = find(nums.begin(), nums.end(), target); //����target
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
*1.ʹ�ö��ַ�Ѱ��Ŀ��ֵ�������еĿ�ʼλ�úͽ���λ��
*/
#include <iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int leftBound(vector<int> &nums, int target)//Ѱ��target����߽�
    {
        int left = 0;
        int right = nums.size()-1;
        while (left <= right)
        {
            int mid = left + (right-left)/2;
            if (nums[mid] == target)//�������target����Χ���ұ߽����ƣ���С��Χ��Ѱ�ҿ�ʼλ��
            {
                right = mid - 1;  
            } 
            else if (nums[mid] < target)//���С��target��target���ұߣ���Χ����߽����ƣ���С��Χ��
            {
                left = mid + 1;
            } 
            else if (nums[mid] > target)//�������target��target����ߣ���Χ���ұ߽����ƣ���С��Χ��
            {
                right = mid - 1;
            }
        }
        if (left >= nums.size() || nums[left] != target)//��Ϊ����Ϊ��С����Ѱ�ҵ��ǿ�ʼλ�ã���ֹ��Χ����߽糬�����鷶Χ
        {
            return -1;
        }
        return left;
    }

    int rightBound(vector<int> &nums, int target) //Ѱ��target���ұ߽�
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
