#include <stdio.h>

int main(void)
{
    int n;
    int a[5];
    int *p;

    a[2] = 1024;
    p = &n;
    /*
    
     memcpy(p, &a[2], sizeof(int));

   */
  ;
  /* ...so that this prints 98\n */
    printf("a[2] = %d\n", a[2]);
    return 0;
}

