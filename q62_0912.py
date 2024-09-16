import numpy as np

class Solution(object):
    def numTilings(self, n):
        """
        :type n: int
        :rtype: int
        """
        arr = np.zeros(n + 3, dtype=int)
        arr[0] = 1
        arr[1] = 2
        arr[2] = 5
        
        for i in range(3, n):
            arr[i] = 2 * arr[i-1] + arr[i-3]
            
        return arr[n-1] % 100000007
        
        