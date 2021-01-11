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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL) return NULL;
        if(head->next==NULL) return head;
        if(head->val!=head->next->val){
            head->next=deleteDuplicates(head->next);
            return head;
        }else{
            //1 1
            //
            while(head->next!=NULL && head->val==head->next->val){
                head=head->next;
            }
            if(head->next==NULL) return NULL;
            return deleteDuplicates(head->next);
        }
    }
};