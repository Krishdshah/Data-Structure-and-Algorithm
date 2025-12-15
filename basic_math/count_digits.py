n = int(input("Enter the number"))
cnt = 0
while (n>0):
    cnt+=1
    n//=10
print("Number of digits = ",cnt)
