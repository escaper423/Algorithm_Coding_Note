//problem URL: https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
/**
 * @param {number[][]} matrix
 * @param {number} k
 * @return {number}
 */
var kthSmallest = function(matrix, k) {
    matrix = matrix.flat();
    matrix.sort((a, b) => a - b);
    return matrix[k-1];
};
