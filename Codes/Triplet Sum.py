from sys import stdin 
def findTriplet(arr, n, x) :
    numTriplets = 0 
    for i in range(n) : 
        for j in range((i + 1), n) :
            for k in range((j + 1), n) : 
                if (arr[i] + arr[j] + arr[k]) == x :
                    numTriplets += 1 
    return numTriplets 
def takeInput() :
    n = int(input())
    if n == 0 : 
        return list(), 0
    arr = list(map(int, input().strip().split(" ")))
    return arr, n 
t = int(input().strip())
while t > 0 :
    arr, n = takeInput()
    x = int(input().strip()) 
    print(findTriplet(arr, n, x))
    
    t -= 1
