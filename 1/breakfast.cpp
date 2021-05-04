/*
С���������м�ѡ����һ�����̯λ��һά�������� staple �м�¼��ÿ����ʳ�ļ۸�һά�������� drinks �м�¼��ÿ�����ϵļ۸�
С�۵ļƻ�ѡ��һ����ʳ��һ�����ϣ��һ��Ѳ����� x Ԫ���뷵��С�۹��ж����ֹ��򷽰���

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/2vYnGI
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

/*
��⣺�������򣬵õ�һ����������ʳ�ļ۸����������£�ֻ���ж����ϵļ۸��ڻ��ѵĽ��޵��±�Ϳɵó���������������Ҫȥ�Ƚ�������ϵļ۸񡣡� 
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
    for (int i = 0; i < staple.size(); i++) //���������������Ӵ󣬻���ʳ�ļ۸����x����������Ӵ󣬿���� staple[i]<x�������жϣ���ʡѭ��ʱ�䣬�����ڲ�����������δ�ӣ����ٱȽϴ������е�ʱ��
    {
        cout=x-staple[i];    //���ٽ����ж�ʱ�������Ĵ���
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
