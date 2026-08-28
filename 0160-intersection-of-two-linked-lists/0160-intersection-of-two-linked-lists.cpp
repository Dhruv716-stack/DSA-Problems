/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* collison(ListNode* t1, ListNode* t2, int d){
        while(d>0){
            t2=t2->next;
            d--;
        }

        while(t1!=t2){
            t1=t1->next;
            t2=t2->next;
        }
        return t1;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int N1=0,N2=0;
        ListNode* t1=headA;
        ListNode* t2=headB;
        while(t1){
            N1++;
            t1=t1->next;
        }

        while(t2){
            N2++;
            t2=t2->next;
        }

        if(N1>N2){
            return collison(headB,headA,N1-N2);
        }
        else return collison(headA,headB,N2-N1);
        return t1;
    }
};