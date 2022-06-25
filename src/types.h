
#ifndef TYPES_H_
#define TYPES_H_


typedef enum{
	CARNE, PESCE, VERDURE, PASTA
} categorie;

typedef struct {
	char nome[50];
	int quantita;
	int peso;
	int dispensa;
} t_alimento;

typedef struct {
	char nome[50];
	int n_ingredienti;
	t_alimento ingredienti[50];
	categorie categoria;
	char procedimento[200];
	int valutazione;
	int proposta; // V/F
} t_ricetta;





#endif /* TYPES_H_ */
