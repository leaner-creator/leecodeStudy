/*
���������������飬�뽻��һ����ֵ��ÿ��������ȡһ����ֵ����ʹ��������������Ԫ�صĺ���ȡ�

����һ�����飬��һ��Ԫ���ǵ�һ��������Ҫ������Ԫ�أ��ڶ���Ԫ���ǵڶ���������Ҫ������Ԫ�ء����ж���𰸣���������һ�����ɡ�����������������ֵ�����ؿ����顣

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/sum-swap-lcci
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

/*
*��⣺�������⣬��֪����Ŀ����������ѧ���㣬����������ֱ���arr1��arr2  ,��������Ԫ����ֵ�ĺͷֱ���sum1��sum2��arr1�ṩ��Ԫ��Ϊa1��arr2�ṩ��Ԫ��Ϊa2;
* ����������   sum1-a1+a2 == sum2-a2+a1 , ��������Ĳ�ֵΪdis=sum1 -sum2= 2a1-2a2����ֵΪż����
* (dis/2)=��sum1 -sum2��/2 == a1-a2,��ֵ��һ��Ϊ�ṩ������Ԫ�صĲ�ֵ������arr2���ҵ�ֵΪ(a1 - dis/2)��Ԫ�ؼ���,
*��������ó��Ĺ�ʽ��ʵ�ִ��뼴�� 
*/

#include <iostream>
#include<vector>
 #include <set>
 
using namespace std;

class Solution {
public:
    vector<int> findSwapValues(vector<int>& array1, vector<int>& array2) {
        
        int sum1 = 0;//����1Ԫ����ֵ�ĺ�
        int sum2 = 0;
        int dis = 0;//�� ����  �Ĳ�ֵ
        vector<int> v;
        set<int> set;
        for(auto iter : array1) //�ֱ����������ĺ� 
        {
            sum1 += iter;
        }

        for(auto iter : array2)
        {
            sum2 += iter;
            set.insert(iter);  //set�в�����ʹ�ö��ֲ���,�ٶȱ� vector �Ĳ��ҿ죬֮ǰʹ��  vector��find()��������ʱ�䳬������ 
        }
     
        dis = sum1 - sum2;
        if((dis & 1 )== 1) //�����������֮�͵Ĳ�Ϊ�������򷵻�[]
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

