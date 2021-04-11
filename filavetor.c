#include "filavetor.h"
//========================================
void print_pessoa(Pessoa p){
  printf("{nome: %s, idade: %d, fase: %d}\n", p.nome, p.idade, p.prioridade);
}
//========================================
void new_fila(Fila *f){
  Pessoa *nova;
  f->inicio = 0;
  f->fim = 0;
  f->tam = 0;
}
//========================================
void enqueue(Fila *f, Pessoa dado){
  f->tam++;
  f->fim++;
  f->F[f->fim] = dado;
}
//========================================
int size_fila(Fila *f){
  return f->tam;
}
//========================================
void print_fila(Fila *f){

  int tmp = f->inicio+1;

  while(tmp <= f->fim){
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

