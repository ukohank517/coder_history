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
private:
    vector<int> a;
public:
    void cal(TreeNode* root){
        if(root==NULL) return;
        cal(root->left);
        a.push_back(root->val);
        cal(root->right);
    }
    TreeNode* calN(int i){
        if(i == a.size()) return NULL;
        TreeNode* ans = new TreeNode(a[i]);
        ans->right = calN(i + 1);
        return ans;
    }
    TreeNode* increasingBST(TreeNode* root) {
        cal(root);
        return calN(0);
    }
};
