/*
换成小写字母
实现函数 ToLowerCase()，该函数接收一个字符串参数 str，并将该字符串中的大写字母转换成小写字母，之后返回新的字符串。
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/to-lower-case
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/ 


/*
	题解 ：遍历string的每个字符，判断若为 大写字母，则根据ascall码值来处理， 大写转换小写为其  ascall码值-32 
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

