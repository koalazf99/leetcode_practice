class Solution:
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        last_match=-1
        dic={}
        max_cnt=0
        for i in range(len(s)):
            if s[i] in dic:
                last_match=max(dic[s[i]],last_match)
            dic[s[i]]=i
            max_cnt=max(max_cnt,i-last_match)
            
        return max_cnt