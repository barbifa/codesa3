#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct TipoItem {
    int bar;
    int dono;
    int intervalo;
    int pos;
/* outros componentes */
} TipoItem;

int verificaCruzamento(TipoItem a, TipoItem b){
    int x1,x2; //vai guardar os numeros pares
    int y1,y2; // vai guardar os numero impares

    if(a.bar%2==0){
        x1 = a.bar;
        y1 = a.dono;
    }else{
        x1 =a.dono;
        y1 =a.bar;
    }

    if(b.bar%2==0){
        x2 = b.bar;
        y2 = b.dono;
    }else{
        x2 =b.dono;
        y2 =b.bar;
    }
    if((x1<= x2 && y1<= y2)||(x2<= x1 && y2<= y1) ){
      //  printf("%d %d | %d %d - nao se cruzam", a.bar, a.dono, b.bar, b.dono);
        return 0;
    }else{
      //  printf("%d %d | %d %d - se cruzam", a.bar, a.dono, b.bar, b.dono);
        return 1;
    }

}




void geraCombinacoes(int binario[],int n){
int k;
    for ( k = n-1 ; k>=0  ; k -- ){
     //printf("binario [%d] : %d ",k,binario[k]);
        if(binario[k]== 0 ){
            binario[k] = 1;
            break;
        } else if(binario[k] == 1){
        binario[k] = 0;
        }
    }
}

int cruza( TipoItem par[],int j){
int i,k;

    for(i=0;i<j;i++){
        for(k = 0; k<j; k ++){
            if(verificaCruzamento(par[i],par[k])==1){
                return 1;
            }
        }
    }

    return 0;



}
int configuracaoBinario(int binario[], int n, TipoItem par[]){
int i,j=0;
TipoItem parTeste[n];
int contaUm=0;
//memcpy(parTeste, binario, n* sizeof(int));
    for(i = 0 ; i < n ; i ++){
        if(binario[i]==1){
            contaUm++;
            parTeste[j] = par[i];
            j++;
        }
    }

// mando parTeste pra outra funcao pra ver se cruza
//se cruzar , ie ==1; retorno 1.
//se nao cruzar,ie =0, retorno o contaUm
if(cruza(parTeste,j)==0){
//    printf("Melhor opcao tem tamnaho %d ", contaUm);
    return contaUm;
}else if(cruza(parTeste,j)==1){
   // printf("Cruzaram, nao vai entrar no espaco solucao ");
    return 0;
}


}

int main()
{
    //gera binarios
    // para cada binario gera um vetor
    //com os pares que estao presentes
    //se cruzar . proxima, se nao, melhor valor = valor
    int n,i,combinacoes;
    scanf("%d",&n);
    combinacoes = pow(2,n);
    TipoItem *par = (TipoItem*)malloc(n*sizeof(TipoItem));
    int *binario = (int*)malloc(n*sizeof(int));
    int melhor = 1;
    int maxBandeiras;
    for(i = 0; i<n; i++){
        scanf("%d %d",&par[i].bar,&par[i].dono);
        binario[i]=0;
    }
    int j;
    for(i = 0; i < combinacoes; i++){
        //GeraBinario
        geraCombinacoes(binario,n);
        maxBandeiras =configuracaoBinario(binario,n,par);
        if(maxBandeiras>melhor){
            melhor = maxBandeiras;
        }

//        for(j = 0; j < n ; j ++){
//            printf("%d ",binario[j]);
//        }
//
//        printf("\n");
    }

    printf("O maximo de bandeiras eh %d ", melhor);





    //
    return 0;
}
