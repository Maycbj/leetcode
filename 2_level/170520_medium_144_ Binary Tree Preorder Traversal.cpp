/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
############################
Solution 1
############################
public class Solution {
    List<Integer> res = new ArrayList<Integer>();
    public List<Integer> preorderTraversal(TreeNode root) {
        preorder(root);
        return res;
    }
    private void preorder(TreeNode root){
        if(root == null)    return;
        res.add(root.val);
        if(root.left != null)   preorder(root.left);
        if(root.right != null)   preorder(root.right);
    }
}

############################
Solution 2
############################
public class Solution {
    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer> res = new ArrayList<Integer>();
        if(root == null)    return res;
        res.add(root.val);
        res.addAll(preorderTraversal(root.left));
        res.addAll(preorderTraversal(root.right));
        return res;
    }
}