n = int(input("Enter number"))

def sum_till_n(n):
    if n == 1:
        return 1
    return n + sum_till_n(n-1)

print("Sum total = ",sum_till_n(n))