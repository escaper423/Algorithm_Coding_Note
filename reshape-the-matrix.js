//problem URL: https://leetcode.com/problems/reshape-the-matrix/
/**
 * @param {number[][]} mat
 * @param {number} r
 * @param {number} c
 * @return {number[][]}
 */
var matrixReshape = function(mat, r, c) {
    let row = mat.length;
    let col = mat[0].length;
    
    if (r * c != row * col)
        return mat;
    
    let arr = [];
    mat = mat.flat();
    
    while(mat.length){
        arr.push(mat.splice(0,c));
    }
    return arr;
};
