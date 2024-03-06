#include<stdio.h>
int main() {
    int n = 0;
    int i = 0;
    scanf_s("%d", &n);
    int arr[51] = { 0 };
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int a = 0;
    scanf_s("%d", &a);
    for (i = n - 1; i >= 0; i--) {
        if (arr[i] > a) {
            arr[i + 1] = arr[i];
            arr[i] = a;
        }
        else {
            arr[i + 1] = a;
            break;
        }
    }


    for (i = 0; i < n + 1; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}