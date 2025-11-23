class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:

        result = []
        temp = []
        idx = 1
        def dfs(idx) -> None :

          if len(temp) == k :
             result.append(temp.copy())
             return
        
          for j in range(idx,n+1) :
             temp.append(j)
             dfs(j+1)
             temp.pop()
        
        dfs(idx)
        
        return result


        
