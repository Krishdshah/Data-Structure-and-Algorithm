n = int(input("Enter Number: "))
cnt=0
for i in range(1,n//2+1):
    if n%i == 0:
        print(i)
        print(n//i)
        cnt+=2
print("Total GCD :",cnt)

