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
    vector<int> ans;
public:
    void cal(TreeNode* root){
        if(root == NULL) return;
        ans.push_back(root->val);
        cal(root->left);
        cal(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        cal(root);
        
        sort(ans.begin(), ans.end());
        return ans[k-1];
    }
};
