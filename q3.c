#include <stdio.h>
int main() 
{
int n;
scanf("%d", &n);
int arr[n];
for(int i = 0; i < n; i++) 
{
    scanf("%d", &arr[i]);
}
int k;
scanf("%d", &k);
int c = 0;
int idx = -1;
for(int i = 0; i < n; i++) {
    c++;
    if(arr[i] == k) {
        idx = i;
        break;
    }
}
if(idx != -1) {
    printf("Found at index %d\n", idx);
} else {
    printf("Not Found\n");
}
printf("Comparisons = %d\n", c);
return 0;
}
