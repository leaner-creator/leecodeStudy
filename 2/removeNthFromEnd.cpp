/*
19. ɾ������ĵ����� N �����

����һ������ɾ������ĵ����� n ����㣬���ҷ��������ͷ��㡣

���ף����ܳ���ʹ��һ��ɨ��ʵ����

*/ 

/* ��⣺�ؼ���һ��ɨ��   1������list�����洢�ڵ��ٲ���  2�����ÿ���˫ָ��
* 1����������ڵ����List��������������Ѱ�ҵ��ýڵ㣬����������ֵN ���ٽ�������ƫ��N-1��λ�ã� �õ������������ N -1���ڵ㣬�ýڵ� ָ��N+1�ڵ� 
* 2�������� right ָ���ƶ� n+1 �Σ� Ȼ���� right �� left ָ��һ���ƶ����� right �ƶ���Ϊ�ڵ�ʱ��left ָ��ָ���� ��n+1���ڵ㣬���ýڵ�ָ�� n-1�ڵ㣬��ɾ�������� n�ڵ�
*���ַ���ʱ�临�Ӷ���ͬ�����ǵ�1�ֵĿռ临�Ӷȴ� 
*/
#include <iostream>

//Definition for singly-linked list.
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };
 

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* p = new ListNode(0);
        p->next = head;
        ListNode* slow = p;
        ListNode* fast = p;
        n=n+1;
        while(n-- && fast != NULL) {
            fast = fast->next;
        }

        while (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;//ɾ���ڵ�
        return p->next;
    }
};


