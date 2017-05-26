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
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        int len = inorder.length;
        return recursive(inorder, postorder, 0, len-1, 0, len-1);
    }
    private TreeNode recursive(int[] inorder, int[] postorder, int is, int ie, int ps, int pe){
        if(ps > pe) return null;
        int pos = ie;
        while(inorder[pos] != postorder[pe])    pos--;
        TreeNode root = new TreeNode(postorder[pe]);
        root.left = recursive(inorder, postorder, is, pos-1, ps, ps+pos-is-1);
        root.right = recursive(inorder, postorder, pos+1, ie, ps+pos-is, pe-1);
        return root;
    }
}