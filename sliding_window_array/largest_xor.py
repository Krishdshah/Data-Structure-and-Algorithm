def greatest_xor(arr,k):
    n = len(arr)
    if n<k:
        return 0
    curr=0
    for i in range(k):
        curr=curr^arr[i]
    maxx = curr
    for i in range(k,n):
        curr = curr^arr[i-k]^arr[k]
        maxx = max(maxx,curr)
    return maxx

arr = [1,2,3,4,5,6,7,8]
k=2
print("Max XOR for given array's subarray of k terms is:",greatest_xor(arr,k))