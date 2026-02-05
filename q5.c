#include <stdio.h>

int main() {
    int p, q;
    
    scanf("%d", &p);
    int server1[p];
    for (int i = 0; i < p; i++) {
        scanf("%d", &server1[i]);
    }
    
    scanf("%d", &q);
    int server2[q];
    for (int i = 0; i < q; i++) {
        scanf("%d", &server2[i]);
    }
    
    int result[p + q];
    int i = 0, j = 0, k = 0;
    
    while (i < p && j < q) {
        if (server1[i] <= server2[j]) {
            result[k++] = server1[i++];
        } else {
            result[k++] = server2[j++];
        }
    }
    
    while (i < p) {
        result[k++] = server1[i++];
    }
    
    while (j < q) {
        result[k++] = server2[j++];
    }
    
    for (int i = 0; i < p + q; i++) {
        printf("%d", result[i]);
        if (i < p + q - 1) {
            printf(" ");
        }
    }
    
    return 0;
}