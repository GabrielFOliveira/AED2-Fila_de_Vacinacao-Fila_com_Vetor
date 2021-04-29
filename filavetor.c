#include "filavetor.h"
//========================================
void print_pessoa(Pessoa p){
  printf("{nome: %s, idade: %d, fase: %d}\n", p.nome, p.idade, p.prioridade);
}
//========================================
void new_fila(Fila *f){
  f->inicio = 0;
  f->fim = 0;
  f->tam = 0;
}
//========================================
void enqueue(Fila *f, Pessoa dado){
  f->tam++;
  f->fim++;
  
  //caso a prioridade da Pessoa seja , é inserido logo ao final da fila
  if(dado.prioridade==5){
    f->F[f->fim] = dado;
  }
  else{
    
    int pos= f->fim;//aponta o contador para o fim da fila

    //percorre a estrutura do final até encontrar onde o novo elemento deve ser inserido. Como a estrutura da prioridade é crescente (prioridade 1 = fase 1), enquanto o valor da prioridade for menor o laço irá rodar
    while(dado.prioridade < f->F[pos-1].prioridade && pos > f->inicio){
      pos--;
    }

    //laço que percorre o inicio ate a posicao a inserir o elemento
    for(int i=f->fim; i > pos;i--){
      f->F[i]=f->F[i-1]; //troca o valor da posicao pelo valor da posicao anterior
    }

    //insere o dado na posição correta
    f->F[pos]=dado;


  }
  

}
//========================================
int size_fila(Fila *f){
  return f->tam;
}
//========================================

//metodo que imprime fila geral
void print_fila(Fila *f){

  int tmp = f->inicio+1;

  printf("=====> Fila de vacinacao <=====\n");


  while(tmp <= f->fim){
    print_pessoa(f->F[tmp]);
    tmp++;
  }
}

//metodo que imprime a fila de vacinacao especifica
void print_fila_especifica(Fila *f, int p){
  
  int tmp = f->inicio+1;

  printf("=====> Fila Fase %d <=====\n", p);

  while(f->F[tmp].prioridade ==p){
    print_pessoa(f->F[tmp]);
    tmp++;
  }

}


//========================================
Pessoa dequeue(Fila *f){

  if(f->tam == 0){
    Pessoa p = {"Invalido", -1};
    return p;
  }

  f->inicio++;
  f->tam--;

  return f->F[f->inicio];

}

