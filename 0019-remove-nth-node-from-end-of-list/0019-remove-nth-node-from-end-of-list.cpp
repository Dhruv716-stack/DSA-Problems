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
        if(head==NULL || head->next==NULL) return NULL;

        if(n==1){
            ListNode* t=head;
            while(t->next!=NULL && t->next->next!=NULL){
                t=t->next;
            }

            ListNode* del=t->next;
            t->next=NULL;
            delete(del);
            return head;
        }


        ListNode* temp=head;
        int N=0;
        while(temp){
            N++;
            temp=temp->next;
        }

        if(N-n==0){
            ListNode* del=head;
            head=head->next;
            delete(del);
            return head;
        }


        temp=head;
        int cnt=0;
        while(temp){
            cnt++;
            if(cnt==N-n){
                ListNode* del=temp->next;
                temp->next=temp->next->next;
                delete(del);
                return head;
            }
            temp=temp->next;
        }

        return head;
    }
};