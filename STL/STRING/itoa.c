#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char s[10];
    int a ;
    scanf("%s",s);
    itoa(145,s,10);

    printf("%d",s);
    return 0 ;
}
