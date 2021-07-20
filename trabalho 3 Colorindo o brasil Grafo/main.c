#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct estado{
    int cod;
    char nome[2];
    int fronteiras;
    int codfront[10];
    int cor;
};
FILE *arq;
int main()
{
    struct estado e[27];
    struct estado aux;
    int i,j,filac[27],coratual,vetcor[27],a=26,tamvet=0,flag,estados=0;
    arq = fopen("estadoColorido.txt","w");// abro o arquivo
    if(!arq)
    {
        printf("Erro na abertura do arquivo!"); // verificando caso de erro do ponteiro arq que aponta para o tipo FILE
        exit(0);
    }
    for(i=0;i<27;i++){
        printf("Digite o codigo do estado:");
        scanf("%d",&e[i].cod);
        printf("Digite o nome do estado:");
        scanf("%s",&e[i].nome);
        e[i].cor=-1;
        fflush(stdin);
        printf("digite a quantidade de fronteiras:");
        scanf("%d",&e[i].fronteiras);
        printf("digite o codigo das fronteiras:");
        for(j=0;j<e[i].fronteiras;j++){
            scanf("%d",&e[i].codfront[j]);
        }
    }
    //ordena os estados por numero de fronteiras atravez do insertion;
    for(i=1;i<27;i++){
        aux=e[i];
        for(j=i;(j>0)&&(aux.fronteiras<e[j-1].fronteiras);j--){
            e[j]=e[j-1];
        }
        e[j]=aux;
    }
    //faço uma fila agr do maior para o menor em numero de vertices;
    j=0;
    for(i=26;i>-1;i--){
        filac[j]=e[i].cod;
        j++;
    }
    printf("fila dos codigos dos estados: ");
    for(i=0;i<27;i++){
        printf("\t%d",filac[i]);
    }
    coratual=1;
    while(estados<27){
        if(e[a].cor==-1){
            if(tamvet==0){
                e[a].cor=coratual;
                vetcor[tamvet]=e[a].cod;
                tamvet++;
                a--;
                estados++;

            }
            else{
                flag=0;
                for(j=0;j<tamvet;j++){
                    for(i=0;i<e[a].fronteiras;i++){
                        if(e[a].codfront[i]==vetcor[j]){
                            flag=1;
                        }
                    }
                }
                if(flag==0){
                    e[a].cor=coratual;
                    vetcor[tamvet]=e[a].cod;
                    tamvet++;
                    a--;
                    estados++;
                }
                else
                    a--;
            }
        }
        else{
            a--;
        }
        if(a==-1){
            a=26;
            a=a-coratual;
            coratual++;
            tamvet=0;

        }
    }


    // falta faze ressa parte de cima
    fprintf(arq,"\nEstados com cores\n");
     for(i=0;i<27;i++){
        printf(" \ncodigo do estado:  %d",e[i].cod);
        fprintf(arq,"\n Codigo do Estado %d  ",e[i].cod);
        printf(" nome do estado: %s\n",e[i].nome);
        fprintf(arq,"nome do Estado %s ",e[i].nome);
        printf(" cor do estado: %d\n",e[i].cor);
        fprintf(arq,"Cor %d\n",e[i].cor);
        printf("fornteira com  ");
        for(j=0;j<e[i].fronteiras;j++){
            printf("%d\t",e[i].codfront[j]);
        }
    }
    fclose(arq);
    return 0;
}
