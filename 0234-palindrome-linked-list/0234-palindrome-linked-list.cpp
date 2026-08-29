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
    ListNode* reverse(ListNode* head){
        ListNode* prev=NULL;
        ListNode* curr=head;
        if(head==NULL || head->next==NULL) return head;
        while(curr){
            ListNode* nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt; 
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* mid=NULL;
        ListNode* s=head;
        ListNode* f=head;
        while(f!=NULL && f->next!=NULL){
            s=s->next;
            f=f->next->next;
        }

        mid=s;
        ListNode* revHead=reverse(mid);
        ListNode* first=head;
        ListNode* sec=revHead;
        while(first!=NULL && sec!=NULL){
            if(first->val!=sec->val) return false;
            first=first->next;
            sec=sec->next;
        }

        return true;
    }
};