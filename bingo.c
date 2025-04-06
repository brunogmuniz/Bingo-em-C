#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int sorteio[60] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int i = 0;


int sorteador() {
    srand(time(NULL));
    int Nmr = 1 + rand() % 60;
    int j;
    for (j = 0; j < 60; j++) {
        if (Nmr == sorteio[j]) {
			Nmr = 1 + rand() % 60;
            j = -1; 
        }
    }
    
    printf("\n\n\033[32m O numero sorteado eh: %d \033[0m \n", Nmr);
    sorteio [i] = Nmr;
    i++;
    return Nmr;
}

int vence(int vencedor[][5]){
    int linha, coluna;
    for (linha = 0; linha < 3; linha++) {
        for (coluna = 0; coluna < 5; coluna++) {
            if (vencedor[linha][coluna] != -1) {
                return 0; // não ganhou
            }
        }
    }
    return 1; // ganhou
}


int main (){
	srand(time(NULL));
 	printf ("Bem Vind@ ao Nosso Bingo!");
	int jogador1 [3][5];
 	int jogador2 [3][5];
 	int jogador3 [3][5];
 	int linha,coluna,j,k = 0;
 	int cartela1[15] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};
 	int cartela2[15] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};
 	int cartela3[15] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};
 	
 printf ("\n  \n  JOGADOR 1: "); //JOGADOR 1
	for (linha=0; linha<3; linha++){
			for (coluna=0;coluna<5; coluna++){
			jogador1[linha][coluna] = 1 + rand() % 60;
				
			for (j = 0; j < 15; j++) {
				if (jogador1[linha][coluna] == cartela1[j]) {
				jogador1[linha][coluna] = 1 + rand() % 60;
           		j = -1; 
				}
				
			}
			cartela1[k] = jogador1[linha][coluna];
				k++;
		}
	}
		
	printf ("\n");
		for (linha=0; linha<3; linha++){
			for (coluna=0; coluna<5; coluna++){
			printf("  %d", jogador1[linha][coluna]);
			}
			printf ("\n");
		}


	k = 0;
	printf ("\n  \n  JOGADOR 2: "); //JOGADOR 2
	for (linha=0; linha<3; linha++){
			for (coluna=0;coluna<5; coluna++){
			jogador2[linha][coluna] = 1 + rand() % 60;
				
			for (j = 0; j < 15; j++) {
				if (jogador2[linha][coluna] == cartela2[j]) {
				jogador2[linha][coluna] = 1 + rand() % 60;
           		j = -1; 
				}
				
			}
			cartela2[k] = jogador2[linha][coluna];
			k++;
		}
	}
		printf ("\n");
		for (linha=0; linha<3; linha++){
			for (coluna=0; coluna<5; coluna++){
			printf("  %d", jogador2[linha][coluna]);
			}
			printf ("\n");
		}
		
	k = 0;
	printf ("\n  \n  JOGADOR 3: "); //JOGADOR 3
	for (linha=0; linha<3; linha++){
			for (coluna=0;coluna<5; coluna++){
			jogador3[linha][coluna] = 1 + rand() % 60;
				
			for (j = 0; j < 15; j++) {
				if (jogador3[linha][coluna] == cartela3[j]) {
				jogador3[linha][coluna] = 1 + rand() % 60;
           		j = -1; 
				}
				
			}
			cartela3[k] = jogador3[linha][coluna];
			k++;
		}
	}
		
	printf ("\n");
		for (linha=0; linha<3; linha++){
			for (coluna=0; coluna<5; coluna++){
			printf("   %d", jogador3[linha][coluna]);
			}
			printf ("\n");
		}
	
	
	
	
	
	//Começa o jogo
	char start,outro;
	int ganhou = 0;
	printf("\n DIGITE C PARA STARTAR: ");
	scanf ("%c", &start);
	if (start =='c' || start=='C'){ // startou
	getchar();
	int jogo = 0;
	
		do{
			system("cls");
			int Nmr=sorteador();
				for (linha=0; linha<3; linha++){ //testar cartela jogador1
					for (coluna=0;coluna<5; coluna++){
						if (jogador1[linha][coluna] == Nmr){
						jogador1[linha][coluna] = -1;
						ganhou =vence(jogador1);
						}
							if (ganhou == 1){
								jogo = 1;
								printf ("\n BINGO! O JOGADOR 1 GANHOU!\n");
								exit(0);
							}
					}
				}
				
				printf ("\n JOGADOR 1:\n");
				for (linha=0;linha<3;linha++){ //mostrar cartela jogador1
					for (coluna=0;coluna<5;coluna++){
						printf("  %d", jogador1[linha][coluna]);
					}
					printf (" \n");
				}
				
				
			for (linha = 0; linha<3; linha++){ //testar cartela jogador2
					for (coluna = 0;coluna<5; coluna++){
						if (jogador2[linha][coluna] == Nmr){
						jogador2[linha][coluna] = -1;
						ganhou = vence(jogador2);
						}
							if (ganhou == 1){
									jogo = 1;
							printf ("\n BINGO! O JOGADOR 2 GANHOU!\n");
							exit(0);
							}
					}
				}
				
				printf ("\n JOGADOR 2:\n");
				for (linha=0;linha<3;linha++){ //mostrar cartela jogador2
					for (coluna=0;coluna<5;coluna++){
						printf("  %d", jogador2[linha][coluna]);
					}
					printf (" \n");
				}
			
			
			for (linha=0; linha<3; linha++){ //testar cartela jogador3
					for (coluna=0;coluna<5; coluna++){
						if (jogador3[linha][coluna] == Nmr){
						jogador3[linha][coluna] = -1;
						ganhou = vence(jogador3);
							if (ganhou == 1){	jogo = 1;
								printf ("\n BINGO! O JOGADOR 3 GANHOU!\n");
								exit(0);
							}
					}
				}
				
				}
				printf ("\n JOGADOR 3:\n");
				for (linha=0;linha<3;linha++){ //mostrar cartela jogador3
					for (coluna=0;coluna<5;coluna++){
						printf("  %d", jogador3[linha][coluna]);
					}
					printf (" \n");
				}
			printf ("\n  *Pressione Enter Para sortear mais numeros*");
			getchar();
		
	}while (jogo == 0);
		
	}
	else {
		system("cls");
		printf("\033[0;31m");
		printf ("\nNao quer jogar? blz!");
		printf("\033[0m");
	}
	return 0;
}
