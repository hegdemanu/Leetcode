/**
 * @param {number[]} nums
 * @return {boolean}
 */
let check = function(nums) {
    let cnt = 0;
    let n = nums.length;
    if(nums[n - 1] > nums[0]) cnt++;
    for(let i = 1 ; i < n; i++){
        if (nums[i] < nums[i - 1]) cnt++;
        if(cnt > 1) break;
    }
    return cnt <= 1;
};