class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int ze = 0, tmp = 0;
        int length = nums.size();
        for(int i= 0; i < length; i++){
            ze = i;
            while(nums[ze]==0 && ze<length)   ze++;
            if(ze >= length)    break;
            tmp = nums[ze];
            nums[ze] = nums[i];
            nums[i] = tmp;
        }
    }
};