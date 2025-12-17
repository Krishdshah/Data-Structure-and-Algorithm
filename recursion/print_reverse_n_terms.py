n = int(input("Enter the number of terms:"))
def printupto0(num):
    print(num)
    if num == 1:
        return
    printupto0(num-1)
printupto0(n)
