#include <stdio.h>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    
    int diagonal_sum = 0;
    int value;
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &value);
            if (i == j) {
                diagonal_sum += value;
            }
        }
    }
    
    printf("%d\n", diagonal_sum);
    
    return 0;
}