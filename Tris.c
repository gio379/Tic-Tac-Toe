#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIM 3

void inzializzaTris(char tris[][DIM]) {
    for(int i=0;i<DIM;i++) {
        for(int j=0;j<DIM;j++) {
            tris[i][j] = '-';
        }
    }
}

void printTris(char tris[][DIM]) {
    for(int i=0;i<DIM;i++) {
        for(int j=0;j<DIM;j++) {
            printf("%c\t",tris[i][j]);
        }
        printf("\n\n");
    }
}

int vittoriaRigheX(char tris[][DIM]) {
    int vittoria = 0;
    if(tris[0][0]=='X' && tris[0][1]=='X' && tris[0][2]=='X') {
        vittoria = 1;
    } else if(tris[1][0]=='X' && tris[1][1]=='X' && tris[1][2]=='X') {
        vittoria = 1;
    } else if(tris[2][0]=='X' && tris[2][1]=='X' && tris[2][2]=='X') {
        vittoria = 1;
    }
    return vittoria;
}

int vittoriaRigheO(char tris[][DIM]) {
    int vittoria = 0;
    if(tris[0][0]=='O' && tris[0][1]=='O' && tris[0][2]=='O') {
        vittoria = 1;
    } else if(tris[1][0]=='O' && tris[1][1]=='O' && tris[1][2]=='O') {
        vittoria = 1;
    } else if(tris[2][0]=='O' && tris[2][1]=='O' && tris[2][2]=='O') {
        vittoria = 1;
    }
    return vittoria;
}

int vittoriaColonneX(char tris[][DIM]) {
    int vittoria = 0;
    if(tris[0][0]=='X' && tris[1][0]=='X' && tris[2][0]=='X') {
        vittoria = 1;
    } else if(tris[0][1]=='X' && tris[1][1]=='X' && tris[2][1]=='X') {
        vittoria = 1;
    } else if(tris[0][2]=='X' && tris[1][2]=='X' && tris[2][2]=='X') {
        vittoria = 1;
    }
    return vittoria;
}

int vittoriaColonneO(char tris[][DIM]) {
    int vittoria = 0;
    if(tris[0][0]=='O' && tris[1][0]=='O' && tris[2][0]=='O') {
        vittoria = 1;
    } else if(tris[0][1]=='O' && tris[1][1]=='O' && tris[2][1]=='O') {
        vittoria = 1;
    } else if(tris[0][2]=='O' && tris[1][2]=='O' && tris[2][2]=='O') {
        vittoria = 1;
    }
    return vittoria;
}

int vittoriaDiagonalepX(char tris[][DIM]) {
    int vittoria = 0;
    if(tris[0][0]=='X' && tris[1][1]=='X' && tris[2][2]=='X') {
        vittoria = 1;
    }
    return vittoria;
}

int vittoriaDiagonalepO(char tris[][DIM]) {
    int vittoria = 0;
    if(tris[0][0]=='O' && tris[1][1]=='O' && tris[2][2]=='O') {
        vittoria = 1;
    }
    return vittoria;
}

int vittoriaDiagonalesX(char tris[][DIM]) {
    int vittoria = 0;
    if(tris[0][2]=='X' && tris[1][1]=='X' && tris[2][0]=='X') {
        vittoria = 1;
    }
    return vittoria;
}

int vittoriaDiagonalesO(char tris[][DIM]) {
    int vittoria = 0;
    if(tris[0][2]=='O' && tris[1][1]=='O' && tris[2][0]=='O') {
        vittoria = 1;
    }
    return vittoria;
}

