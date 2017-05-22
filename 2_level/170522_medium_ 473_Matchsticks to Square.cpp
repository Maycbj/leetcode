public class Solution {
    public boolean makesquare(int[] nums) {
        if(nums == null || nums.length < 4) return false;
        int sum=0;
        for(int i=0; i<nums.length; i++)  sum += nums[i];  
        if(sum%4 != 0)  return false;
        return dfs(nums, new int[4], 0, sum/4);
    }
    private boolean dfs(int[] nums, int[] sums, int ind, int target){
        if(ind == nums.length){
            if(sums[0] != target || sums[1] != target ||sums[2] != target) return false;
            else    return true;
        }
        for(int i=0; i<4; i++){
            if(sums[i]+nums[ind] > target)    continue;
            sums[i] += nums[ind];
            if(dfs(nums, sums, ind+1, target))    return true;
            sums[i] -= nums[ind];
        }
        return false;
    }
}