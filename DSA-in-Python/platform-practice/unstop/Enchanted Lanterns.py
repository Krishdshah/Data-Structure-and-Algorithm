"Enchanted Lanterns: Calculating the Sum of Wish Values"
'''
Problem Statement
In a village nestled at the foot of a mountain, skilled artisans crafted magical lanterns that glowed brighter the higher they were carried. To create the most powerful lantern, the village elder needed to calculate its "wish value (absolute difference between maximum and minimum brightness)" by comparing two factors for each mountain peak:

The maximum brightness from the current peak to the highest point.
The minimum brightness from the start to that peak.
The elder had to calculate the sum of these wish values to determine the lantern's power. The village eagerly awaited to see if the elder could craft the most powerful lantern ever made.

Input Format
The first line contains an integer N, representing the number of mountain peaks.

The second line contains N space-separated integers A[i], representing the brightness values of each peak.

Output Format
Print a single integer representing the sum of all wish values.

Constraints
1<= N <=10^6

1<= A[i] <= 10^6

Sample Testcase 0
Testcase Input
3
1 3 2
Testcase Output
5
Explanation
For each peak:


Peak 0: The maximum brightness from peak 0 to 2 is 3, and the minimum brightness from peak 0 to 0 is 1. Wish value = |3 - 1| = 2


Peak 1: The maximum brightness from peak 1 to 2 is 3, and the minimum brightness from peak 0 to 1 is 1. Wish value = |3 - 1| = 2


Peak 2: The maximum brightness from peak 2 to 2 is 2, and the minimum brightness from peak 0 to 2 is 1. Wish value = |2 - 1| = 1


Sum of all wish values = 2 + 2 + 1 = 5.

Sample Testcase 1
Testcase Input
5
4 2 3 1 5
Testcase Output
15
Explanation
For each peak:


Peak 0: The maximum brightness from peak 0 to 4 is 5, and the minimum brightness from peak 0 to 0 is 4. Wish value = |5 - 4| = 1


Peak 1: The maximum brightness from peak 1 to 4 is 5, and the minimum brightness from peak 0 to 1 is 2. Wish value = |5 - 2| = 3


Peak 2: The maximum brightness from peak 2 to 4 is 5, and the minimum brightness from peak 0 to 2 is 2. Wish value = |5 - 2| = 3


Peak 3: The maximum brightness from peak 3 to 4 is 5, and the minimum brightness from peak 0 to 3 is 1. Wish value = |5 - 1| = 4


Peak 4: The maximum brightness from peak 4 to 4 is 5, and the minimum brightness from peak 0 to 4 is 1. Wish value = |5 - 1| = 4


Sum of all wish values = 1 + 3 + 3 + 4 + 4 = 15
'''

def calculate_wish_values_sum(N, A):
    """
    Write your logic here.
    Parameters:
        N (int): Number of mountain peaks
        A (list): List of brightness values of each peak
    Returns:
        int: Sum of all wish values
    """
    if N <= 1:
        return 0

    prefix_min = [0] * N
    suffix_max = [0] * N

    prefix_min[0] = A[0]
    for i in range(1, N):
        prefix_min[i] = min(prefix_min[i - 1], A[i])

    suffix_max[-1] = A[-1]
    for i in range(N - 2, -1, -1):
        suffix_max[i] = max(suffix_max[i + 1], A[i])

    total = 0
    for i in range(N):
        total += abs(suffix_max[i] - prefix_min[i])

    return total


def main():
    import sys
    input = sys.stdin.read
    data = input().strip().split()
    
    N = int(data[0])  # First input is the integer N
    A = list(map(int, data[1:]))  # Remaining input is the array of integers representing brightness values
    
    # Call user logic function and print the output
    result = calculate_wish_values_sum(N, A)
    print(result)

if __name__ == "__main__":
    main()