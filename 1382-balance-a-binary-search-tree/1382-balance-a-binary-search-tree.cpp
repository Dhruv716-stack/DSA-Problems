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
    void inorder(TreeNode* root,vector<int> &v)
    {
        if(root==nullptr) return;
        if(root->left) inorder(root->left,v);
        v.push_back(root->val);
        if(root->right) inorder(root->right,v);
        return;
    }
    TreeNode* bst(int l, int r,vector<int>&v)
    {
        int n=v.size();
        if(l>r) return NULL;
        int mid=l+(r-l)/2;
        TreeNode* root=new TreeNode(v[mid]);
        root->left=bst(l,mid-1,v);
        root->right=bst(mid+1,r,v);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> v;
        inorder(root,v);
        int n=v.size();
        return bst(0,n-1,v);
    }
};