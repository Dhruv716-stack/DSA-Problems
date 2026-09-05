/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*> mp1;
        unordered_map<Node*,Node*> mp2;
        Node* temp=head;
        if(head==NULL) return head;
        while(temp){
            mp1[temp]= temp!=NULL? new Node(temp->val):NULL;
            temp=temp->next;
        }

        temp=head;
        while(temp){
            mp2[temp->random]=mp1[temp->random];
            temp=temp->next;
        }

        Node* DummyNode=new Node(-1);
        Node* curr=DummyNode;
        temp=head;
        while(temp){
            curr->next=mp1[temp];
            if(temp->random!=NULL) curr->next->random= curr->next!=NULL? mp2[temp->random]:NULL;
            else curr->next->random=NULL;
            temp=temp->next;
            curr=curr->next;
        }

        return DummyNode->next;
    }
};