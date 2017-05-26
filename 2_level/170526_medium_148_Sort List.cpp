/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode sortList(ListNode head) {
        if(head==null || head.next==null)   return head;
        ListNode pre=null, slow=head, fast=head;
        while(fast!=null && fast.next!=null){
            pre = slow;
            slow = slow.next;
            fast = fast.next.next;
        }
        pre.next = null;
        ListNode node1 = sortList(head);
        ListNode node2 = sortList(slow);
        
        return merge(node1, node2);
    }
    private ListNode merge(ListNode head1, ListNode head2){
        ListNode head = new ListNode(0), tmp = head;
        while(head1!=null && head2!=null){
            if(head1.val < head2.val){
                tmp.next = head1;
                head1 = head1.next;
            }else{
                tmp.next = head2;
                head2 = head2.next;
            }
            tmp = tmp.next;
        }
        if(head1!=null) tmp.next=head1;
        if(head2!=null) tmp.next=head2;
        return head.next;
    }
}