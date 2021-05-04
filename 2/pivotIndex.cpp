//������������±�
//
//����һ���������� nums�����дһ���ܹ��������� �������±ꡱ �ķ�����
//
//���� �����±� �������һ���±꣬���������Ԫ����ӵĺ͵����Ҳ�����Ԫ����ӵĺ͡�
//
//������鲻���������±꣬���� -1 ����������ж�������±꣬Ӧ�÷��������ߵ���һ����
//
//ע�⣺�����±���ܳ�������������ˡ�

/*
*��⣺�����鵱��һ���ʣ�Ѱ������֧��ʹ��ﵽƽ�⣻ ���ȼ�����֧�ʵ�������֧��ӱʵ���˿�ʼ�ƶ� ������֧����˵��������Ҷ˵����������������ʱ�����ҵ�ƽ��㡣 
* ͬ�������±��  ���Ԫ�صĺ� ����������Ԫ�صĶ��ܺͼ�ȥ���Ԫ�صĺ͵õ��ұ�Ԫ�صĺͣ��±��𽥴��������ƶ��� �����Ԫ�صĺ����ұ�Ԫ�صĺ����ʱ�����ҵ������±� 
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
