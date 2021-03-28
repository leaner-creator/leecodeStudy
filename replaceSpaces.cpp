/*
URL化。编写一种方法，将字符串中的空格全部替换为%20。假定该字符串尾部有足够的空间存放新增字符，并且知道字符串的“真实”长度。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/string-to-url-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

//题解：根据 length 控制输入字符串的真实长度 ，替换字符串真实长度内的空格 
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
