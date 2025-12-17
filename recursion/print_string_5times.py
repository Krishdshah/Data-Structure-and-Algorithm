def printname(string,i,n):
    if i>n:
        return
    print(string)
    printname(string,i+1,n)

string = input("Enter string to print")
n=int(input("Enter value:"))
printname(string,1,n)