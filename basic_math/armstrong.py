n = int(input("Enter number: "))
m=n
summ = 0
while n>0:
    summ+=((n%10)**3)
    n//=10
if summ == m:
    print("Armstrong Number")
else:
    print("Not an Armstrong Number")
    