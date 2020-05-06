/**
 * @param {number[]} nums
 * @return {boolean}
 */

 //Problem URL: https://leetcode.com/problems/jump-game/
function helper(nums, targetIdx){
    if (targetIdx == 0)
        return true;
    
    for(let i = targetIdx - 1; i >= 0; i--){
        let canReach = i + nums[i];
        if (canReach >= targetIdx){
            return helper(nums,i);
        }
    }
    return false;
};


var canJump = function(nums) {
    var targetIdxNum= nums.length - 1;
    return helper(nums,targetIdxNum);
};
