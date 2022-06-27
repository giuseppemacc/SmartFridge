#include <stdio.h>
#include <string.h>
#include <ctype.h>
// ??TODO?? ordina file



// ??TODO?? apri il file se non è già aperto
int apriFile(FILE** file, char* file_name, char* mode){
	int flag_open=0;

	*file = fopen(file_name, mode);

	if ((*file) == NULL){
	       puts("file non trovato");
	 }else{
		 puts("."); //TODO: da togliere poi serve solo per capire che è andato tutto bene
		 flag_open=1;
	 }
	return flag_open;
}



//TODO: capire come funziona perchè ho copiato e incollato
void strToUpper(char * str) {
  char * name;
  name = strtok(str,":");

  // Convert to upper case
  char *s = name;
  while (*s) {
    *s = toupper((unsigned char) *s);
    s++;
  }

}



/*    === PATTERN PER USARE I FILE ===
 *
 * FILE* file;
 *
 * if( apriFile(&file, FILENAME_ALIMENTI, "rb+") ){
 *
 *
 * 	// .... istruzioni che operano sul file ....
 *
 *
 * 	fclose(file);
 *
 * }
 *
 * */












//NULL == 0


//	FILE* file;
//	apriFile(&file, FILENAME_ALIMENTI, "rb+");
//	//file = fopen(FILENAME_ALIMENTI,"rb+");
//
//		t_alimento alimento;
//		//fseek(file, sizeof(t_alimento), SEEK_SET);
//		fread( &alimento, sizeof(t_alimento), 1, file);
//		puts("----");
//		print_alimento(alimento);
//		alimento.quantita += 100;
//		puts("----");
//		fseek(file, -1*sizeof(t_alimento), SEEK_CUR); // sposta di uno indietro
//		fwrite( &alimento, sizeof(t_alimento), 1, file);
//
//
//	fclose(file);


//fseek(file_alimenti, 0, SEEK_END); // posiziona alla fine
