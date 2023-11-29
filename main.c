#define _CRT_SECURE_NO_WARNINGS //for use scanf in Microsoft without no warnings
#include <stdio.h>
#define ROWS 3
#define COLS 3



void riempi(char mat[ROWS][COLS]);
void stampa(char mat[][COLS]);
int isTherATris(char mat[][COLS]);

int main() {
    char mat[ROWS][COLS];
    int i, j;
    int l = 0;
    int player = 0, player1 = 1, vinto = 0, counter = 0, tris = 0;

    riempi(mat);
    stampa(mat);

    while (!vinto && counter<9) {

        printf("Dammi indice di riga e di colonna \n");
        scanf("%d%d", &i, &j);

        if (counter % 2 == 0)
        {
            while (mat[i - 1][j - 1] == 'x' || mat[i - 1][j - 1] == 'o')
            {
                printf("Casella gia riempita, riprova! \n");
                printf("Dammi indice di riga e di colonna \n");
                scanf("%d%d", &i, &j);

            }
            mat[i - 1][j - 1] = 'o';
            stampa(mat);
            tris = isTherATris(mat);
            printf("%d\n", tris);
        }
        else
        {
            while (mat[i - 1][j - 1] == 'o' || mat[i - 1][j - 1] == 'x')
            {
                printf("Casella gia riempita, riprova! \n");
                printf("Dammi indice di riga e di colonna \n");
                scanf("%d%d", &i, &j);
            }
            mat[i - 1][j - 1] = 'x';
            stampa(mat);
        }
        counter++;

    }
    if(counter>=9){
        printf("partita finita");
    }
    
}
//fine while
int isTherATris(char mat[ROWS][COLS])
{
    int tris = 0;
    for (int i = 0; i < ROWS && !tris; i++)
    {
        tris = 0;
        if (mat[i][0] != '-' && mat[i][0] == mat[i][1] && mat[i][1] == mat[i][2])
        {
            tris = 1;
        }
    }
    if (!tris) {
        for (int i = 0; i < ROWS && !tris; i++)
        {
            tris = 0;
            if (mat[i][0] != '-' && mat[0][i] == mat[1][i] && mat[1][i] == mat[2][i])
            {
                tris = 1;
            }
        }
    }
    if (!tris) {
        if (mat[0][0] != '-' && mat[0][0] == mat[1][1] && mat[1][1] == mat[2][2])
        {
            tris = 1;
        }
    }
    if (!tris) {
        if (mat[0][2] != '-' && mat[0][2] == mat[1][1] && mat[1][1] == mat[2][0])
        {
            tris = 1;
        }
    }

    return tris;

}
void riempi(char mat[][COLS]) {

    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            mat[r][c] = '-';
        }

    }
}




void stampa(char mat[][COLS]) {
    for (size_t r = 0; r < ROWS; r++) {
        for (size_t c = 0; c < COLS; c++) {
            printf("%3c", mat[r][c]);
        }
        puts("\n");

    }
}
