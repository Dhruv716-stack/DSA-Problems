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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        unordered_map<int,int> mp;
        vector<int> v=preorder;
        sort(v.begin(),v.end());
        int n=preorder.size();
        for(int i=0;i<n;i++)
        {
            mp[v[i]]=i;
        }
        TreeNode* root=buildtree(preorder,0,n-1,v,0,n-1,mp);
        return root;


    }
    TreeNode* buildtree(vector<int>&preorder,int ps,int pe, vector<int>&v,int vs,int ve,unordered_map<int,int>&mp)
    {
        if(ps>pe || vs>ve) return NULL;
        TreeNode* root=new TreeNode(preorder[ps]);
        int inR=mp[root->val];
        int num_left=inR-vs;
        root->left=buildtree(preorder,ps+1,ps+num_left,v,vs,inR-1,mp);
        root->right=buildtree(preorder,ps+num_left+1,pe,v,inR+1,ve,mp);
        return root;

    }
    
};