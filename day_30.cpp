// Validate a BST leetcode using recursion

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, NULL, NULL);
    }
    
    bool isValidBST(TreeNode* root, TreeNode* minNode, TreeNode* maxNode) 
    {
        if(root == NULL) 
            return true;
        if(minNode != NULL && root->val <= minNode->val) 
            return false;
        if(maxNode != NULL && root->val >= maxNode->val) 
            return false;
        return isValidBST(root->left, minNode, root) && isValidBST(root->right, root, maxNode);
    }
};