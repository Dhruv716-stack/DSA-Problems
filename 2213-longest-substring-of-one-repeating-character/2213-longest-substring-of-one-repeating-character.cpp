#include <bits/stdc++.h>
struct Node{
    int pre=0;
    int suff=0;
    int ml=0;
    char leftChar=0;
    char rightChar=0;
};

class Solution {
public:
   int n;
   vector<Node> segTree;

    Node merged(Node &L,Node &R,int left_len, int right_len){
        Node res;
        res.leftChar=L.leftChar;
        res.rightChar=R.rightChar;

        res.pre=L.pre;
        if(L.pre==left_len && L.rightChar==R.leftChar){
            res.pre=L.pre+R.pre;
        }

        res.suff=R.suff;
        if(R.suff==right_len && L.rightChar==R.leftChar){
            res.suff=R.suff+L.suff;
        }

        res.ml=max(L.ml,R.ml);
        if(L.rightChar==R.leftChar){
            res.ml=max(res.ml,L.suff+R.pre);
        }

        return res;
    }

    void update(int i, int l, int r,int pos, char ch){
        if(l==r){
            segTree[i]={1,1,1,ch,ch};
            return;
        }

        int mid=l+(r-l)/2;
        if(pos<=mid) update(2*i +1,l,mid,pos,ch);
        else update(2*i+2,mid+1,r,pos,ch);

        segTree[i]=merged(segTree[2*i+1],segTree[2*i+2],mid-l+1,r-mid);
        
    }

    void buildSegTree(int i, int l, int r,string &s){
        if(l==r){
            segTree[i]={1,1,1,s[l],s[l]};
            return;
        }

        int mid=l+(r-l)/2;

        buildSegTree(2*i+1,l,mid,s);
        buildSegTree(2*i+2,mid+1,r,s);
        int left_len=mid-l+1;
        int right_len=r-mid;
        segTree[i]=merged(segTree[2*i+1],segTree[2*i+2],left_len,right_len);
    }
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int k=queryIndices.size();
        n=s.size();
        vector<int> ans;
        segTree.assign(4*n,Node());
        buildSegTree(0,0,n-1,s);
        for(int i=0;i<k;i++){
            int pos=queryIndices[i];
            char ch=queryCharacters[i];
            update(0,0,n-1,pos,ch);
            ans.push_back(segTree[0].ml);
        }

        return ans;
    }
};