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
 
 //problem URL: https://leetcode.com/problems/all-elements-in-two-binary-search-trees/
class Solution {
private:
    vector<int> res;
public:
    void insertNodeValues(TreeNode *root){
        if (!root)
            return;
        
        insertNodeValues(root->left);
        res.push_back(root->val);
        insertNodeValues(root->right);
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        insertNodeValues(root1);
        insertNodeValues(root2);
        sort(res.begin(), res.end());
        return res;
    }
};
