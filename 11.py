class Solution:
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        ps=0
        pe=len(height)-1
        res=0
        while (ps<pe):
            res=max(res,min(height[ps],height[pe])*(pe-ps))
            if height[ps]<height[pe]:
                ps+=1
            else:
                pe-=1
        return res