class Solution:
    def climbStairs(self, n: int) -> int:
        return self.helper(0,n,{})
        
    def helper(self, curr, target,memo) : 
        if curr== target: return 1
        elif curr> target : return 0
        currkey=curr
        if currkey in memo:
            return memo[currkey]
        
        onestep= self.helper(curr+1,target,memo)
        twostep= self.helper(curr+2,target,memo)
        
        memo[currkey]= onestep+twostep
        return memo[currkey]