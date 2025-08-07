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
    vector<int> inorder(TreeNode* root,vector<int> &v)
    {
        if(root==NULL) return v;
        if(root->left) inorder(root->left,v);
        v.push_back(root->val);
        if(root->right) inorder(root->right,v);
        return v;
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> v;
        v=inorder(root,v);
        int n=v.size();
        int i=0,j=n-1;
        while(i<j)
        {
            if(v[i]+v[j]>k) j--;
            else if(v[i]+v[j]<k) i++;
            else return true;
        }
        return false;

    }
};