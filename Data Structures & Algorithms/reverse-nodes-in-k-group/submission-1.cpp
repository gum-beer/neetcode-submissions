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
private:
ListNode* getKth(ListNode* curr, int k)
{
    while(curr and k)
    {
        curr=curr->next;
        k--;
    }
    return curr;

}
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0,head);
        ListNode* groupPrev=&dummy;

        while(true)
        {
            ListNode* kthNode=getKth(groupPrev,k);
            if(kthNode==nullptr)
            {
                break;
            }
            ListNode* groupNext=kthNode->next;

            //reverse begins
            ListNode* prev=groupNext;//this is fucking mental
            ListNode* curr= groupPrev->next;
            while(curr!= groupNext)
            {
                ListNode* temp = curr->next;
                curr->next=prev;
                prev=curr;
                curr=temp;
            }
            ListNode* temp=groupPrev->next;
            groupPrev->next=kthNode;
            groupPrev=temp;

        }
return dummy.next;

    }
};
