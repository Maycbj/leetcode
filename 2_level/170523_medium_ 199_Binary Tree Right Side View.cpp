/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    public List<Integer> rightSideView(TreeNode root) {
        List<Integer> res = new ArrayList<Integer>();
        levelOrder(root, res, 0);
        return res;
    }
    private void levelOrder(TreeNode curr, List<Integer> res, int currDepth){
        if(curr == null)    return;
        if(res.size() == currDepth) res.add(curr.val);
        levelOrder(curr.right, res, currDepth+1);
        levelOrder(curr.left, res, currDepth+1);
    }
}