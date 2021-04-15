/**
 * @param {number[]} A
 * @return {number}
 */
var minScoreTriangulation = function(A) {
    
    var dp = Array(50).fill(0).map(x => Array(50).fill(0));
    for(let i = A.length - 1; i >= 0; --i){
        for (let j = i+1; j < A.length; j++){
            for (let k = i+1; k < j; k++){
                dp[i][j] = Math.min((dp[i][j] == 0 || undefined)?Infinity:dp[i][j],dp[i][k] + A[i] * A[j] * A[k] + dp[k][j]);
            }
        }
    }
    return dp[0][A.length - 1];
};

//Reference: https://leetcode.com/problems/minimum-score-triangulation-of-polygon/discuss/286753/C%2B%2B-with-picture