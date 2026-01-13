def bin2dec(num):
    decimal = 0
    pwr=0
    while num>0:
        decimal=decimal+num%10*2**pwr
        pwr+=1
        num//=10
    return decimal

print(bin2dec(10))

#can be solved using recursion and inbuilt function