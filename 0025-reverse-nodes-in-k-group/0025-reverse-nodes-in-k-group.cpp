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
        if(head==NULL || head->next==NULL) return head;
        ListNode* newHead=reverse(head->next);
        ListNode* front=head->next;
        front->next=head;
        head->next=NULL;
        return newHead;
    }

    ListNode* Kth_Node(ListNode* temp, int k){
        k-=1;
        while(temp!=NULL && k>0){
            k--;
            temp=temp->next;
        }
        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        ListNode* next_node=NULL;
        ListNode* prev_node=NULL;
        while(temp){
            ListNode* KthNode=Kth_Node(temp,k);
            if(KthNode==NULL){
                if(prev_node) prev_node->next=temp;
                break;
            }

            next_node=KthNode->next;
            KthNode->next=NULL;
            ListNode* revHead=reverse(temp);

            if(temp==head) head=revHead;
            else prev_node->next=revHead;

            prev_node=temp;
            temp=next_node;
        }

        return head;
    }

};