//NAMA     : DIMAS RAGA
//NRP      : 5022221048
//KELOMPOK : TE07
#include <stdio.h>
#include <stdlib.h>
//mencetak papan board untuk pilihan 1 lawan bot
void Move1(char* mode1) {
    for (int i = 0; i < 3; ++i) {
        printf(" %c %c %c \n", mode1[i*3]==' ' ? '.' : mode1[i*3], mode1[i*3+1]==' ' ? '.' : mode1[i*3+1], mode1[i*3+2]==' ' ? '.' : mode1[i*3+2]);
    }
}
//mencetak papan board untuk pilihan 2 lawan player
void Move2(char * mode2) {
    for (int i = 0; i < 3; ++i) {
        printf(" %c %c %c \n", mode2[i*3]==' ' ? '.' : mode2[i*3], mode2[i*3+1]==' ' ? '.' : mode2[i*3+1], mode2[i*3+2]==' ' ? '.' : mode2[i*3+2]);
    }
}
//fungsi game tic tac toe untuk komponen dari pilihan 1 lawan bot
void play1(char* mode1, int pos1, int turn1) {
    if (turn1%2==0)
        mode1[pos1] = 'X';
    else
        mode1[pos1] = 'O';
}
//fungsi game tic tac toe untuk komponen dari pilihan 1 lawan bot
void play2(char* mode2, int pos2, int turn2) {
    if (turn2%2==0) 
        mode2[pos2] = 'X';
    else 
        mode2[pos2] = 'O';
}
//mengecek kesamaan dari pilihan 1 lawan bot
int ceksama1(char* mode1, int a1, int b1, int c1) {
    if (mode1[a1] == mode1[b1] && mode1[a1] == mode1[c1]) {
        if (mode1[a1] == 'X')
            return 1;
        if (mode1[a1] == 'O')
            return -1;
    }
    return 0;
}
//mengecek kesamaan dari pilihan 2 lawan player
int ceksama2(char * mode2, int a2, int b2, int c2) {
    if (mode2[a2] == mode2[b2] && mode2[a2] == mode2[c2]) {
        if (mode2[a2] == 'X') 
            return 1;
        if (mode2[a2] == 'O') 
            return -1;
    }
    return 0;
}
//pengecekan menang pada pilihan 1 lawan bot
int win1(char* mode1) {
    int hasil1 = 0;
        hasil1 += ceksama1(mode1, 0, 4, 8);
        hasil1 += ceksama1(mode1, 2, 4, 6);
    for (int i = 0; i < 3 && hasil1 == 0; ++i) {
        hasil1 += ceksama1(mode1, i*3, i*3+1, i*3+2);
        hasil1 += ceksama1(mode1, i, i+3, i+6);;
    }
    return hasil1;
}
//pengecekan menang pada pilihan 2 lawan player
int win2(char * mode2) {
    int hasil2 = 0;
        hasil2 += ceksama2(mode2, 0, 4, 8);
        hasil2 += ceksama2(mode2, 2, 4, 6);
    for (int i = 0; i < 3 && hasil2 == 0; ++i) {
        hasil2 += ceksama2(mode2, i * 3, i * 3 + 1, i * 3 + 2);
        hasil2 += ceksama2(mode2, i, i + 3, i + 6);;
    }
    return hasil2;
}
//fungsi untuk menjelaskan langkah terbaik untuk bot
int lawanbot(char* mode1, int turn1, int* nextmovebot) {
    int w1 = win1(mode1);
    if (turn1 == 9 || w1 != 0)
        return w1;
    int nilaibot = 2;
    if (turn1 % 2 == 0)
        nilaibot = -nilaibot;
    for (int i = 0; i < 9; ++i) {
        if (mode1[i] != ' ')
            continue;
        play1(mode1, i, turn1);
        int nextlb = lawanbot(mode1, turn1 + 1, nextmovebot + 1);
        if ((nilaibot < nextlb && turn1 % 2 == 0) || (nilaibot > nextlb && turn1 % 2 == 1)) {
            nilaibot = nextlb;
            *nextmovebot = i;
        }
        mode1[i] = ' ';
    }
    return nilaibot;
}
//fungsi utama main
int main() {
    int a;
    printf("PvB mode = 1\n");
    printf("PvP mode = 2\n");
    printf("Pilih Mode = ");
    scanf("%d", &a);

    //
    if(a==1){
        char mode1[9];
        for (int i = 0; i < 9; ++i)
            mode1[i] = ' ';
        for (int turn1 = 0; turn1 < 9 && win1(mode1) == 0; ++turn1) {
            Move1(mode1);
            if (turn1 % 2 == 1) {
                    printf("Bot : \n");
                    int botplay1[9];
                    lawanbot(mode1, turn1, botplay1);
                    play1(mode1, botplay1[0], turn1);
                    continue;
            }
            int i, j;
            awal_1:
            printf("Player1 your move: ");
            scanf("%d %d", &i, &j);
            if( i>2 || j>2 ){
                printf("\nInvalid move\n\n");
                goto awal_1;
            }else{
                play1(mode1, i*3+j, turn1);
            }
        }
        Move1(mode1);
        int hasil1 = win1(mode1);
        if(hasil1 == 1){
            printf("Player1 wins.\n");
        }else if(hasil1 == -1){
            printf("Bot wins.\n");
        }else{
            printf("Draw.\n");
        }
    }

    if(a==2){
        char mode2[9];
        for (int i = 0; i < 9; ++i)
            mode2[i] = ' ';
        for (int turn2 = 0; turn2 < 9 && win2(mode2) == 0; ++turn2) {
            Move2(mode2);
            int i, j;
            awal_2:
            printf("Player%d your move: ", (turn2 % 2) + 1);
            scanf(" %d %d", &i, &j);
            if( i>2 || j>2 ){
                printf("\nInvalid move\n\n");
                goto awal_2;
            }else{
            play2(mode2, i * 3 + j, turn2);
            }
        }
        Move2(mode2);
        int hasil2 = win2(mode2);
        if(hasil2 == 1) {
            printf("Player1 wins.\n");
        }else if(hasil2 == -1) {
            printf("Player2 wins.\n");
        }else{
            printf("Draw.\n");
        }
    }
    return 0;
}
