#include <stdio.h>

int decrementedValley(int arr[],int n){
    for (int i=1;i<n;i++){
        if (i%2==0 && arr[i]>arr[i-1]){
            continue;
        }
        else if(i%2==1 && arr[i]<arr[i-1]){
            continue;
        }
        else{
            return 0;
        }
    }
    return 1;
}

int incrementedValley(int arr[],int n){
    for (int i=1;i<n;i++){
        if (i%2==1 && arr[i]>arr[i-1]){
            continue;
        }
        else if(i%2==0 && arr[i]<arr[i-1]){
            continue;
        }
        else{
            return 0;
        }
    }
    return 1;
}
int isMountainValleyPattern(int arr[], int n) {
    if (n==0 || n==1){
        return 0;
    }
    else if (arr[1]>arr[0]){
        return incrementedValley(arr,n);
    }
    else{
        return decrementedValley(arr,n);
    }
}

int main() {
    int n=5;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int result = isMountainValleyPattern(arr, n);
    printf("%d\n", result);
    return 0;
}