n = int(input("Enter the number of terms:"))
def printuptoN(num):
    print(num)
    if num == n:
        return
    printuptoN(num+1)
printuptoN(1)