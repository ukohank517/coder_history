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
    void recoverTree(TreeNode* root) {
        if(root == NULL) return;
        if(root->left != NULL){
            if(root->left->val > root->val) swap(root->left->val, root->val);
            else recoverTree(root->left);
        }
        if(root->right != NULL){
            if(root->right->val < root->val) swap(root->right->val, root->val);
            else recoverTree(root->right);
        }
    }
};
