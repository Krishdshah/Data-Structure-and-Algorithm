n = int(input("Enter the number"))
cnt = 0
while n>0:
    cnt = cnt*10+n%10
    n//=10
print('Reversed :',cnt)

