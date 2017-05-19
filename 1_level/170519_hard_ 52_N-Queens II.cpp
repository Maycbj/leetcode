public class Solution {
    Set<Integer> cols = new HashSet<Integer>();
    Set<Integer> diags1 = new HashSet<Integer>();
    Set<Integer> diags2 = new HashSet<Integer>();
    public int totalNQueens(int n) {
        return recursive(0, n, 0);
    }
    private int recursive(int row, int n, int count){
        for(int i = 0; i < n; i++){
            if(cols.contains(i))    continue;
            int diag1 = i+row;
            int diag2 = i-row;
            if(diags1.contains(diag1))  continue;
            if(diags2.contains(diag2))  continue;
            if(row == n-1)  return ++count;
            cols.add(i);
            diags1.add(diag1);
            diags2.add(diag2);
            count = recursive(row+1, n, count);
            cols.remove(i);
            diags1.remove(diag1);
            diags2.remove(diag2);
        }
        return count;
    }
}