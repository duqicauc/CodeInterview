#include <stdio.h>

int main()
{
    char str[100];
    double f=1.2f;
    
    sprintf(str,"%.4lf",f);
    printf("%s\n",str);
    return 0;
}
