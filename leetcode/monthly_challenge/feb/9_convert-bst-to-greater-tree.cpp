#include <iostream>
using namespace std;
/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int now = 0;
    TreeNode* convertBST(TreeNode* root) {
        if(root == NULL){
            return NULL;
        }
        root->right = convertBST(root->right);
        now += root->val;
        root->val = now;
        root->left = convertBST(root->left);
        return root;
    }
};