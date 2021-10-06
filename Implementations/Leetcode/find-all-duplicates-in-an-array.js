//problem URL: https://leetcode.com/problems/find-all-duplicates-in-an-array/
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var findDuplicates = function(nums) {
    let mp = {}
    let res = []
    for(let l of nums){
        if(!mp[l]){
            mp[l] = 1
        }
        else{
            mp[l]++
        }
    }
    
    for(let [k, v] of Object.entries(mp)){
        if (v >= 2){
            res.push(k)
        }
    }
    
    return res
};
