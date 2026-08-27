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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* f=head;
        int cnt=0;
        for(int i=0;i<n;i++){
            f=f->next;
        }

        if(f==NULL){
            ListNode* del=head;
            head=head->next;
            delete (del);
            return head;
        }

        ListNode* s=head;
        while(f->next){
            s=s->next;
            f=f->next;
        }

        ListNode* fre=s->next;
        s->next=fre->next;
        delete (fre);
        return head;

    }
};