def reversing(l,r):
    if l>=r:
        return
    A[l],A[r]=A[r],A[l]
    reversing(l+1,r-1)
A = [1,2,3,4,2]
reversing(0,len(A)-1)
print(A)