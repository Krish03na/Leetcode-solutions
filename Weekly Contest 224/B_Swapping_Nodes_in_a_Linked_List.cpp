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
    int size(ListNode*head){
        int c=0;
        while(head!=NULL){
            c++;
            head=head->next;
        }
        return c;
    }
    ListNode* swapNodes(ListNode* head, int k) {
        int n=size(head);
        int a[n];
        ListNode*temp=head;
        for(int i=0;i<n;i++){
            a[i]=temp->val;
            temp=temp->next;
        }
        swap(a[k-1],a[n-k]);
        temp=head;
        for(int i=0;i<n;i++){
            temp->val=a[i];
            temp=temp->next;
        }
        return head;
    }
};