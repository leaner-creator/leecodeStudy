/*
设计一个函数把两个数字相加。不得使用 + 或者其他算术运算符。
*/

/*
题解：不用运算符，即想到回归运算符的实现原理，即利用位运算，加法运算时，0+0=0；0+1=1 ；1+1=10；抛去进位，式子为：0+0=0；0+1=1 ；1+1=0； 可得   通过异或运算 实现无进位的加法 ；
当有进位时，必然是 1+1 ， 通过与运算 使 1&1=1 ,再将1左移一位，变为 10 ，得到进位的值 ，进位的值与 无进位的和 相加 
直到最后无进位时，式子相当于无进位的加法，便得到两个数的值 
*/

#include <iostream>

using namespace std;

class Solution {
public:
    int add(int a,int b){
        while (b != 0) {
            int sum =a^b;
            auto carry = (unsigned int)(a&b) << 1;
            a = sum;
            b = carry;
        }
        return a;
    }
};
/*使用递归替代循环 
class Solution {
public:
    int add(int a, int b) {
        return b == 0 ? a : add(a^b, (unsigned int)(a&b) << 1);
    }
};
*/
int  main()
{

	Solution *solution = new Solution();
	cout<<solution->add(2,1);
} 
