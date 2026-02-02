#include <stdio.h>
int main()
 {
int a,b;
scanf("%d", &a);
int c[a];
    for (int i = 0; i < a; i++)
    {
        scanf("%d", &c[i]);
    }
scanf("%d", &b);
    if (b < 1 || b > a) 
    {
        return 1;
    }
int d = b - 1;
    for (int i = d; i < a - 1; i++)
     {
        c[i] = c[i + 1];
    }
    for (int i = 0; i < a - 1; i++)
    {
        printf("%d", c[i]);
        if (i < a - 2)
        {
            printf(" ");
        }
    }
    printf("\n");
    return 0;
}