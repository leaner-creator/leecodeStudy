/*
URL������дһ�ַ��������ַ����еĿո�ȫ���滻Ϊ%20���ٶ����ַ���β�����㹻�Ŀռ��������ַ�������֪���ַ����ġ���ʵ�����ȡ�

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/string-to-url-lcci
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

//��⣺���� length ���������ַ�������ʵ���� ���滻�ַ�����ʵ�����ڵĿո� 
#include <iostream>
using namespace std;

class Solution {
public:
    string replaceSpaces(string S, int length) 
    {
        string tmp=""; 
		int i = 0;
        for (int i = 0; i < length ; i ++)
            if (S[i] == ' ') 
				tmp += "%20";
            else 
				tmp += S[i];
        return tmp;
    }
};

int main()
{
	Solution *solution = new Solution();
	std::cout<<solution->replaceSpaces("Mr John Smith    ", 13);
} 
