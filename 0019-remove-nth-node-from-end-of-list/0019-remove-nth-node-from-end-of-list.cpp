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
    int length(ListNode* head)
    {
        int cnt=0;
        ListNode* temp=head;
        while(temp)
        {
            cnt++;
            temp=temp->next;
        }
        return cnt;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len=length(head);
        int k=len-n;
        k++;
        cout<<len<<" "<<k<<endl;
        if(head==nullptr) return head;
        if(k==1)
        {
            ListNode* temp_h=head;
            head=head->next;
            delete(temp_h);
            return head;
        }

        ListNode*temp=head;
        int cnt=0;
        while(temp)
        {
            cnt++;
            if(cnt==k-1)
            {
                ListNode* temp2=temp->next;
                temp->next=temp->next->next;
                delete(temp2);
                break;
            }
            temp=temp->next;
        }
        return head;
    }
};