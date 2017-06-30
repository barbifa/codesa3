#include <stdio.h>
#include <stdlib.h>
#include <math.h>



/// Lista de pares




typedef struct {
    int bar;
    int dono;
    int intervalo;
    int pos;
/* outros componentes */
} TipoItem;

typedef struct TipoCelula *TipoApontador;

typedef struct TipoCelula {
    TipoItem Item;	
    TipoApontador Prox;
} TipoCelula;

typedef struct {
    TipoApontador Primeiro, Ultimo;
    int tam;
} TipoLista;


void FLVazia(TipoLista *Lista)
{
    Lista -> Primeiro = (TipoApontador) malloc(sizeof(TipoCelula));
    Lista -> Ultimo = Lista -> Primeiro;
    Lista -> Primeiro -> Prox = NULL;
    Lista->tam = 0;
}
void ImprimeLista(TipoLista *l){ //imprime os pontos da lista
    TipoApontador Aux;
    Aux = l->Primeiro->Prox;
    while(Aux){
        printf("%d %d \n", Aux->Item.bar , Aux->Item.dono);
        Aux = Aux->Prox;
    }
}


void InsereUltimo(TipoItem i, TipoLista l){ //insere um item na última posição
    l.Ultimo->Prox = (TipoApontador)malloc(sizeof(TipoItem)); //aloca memoria para o novo item
    l.Ultimo = l.Ultimo->Prox;
    l.Ultimo->Item = i;
    l.Ultimo->Prox = NULL;
}

void InsereOrdenado(TipoItem i, TipoLista *l){ //insere um item na ordem da lista
    TipoApontador novo = (TipoApontador)malloc(sizeof(TipoItem)); //aloca memoria para o novo item
    TipoApontador Aux;
    /*variaveis
    novo = novo TipoItem que sera inserido na lista;
    pAux = TipoItem auxiliar para percorrer a lista;
    */
    if(l->Primeiro == NULL){
        InsereUltimo(i, *l);
        l->tam ++;
    }

    else{
        novo->Item = i;
        Aux = l->Primeiro;
    while(Aux->Prox != NULL && Aux->Prox->Item.intervalo < i.intervalo){
        Aux = Aux->Prox; //enquanto o x do proximo ponto for menor que o x do novo
    }
        novo->Prox = Aux->Prox;
        Aux->Prox = novo;
        l->tam++;
    }
}

int Vazia(TipoLista Lista)
{ return (Lista.Primeiro == Lista.Ultimo);
}

void Retira(TipoApontador p, TipoLista *Lista)
{


/* --- Obs.: o item a ser retirado e o seguinte ao apontado por p --- */
    TipoApontador q;
//    printf("\nVALOR A RETIRAR %d %d\n ",p->Item.bar,p->Item.dono);


    q = p -> Prox;

    p -> Prox = q -> Prox;
    if (p -> Prox == NULL) Lista -> Ultimo = p;
    free(q);
    Lista->tam--;

}
///Verfica se o item cruza com algum Item Anterior

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
    if((x1< x2 && y1< y2)||(x2< x1 && y2< y1) ){
      //  printf("%d %d | %d %d - nao se cruzam", a.bar, a.dono, b.bar, b.dono);
        return 0;
    }else{
      //  printf("%d %d | %d %d - se cruzam", a.bar, a.dono, b.bar, b.dono);
        return 1;
    }

}
int cruza(TipoApontador anterior, TipoLista *l){
    ///Percorrer ateh o item ser igual Item->pos
    int cruza =0;
    TipoApontador Aux;

    Aux = l->Primeiro->Prox;
    //TipoItem Retirado;

    while(Aux!=NULL){
        if(Aux->Item.pos==anterior->Prox->Item.pos){
        //   printf("VAZA\n");
            break;
        }
    if(verificaCruzamento(Aux->Item,anterior->Prox->Item)==1){
      //printf("-CRUZA (%d %d) \n ",Aux->Item.bar , Aux->Item.dono);
        cruza = 1;
    //    printf("\n Item que eu quero retirar %d %d ", Aux->Item.bar, Aux->Item.dono);
     //   printf("\n Item que edo anterior %d %d ", anterior->Item.bar, anterior->Item.dono);
     //   printf("\n Valor do prox anterior %d %d ", anterior->Prox->Item.bar, anterior->Prox->Item.dono);
        // printf(anterior);
        // printf(anterior->Prox);
        ImprimeLista(l);
        printf("--RetiraAnterior (%d %d) \n",anterior->Item.bar , anterior->Item.dono);
        printf("--Retira (%d %d) \n",anterior->Prox->Item.bar , anterior->Prox->Item.dono);
        Retira(anterior,l);
        ImprimeLista(l);
        printf("\n");
        
    break;
    }

    Aux = Aux->Prox;

    }
    if (cruza==0){
        return 0; //nao ouve cruzamento
    }else{
        return 1; /// ja eh invalido
    }

}

void guloso(TipoLista *l){
    TipoApontador Aux;
    TipoApontador anterior = l->Primeiro;
    Aux = l->Primeiro->Prox;
    while(Aux){
    //   ImprimeLista(l);
      printf("ANT (%d %d) \n", anterior->Item.bar , anterior->Item.dono);
      //  printf("\n\nITEM %d %d \n\n",Aux->Item.bar , Aux->Item.dono);
        if(!cruza(anterior,l)){
          anterior = Aux;
          }
        //ImprimeLista(l);
        Aux = Aux->Prox;
}


}

int main()
{

    int n;
    char op;
    scanf("%c",&op);
    scanf("%d",&n);
    int i,j,k;
    //int nCombinacoes= pow(2,n);
    //int binario[n];
    //par par[8];

    switch(op){

    case 'g':
    break;
    case 'b':
    break;
    case 'd':
    break;

    }
    int bar, dono,intervalo;
    TipoLista lista;
    TipoItem par;
    FLVazia(&lista);

    for(i = 0; i < n; i++){
        scanf("%d %d",&bar,&dono);
        //binario[i] = 0;
        intervalo = abs(bar - dono);
        par.bar = bar;
        par.dono = dono;
        par.intervalo = intervalo;
        par.pos = i;
        // printf("\n %d %d %d\n",par.bar,par.dono,par.intervalo);
        InsereOrdenado(par,&lista);


    }
  //  ImprimeLista(&lista);

    // guloso(&lista);
   // printf("\n After Guloso:\n");
    guloso(&lista);
    // Retira(lista.Primeiro->Prox,&lista);
    printf("\n\n --- numero de bandeirolas GULOSO %d---- \n",lista.tam);
    //(&lista);
    
    return 0;
}
