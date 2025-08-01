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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> mp;
        int idx=0;
        int n=inorder.size();
        TreeNode* root=BuildTree(preorder,inorder,0,n-1,idx);
        return root;
    }
    TreeNode* BuildTree(vector<int>&preorder,vector<int>& inorder,int s,int e,int &idx)
    {
        if(s>e) return NULL;
        int rootval=preorder[idx];
        
        int i=s;
        for(;i<=e;i++)
        {
            if(inorder[i]==rootval) break;
        }
        idx++;
        TreeNode* root=new TreeNode(rootval);
        root->left=BuildTree(preorder,inorder,s,i-1,idx);
        root->right=BuildTree(preorder,inorder,i+1,e,idx);
        return root;
    }
};