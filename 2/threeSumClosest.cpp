/*
16. ��ӽ�������֮��

����һ������ n ������������ nums �� һ��Ŀ��ֵ target���ҳ� nums �е�����������ʹ�����ǵĺ��� target ��ӽ����������������ĺ͡��ٶ�ÿ������ֻ����Ψһ�𰸡�
*/ 
/*��⣺1����������ѭ�����������е����. 2 ��������+˫ָ��ķ���
* ����ѭ��ʱ�临�Ӷ�ΪO��n^3��,�ռ临�Ӷ�ΪO(1) ;����+˫ָ�� ʱ�临�Ӷ�ΪO��n^2��,�ռ临�Ӷ�ΪO(n) ;
*��Ŀ��ʱ�����ƣ����� ����+˫ָ��ķ��� 
*���Ƚ����������򣬰�һ������Ϊ�̶���ȡ�����Ҷ� ��С��������������
*�������ĺ� �� Ŀ��ֵ�Ƚϣ���С������˵��������ƶ������������ĺͣ�
*���������Ҷ˵������ƶ�����С�����ĺ�
*������������ÿһ������Ϊ�̶�ֵʱ�������ĺ� ��� target ��ֵ
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
                if(abs(target - sum) < abs(target - ans))//��¼��ֵ ��С��ֵ
                    ans = sum;

                if(sum > target) //�� ����Ŀ��ֵ�����ͼ�С
                    end--;
                else if(sum < target)//�� С��Ŀ��ֵ����������
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
