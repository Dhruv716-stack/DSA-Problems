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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* node=new TreeNode(val);
        if(root==NULL) return node;
        TreeNode* temp=root;
        TreeNode* temp2=NULL;
        while(temp)
        {
            if(temp->val >val)
            {
                if(temp->left) temp=temp->left;
                else
                {
                    temp->left=node;
                    break;
                    //temp=temp->left;
                }
            }
            else
            {
                if(temp->right) temp=temp->right;
                else
                {
                    temp->right=node;
                    break;
                    //temp=temp->right;
                }
            }
            //temp=temp->left;
            //temp=temp->right;
        }
        return root; 
    }
};