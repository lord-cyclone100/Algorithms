#include<stdio.h>
#define MAX 1000

int i;
int lookup[MAX];

void initialize() {
    for(i = 0; i < MAX; i++)
        lookup[i] = -1;
}

int fiboMemoization(int n) {
    if(n <= 1)
        return n;

    if(lookup[n] == -1)
        lookup[n] = fiboMemoization(n-1) + fiboMemoization(n-2);

    return lookup[n];
}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    initialize();
    printf("Fibonacci number is: %d\n", fiboMemoization(n));
    return 0;
}
