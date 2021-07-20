/*
    TAD tipoCP:
    calcula a complexidade de um algoritimo,retornando o tempo de execução, a quantidade
    de clocks, um numero grande tipo char e a anotação O grande do algoritimo
*/
typedef struct {
char numero[20];
int ultimo;
time_t tempoInicial, tempoFinal;
clock_t tic,tac;
}tipocp;
/* Função iniciaCP - atribui 0 em todas as posições do numero grande,
inicia o tempo de inicial do programa  e o ciclo de clock iinicial */
void iniciaCP(tipocp *cp);
/* Função ContaCP - soma o valor do contador de operações no numero grande */
void contaCP(tipocp *cp,int val);
/* Função finalizaCP - calcula a diferença entre o tempo final o tempo inicial assim como
ciclo de clock final e o ciclo inicial e mostra o numero numero grande dizendo qual sua ordem. */
void finalizaCP(tipocp cp);



void iniciaCP(tipocp *cp){
    cp->ultimo=19;
    int i;
    for(i=0; i<20; i++)
    {
        cp->numero[i]='0';
    }
    cp->tic=clock();
    cp->tempoInicial = time(NULL);
}
void contaCP(tipocp *cp,int val)
{
    while(val>0)
    {
        while(cp->numero[cp->ultimo]=='9')
        {
            cp->numero[cp->ultimo]='0';
            cp->ultimo--;
        }
        cp->numero[cp->ultimo]+=1;
        val--;
        cp->ultimo=19;
    }
}

void finalizaCP(tipocp cp)
{
    FILE *pont_arq;
    pont_arq = fopen("teste.txt", "a");  // a não apaga o conteudo
    fprintf(pont_arq, "\nPrograma 3 N=30: \n");
    int i;
    cp.tempoFinal = time(NULL);
    cp.tac=clock();
    float tempoc,tempos;
    tempoc = (cp.tac - cp.tic)*1000/CLOCKS_PER_SEC;
    tempos = difftime(cp.tempoFinal,cp.tempoInicial);
    printf("\nNumeros de ciclos de execucao %0.f em milisegundos \n",tempoc);
    printf("Tempo de Execucao: %.2f em segundos \n", tempos);
    fprintf(pont_arq, "numeros de ciclos de execucao: %.0f em milisegundos \n",tempoc);
    fprintf(pont_arq, "tempo de execucao: %2.f segundos  \n", tempos);
    fprintf(pont_arq, "numero de Operaçoes : ");
    for(i=0; i<20; i++)
    {
        printf("%c ",cp.numero[i]);
        fprintf(pont_arq, "%c ",cp.numero[i]);

    }
    int val=atoi(cp.numero);

    printf("\ncomplexidade do algoritmo: ");
    fprintf(pont_arq, "\ncomplexidade do algoritmo: ");
    if(val<=1)
    {
        printf("ordem constante:");
        fprintf(pont_arq, "ordem constante! \n");
    }
    else if(val>1&&val<=1.4771)
    {
        printf("ordem logaritmica");
        fprintf(pont_arq, "ordem logaritmica! \n");
    }
    else if(val>1.4771 &&val<=30)
    {
        printf("ordem linear");
        fprintf(pont_arq, "ordem linear! \n");
    }
    else if(val>30&&val<=44.3136)
    {
        printf("ordem log linear");
        fprintf(pont_arq, "ordem log liner! \n");
    }
    else if(val>44.3136&&val<=900)
    {
        printf("ordem quadratica");
        fprintf(pont_arq, "ordem quadratica! \n");
    }
    else if(val>900&&val<=27000)
    {
        printf(" ordem cubica,");
        fprintf(pont_arq, "ordem cubica! \n");
    }
    else if(val>27000&&val<=1073741824)
    {
        printf("ordem exponencial");
        fprintf(pont_arq, "ordem exponencial! \n");
    }
    else
    {
        printf("ordem fatorial !");
        fprintf(pont_arq, "ordem fatorial: \n");
    }

     fclose(pont_arq);
}