int main() {
    
    char tris[3][3];

    printf("\n");
    printf("0- Avvia Partita\n");
    int opzione;
    scanf("%d",&opzione);

    int vittorieG1 = 0;
    int vittorieG2 = 0;
    int pareggi = 0;

    while(opzione == 0) {
    
        inzializzaTris(tris);

        printf("\nTris!\n\n");

        printf("Turno di Giocatore 1:\n");
        printf("Premi 0 per lanciare il dado:\n");
        int sceltaDadoG1;
        scanf("%d",&sceltaDadoG1);
        int dadoG1;
        if(sceltaDadoG1 == 0) {
            printf("\n");
            srand(time(0));
            dadoG1 = (rand()%6)+1;
            printf("Numero estratto da Giocatore 1: %d\n",dadoG1);
        } else {
            printf("\n");
            printf("Lancio del dado non valido!\n");
            dadoG1 = 0;
            printf("Numero estratto da Giocatore 1: %d\n",dadoG1);
        }
        printf("\n");

        printf("Turno di Giocatore 2:\n");
        printf("Premi 0 per lanciare il dado:\n");
        int sceltaDadoG2;
        scanf("%d",&sceltaDadoG2);
        int dadoG2;
        if(sceltaDadoG2 == 0) {
            printf("\n");
            srand(time(0));
            dadoG2 = (rand()%6)+1;
            printf("Numero estratto da Giocatore 2: %d\n",dadoG2);
        } else {
            printf("\n");
            printf("Lancio del dado non valido!\n");
            dadoG2 = 0;
            printf("Numero estratto da Giocatore 2: %d\n",dadoG2);
        }
        printf("\n");

        int dadoG1_ = 0;
        int dadoG2_ = 0;

        if(dadoG1==dadoG2) {

            while (dadoG1_ == dadoG2_) {
                printf("Parità!\nLanciare i dadi nuovamente:\n");
                printf("\n");

                printf("Turno di Giocatore 1:\n");
                printf("Premi 0 per lanciare il dado:\n");
                int sceltaDadoG1_;
                scanf("%d",&sceltaDadoG1_);
                if(sceltaDadoG1_ == 0) {
                    printf("\n");
                    srand(time(0));
                    dadoG1_ = (rand()%6)+1;
                    printf("Numero estratto da Giocatore 1: %d\n",dadoG1_);
                } else {
                    printf("Lancio del dado non valido!\n");
                    dadoG1_ = 0;
                    printf("Numero estratto da Giocatore 1: %d\n",dadoG1_);
                }
                printf("\n");

                printf("Turno di Giocatore 2:\n");
                printf("Premi 0 per lanciare il dado:\n");
                int sceltaDadoG2_;
                scanf("%d",&sceltaDadoG2_);
                if(sceltaDadoG2_ == 0) {
                    printf("\n");
                    srand(time(0));
                    dadoG2_ = (rand()%6)+1;
                    printf("Numero estratto da Giocatore 2: %d\n",dadoG2_);
                } else {
                    printf("Lancio del dado non valido!\n");
                    dadoG2_ = 0;
                    printf("Numero estratto da Giocatore 2: %d\n",dadoG2_);
                }

                printf("\n");
            }

            if(dadoG1_ != dadoG2_) {

                int numero_turni = 1;
                if(dadoG1_>dadoG2_) {
                    while(numero_turni<=9) {
                        if(numero_turni%2!=0) {
                            printf("Giocatore 1 scelga dove posizionare X!\n");
                            int riga,colonna;
                            scanf("%d %d",&riga,&colonna);
                            tris[riga-1][colonna-1] = 'X';
                            printf("\n");
                            printTris(tris);
                            if (vittoriaRigheX(tris)) {
                                printf("Giocatore 1 vince!\nGrazie ad un tris di X in riga!\n");
                                break;
                            }
                            if (vittoriaRigheO(tris)) {
                                printf("Giocatore 2 vince!\nGrazie ad un tris di O in riga!\n");
                                break;
                            }
                            if (vittoriaColonneX(tris)) {
                                printf("Giocatore 1 vince!\nGrazie ad un tris di X in colonna!\n");
                                break;
                            }
                            if (vittoriaColonneO(tris)) {
                                printf("Giocatore 2 vince!\nGrazie ad un tris di O in colonna!\n");
                                break;
                            }
                            if (vittoriaDiagonalepX(tris)) {
                                printf("Giocatore 1 vince!\nGrazie ad un tris di X nella diagonale principale!\n");
                                break;
                            }
                            if (vittoriaDiagonalepO(tris)) {
                                printf("Giocatore 2 vince!\nGrazie ad un tris di O nella diagonale principale!\n");
                                break;
                            }
                            if (vittoriaDiagonalesX(tris)) {
                                printf("Giocatore 1 vince!\nGrazie ad un tris di X nella diagonale secondaria!\n");
                                break;
                            }
                            if (vittoriaDiagonalesO(tris)) {
                                printf("Giocatore 2 vince!\nGrazie ad un tris di O nella diagonale secondaria!\n");
                                break;
                            }
                        } else {
                            printf("Giocatore 2 scelga dove posizionare O!\n");
                            int riga,colonna;
                            scanf("%d %d",&riga,&colonna);
                            tris[riga-1][colonna-1] = 'O';
                            printf("\n");
                            printTris(tris);
                            if (vittoriaRigheX(tris)) {
                                printf("Giocatore 1 vince!\nGrazie ad un tris di X in riga!\n");
                                break;
                            }
                            if (vittoriaRigheO(tris)) {
                                printf("Giocatore 2 vince!\nGrazie ad un tris di O in riga!\n");
                                break;
                            }
                            if (vittoriaColonneX(tris)) {
                                printf("Giocatore 1 vince!\nGrazie ad un tris di X in colonna!\n");
                                break;
                            }
                            if (vittoriaColonneO(tris)) {
                                printf("Giocatore 2 vince!\nGrazie ad un tris di O in colonna!\n");
                                break;
                            }
                            if (vittoriaDiagonalepX(tris)) {
                                printf("Giocatore 1 vince!\nGrazie ad un tris di X nella diagonale principale!\n");
                                break;
                            }
                            if (vittoriaDiagonalepO(tris)) {
                                printf("Giocatore 2 vince!\nGrazie ad un tris di O nella diagonale principale!\n");
                                break;
                            }
                            if (vittoriaDiagonalesX(tris)) {
                                printf("Giocatore 1 vince!\nGrazie ad un tris di X nella diagonale secondaria!\n");
                                break;
                            }
                            if (vittoriaDiagonalesO(tris)) {
                                printf("Giocatore 2 vince!\nGrazie ad un tris di O nella diagonale secondaria!\n");
                                break;
                            }
                        }
                        numero_turni++;
                    }
                    if(!vittoriaRigheX(tris) && !vittoriaRigheO(tris) && !vittoriaColonneX(tris) && !vittoriaColonneO(tris) && !vittoriaDiagonalepX(tris) && !vittoriaDiagonalepO(tris) && !vittoriaDiagonalesX(tris) && !vittoriaDiagonalesO(tris))
                        printf("Pareggio!\n");
                } else {
                    while(numero_turni<=9) {
                    if(numero_turni%2!=0) {
                        printf("Giocatore 2 scelga dove posizionare O!\n");
                        int riga,colonna;
                        scanf("%d %d",&riga,&colonna);
                        tris[riga-1][colonna-1] = 'O';
                        printf("\n");
                        printTris(tris);
                        if (vittoriaRigheX(tris)) {
                                printf("Giocatore 1 vince!\nGrazie ad un tris di X in riga!\n");
                                break;
                            }
                            if (vittoriaRigheO(tris)) {
                                printf("Giocatore 2 vince!\nGrazie ad un tris di O in riga!\n");
                                break;
                            }
                            if (vittoriaColonneX(tris)) {
                                printf("Giocatore 1 vince!\nGrazie ad un tris di X in colonna!\n");
                                break;
                            }
                            if (vittoriaColonneO(tris)) {
                                printf("Giocatore 2 vince!\nGrazie ad un tris di O in colonna!\n");
                                break;
                            }
                            if (vittoriaDiagonalepX(tris)) {
                                printf("Giocatore 1 vince!\nGrazie ad un tris di X nella diagonale principale!\n");
                                break;
                            }
                            if (vittoriaDiagonalepO(tris)) {
                                printf("Giocatore 2 vince!\nGrazie ad un tris di O nella diagonale principale!\n");
                                break;
                            }
                            if (vittoriaDiagonalesX(tris)) {
                                printf("Giocatore 1 vince!\nGrazie ad un tris di X nella diagonale secondaria!\n");
                                break;
                            }
                            if (vittoriaDiagonalesO(tris)) {
                                printf("Giocatore 2 vince!\nGrazie ad un tris di O nella diagonale secondaria!\n");
                                break;
                            }
                    } else {
                        printf("Giocatore 1 scelga dove posizionare X!\n");
                        int riga,colonna;
                        scanf("%d %d",&riga,&colonna);
                        tris[riga-1][colonna-1] = 'X';
                        printf("\n");
                        printTris(tris);
                        if (vittoriaRigheX(tris)) {
                                printf("Giocatore 1 vince!\nGrazie ad un tris di X in riga!\n");
                                break;
                            }
                            if (vittoriaRigheO(tris)) {
                                printf("Giocatore 2 vince!\nGrazie ad un tris di O in riga!\n");
                                break;
                            }
                            if (vittoriaColonneX(tris)) {
                                printf("Giocatore 1 vince!\nGrazie ad un tris di X in colonna!\n");
                                break;
                            }
                            if (vittoriaColonneO(tris)) {
                                printf("Giocatore 2 vince!\nGrazie ad un tris di O in colonna!\n");
                                break;
                            }
                            if (vittoriaDiagonalepX(tris)) {
                                printf("Giocatore 1 vince!\nGrazie ad un tris di X nella diagonale principale!\n");
                                break;
                            }
                            if (vittoriaDiagonalepO(tris)) {
                                printf("Giocatore 2 vince!\nGrazie ad un tris di O nella diagonale principale!\n");
                                break;
                            }
                            if (vittoriaDiagonalesX(tris)) {
                                printf("Giocatore 1 vince!\nGrazie ad un tris di X nella diagonale secondaria!\n");
                                break;
                            }
                            if (vittoriaDiagonalesO(tris)) {
                                printf("Giocatore 2 vince!\nGrazie ad un tris di O nella diagonale secondaria!\n");
                                break;
                            }
                    }
                    numero_turni++;
                }
                if(!vittoriaRigheX(tris) && !vittoriaRigheO(tris) && !vittoriaColonneX(tris) && !vittoriaColonneO(tris) && !vittoriaDiagonalepX(tris) && !vittoriaDiagonalepO(tris) && !vittoriaDiagonalesX(tris) && !vittoriaDiagonalesO(tris))
                        printf("Pareggio!\n");
                }

            }

        } else {

            int numero_turni = 1;
            if(dadoG1>dadoG2) {
                while(numero_turni<=9) {
                    if(numero_turni%2!=0) {
                        printf("Giocatore 1 scelga dove posizionare X!\n");
                        int riga,colonna;
                        scanf("%d %d",&riga,&colonna);
                        tris[riga-1][colonna-1] = 'X';
                        printf("\n");
                        printTris(tris);
                        if (vittoriaRigheX(tris)) {
                                printf("Giocatore 1 vince!\nGrazie ad un tris di X in riga!\n");
                                break;
                            }
                            if (vittoriaRigheO(tris)) {
                                printf("Giocatore 2 vince!\nGrazie ad un tris di O in riga!\n");
                                break;
                            }
                            if (vittoriaColonneX(tris)) {
                                printf("Giocatore 1 vince!\nGrazie ad un tris di X in colonna!\n");
                                break;
                            }
                            if (vittoriaColonneO(tris)) {
                                printf("Giocatore 2 vince!\nGrazie ad un tris di O in colonna!\n");
                                break;
                            }
                            if (vittoriaDiagonalepX(tris)) {
                                printf("Giocatore 1 vince!\nGrazie ad un tris di X nella diagonale principale!\n");
                                break;
                            }
                            if (vittoriaDiagonalepO(tris)) {
                                printf("Giocatore 2 vince!\nGrazie ad un tris di O nella diagonale principale!\n");
                                break;
                            }
                            if (vittoriaDiagonalesX(tris)) {
                                printf("Giocatore 1 vince!\nGrazie ad un tris di X nella diagonale secondaria!\n");
                                break;
                            }
                            if (vittoriaDiagonalesO(tris)) {
                                printf("Giocatore 2 vince!\nGrazie ad un tris di O nella diagonale secondaria!\n");
                                break;
                            }
                    } else {
                        printf("Giocatore 2 scelga dove posizionare O!\n");
                        int riga,colonna;
                        scanf("%d %d",&riga,&colonna);
                        tris[riga-1][colonna-1] = 'O';
                        printf("\n");
                        printTris(tris);
                        if (vittoriaRigheX(tris)) {
                                printf("Giocatore 1 vince!\nGrazie ad un tris di X in riga!\n");
                                break;
                            }
                            if (vittoriaRigheO(tris)) {
                                printf("Giocatore 2 vince!\nGrazie ad un tris di O in riga!\n");
                                break;
                            }
                            if (vittoriaColonneX(tris)) {
                                printf("Giocatore 1 vince!\nGrazie ad un tris di X in colonna!\n");
                                break;
                            }
                            if (vittoriaColonneO(tris)) {
                                printf("Giocatore 2 vince!\nGrazie ad un tris di O in colonna!\n");
                                break;
                            }
                            if (vittoriaDiagonalepX(tris)) {
                                printf("Giocatore 1 vince!\nGrazie ad un tris di X nella diagonale principale!\n");
                                break;
                            }
                            if (vittoriaDiagonalepO(tris)) {
                                printf("Giocatore 2 vince!\nGrazie ad un tris di O nella diagonale principale!\n");
                                break;
                            }
                            if (vittoriaDiagonalesX(tris)) {
                                printf("Giocatore 1 vince!\nGrazie ad un tris di X nella diagonale secondaria!\n");
                                break;
                            }
                            if (vittoriaDiagonalesO(tris)) {
                                printf("Giocatore 2 vince!\nGrazie ad un tris di O nella diagonale secondaria!\n");
                                break;
                            }
                    }
                    numero_turni++;
                } 
                if(!vittoriaRigheX(tris) && !vittoriaRigheO(tris) && !vittoriaColonneX(tris) && !vittoriaColonneO(tris) && !vittoriaDiagonalepX(tris) && !vittoriaDiagonalepO(tris) && !vittoriaDiagonalesX(tris) && !vittoriaDiagonalesO(tris))
                    printf("Pareggio!\n");
            } else {
                while(numero_turni<=9) {
                if(numero_turni%2!=0) {
                    printf("Giocatore 2 scelga dove posizionare O!\n");
                    int riga,colonna;
                    scanf("%d %d",&riga,&colonna);
                    tris[riga-1][colonna-1] = 'O';
                    printf("\n");
                    printTris(tris);
                    if (vittoriaRigheX(tris)) {
                                printf("Giocatore 1 vince!\nGrazie ad un tris di X in riga!\n");
                                break;
                            }
                            if (vittoriaRigheO(tris)) {
                                printf("Giocatore 2 vince!\nGrazie ad un tris di O in riga!\n");
                                break;
                            }
                            if (vittoriaColonneX(tris)) {
                                printf("Giocatore 1 vince!\nGrazie ad un tris di X in colonna!\n");
                                break;
                            }
                            if (vittoriaColonneO(tris)) {
                                printf("Giocatore 2 vince!\nGrazie ad un tris di O in colonna!\n");
                                break;
                            }
                            if (vittoriaDiagonalepX(tris)) {
                                printf("Giocatore 1 vince!\nGrazie ad un tris di X nella diagonale principale!\n");
                                break;
                            }
                            if (vittoriaDiagonalepO(tris)) {
                                printf("Giocatore 2 vince!\nGrazie ad un tris di O nella diagonale principale!\n");
                                break;
                            }
                            if (vittoriaDiagonalesX(tris)) {
                                printf("Giocatore 1 vince!\nGrazie ad un tris di X nella diagonale secondaria!\n");
                                break;
                            }
                            if (vittoriaDiagonalesO(tris)) {
                                printf("Giocatore 2 vince!\nGrazie ad un tris di O nella diagonale secondaria!\n");
                                break;
                            }
                } else {
                    printf("Giocatore 1 scelga dove posizionare X!\n");
                    int riga,colonna;
                    scanf("%d %d",&riga,&colonna);
                    tris[riga-1][colonna-1] = 'X';
                    printf("\n");
                    printTris(tris);
                    if (vittoriaRigheX(tris)) {
                                printf("Giocatore 1 vince!\nGrazie ad un tris di X in riga!\n");
                                break;
                            }
                            if (vittoriaRigheO(tris)) {
                                printf("Giocatore 2 vince!\nGrazie ad un tris di O in riga!\n");
                                break;
                            }
                            if (vittoriaColonneX(tris)) {
                                printf("Giocatore 1 vince!\nGrazie ad un tris di X in colonna!\n");
                                break;
                            }
                            if (vittoriaColonneO(tris)) {
                                printf("Giocatore 2 vince!\nGrazie ad un tris di O in colonna!\n");
                                break;
                            }
                            if (vittoriaDiagonalepX(tris)) {
                                printf("Giocatore 1 vince!\nGrazie ad un tris di X nella diagonale principale!\n");
                                break;
                            }
                            if (vittoriaDiagonalepO(tris)) {
                                printf("Giocatore 2 vince!\nGrazie ad un tris di O nella diagonale principale!\n");
                                break;
                            }
                            if (vittoriaDiagonalesX(tris)) {
                                printf("Giocatore 1 vince!\nGrazie ad un tris di X nella diagonale secondaria!\n");
                                break;
                            }
                            if (vittoriaDiagonalesO(tris)) {
                                printf("Giocatore 2 vince!\nGrazie ad un tris di O nella diagonale secondaria!\n");
                                break;
                            }
                }
                numero_turni++;
            }
            if(!vittoriaRigheX(tris) && !vittoriaRigheO(tris) && !vittoriaColonneX(tris) && !vittoriaColonneO(tris) && !vittoriaDiagonalepX(tris) && !vittoriaDiagonalepO(tris) && !vittoriaDiagonalesX(tris) && !vittoriaDiagonalesO(tris))
                    printf("Pareggio!\n");
            }

        }

        if(vittoriaRigheX(tris) || vittoriaColonneX(tris) || vittoriaDiagonalepX(tris) || vittoriaDiagonalesX(tris)) {
            vittorieG1++;
        } else if(vittoriaRigheO(tris) || vittoriaColonneO(tris) || vittoriaDiagonalepO(tris) || vittoriaDiagonalesO(tris)) {
            vittorieG2++;
        } else {
            pareggi++;
        }

        printf("\n");
        printf("Vittorie Giocatore 1 = %d\nVittorie Giocatore 2 = %d\n",vittorieG1,vittorieG2);
        
        printf("\n");
        printf("0- Avvia Nuova Partita\n1- Termina e Visualizza il Risultato Finale\n");
        scanf("%d",&opzione);

        if(opzione == 1) {
            if(vittorieG1>vittorieG2) {
                printf("\nVince la sfida il Giocatore 1.\nCon %d incontro/i vinto/i su %d!\n",vittorieG1,vittorieG1+vittorieG2+pareggi);
            } else if(vittorieG1<vittorieG2) {
                printf("\nVince la sfida il Giocatore 2.\nCon %d incontro/i vinto/i su %d!\n",vittorieG2,vittorieG1+vittorieG2+pareggi);
            } else {
                printf("\nLa sfida finisce in parità, con %d vittoria/e a testa!\n",vittorieG1);
            }
        }

    }

}