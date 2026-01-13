def dec_2_bin(dec_num):
    binary_number = 0
    power =1
    while dec_num>0:
        binary_number = binary_number+dec_num%2*power
        power = power*10
        dec_num=dec_num//2
    return binary_number

print(dec_2_bin(10))