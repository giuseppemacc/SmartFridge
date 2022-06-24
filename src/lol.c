/*
 * lol.c
 *
 *  Created on: 24 giu 2022
 *      Author: giuse
 */

#include "struct.h"
#include <stdio.h>

void visualizza_studente(t_studente studente){
  puts("====================");
  printf("codice: %d\n", studente.codice);
  printf("nome: %s\n", studente.nome);
  printf("cognome: %s\n", studente.cognome);
  printf("matricola: %d\n", studente.matricola);
  printf("media voti: %.2f\n", studente.media_voti);
  puts("====================");
}

void ricerca_per_codice(FILE* file){
  int codice;
  t_studente studente_corrente;
  int trovato=0;

  printf("Inserisci il codice >> ");
  scanf("%d",&codice);

  rewind(file);
  fread( &studente_corrente, sizeof(t_studente), 1, file);

  while(!feof(file) && trovato==0){
    if( studente_corrente.codice == codice ){
      trovato = 1;
    }else{
      fread( &studente_corrente, sizeof(t_studente), 1, file);
    }
  }

  if(trovato==1){
    visualizza_studente(studente_corrente);
  }else{
    puts("Studente non trovato");
  }
  puts("");
}




