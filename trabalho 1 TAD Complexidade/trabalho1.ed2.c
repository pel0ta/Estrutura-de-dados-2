#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include "cp.h"
tipocp cp;
int funcaox(int a){
    if (a<2){
        return 1;
    }
    else{
        contaCP(&cp,3);
        return funcaox(a-1) + funcaox(a-2);
    }
}

int main()
{
    iniciaCP(&cp);
    //Programa1
    /*
    int n,i,a;
    contaCP(&cp,3);
    a=2;
    n=30;
    contaCP(&cp,2);
    contaCP(&cp,n);
    for (i=0; i<n; i++){
        a=a*2;
        contaCP(&cp,2);
    }
    */
        //programa 2;
        int n;
        contaCP(&cp,1);
        n=30;
        contaCP(&cp,1);
        funcaox(n);

    /*/
        //Programa 3;

        int i, j, k,n,a;
        contaCP(&cp,5);
        n=30;
        contaCP(&cp,1);
        contaCP(&cp,n);
        for (i=0;i<n;i++){
            contaCP(&cp,n);
            for (j=0;j<n;j++){
                contaCP(&cp,n);
                for (k=0;k<n;k++){
                    a=a*2;
                    contaCP(&cp,2);
                }
            }
        }
    */
    finalizaCP(cp);
    return 0;
}

