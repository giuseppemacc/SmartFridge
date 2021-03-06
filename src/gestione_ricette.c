
#include "file_names.h"
#include "types.h"
#include "utils.h"
#include "gestione_alimenti.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

//da una stringa resitituisce l'enum corrispondente
//TODO: "carne","pesce" ecc.. come costanti dichiarate da qualche parte
categorie getCategoria(char* str){
	categorie cat;
	strToUpper(str);

	if( strcmp(str,"CARNE")==0 ){
		cat = CARNE;
	}else if( strcmp(str,"PESCE")==0 ){
		cat = PESCE;
	}else if( strcmp(str,"VERDURE")==0 ){
		cat = VERDURE;
	}else if( strcmp(str,"PASTA")==0 ){
		cat = PASTA;
	}else{
		cat = NONE;
		puts("categoria non trovata");
	}

	return cat;
}

//TODO: funzione che da categoria ritorna la stringa


void print_ricetta(t_ricetta ricetta){
  puts("====================");
  printf("\tnome: %s\n", ricetta.nome);
  printf("\tcategoria: %d\n", ricetta.categoria);//TODO: far visualizzare la categoria come stringa
  printf("\tprocedimento: %s\n", ricetta.procedimento);

  for(int i=0; i<ricetta.n_ingredienti; i++){
	  printf("\tingrediente %d\n",i+1);
	  print_alimento(ricetta.ingredienti[i]);
  }
  puts("====================");
}


void print_ricette(){
	FILE* file_ricette;
	t_ricetta ricetta_corrente;

	if( apriFile(&file_ricette, FILENAME_RICETTE, "rb+") ){

		rewind(file_ricette);
		fread( &ricetta_corrente, sizeof(t_ricetta), 1, file_ricette);

		 while(!feof(file_ricette)){
			 if(strcmp(ricetta_corrente.nome,"")!=0){
				print_ricetta(ricetta_corrente);
			 }
		  fread( &ricetta_corrente, sizeof(t_ricetta), 1, file_ricette);
		}

		fclose(file_ricette);
	}
}


t_ricetta input_ricetta(){
	t_ricetta ricetta;
	int input;
	char str[50];
	t_alimento alimento;

	ricetta.n_ingredienti = 0;
	ricetta.valutazione = -1;
	ricetta.proposta = 0;

	  printf("Inserisci nome ricetta >> ");
	  scanf("%s", ricetta.nome);

	  do{
		  printf("Inserisci categoria ricetta >> ");
		  scanf("%s", str);
		  ricetta.categoria = getCategoria(str);
	  }while( ricetta.categoria == NONE );


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



void aggiungi_ricette(){
	FILE* file_ricette;
	int input;
	t_ricetta ricetta;

	if( apriFile(&file_ricette, FILENAME_RICETTE, "rb+") ){

		fseek(file_ricette, 0, SEEK_END); // posiziona alla fine

		do{
			puts("Inserisci ricetta:");
			ricetta = input_ricetta();
			fwrite( &ricetta, sizeof(t_ricetta), 1, file_ricette);

			printf("Caricare un altra ricetta? [si:1, no:0] >> ");
			scanf("%d", &input);

		}while(input == 1);

	  	fclose(file_ricette);
	}
}


int ricerca_ricetta(char* nome, t_ricetta* ricetta, FILE* file_ricette){
	int flag_ricetta_trovato=0;
	t_ricetta ricetta_corrente;

	rewind(file_ricette);
	fread( &ricetta_corrente, sizeof(t_ricetta), 1, file_ricette);

	 while(!feof(file_ricette) && (flag_ricetta_trovato==0)){
	  if( strcmp(ricetta_corrente.nome, nome)==0 ){
		  flag_ricetta_trovato=1;
		  *ricetta = ricetta_corrente;
		  fseek(file_ricette, -1*sizeof(t_ricetta), SEEK_CUR);//sposta di uno indietro
	  }else{
		  fread( &ricetta_corrente, sizeof(t_ricetta), 1, file_ricette);
	  }
	}
	return flag_ricetta_trovato;
}

void modifica_ricette(){
	int input;
	char str[50];
	t_ricetta ricetta;
	FILE* file_ricette; //ricettario

	do{

		printf("Inserisci il nome della ricetta da modificare/rimuovere >> ");
		scanf("%s", str);

		if( apriFile(&file_ricette, FILENAME_RICETTE, "rb+") ){

			if( ricerca_ricetta(str, &ricetta, file_ricette) ){

				print_ricetta(ricetta);
				puts("[1] elimina ricetta");
				puts("[2] modifica ricetta");
				scanf("%d",&input);


				// elimina alimento
				if(input == 1){
					strcpy(ricetta.nome,"");
				}

				// modifica alimento
				if(input == 2){
					//TODO: chiedere qui all utente cosa e di quanto modificare
					strcpy(ricetta.procedimento,"");
					ricetta.categoria = PASTA;
					printf("%s\n",ricetta.procedimento);
				}

				fwrite( &ricetta, sizeof(t_ricetta), 1, file_ricette);

			}else{
				puts("ricetta non trovato");
			}

			fclose(file_ricette);

		}

		print_ricette();

		printf("Modificare/Eliminare un altra ricetta? [si:1, no:0] >> ");
		scanf("%d", &input);

	}while(input==1);
}



