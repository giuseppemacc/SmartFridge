#include <stdio.h>


FILE* apriFile(char* file_name){
	FILE* file;

	file = fopen(file_name, "rb+");

	if ((file) == NULL){
	       puts("file non trovato");
	 }

	return file;
}

void chiudiFile(FILE* file){
	if(!fclose(file)){
		puts("\n--");
	}else{
		puts("impossibile chiudere il file");
	}
}
