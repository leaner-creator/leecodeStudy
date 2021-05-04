/*
配对交换。编写程序，交换某个整数的奇数位和偶数位，尽量使用较少的指令（也就是说，位0与位1交换，位2与位3交换，以此类推）。
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/exchange-lcci/
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/*题解： 
    num=2  0010
    0010 & 0101 ->0000 <<1 ->0000 保留奇数位的值 奇数位往偶数位移动
    0010 & 1010 ->0010 >>1 ->0001   保留偶数位的值 偶数位往奇数位移动
    0000|0001       合并奇数位和偶数位 
*/
#include <iostream>

class Solution {
public:
    int exchangeBits(int num) {
        return ((num & 0x55555555)<<1)|((num & 0xaaaaaaaa)>>1);
    }
};

int main()
{
	Solution *solution = new Solution();
	std::cout<<solution->exchangeBits(2);
} 
