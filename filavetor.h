#ifndef  FILAVETOR_H
#define  FILAVETOR_H
//========================================
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//========================================
typedef struct Pessoa{
  char nome[100];
  int idade;
  int prioridade;
}Pessoa;
void print_pessoa(Pessoa p);

//========================================
typedef struct Fila{
  int inicio;
  int fim;
  int tam;
  Pessoa F[100];
}Fila;
//========================================
//========================================
void new_fila(Fila *f);
//========================================
void enqueue(Fila *f, Pessoa dado);
//========================================
void print_fila(Fila *f);
//========================================
int size_fila(Fila *f);
//========================================
Pessoa dequeue(Fila *f);
//========================================
#endif 