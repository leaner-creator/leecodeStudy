/*
19. 删除链表的倒数第 N 个结点

给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。

进阶：你能尝试使用一趟扫描实现吗？

*/ 

/* 题解：关键点一趟扫描   1、利用list容器存储节点再操作  2、利用快慢双指针
* 1、将将链表节点存入List容器，在容器中寻找到该节点，并记下索引值N ，再将该链表偏移N-1个位置， 得到链表的正数第 N -1个节点，该节点 指向N+1节点 
* 2、首先让 right 指针移动 n+1 次； 然后让 right 和 left 指针一起移动，当 right 移动到为节点时，left 指针指向倒数 第n+1个节点，将该节点指向 n-1节点，即删除倒数第 n节点
*两种方法时间复杂度相同，但是第1种的空间复杂度大 
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
        slow->next = slow->next->next;//删除节点
        return p->next;
    }
};


