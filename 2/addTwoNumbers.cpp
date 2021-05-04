/*
2. 两数相加

给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。

请你将两个数相加，并以相同形式返回一个表示和的链表。

你可以假设除了数字 0 之外，这两个数都不会以 0 开头。
*/

/*题解： 该题和不用加法运算符求两数相加的情况相似，先不考虑进位情况，将进位和下一节点一起计算 
* 数字按逆序存于链表，对应加法从个位开始，计算两个列表对应的低位的和sumsum，sum % 10 ->求余只取个位的值，
*利用sum /= 10求得进位值，与下次的高位一起计算。
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
        while (l1 || l2 || sum)//算式直到访问完l1、l2。  sum 目的在于计算最高位有进位的情况
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

