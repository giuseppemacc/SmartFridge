#include "types.h"
#include "file_names.h"
#include "utils.h"
#include <stdio.h>

void print_alimento(t_alimento alimento){
  puts("====================");
  printf("nome: %s\n", alimento.nome);
  printf("peso: %d\n", alimento.peso);
  printf("quantita: %d\n", alimento.quantita);
  puts("====================");
}

void print_alimenti(){
  t_alimento alimento_corrente;
  FILE* file_alimenti;


  file_alimenti = apriFile(FILENAME_ALIMENTI);

  	if(!(file_alimenti == NULL)){
  		rewind(file_alimenti);
  		fread( &alimento_corrente, sizeof(t_alimento), 1, file_alimenti);

  		 while(!feof(file_alimenti)){
  		  print_alimento(alimento_corrente);
  		  fread( &alimento_corrente, sizeof(t_alimento), 1, file_alimenti);
  		}
  	}

  	chiudiFile(file_alimenti);
}


t_alimento input_alimento(){
  t_alimento alimento;

  alimento.dispensa = 0;

  printf("Inserisci nome alimento >> ");
  scanf("%s", alimento.nome);
  printf("Inserisci la quantità >> ");
  scanf("%d", &alimento.quantita);
  printf("Inserisci il peso >> ");
  scanf("%d", &alimento.peso);

  return  alimento;

}

void aggiungi_alimenti(){
  int input;
  t_alimento alimento;
  FILE* file_alimenti;


	file_alimenti = apriFile(FILENAME_ALIMENTI);

	if(!(file_alimenti == NULL)){

	  fseek(file_alimenti, 0, SEEK_END); // posiziona alla fine

  	  do{
  		alimento = input_alimento();
  		fwrite( &alimento, sizeof(t_alimento), 1, file_alimenti);

  		printf("Caricare un altro alimento? [si:1, no:0] >> ");
  		scanf("%d", &input);

  	  }while(input == 1);
	}

	chiudiFile(file_alimenti);
}


t_ricetta input_ricetta(){
	t_ricetta ricetta;
	int input;
	t_alimento alimento;

	ricetta.n_ingredienti = 0;
	ricetta.valutazione = -1;
	ricetta.proposta = 0;

	  printf("Inserisci nome ricetta >> ");
	  scanf("%s", ricetta.nome);
	  printf("Inserisci categoria ricetta >> ");
	  scanf("%d", &ricetta.categoria); // inserire come stringa la categoria
	  printf("Inserisci procedimento ricetta >> ");
	  scanf("%s", ricetta.procedimento);
	  printf("Inserisci ingredienti >> ");
	  do{
		  printf("n%d:\n",ricetta.n_ingredienti+1);
		  alimento = input_alimento();

		  printf("questo alimento si trova in dispensa? [0:no, 1:si] >> ");
		  scanf("%d", &input);

		  if(input == 1){
			  alimento.dispensa = 1;
		  }

		  ricetta.ingredienti[ ricetta.n_ingredienti ] = alimento;
		  ricetta.n_ingredienti++;

		  printf("Aggiungere un altro alimento? [si:1, no:0] >> ");
		  scanf("%d", &input);

	  }while(input==1);


	return ricetta;
}

void print_ricetta(t_ricetta ricetta){
  puts("====================");
  printf("nome: %s\n", ricetta.nome);
  printf("procedimento: %s\n", ricetta.procedimento);

  for(int i=0; i<ricetta.n_ingredienti; i++){
	  printf("\tingrediente %d\n",i+1);
	  print_alimento(ricetta.ingredienti[i]);
  }
  puts("====================");
}


void aggiungi_ricette(){}

void print_ricette(){}


void rimuovi_ricette(){}


void modifica_ricette(){}
