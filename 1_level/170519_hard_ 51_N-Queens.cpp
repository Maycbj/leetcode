public class Solution {
    Stack<Integer> cols = new Stack<Integer>();
    Set<Integer> diags1 = new HashSet<Integer>();
    Set<Integer> diags2 = new HashSet<Integer>();
    List<List<String>> res = new ArrayList<List<String>>();
    public List<List<String>> solveNQueens(int n) {
        recursive(0, n);
        return res;
    }
    private void recursive(int row, int n){
        if(row == n)  
            draw(n);
        for(int i = 0; i < n; i++){
            int diag1 = i+row, diag2 = i-row;
            if(!cols.contains(i) && !diags1.contains(diag1) && !diags2.contains(diag2)){
                cols.push(i);
                diags1.add(diag1);
                diags2.add(diag2);
                recursive(row+1, n);
                cols.pop();
                diags1.remove(diag1);
                diags2.remove(diag2);
            }
        }
    }
    private void draw(int n){
        List<String> res_tmp = new ArrayList<String>();
        for(int i = 0 ;i < n; i++){
            String str_tmp = new String();
            int col = cols.get(i);
            for(int j = 0; j < n; j++){
                if(j == col){
                    str_tmp += 'Q';
                }else{
                    str_tmp += '.';
                }
            }
            res_tmp.add(str_tmp);
        }
        res.add(res_tmp);
    }
}


Solution 2: