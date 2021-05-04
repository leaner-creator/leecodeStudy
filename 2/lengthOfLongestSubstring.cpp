//给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

/*题解： 根据题意 ，找出所有不含有重复字符的子串，取长度最长的子串  
*开始时，窗口长度为1，由于新的元素都在最右端，内部无重复的元素，只需判断内部有无元素与最右端的字符相同，
*当窗口里没有重复的元素时，向右增大1个长度；当有重复元素时，左边向右靠近缩小1个长度，直到窗口内部无重复的元素，再向右扩张；
*在扩张的过程中，记录窗口的长度，与当前最大长度比较，获得最终最大长度
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

        int sLen=s.size();  //字符串小于2，直接返回
        if (sLen < 2)
            return sLen;

        while (right < sLen)
        {
            int st = left;
            for (int i = st; i<right; i++)  
            {
                if (s[i] == s[right]) 
                {
                    left = i + 1; //左边向右靠近缩小窗口
                    break;
                }
            }
            right++;//往右增大窗口
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

