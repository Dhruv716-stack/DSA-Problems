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

    TreeNode* solve(vector<int>&inorder, vector<int>&postorder,int inStart,int inEnd,int poStart,int poEnd,unordered_map<int,int>&mp)
    {
        if(inStart>inEnd ||poStart>poEnd) return NULL;
        int rootVal=postorder[poEnd];
        int i=mp[rootVal];
        int left_size=i-inStart;
        int right_size=inEnd-i;
        TreeNode* root=new TreeNode(rootVal);
        root->left=solve(inorder,postorder,inStart,i-1,poStart,poStart+left_size-1,mp);
        root->right=solve(inorder,postorder,i+1,inEnd,poEnd-right_size,poEnd-1,mp);
        return root;

    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> mp;
        int n=inorder.size();
        int m=postorder.size();
        for(int i=0;i<n;i++)
        {
            mp[inorder[i]]=i;
        }
        TreeNode* root=solve(inorder,postorder,0,n-1,0,m-1,mp);
        return root;

    }
};