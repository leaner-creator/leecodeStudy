//����һ���ַ����������ҳ����в������ظ��ַ��� ��Ӵ� �ĳ��ȡ�

/*��⣺ �������� ���ҳ����в������ظ��ַ����Ӵ���ȡ��������Ӵ�  
*��ʼʱ�����ڳ���Ϊ1�������µ�Ԫ�ض������Ҷˣ��ڲ����ظ���Ԫ�أ�ֻ���ж��ڲ�����Ԫ�������Ҷ˵��ַ���ͬ��
*��������û���ظ���Ԫ��ʱ����������1�����ȣ������ظ�Ԫ��ʱ��������ҿ�����С1�����ȣ�ֱ�������ڲ����ظ���Ԫ�أ����������ţ�
*�����ŵĹ����У���¼���ڵĳ��ȣ��뵱ǰ��󳤶ȱȽϣ����������󳤶�
*/

#include <iostream>
#include <string>

using namespace std;
 
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0; 
        int right = 1; 
        int maxLen = 0;

        int sLen=s.size();  //�ַ���С��2��ֱ�ӷ���
        if (sLen < 2)
            return sLen;

        while (right < sLen)
        {
            int st = left;
            for (int i = st; i<right; i++)  
            {
                if (s[i] == s[right]) 
                {
                    left = i + 1; //������ҿ�����С����
                    break;
                }
            }
            right++;//�������󴰿�
            (right-left > maxLen) ? (maxLen=right-left):maxLen; 
        }
        return maxLen;
    }
};

int  main()
{
	Solution *solution = new Solution();
	cout<<solution->lengthOfLongestSubstring("abcabcbb");
} 

