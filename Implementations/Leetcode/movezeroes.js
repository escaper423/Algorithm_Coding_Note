/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */

//Problem URL: https://leetcode.com/problems/move-zeroes/
var moveZeroes = function(nums) {
    let i = 0;
    var numzero = 0;
    for (i = 0; i < nums.length; i++){
        if(nums[i] == 0){
            nums.splice(i,1);
            i--;
            numzero++;
        }
    }
    for(let n = 0; n < numzero; n++){
        nums.push(0);
    }
};