/*
�ַ���������ת�����ǰ��ַ���ǰ������ɸ��ַ�ת�Ƶ��ַ�����β�����붨��һ������ʵ���ַ�������ת�����Ĺ��ܡ����磬�����ַ���"abcdefg"������2���ú�������������ת��λ�õ��Ľ��"cdefgab"��

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/zuo-xuan-zhuan-zi-fu-chuan-lcof
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

/*	���: 
    ͨ����ת0��n-1��n��β�� �������ֵ��ַ������õ�����ת�ַ����ķ�ת�ַ�����
    �ٷ�ת���õ�����ת�ַ���
    ����s = "abcdefg"  n=2
    1�� s = "ba cdefg" 
    2�� s = "ba gfedc"
    3�� s = "cdefgab"

    Ҳ����ͨ����ȡn֮ǰ�ַ���ת�Ƶ��ַ�����β����ʵ��
*/
#include <iostream>
#include<algorithm>

using namespace std;

class Solution {
public:
    string reverseLeftWords(string s, int n) ;
};
string Solution::reverseLeftWords(string s, int n)
{
    reverse(s.begin(),s.begin()+n);
    reverse(s.begin()+n,s.end());
    reverse(s.begin(),s.end());

    return s;
}
int main()
{
	Solution *solution = new Solution();
	cout<<solution->reverseLeftWords("abcdefg",2);
} 
