public class Solution {
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> res_list = new ArrayList();
        recursive(res_list, new ArrayList<>(), nums);
        return res_list;
    }
    public void recursive(List<List<Integer>> res_list, List<Integer> num_list, int[] nums){
        if(num_list.size() == nums.length){
            res_list.add(new ArrayList(num_list));
        }else{
            for(int i = 0; i < nums.length; i++){
                if(num_list.contains(nums[i])) continue;
                num_list.add(nums[i]);
                recursive(res_list, num_list, nums);
                num_list.remove(num_list.size()-1);
            }
        }
    }
}