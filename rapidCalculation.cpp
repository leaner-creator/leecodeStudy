/*
小扣在秋日市集发现了一款速算机器人。店家对机器人说出两个数字（记作 x 和 y），请小扣说出计算指令：

"A" 运算：使 x = 2 * x + y；
"B" 运算：使 y = 2 * y + x。
在本次游戏中，店家说出的数字为 x = 1 和 y = 0，小扣说出的计算指令记作仅由大写字母 A、B 组成的字符串 s，字符串中字符的顺序表示计算顺序，请返回最终 x 与 y 的和为多少。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/nGK0Fy
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>

using namespace std;
/*
题解：按照题意简单粗暴解决
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

/*题解：
当只有s=“A”时：x+y=2x+y+y=2(x+y)
当只有s="B"时：x+y=2y+x+x=2(x+y)
综上，没出现一个字符，就把x+y的和的值翻倍；
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

