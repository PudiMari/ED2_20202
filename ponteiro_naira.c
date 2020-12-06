#include <stdio.h>
#include <stdlib.h>

int main(){
    int x = 200;
    int *p = &x;
    printf("Valor de x: %d \n", x);
    printf("Valor de *p: %p \n", p);
    printf("Valor apontado por *p: %p \n", *p);
    x = x + 200;
    printf("Novo valor de x: %d \n", x);
    printf("Valor apontado por *p: %p \n", *p);
    // *p++;
    printf("Novo valor de x: %d \n", x);
    printf("Valor apontado por *p: %p \n", *p);
    return 0;
}
