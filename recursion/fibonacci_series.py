def fibonnaci(n):
    if n==0 or n==1:
        return n
    return fibonnaci(n-1)+fibonnaci(n-2)

print(fibonnaci(10)) #prints 10th fibonacci [loop is better]