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
    ListNode* rotateRight(ListNode* head, int k) {
        int n=0;
        if(head==NULL || head->next==NULL) return head;

        ListNode* temp=head;
        while(temp->next){
            n++;
            temp=temp->next;
        }
        n++;

        k=k%n;
        if(k==0) return head;

        ListNode* temp2=head;
        for(int i=1;i<n-k;i++){
            temp2=temp2->next;
        }

        temp->next=head;
        ListNode* newHead=temp2->next;
        temp2->next=NULL;

        return newHead;


    }
};