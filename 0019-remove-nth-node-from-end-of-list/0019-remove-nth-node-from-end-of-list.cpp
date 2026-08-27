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
        int N=0;
        ListNode* temp=head;
        if(head==NULL || head->next==NULL) return NULL;
        while(temp){
            N++;
            temp=temp->next;
        }

        if(N-n==0){
            ListNode* del=head;
            head=head->next;
            delete (del);
            return head;
        }

        int cnt=0;
        temp=head;
        while(temp){
            cnt++;
            if(cnt==N-n){
                ListNode* del=temp->next;
                temp->next=del->next;
                delete del;
                return head;
            }
            temp=temp->next;
        }

        return head;
    }
};