#include <stdlib.h>
#include <stdio.h>
FILE *arq;
int r[8],possibilidades=1;
int  rainhas(int c)
{
    int a=0,i;
    for (i=0; i<c; i++)
    {
        if (r[i]==r[c]) //verifica a coluna do tabuleiro
        {
            return 1;
        }
        if (r[c]==(r[i]+(c-i)))  //verifica a diagonal principal
        {
            return 1;
        }
        if (r[c]==(r[i]-(c-i)))  //verifica a diagonal segundaria
        {
            return 1;
        }
    }
    return 0;
}

void imprimir(int c)
{
    int i;
    printf("Possibilidade %d\n\t\t\tTABULEIRO\n\n",possibilidades);
    fprintf(arq,"Possibilidade %d\n\t\t\tTABULEIRO\n\n",possibilidades);
        for( i=0; i<8; i++)
    {
        fprintf(arq,"\t%d",i);//grava a coluna  coluna
        printf("\t%d",i);
    }

    for( i=0; i<=c-1; i++)
    {

        fprintf(arq,"\n\n%d ",i);//grava a linha linha
        printf("\n\n%d-> ",i);
        int j;
        for(j=0; j<=c-1; j++)
        {

            if(r[j]==i)   // fiz uma matriz para mostra as possisoes das rainhas
            {

                fprintf(arq,"%s","\tR"); //printo um r simbolizando a rainha
                printf("\tR");

            }
            else
            {

                fprintf(arq,"%s","\t.");//nao e a rainha eu printo um ponto
                printf("\t.");

            }

        }

    }
    printf("\n\nPosicoes das rainhas:\n");
    for(i=0; i<8; i++)
    {
        printf("coluna [%d] = linha %d\n",i,r[i]); //Printa o vetor cl com as posicoes das rainhas
        fprintf(arq,"\ncoluna [%d] = linha %d\n",i,r[i]);
    }
    possibilidades++;//toda vez que eu imprimo o tabuleiro eu aumento a possibilidade pq se entrar denovo ja esta na contaguem certa.
}

int buscaRainha(int c)
{
    if(c==8)  // limite do tabuleiro
    {
        imprimir(c);// printo o tabuleiro
        c--;    //volto o c e avanço a possiçao para achar mais possibilidades  da um loop mais encontro 250 e minha memoria estoura
        r[c]++;
        buscaRainha(c); // volta recursivamente com a coluna c
        return 1;
    }
    if else(c==-1)  //se c =-1 nao possui mais resposta
    {
        printf("entra aqui");// nao entra pois a memoria estoura :(
        printf("Fim das posibilidades\n");
        printf("fim da soluçao\n"); // printa no Dos
        return 0;

    }
    else if(r[c] > 7)   // se a linha for mair que 7,nao há uma posição possivel para essa coluna
    {
        r[c]=0; //volto o valor 0
        if((c-1)>1){ // verifica se a coluna anterior é maior -1,ou seja,se ainda está dentro do tabuleiro
            r[c-1]++;// na coluna anterior é incrementado o numero de linhas para verificar uma nova posição
        }
        buscaRainha(rainhas(c-1)); // volta recursivamente com a coluna anterior para testar a condição da nova posicao na linha
        return 1;
    }
    else if(rainhas(c)==0)  // procura uma posição aceitavel no tabuleiro
    {
        c++; // incrementa a coluna
        buscaRainha(c); // volta recursivamente com a proxima coluna
        return 1;
    }
    else
    {
        r[c]++; // incrementa  na linha para testar uma nova posição
        buscaRainha(c); // volta recursivamente com a coluna c
        return 1;
    }
}

int main()
{
    int i;
    arq = fopen("possibilidades.txt","w");// abro o arquivo
    if(!arq)
    {
        printf("Erro na abertura do arquivo!"); // verificando caso de erro do ponteiro arq que aponta para o tipo FILE
        exit(0);
    }
    for(i=0; i<8; i++) // iniciando o vetor da posiçoes das rainhas com zeros
    {
        r[i]=0;
    }
    buscaRainha(0); // iniciando  a coluna na possiçao zero
    fclose(arq);//fecha o arquivo
    return 0;
}
