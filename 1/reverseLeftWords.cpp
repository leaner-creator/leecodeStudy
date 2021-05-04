/*
字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。请定义一个函数实现字符串左旋转操作的功能。比如，输入字符串"abcdefg"和数字2，该函数将返回左旋转两位得到的结果"cdefgab"。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/zuo-xuan-zhuan-zi-fu-chuan-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/*	题解: 
    通过翻转0到n-1、n到尾部 这两部分的字符串，得到左旋转字符串的反转字符串，
    再翻转，得到左旋转字符串
    例如s = "abcdefg"  n=2
    1、 s = "ba cdefg" 
    2、 s = "ba gfedc"
    3、 s = "cdefgab"

    也可以通过截取n之前字符串转移到字符串的尾部来实现
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
