#include <stdio.h>

// apri il file se non è già aperto
//TODO: ritorna 1 se aperto correttamente
void apriFile(FILE** file, char* file_name, char* mode){

	*file = fopen(file_name, mode);

	if ((*file) == NULL){
	       puts("file non trovato");
	 }else{
		 puts(".");
	 }
}



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
