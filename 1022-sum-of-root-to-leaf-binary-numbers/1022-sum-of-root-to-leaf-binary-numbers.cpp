/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

int d2b(string a)
{
    int n=a.length();
    int sum=0;
    int p2=1;
    for(int i=n-1;i>=0;i--)
    {
        if(a[i]=='1')
        {
            sum+= p2;
        }
        p2= p2*2;
        
    }
    return sum;
}
    
void dfs(TreeNode* node,string s,vector<string>&v)
    {
        if(node==NULL) return;
        s+=to_string(node->val);
        if(node->left==NULL && node->right==NULL)
        {
            v.push_back(s);
            s="";
            return;
        }
        dfs(node->left,s,v);
        dfs(node->right,s,v);
        return;
    }
    int sumRootToLeaf(TreeNode* root) {
        vector<string> v;
        string s="";
        dfs(root,s,v);
        int sum=0;
        for(int i=0;i<v.size();i++)
        {
            int x=d2b(v[i]);
            sum+=x;
        }
        return sum;
    }
};