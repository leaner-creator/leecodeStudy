/*
С���������м�������һ����������ˡ���ҶԻ�����˵���������֣����� x �� y������С��˵������ָ�

"A" ���㣺ʹ x = 2 * x + y��
"B" ���㣺ʹ y = 2 * y + x��
�ڱ�����Ϸ�У����˵��������Ϊ x = 1 �� y = 0��С��˵���ļ���ָ��������ɴ�д��ĸ A��B ��ɵ��ַ��� s���ַ������ַ���˳���ʾ����˳���뷵������ x �� y �ĺ�Ϊ���١�

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/nGK0Fy
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

#include <iostream>

using namespace std;
/*
��⣺��������򵥴ֱ����
*/

// class Solution {
// public:
//     int calculate(string s) {
//         for(int i=0;i<s.size();++i)
//         {
//             switch(s[i])
//             {
//                 case 'A':x=2*x+y;
//                         break;
//                 case 'B':y=2*y+x;
//                         break;
//                 default:break;
//             }
//         }
//         return x+y;
//     }
// private:
//     int x=1;
//     int y=0;
// };

/*��⣺
��ֻ��s=��A��ʱ��x+y=2x+y+y=2(x+y)
��ֻ��s="B"ʱ��x+y=2y+x+x=2(x+y)
���ϣ�û����һ���ַ����Ͱ�x+y�ĺ͵�ֵ������
*/
class Solution {
public:
    int calculate(string s) {
        return 1<<s.size();
        }
};
int main()
{
	Solution *solution = new Solution();
	cout<<solution->calculate("AB");

} 

