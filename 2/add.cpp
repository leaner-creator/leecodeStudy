/*
���һ������������������ӡ�����ʹ�� + �������������������
*/

/*
��⣺��������������뵽�ع��������ʵ��ԭ��������λ���㣬�ӷ�����ʱ��0+0=0��0+1=1 ��1+1=10����ȥ��λ��ʽ��Ϊ��0+0=0��0+1=1 ��1+1=0�� �ɵ�   ͨ��������� ʵ���޽�λ�ļӷ� ��
���н�λʱ����Ȼ�� 1+1 �� ͨ�������� ʹ 1&1=1 ,�ٽ�1����һλ����Ϊ 10 ���õ���λ��ֵ ����λ��ֵ�� �޽�λ�ĺ� ��� 
ֱ������޽�λʱ��ʽ���൱���޽�λ�ļӷ�����õ���������ֵ 
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
/*ʹ�õݹ����ѭ�� 
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
