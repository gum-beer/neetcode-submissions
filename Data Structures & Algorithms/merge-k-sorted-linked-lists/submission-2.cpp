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
        if(lists.size()==0)
        {
            return{};
        }
        while(lists.size()>1)
        {
            vector<ListNode*> res;
            for(int i=0;i<lists.size();i+=2)
            {
            ListNode* temp1=lists[i];
            ListNode* temp2 = i+1<lists.size() ? lists[i+1] : nullptr;
            res.push_back(mergeTwoLists(temp1,temp2));

            }
            lists=res;
        }
        return lists[0];
        
        
    }
};
