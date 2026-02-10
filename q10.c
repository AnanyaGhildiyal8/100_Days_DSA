#include <stdio.h>
#include <string.h>

int main() {
    char s[1001];
    
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = '\0';
    
    int left = 0;
    int right = strlen(s) - 1;
    int isPalindrome = 1;
    
    while (left < right) {
        if (s[left] != s[right]) {
            isPalindrome = 0;
            break;
        }
        left++;
        right--;
    }
    
    if (isPalindrome) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    
    return 0;
}