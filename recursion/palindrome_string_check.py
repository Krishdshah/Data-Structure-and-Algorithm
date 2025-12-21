def palindrome(l):
    if l>=len(s)//2:
        return True
    if(s[l]!=s[len(s)-l-1]):
        return False
    return palindrome(l+1)
s="madam"
if palindrome(0):
    print("Palindrome")
else:
    print("Not Palindrome")