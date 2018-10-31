class Solution:
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        p=q=head
        while p:
            p=p.next
            if n<0:
                q=q.next
            n-=1
        if n>=0:
            return head.next
        q.next=q.next.next
        return head