#include "file_names.h"
#include "types.h"
#include "utils.h"
#include <stdio.h>
#include <string.h>
//TODO: migliorare i messaggi all' utente (es: "inserisci questo ...")
//TODO: aggiungere i controlli di inserimento int, string, ecc. ad es
//       creando delle funzioni in utils come inputInt(), inputString(), ... che
//       gestiscono i vari casi



void print_alimento(t_alimento alimento){
  printf("\t%s:", alimento.nome);
  printf("  %d x", alimento.quantita);
  printf(" %dgr", alimento.peso);
  puts("");
}


//TODO: visualizzare gli alimenti in ordine alfabetico
void print_alimenti(){
  t_alimento alimento_corrente;
  FILE* file_alimenti;


  	if( apriFile(&file_alimenti, FILENAME_ALIMENTI, "rb+") ){
  		rewind(file_alimenti);
  		fread( &alimento_corrente, sizeof(t_alimento), 1, file_alimenti);

  		 while(!feof(file_alimenti)){
  			 if(strcmp(alimento_corrente.nome,"")!=0){
  				print_alimento(alimento_corrente);
  			 }
  		  fread( &alimento_corrente, sizeof(t_alimento), 1, file_alimenti);
  		}

  		fclose(file_alimenti);
  	}


}


//TODO: sistemare quantità/peso (cioè come e quando far inserire uno dei due)
/* voglio comunque tenere i campi quantià e peso in t_alimenti perchè ci
  semplificheranno la vita dopo
*/
t_alimento input_alimento(){
  t_alimento alimento;

  alimento.dispensa = 0;

  printf("\tnome >> ");
  scanf("%s", alimento.nome);
  printf("\tquantita' >> ");
  scanf("%d", &alimento.quantita);
  printf("\tpeso >> ");
  scanf("%d", &alimento.peso);
  puts("");

  return  alimento;
}

//TODO: alimento già presente
void aggiungi_alimenti(){
  int input;
  t_alimento alimento;
  FILE* file_alimenti; //frigo


	if( apriFile(&file_alimenti, FILENAME_ALIMENTI, "rb+") ){

	  fseek(file_alimenti, 0, SEEK_END); // posiziona alla fine

  	  do{
  		puts("Inserisci alimento:");
  		alimento = input_alimento();
  		fwrite( &alimento, sizeof(t_alimento), 1, file_alimenti);

  		printf("Caricare un altro alimento? [si:1, no:0] >> ");
  		scanf("%d", &input);

  	  }while(input == 1);
  	  fclose(file_alimenti);
	}

}

//TODO: aggiungere ricerca su sottostringa (?? e forse cercavi ... ??)
/*dato che dobbiamo visualizzare gli alimenti in ordine alfabetico possiamo
 * pensare di ordinare direttamente il file_alimenti e usare qui la ricerca binaria*/
int ricerca_alimento(char* nome, t_alimento* alimento, FILE* file_alimenti){
	int flag_alimento_trovato=0;
	t_alimento alimento_corrente;

	// cerca nel file alimenti e ritorna 1/0 se lo trova e lo setta in *alimento
	rewind(file_alimenti);
	fread( &alimento_corrente, sizeof(t_alimento), 1, file_alimenti);

	 while(!feof(file_alimenti) && (flag_alimento_trovato==0)){
	  if( strcmp(alimento_corrente.nome, nome)==0 ){
		  flag_alimento_trovato=1;
		  *alimento = alimento_corrente;
		  fseek(file_alimenti, -1*sizeof(t_alimento), SEEK_CUR);//sposta di uno indietro
	  }else{
		  fread( &alimento_corrente, sizeof(t_alimento), 1, file_alimenti);
	  }
	}
	return flag_alimento_trovato;
}


//TODO: chiedere all utente di modificare l'alimento e modificarlo
void modifica_alimenti(){
	int input;
	char str[50];
	t_alimento alimento;
	FILE* file_alimenti; //frigo

	do{

		printf("Inserisci il nome dell'alimento da modificare/rimuovere >> ");
		scanf("%s", str);

		if( apriFile(&file_alimenti, FILENAME_ALIMENTI, "r+") ){

			if( ricerca_alimento(str, &alimento, file_alimenti) ){

				print_alimento(alimento);
				puts("[1] elimina alimento");
				puts("[2] modifica alimento");
				scanf("%d",&input);

				// elimina alimento
				if(input == 1){
					strcpy(alimento.nome,"");
				}

				// modifica alimento
				if(input == 2){
					//TODO: chiedere qui all utente cosa e di quanto modificare
					alimento.quantita += 100;
				}

				fwrite( &alimento, sizeof(t_alimento), 1, file_alimenti);

			}else{
				puts("alimento non trovato");
			}

			fclose(file_alimenti);

		}

		print_alimenti();

		printf("Modificare/Eliminare un altro alimento? [si:1, no:0] >> ");
		scanf("%d", &input);

	}while(input==1);

}

