/*
 ============================================================================
 Name        : SmartFridge.c
 Author      : giuseppe-gioele
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include "lol.h"
#include "struct.h"

#define FILENAME_STUDENTI "file_studenti.dat"




void carica_studenti(FILE* file);
t_studente input_studente();

void visualizza_studenti(FILE* file);




void visualizza_stud_max_media(FILE* file);



int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0);

  FILE* FileStudenti;
  int input;

  if ((FileStudenti = fopen(FILENAME_STUDENTI, "rb+")) == NULL){
    puts("file non trovato");

  }else{

    do {
      puts("1 carica studenti\n2 ricerca studente\n3 visualizza stud max media\n4 visualizza studenti\n0 esci\n>> ");
      scanf("%d", &input);
      if(input == 1){
        carica_studenti(FileStudenti);
      }else if(input == 2){
        ricerca_per_codice(FileStudenti);
      }else if(input == 3){
        visualizza_stud_max_media(FileStudenti);
      }else if(input == 4){
        visualizza_studenti(FileStudenti);
      }
    }while(input != 0);
  }

  if(!fclose(FileStudenti)){
    puts("file chiuso");
  }

  return 0;
}

void visualizza_stud_max_media(FILE* file){
  t_studente studente_corrente;
  int max_media=0;

  // primo ciclo: trova qual è la media maggiore
  // secondo ciclo: visualizza tutti gli studenti che hanno quella media

  for(int i=0; i<2; i++){

    rewind(file);
    fread( &studente_corrente, sizeof(t_studente), 1, file);

    while(!feof(file)){

      if(studente_corrente.media_voti >= max_media){
        if(i == 0){ // se è il primo ciclo
          max_media = studente_corrente.media_voti;
        }else if( i == 1){ // se è il secondo ciclo
          visualizza_studente(studente_corrente);
        }
      }

      fread( &studente_corrente, sizeof(t_studente), 1, file);
    }
  }
}







void visualizza_studenti(FILE* file){
  t_studente studente_corrente;

  rewind(file);
  fread( &studente_corrente, sizeof(t_studente), 1, file);

  while(!feof(file)){
    visualizza_studente(studente_corrente);
    fread( &studente_corrente, sizeof(t_studente), 1, file);
  }
}



void carica_studenti(FILE* file){
  int input;
  t_studente studente;

  fseek(file, 0, SEEK_END); // posiziona alla fine
  do{

    studente = input_studente();
    fwrite( &studente, sizeof(t_studente), 1, file);

    printf("Caricare un altro studente? [si:1, no:0] >> ");
    scanf("%d", &input);

  }while(input == 1);

}

t_studente input_studente(){
  t_studente studente;

  printf("Inserisci il codice: ");
  scanf("%d", &studente.codice);
  printf("Inserisci il nome: ");
  scanf("%s", studente.nome);
  printf("Inserisci il cognome: ");
  scanf("%s", studente.cognome);
  printf("Inserisci la matricola: ");
  scanf("%d", &studente.matricola);
  printf("Inserisci la media dei voti: ");
  scanf("%f", &studente.media_voti);

  return  studente;

}
