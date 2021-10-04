# DYNAMIC PROGRAMMING [COIN CHANGE PERMUTATION]          
# TABULATION

def permutation(coins , amt):
    dp = [0]*(amt+1)
    dp[0] =1
    
    for i in range(0 , len(dp)):
        for j in range(0 , len(coins)):
            coin = coins[j]
            
            if(i - coin>=0):
                dp[i] += dp[i-coin]
                
    return dp[amt]



lst = []
n = int(input('enter no. of element '))
for i in range( 0 , n):
    ele =  int(input())
    lst.append(ele)
        
print(lst)
tar = int(input('enter tar: '))
ans = permutation(lst , tar)
print(ans)    