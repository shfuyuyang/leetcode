/*

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/add-two-numbers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *res=malloc(sizeof(struct ListNode));
    struct ListNode *temp=res;
    temp->val=0;
    temp->next=NULL;
    while(l1!=NULL||l2!=NULL)
    {
        int sum=0;
        if(l1!=NULL)
        {
            sum+=l1->val;
        }
        if(l2!=NULL)
        {
            sum+=l2->val;
        }
        sum=sum+temp->val;
        temp->val=0;
        temp->val+=sum%10;
        if(sum>=10)
        {
            temp->next=malloc(sizeof(struct ListNode));
            temp->next->val=sum/10;
            temp->next->next=NULL;
        }
        if(l1!=NULL)
        {
            l1=l1->next;
        }
        if(l2!=NULL)
        {
            l2=l2->next;
        }
        if((l1!=NULL||l2!=NULL)&&temp->next==NULL)
        {
            temp->next=malloc(sizeof(struct ListNode));
            temp->next->val=0;
            temp->next->next=NULL;
        }
        temp=temp->next;
    }
    return res;
}
