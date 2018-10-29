class Solution:
    
    def findkth(self,k,a,b):
        import math
        lena=len(a)
        lenb=len(b)
        if (lena>lenb):
            return self.findkth(k,b,a)
        if (lena==0):
            return b[k-1]
        if (lenb==0):
            return a[k-1]
        if k==1:
            return min(a[0],b[0])
        pa=min(k//2,lena)
        pb=k-pa
        if a[pa-1]<b[pb-1]:
            return self.findkth(pb,a[pa:],b)
        else:
            return self.findkth(pa,a,b[pb:])
        
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        mid,left=(len(nums1)+len(nums2))//2,(len(nums1)+len(nums2))%2
        if left:
            return self.findkth(mid+1,nums1,nums2)
        else:
            return (self.findkth(mid+1,nums1,nums2)+self.findkth(mid,nums1,nums2))/2