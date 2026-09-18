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
    ListNode* getKth(ListNode* curr,int k)
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
        ListNode* prevGroupLE =&dummy;
        while(true)
        {
            ListNode* kthNode=getKth(prevGroupLE,k);
            if(kthNode==nullptr)
            {
                break ;
            }
            ListNode* nextGroupFE=kthNode->next;
            ListNode* prev=nextGroupFE;
            ListNode* curr=prevGroupLE->next;
            while(curr!=nextGroupFE)
            {
                ListNode* temp=curr->next;                
                curr->next=prev;
                prev=curr;
                curr=temp;
            }
            ListNode* temp=prevGroupLE->next;
            prevGroupLE->next=kthNode;
            prevGroupLE=temp;


        }
        return dummy.next;
        
    }
};
