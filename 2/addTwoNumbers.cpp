/*
2. �������

�������� �ǿ� ��������ʾ�����Ǹ�������������ÿλ���ֶ��ǰ��� ���� �ķ�ʽ�洢�ģ�����ÿ���ڵ�ֻ�ܴ洢 һλ ���֡�

���㽫��������ӣ�������ͬ��ʽ����һ����ʾ�͵�����

����Լ���������� 0 ֮�⣬���������������� 0 ��ͷ��
*/

/*��⣺ ����Ͳ��üӷ��������������ӵ�������ƣ��Ȳ����ǽ�λ���������λ����һ�ڵ�һ����� 
* ���ְ��������������Ӧ�ӷ��Ӹ�λ��ʼ�����������б��Ӧ�ĵ�λ�ĺ�sumsum��sum % 10 ->����ֻȡ��λ��ֵ��
*����sum /= 10��ý�λֵ�����´εĸ�λһ����㡣
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode tmpList(0);
        ListNode *p = &tmpList;
        int sum = 0;
        while (l1 || l2 || sum)//��ʽֱ��������l1��l2��  sum Ŀ�����ڼ������λ�н�λ�����
        {
            if (l1) 
            {
                sum += l1->val;
                l1 = l1->next;  
            }
            if (l2) 
            {
                sum += l2->val;
                l2 = l2->next; 
            }
            p->next= new ListNode(sum % 10);
            p = p->next ;
            sum /= 10;
        }
        return tmpList.next;
    }
};

