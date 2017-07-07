#include <stdio.h>
#include <stdlib.h>
#include<math.h>
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

int binaryToDecimal(int binario[], int n){
    int i,j=0;
    int soma = 0;
    for ( i = n-1 ;i>=0; i --){
        if(binario[i]==1){
            soma = soma + pow(2,j);
           // printf("binario[%d] = %d",i,binario[i]);
          //  printf("som %d bina %d %d pow %f ",soma,binario[i],i,pow(2,j));
        }
        j++;
    }

   // printf("Numero eh = %d",soma);
return soma;

}




void removeCruzamentos(int retirado,int binario[], int n,TipoItem pares[]){
    int i,j;
    TipoItem aux;
    aux = pares[retirado];
    binario[retirado] = 0;

    //retirar TODOS os pares que cruzam com o retirado
      for(i = 0 ; i < n ; i ++){
        if(binario[i]==1){
           if(verificaCruzamento(aux,pares[i])==1){
                binario[i] = 0;
           }
        }
    }


}

int A(int binario[],int n,TipoItem pares[],int k){


    if(binaryToDecimal(binario,n)==0){
            printf("#########\n");
        return 0;
    }

    int m=0;
    int i,j;
    int r;

      int *binarioAux = (int*)malloc(n*sizeof(int));

    for(i = 0; i< n ; i ++){
      //  binarioAux[i] = binario[i];
      //printf("binarioaux = %d binario %d \n",binarioAux[i],binario[i]);
      binarioAux[i] = binario[i];
  //  printf("binarioaux = %d binario %d \n",binarioAux[i],binario[i]);

    }

      removeCruzamentos(k,binarioAux,n,pares);
        for(j=0;j<n;j++){
            printf("depois de remover : binario[%d]=  %d \n",j,binario[j]);
        }

    for(i = 0;i<n;i++){
        if(binario[i]==0){
            continue;
        }else{

//             for(j=0;j<n;j++){
//                printf(" depois de remover : binario[%d]=  %d \n",j,binario[j]);
//            }
            printf(" Chamada %d \n",i);
            r = 1 + A(binarioAux,n,pares,i);

            if(r>m){
                m = r;
            }



        }

    }

    printf("Valor maximo : %d\n ",m);


}

int main()
{
    int i;
    TipoItem par[3];
    par[0].bar =1;
    par[0].dono = 4;

    par[1].bar =3;
    par[1].dono = 6;

    par[2].bar =2;
    par[2].dono = 5;

    int binario[3] = {1,1,1};
  //  printf("valor %d\n ", binaryToDecimal(binario,3));

    //removeCruzamentos(0,binario,3,par);
    for(i = 0; i <3 ; i ++){
         printf("Chamada %d\n",i);
         A(binario,3,par,i);
    }




    return 0;
}
