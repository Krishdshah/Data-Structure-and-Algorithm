def prime(num):
    for i in range(2,num//2+1):
        if num%i==0:
            return False
    return True

print(prime(int(input("Enter the number"))))

