########################
Solution 1: dfs(超时)
########################
public class Solution {
    public boolean canCross(int[] stones) {
        if(stones==null)    return false;
        return dfs(stones, 0, 0);
    }
    private boolean dfs(int[] stones, int ind, int step){
        if(ind == stones.length-1)  return true;
        for(int i=ind+1; i<stones.length; i++){
            if(stones[i]-stones[ind] < step-1)  continue;
            if(stones[i]-stones[ind] > step+1)  return false;
            // System.out.println(i+"  "+(stones[i]-stones[ind]));
            if(dfs(stones, i, stones[i]-stones[ind]))   return true;
        }
        return false;
    }
}

########################
Solution 2: 有记录的dfs
########################
public class Solution {
    public boolean canCross(int[] stones) {
        if(stones.length == 0)  return true;
        Map<Integer, HashSet<Integer>> map = new HashMap();
        map.put(0, new HashSet<Integer>());
        map.get(0).add(1);
        for(int i=1; i<stones.length-1; i++){
            map.put(stones[i], new HashSet<Integer>());
        }
        for(int i=0; i<stones.length-1; i++){
            int stone = stones[i];
            for(int step : map.get(stone)){
                int reach = stone+step;
                if(reach == stones[stones.length-1])    return true;
                HashSet<Integer> set = map.get(reach);
                if(set != null){
                    if(step > 1)  set.add(step-1);
                    set.add(step);
                    set.add(step+1);
                }
            }
        }
        return false;
    }
}