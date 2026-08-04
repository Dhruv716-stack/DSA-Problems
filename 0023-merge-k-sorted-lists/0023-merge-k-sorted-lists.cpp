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
    ListNode* merge_two_lists(ListNode* l1, ListNode* l2){
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        if(l1->val<=l2->val){
            l1->next=merge_two_lists(l1->next,l2);
            return l1;
        }
        else{
            l2->next=merge_two_lists(l1,l2->next);
            return l2;
        }
    }

    ListNode* partition_and_merge(vector<ListNode*> &lists,int s, int e){
        int n=lists.size();
        int mid=s+(e-s)/2;
        if(s==e) return lists[s]==NULL?NULL:lists[s];
        ListNode* l1=partition_and_merge(lists,s,mid);
        ListNode* l2=partition_and_merge(lists,mid+1,e);
        return merge_two_lists(l1,l2);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();
        if(n==0) return NULL;
        return partition_and_merge(lists,0,n-1);
    }
};