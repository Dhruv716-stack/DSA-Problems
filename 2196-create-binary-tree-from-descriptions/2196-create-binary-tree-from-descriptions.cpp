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
    TreeNode* createBinaryTree(vector<vector<int>>& desc) {
        unordered_map<int,TreeNode*> mp;
        for(auto &it:desc)
        {
            int p=it[0];
            int c=it[1];
            int isLeft=it[2];
            if(mp.find(p)==mp.end())
            {
                TreeNode* node=new TreeNode(p);
                mp[p]=node;
            }

            if(mp.find(c)==mp.end())
            {
                TreeNode* node=new TreeNode(c);
                mp[c]=node;
            }

            TreeNode* node_p=mp[p];
            TreeNode* node_c=mp[c];

            if(isLeft==1)
            {
                node_p->left=node_c;
                mp[p]=node_p;
            }
            else{
                node_p->right=node_c;
                mp[p]=node_p;
            } 
        }

        int root=-1;
        for(auto &it:mp)
        {
            bool flag=false;
            int cnt=0;
            int p=it.first;
            for(int i=0;i<desc.size();i++)
            {
                if(p!=desc[i][1]) cnt++;
            }
            if(cnt==desc.size())
            {
                root=p;
                break;
            }
        }

        return mp[root];

        
    }
};