/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode* >q;
        string s="";
        q.push(root);
        while(!q.empty())
        {
            TreeNode* curr=q.front();
            q.pop();
            if(curr==NULL) s.append("#,");
            else
            {
                s.append(to_string(curr->val)+',');
            }
            if(curr!=NULL)
            {
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        cout<<s;
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
    if (data.empty()) return NULL;

    stringstream s(data);
    string str;
    getline(s, str, ',');
    if (str.empty() || str == "#") return NULL; 

    TreeNode* root = new TreeNode(stoi(str));
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        // Left
        if (getline(s, str, ',')) {
            if (str == "#" || str.empty()) node->left = NULL;
            else {
                TreeNode* leftnode = new TreeNode(stoi(str));
                node->left = leftnode;
                q.push(leftnode);
            }
        }

        // Right
        if (getline(s, str, ',')) {
            if (str == "#" || str.empty()) node->right = NULL;
            else {
                TreeNode* rightnode = new TreeNode(stoi(str));
                node->right = rightnode;
                q.push(rightnode);
            }
        }
    }
    return root;
}

    
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));