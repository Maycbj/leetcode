class Solution {
public:
    int search(vector<int>& nums, int target) {
        int from=0, to = nums.size()-1, length = nums.size();
        while(from<to){
            int mid = (from+to) >> 1;
            if(nums[to] < nums[mid]) from = mid + 1;
            else    to = mid;
        }
        int offset = from;
        from=0, to = length - 1;
        while(from<=to){
            int mid = (from+to) >> 1;
            int realmid = (mid+offset)%length;
            if(target == nums[realmid])  return realmid;
            else if(target < nums[realmid]) to = mid - 1;
            else    from = mid + 1;
        }
        return -1;
    }
};