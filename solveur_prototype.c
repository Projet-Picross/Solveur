#include <stdio.h>
#include <stdlib.h>
#define N 15

FILE * fichier;

void recup_result(int resultat[N][N]){
	int i, j;
	char detect;
	fichier = fopen("sauvegarde.txt","r");
	do{													// le diese est utilisé comme marqueur dans le fichier pour indiquer que la matrice résultat le suit
		fscanf(fichier,"%c",&detect);					// on avance jusqu'à atteindre le marqueur
	}while(detect != '#');
	fscanf(fichier,"%c",&detect);

	for(i = 0; i < N; i++){								//récupération de la matrice contenant le picross complet
		for(j = 0; j < N; j++){
			fscanf(fichier,"%i",&resultat[i][j]);
		}
	}
	fclose(fichier);
}

void recup_actuel(int mat[N][N]){
	int i, j;
	fichier = fopen("sauvegarde.txt","r");
	for(i = 0; i < N; i++){								//récupération de la matrice modifiée par l'utilisateur
		for(j = 0; j < N; j++){
			fscanf(fichier,"%i",&mat[i][j]);
		}
	}
	fclose(fichier);
}

void init_matrice(int matrice[N][N]){					//initialise la matrice avec des 0
	int i,j;
	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++){
			matrice[i][j] = 0;
		}
		printf("\n");
	}
}

void affichage(int m[N][N]){					
	int i,j;
	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++){
			printf("%i ", m[i][j]);
		}
		printf("\n");
	}
}

int solveur(int mat_user[N][N], int mat_result[N][N]){		//compare simultanément les 2 matrices (celle de l'utilisateur et la matrice résultat) et remplace les valeurs si nécessaire 
	int i, j;
	int compt = 0;
	for(i=0; i < N; i++){
		for(j=0; j < N; j++){
			if(mat_user[i][j] == mat_result[i][j]){
				compt++;
			}
			mat_user[i][j] = mat_result[i][j];
		}
	}
	printf("Vous avez %i bonnes cases sur %d \n", compt, N*N);
	return 1;
}

int main(){
	int mat_user[N][N];
	int mat_result[N][N];
	int check;
	init_matrice(mat_user);
	recup_actuel(mat_user);
	recup_result(mat_result);

	printf("Affichage de la matrice de l'utilisateur avant résolution \n");
	affichage(mat_user);
	printf("Affichage de la matrice de l'utilisateur après résolution \n");
	
	check = solveur(mat_user, mat_result);
	affichage(mat_user);
	if(check == 1){
		printf("Le solveur a fait son travail ! \n");
	}else{
		printf("Il y a un petit problème technique ... \n");
	}
	return 1;
}





















