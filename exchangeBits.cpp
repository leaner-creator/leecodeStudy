/*
��Խ�������д���򣬽���ĳ������������λ��ż��λ������ʹ�ý��ٵ�ָ�Ҳ����˵��λ0��λ1������λ2��λ3�������Դ����ƣ���
��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/exchange-lcci/
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

/*��⣺ 
    num=2  0010
    0010 & 0101 ->0000 <<1 ->0000 ��������λ��ֵ ����λ��ż��λ�ƶ�
    0010 & 1010 ->0010 >>1 ->0001   ����ż��λ��ֵ ż��λ������λ�ƶ�
    0000|0001       �ϲ�����λ��ż��λ 
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
