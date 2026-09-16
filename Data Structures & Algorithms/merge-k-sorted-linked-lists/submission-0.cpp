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
    ListNode* mergeTwoLists(ListNode* l1,ListNode* l2)
    {
        ListNode dummy;
        ListNode* curr=&dummy;
        while(l1 and l2)
        {
            if(l1->val>l2->val)
            {
                curr->next=l2;
                l2=l2->next;
                curr=curr->next;
            }
            else{
                curr->next=l1;
                l1=l1->next;
                curr=curr->next;
            }
        }
        if(l1)
        {
            curr->next=l1;
        }
        if(l2){
            curr->next=l2;
        }
        return dummy.next;
        
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();
        if(n==0)
        {   
            return nullptr;
        }
        
        while(n>1)
        {
            vector<ListNode*> merged;
            for(int i=0;i<n;i=i+2)
            {
                ListNode* temp1=lists[i];
                ListNode* temp2 = (i + 1) < lists.size() ? lists[i + 1] : nullptr;
                merged.push_back(mergeTwoLists(temp1,temp2));
            }
            lists=merged;
            n = lists.size();
        }
        return lists[0] ;

        
        
    }
};
