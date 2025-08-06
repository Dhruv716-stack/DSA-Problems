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
    int cnt=0;
    void inorder(TreeNode* root,int &k,int &ans)
    {
        if(root==NULL) return;
        if(root->left) inorder(root->left,k,ans);
        cnt++;
        if(cnt==k) {ans=root->val;
        return;}
        if(root->right) inorder(root->right,k,ans);
        return;
    }
    
    int kthSmallest(TreeNode* root, int k) {
       if(root==NULL) return 0;
       int ans=0;
       inorder(root,k,ans);
       return ans;
    }
};