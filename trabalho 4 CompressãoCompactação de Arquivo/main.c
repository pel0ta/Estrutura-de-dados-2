#include <stdio.h>
#include <stdlib.h>
void compactaArquivo()
{
    char nome[50];
    //Abro os arquivos
    FILE *arq1;
    FILE *arq2;
    char cant,catual;
    int inicio=0,i,taman=0,sobra=0;
    printf("digite o nome do arquivo que deseja compactar:\nEX t2.txt\n");
    scanf("%s",nome);
    arq1=fopen(nome,"rb");
    arq2=fopen("novo.txt","wb");
    if (arq1==NULL)
    {
        printf("nao abriu arquivo 1");
    }
    //enquanto eu tiver dados nos arquivos faço:
    while(!feof(arq1))
    {
        fread(&catual,1,1,arq1);
         //se for o primeiro dado
        if (inicio==0)
        {
            cant=catual;
            taman=1;
            inicio=1;
        }
        else
         //eu comparo esse e igual o anterior?
        {
            if(catual==cant)
             //se for soh aumento o tamanho
            {
                taman++;
            }
            else
             //se nao eu vejo meu tamanho e >3
            {
                //se for maior que 12 eu teria 2 cassas decimais para representar o arquivo:(
                //entao fiz essa limitação:
                while(taman>12){
                        fwrite(&cant,1,1,arq2);
                        fwrite(&cant,1,1,arq2);
                        fwrite(&cant,1,1,arq2);
                        taman=taman-12;
                        sobra=9;
                        fprintf(arq2,"%d",sobra);
                }
                if(taman<3)
                 //se for menos que 3 eu soh imprimo o quanto de vezes ele apareceu
                {
                    for(i=0; i<taman; i++)
                    {
                        fwrite(&cant,1,1,arq2);
                    }
                     //anterio recebe o atual e o tamanho volta pra 1:
                    cant=catual;
                    taman=1;
                }
                else
                 //se nao eu imprimo 3 vezes aquele simbolo e subitraio o tamanho por 3 e coloco na sobra e printo no arquivo
                {
                    fwrite(&cant,1,1,arq2);
                    fwrite(&cant,1,1,arq2);
                    fwrite(&cant,1,1,arq2);
                    sobra=taman-3;
                    fprintf(arq2,"%d",sobra);
                    cant=catual;
                    taman=1;
                }
            }
        }
    }
    //esvazio o que sobrou na memoria pos os ultimos valores nao vieramm;
    while(taman>12){
                        fwrite(&cant,1,1,arq2);
                        fwrite(&cant,1,1,arq2);
                        fwrite(&cant,1,1,arq2);
                        taman=taman-12;
                        sobra=9;
                        fprintf(arq2,"%d",sobra);
    }
    if(taman<3)
    {
        for(i=0; i<taman; i++)
        {
            fwrite(&cant,1,1,arq2);
        }
    }
    else
    {
        fwrite(&cant,1,1,arq2);
        fwrite(&cant,1,1,arq2);
        fwrite(&cant,1,1,arq2);
        sobra=taman-3;
        sobra--;
        //sempre o ultimo valor aparecia com o erro de um numeral a mais
         //nao foço ideia o pq :(
        fprintf(arq2,"%d",sobra);
    }
     //fecho os arquivos e dou fim na etapa de compactar arquivos:
    fclose(arq1);
    fclose(arq2);
    printf("Arquivo comprimido com sucesso:\nO nome do novo arquivo e: \nnovo.txt");
}
void descompactaArquivo(){
    char nome[50];
    char cant,catual;
    int inicio=0,i,taman=0,sobra=0;
     //abro os arquivos
    FILE *arq1;
    FILE *arq2;
    printf("digite o nome do arquivo que deseja compactar:\nEX novo.txt\n");
    scanf("%s",nome);
    arq1=fopen(nome,"rb");
    arq2=fopen("novoarquivo.txt","wb");
    if (arq1==NULL)
    {
        printf("nao abriu arquivo 1");
    }
    inicio=0;
    while(!feof(arq1))
    {
         //começo a ler os dados do arquivo
        fscanf(arq1,"%c",&catual);
         //se for o inicio de um simbolo faço esse ifi
        if (inicio==0)
        {
            cant=catual;
            taman=1;
            inicio=1;
        }
        else
        {
             //nao nao e o inicio do simbolo vejo se meu tamanh e menor que 3
            if(taman<3)
            {
                if(cant==catual)
                {
                    taman++;
                }
                else
                     //se for diferente soh escrevos os simbolos no outro arquivo
                {
                    for(i=0; i<taman; i++)
                    {
                        fwrite(&cant,1,1,arq2);
                    }
                    cant=catual;
                    taman=1;
                }
            }
             //se for maior que 3 printo o simbolo 3 vezes e faço um for de 0 ate o valor do meu simbolo atual pois e o idice desse numero
            else
            {
                fwrite(&cant,1,1,arq2);
                fwrite(&cant,1,1,arq2);
                fwrite(&cant,1,1,arq2);
                // aqui eu fiz um vetor de char nem sabia que isso existia, mais como eu tava lendo um char resolvi tentar
                for(i='0'; i<catual; i++)
                {
                    fwrite(&cant,1,1,arq2);
                }
                 // inicio =0 pois agr virar um simbolo novo
                inicio=0;
            }
        }
    }
     //fecho os arquivos eponho um fim na parde de descompactação do projeto
    fclose(arq1);
    fclose(arq2);
    printf("Arquivo descompactado com sucesso:\nO nome do arquivo ficou assim:\nnovoarquivo.txt");
}
int main()
{
    int op=1;
    while(op!=0)
    {
        printf("\nEscolha uma opcao:\n1-compactar Arquivo\n2-descompactar Arquivo\n0-sair");
        scanf("%d",&op);

        switch(op)
        {
        case 1:
            printf("case 1");
            compactaArquivo();
            break;
        case 2:
            printf("case 2");
            descompactaArquivo();
            break;

        default:
            printf("Opcao invalida:\n me ajude a te ajudar:");
            break;
        }
    }
    return 0;
}
