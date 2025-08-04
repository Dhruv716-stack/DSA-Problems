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
void parent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& mp) {
    if (root == NULL) return;
    if (root->left) mp[root->left] = root;
    parent(root->left, mp);
    if (root->right) mp[root->right] = root;
    parent(root->right, mp);
}

TreeNode* deleteNode(TreeNode* root, int key) {
    if (root == NULL) return NULL;

    unordered_map<TreeNode*, TreeNode*> mp;
    parent(root, mp);

    TreeNode* temp = root;
    while (temp) {
        if (temp->val == key) break;
        else if (temp->val > key) temp = temp->left;
        else temp = temp->right;
    }

    if (temp == NULL) return root;  // Key not found

    TreeNode* leftSub = temp->left;
    TreeNode* rightSub = temp->right;

    // Case 1: Node is root
    if (temp == root) {
        if (!rightSub) {
            delete root;
            return leftSub;
        }
        TreeNode* minRight = rightSub;
        while (minRight->left) minRight = minRight->left;
        minRight->left = leftSub;
        delete root;
        return rightSub;
    }

    TreeNode* par = mp[temp];

    
    if (!rightSub) {
        if (par->left == temp) par->left = leftSub;
        else par->right = leftSub;
        delete temp;
        return root;
    }

    
    if (par->left == temp) par->left = rightSub;
    else par->right = rightSub;

    TreeNode* minRight = rightSub;
    while (minRight->left) minRight = minRight->left;
    minRight->left = leftSub;

    delete temp;
    return root;
}

};