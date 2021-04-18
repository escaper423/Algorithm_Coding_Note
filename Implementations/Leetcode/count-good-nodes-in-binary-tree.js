/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */
//problem URL: https://leetcode.com/problems/count-good-nodes-in-binary-tree/
function goodNode(root, v){
    if (root == null)
        return 0;
    
    return (root.val >= v) +
        goodNode(root.left, Math.max(root.val,v)) +
        goodNode(root.right, Math.max(root.val,v));
        
}

var goodNodes = function(root) {
    return goodNode(root, root.val);
};
