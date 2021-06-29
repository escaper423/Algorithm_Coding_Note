//problem URL: https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/
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
    int res = 0;
    enum {
        LEFT = 0,
        RIGHT = 1
    };
    
public:
    void solve(TreeNode* root, int prev, int cnt){
        if (!root)    
            return;
        
        if(root->right && prev == LEFT){
            solve(root->right, (prev+1)%2, cnt+1);
        }
        
        if(root->left && prev == LEFT){
            solve(root->left, LEFT, 1);
        }
        
        if(root->left && prev == RIGHT) {
            solve(root->left, (prev+1)%2, cnt+1);
        }
        
        if(root->right && prev == RIGHT){
            solve(root->right, RIGHT, 1);
        }
        
        res = max(cnt,res);
    }
    
    int longestZigZag(TreeNode* root) {
        if (!root)
            return 0;
        
        if (root->left)
            solve(root->left, LEFT , 1);
        
        if (root->right)
            solve(root->right, RIGHT, 1);
        
        return res;
        
    }
};
