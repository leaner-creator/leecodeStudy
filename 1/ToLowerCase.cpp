/*
����Сд��ĸ
ʵ�ֺ��� ToLowerCase()���ú�������һ���ַ������� str���������ַ����еĴ�д��ĸת����Сд��ĸ��֮�󷵻��µ��ַ�����
��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/to-lower-case
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/ 


/*
	��� ������string��ÿ���ַ����ж���Ϊ ��д��ĸ�������ascall��ֵ������ ��дת��СдΪ��  ascall��ֵ-32 
*/
#include <iostream>

using namespace std;

class Solution {
public:
	string toLowerCase(string str); 
};
string Solution::toLowerCase(string str) 
{
    for(int i=0;i < str.length();i++ )
    {
        if(str[i] >= 65 && str[i] <= 90)
            str[i]+=32;
    }
    return str;
}


int main()
{
	Solution *solution = new Solution();
	std::cout<<solution->toLowerCase("HELLO");
	
}

