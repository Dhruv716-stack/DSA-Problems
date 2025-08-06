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
    vector <int>inorder(TreeNode* root,vector<int> &v)
    {
        TreeNode* curr=root;
        while(curr)
        {
            if(curr->left==NULL)
            {
                v.push_back(curr->val);
                curr=curr->right;
            }
            else
            {
                TreeNode* prev=curr->left;
                while(prev->right && prev->right!=curr) prev=prev->right;
                if(prev->right==NULL)
                {
                    prev->right=curr;
                    curr=curr->left;
                }
                else
                {
                    prev->right=NULL;
                    v.push_back(curr->val);
                    curr=curr->right;
                }
            }

        }
        return v;

    }
    bool isValidBST(TreeNode* root) {
        vector<int> v;
        v=inorder(root,v);
        for(int i=0;i<v.size()-1;i++)
        {
            if(v[i]==v[i+1]) return false;
        }
        if(is_sorted(v.begin(),v.end())) return true;
        return false;
    }
};