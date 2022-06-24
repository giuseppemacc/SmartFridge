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
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

#define ROW 6
#define COLUMN 6
#define N_SHIP 6
#define MAX_ATTEMPTS 10

typedef struct{
  int x;
  int y;
} t_coord;

// genera n_ship coordinate e le memorizza in coord_ships
// ogni coordinata è generata in maniera casuale in un range tra 0 e ROW-1 per le y e tra 0 e COLUMN-1 per le x
// tutte le coordinate generate sono distinte tra loro
void gen_randomShips(t_coord coord_ships[], const int n_ship);

// ricerca cord nell'array di coordinate coords
// ritorna 1 se coord è presente in coords
// ritorna 0 se coord non è presente in coords
int ricerca_coord(const t_coord cord, const t_coord coords[], const int n_coord );

// genera un numero random compreso tra min e max
int rand_inRange(int min, int max);

// fa inserire all'utente una coordinata scritta necessariamente nel formato A1,a1,B3,c5 ...
// e la converte nelle corrispondenti coordinate per la matrice grid
void inputCoord(t_coord *coord, const char grid[ROW][COLUMN]);

// attacca alla coordinata strike_coords
// fa visualizzare il messaggio "COLPITO" o "MANCATO"
// se necessario incrementa il punteggio
void strike(char grid[ROW][COLUMN], const t_coord coord_ships[], const int n_ships, const t_coord strike_coord, int *punteggio);

// visualizza la griglia
void viewGrid(const char grid[ROW][COLUMN]);

// visualizza le coordinate delle navi
void viewCoordships(const t_coord coord_ships[], const int n_ships);


int main(void) {
  setvbuf(stdout, NULL, _IONBF, 0);
  srand(time(NULL));

  char Grid[ROW][COLUMN];


  t_coord coord_ships[N_SHIP]; // array con le coord delle navi
  t_coord strike_coord; // coordinate in cui attaccare
  int punteggio=0;
  int n_attempts=0;

  //inizializza Grid a '.'
  int x,y;
  for(y=0; y<ROW; y++){
    for(x=0; x<COLUMN; x++){
      Grid[y][x] = '.';
    }
  }

  gen_randomShips(coord_ships, N_SHIP); // genera le coordinate delle navi
  viewGrid(Grid);

  // esce o quando è stato raggiunto il numero massimo di tentaivi
  // o quando sono state trovare tutte le navi
  while(n_attempts<MAX_ATTEMPTS && punteggio<N_SHIP){
    inputCoord(&strike_coord, Grid); // fa inserire all'utente la coordinate in cui attaccare
    strike( Grid, coord_ships, N_SHIP, strike_coord, &punteggio); // attacca a quella coordinata e incrementa punteggio se necessario
    n_attempts++;
    printf("tentativi %d/%d\tnavi colpite: %d/%d",n_attempts,MAX_ATTEMPTS,punteggio,N_SHIP);
    viewGrid(Grid);
  }

  if(punteggio == N_SHIP){
    printf("HAI VINTO!\n");
  }else{
    printf("HAI PERSO!\n");
  }
  printf(" punteggio: %d/%d\n",punteggio,N_SHIP);

  printf("le navi erano in posizione: ");
  viewCoordships(coord_ships, N_SHIP);
  return 0;
}

void viewCoordships(const t_coord coord_ships[], const int n_ships){
  int i=0;
  printf("{");
  for(i=0; i<n_ships; i++){
    printf("(%c%d)",'A'+coord_ships[i].x, coord_ships[i].y+1);
    if(i < n_ships-1)
      printf(", ");
  }
  printf("}");
}

void inputCoord(t_coord *coord, const char grid[ROW][COLUMN]){

  int flag_error;
  char input[100];
  int input_len;

  do{
    flag_error = 1;
    printf("\nInserisci la coordinata in cui colpire >> ");
    scanf("%s",input);
    input_len = strlen(input);

    if(input_len == 2){
      coord->x = toupper(input[0])-'A'; // 65 = ASCII di 'A'
      if( coord->x>=0 && coord->x<=(COLUMN-1) ){ // x deve essere compreso tra A e F
        coord->y = input[1]-'1'; // 49 = ASCII di '1'
        if( coord->y>=0 && coord->y<=ROW-1 ){ // y deve essere compreso tra 1 e 6
          if( grid[coord->y][coord->x] == '.' ){  // controlla che in coord non sia già avvenuto un attacco
            flag_error = 0;
          }else{
            puts("\tNon puoi eseguire più volte la stessa mossa!");
          }
        }else{
          puts("\tLa riga deve essere un numero compreso tra 1 e 6");
        }
      }else{
        puts("\tLa colonna deve essere una lettera compresa tra A e F");
      }
    }else{
      puts("\tLe coordinate devono essere scritte nel formato A1, a1, B3, b3 ...");
    }
  }while(flag_error==1);
}

void strike(char grid[ROW][COLUMN], const t_coord coord_ships[], const int n_ships, const t_coord strike_coord, int *punteggio){
  if( ricerca_coord(strike_coord, coord_ships, n_ships) == 1 ){
    printf("COLPITO \t");
    grid[strike_coord.y][strike_coord.x] = 'x';
    *punteggio += 1;
  }else{
    printf("MANCATO \t");
    grid[strike_coord.y][strike_coord.x] = 'o';
  }
}

void viewGrid(const char grid[ROW][COLUMN]){
  int x,y;
  puts("\n-------------");
  printf("  A B C D E F");
  for(y=0; y<ROW; y++){
    printf("\n%d ", y+1 );
    for(x=0; x<COLUMN; x++){
      printf("%c ",grid[y][x]);
    }
  }
  puts("\n-------------\n");
}

void gen_randomShips(t_coord coord_ships[], const int n_ship){
  t_coord random_coord;
  int i=0;
  while(i<n_ship){
    random_coord.x = rand_inRange(0,COLUMN-1);
    random_coord.y = rand_inRange(0,ROW-1);
    if( ricerca_coord(random_coord, coord_ships, n_ship) == 0 ){ // se è una coordinata che non è già stata generata
      coord_ships[i].x = random_coord.x;
      coord_ships[i].y = random_coord.y;
      i++;
    }
  }
}

int ricerca_coord(const t_coord cord, const t_coord coords[], const int n_coord ){
  int found=0;
  int i=0;
  while(i<n_coord && found==0){
    if( (cord.x == coords[i].x) && (cord.y == coords[i].y) ){
      found=1;
    }
    i++;
  }
  return found;
}

int rand_inRange(int min, int max){
  // (MAX-MIN+1) + MIN
  return rand() % (max-min+1) + min;
}
