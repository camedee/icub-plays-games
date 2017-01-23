#include <stdio.h>
#include <iostream>
using namespace std;

void keySelect(unsigned char key, int x, int y);
int plateau[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };// modélisation de la grille et des pions déjà posés
int vide[9] = { 1, 1, 1, 1, 1, 1, 1, 1, 1 };// définit pour chaque case si elle est vide (e prenant en compte les coups pas encore joués)
int ptest[9];// similaire à "plateau", mais utilisé pour prévoir les coups
int turn = 1;// définit le joueur devant jouer

void afficher(int plateau[9]){// permet d'afficher sur la console la grille et les pions déjà posés
	printf("     |     |\n  ");if (plateau[6] == 0){printf(" ");}else{printf("%i",plateau[6]);}
	printf("  |  ");if (plateau[7] == 0){printf(" ");}else{printf("%i",plateau[7]);}
	printf("  |  "); if (plateau[8] == 0){ printf(" ");}else{printf("%i",plateau[8]);}
	printf(" \n-----+-----+-----\n     |     | \n  "); if (plateau[3] == 0){printf(" ");}else{printf("%i",plateau[3]);}
	printf("  |  "); if (plateau[4] == 0){printf(" ");}else{printf("%i",plateau[4]);}
	printf("  |  "); if (plateau[5] == 0){printf(" ");}else{printf("%i",plateau[5]);}
	printf("\n-----+-----+-----\n     |     | \n  "); if (plateau[0] == 0){printf(" ");}else{printf("%i",(plateau[0]));}
	printf("  |  "); if (plateau[1] == 0){printf(" ");}else{printf("%i",plateau[1]);}
	printf("  |  "); if (plateau[2] == 0){printf(" ");}else{printf("%i",plateau[2]);}
	printf("\n\n\n\n");
}

int diag(int plateau[9], int n){// retourne le joueur ayant rempli une diagonale (retourne 0 si aucune diagonale n'est possédée par un seul joueur)
	if (n == 1){
		if ((plateau[0] == plateau[4]) & (plateau[4] == plateau[8])){
			return plateau[0];
		}
		else{
			return 0;
		}
	}
	else{
		if ((plateau[2] == plateau[4]) & (plateau[4] == plateau[6])){
			return plateau[2];
		}
		else{
			return 0;
		}
	}
}

int line(int plateau[9],int n){// similaire à "diag" mais pour les lignes ;  Rq: on considère qu'il y a un joueur gagnant maximum
	if (n == 1){
		if ((plateau[0] == plateau[1]) & (plateau[2] == plateau[1])){
			return plateau[0];
		}
		else{
			return 0;
		}
	}
	if (n == 2){
		if ((plateau[3] == plateau[4]) & (plateau[4] == plateau[5])){
			return plateau[3];
		}
		else{
			return 0;
		}
	}
	else{
		if ((plateau[6] == plateau[7]) & (plateau[7] == plateau[8])){
			return plateau[8];
		}
		else{
			return 0;
		}
	}
}

int col(int plateau[9], int n){// similaire à "line"  mais pour les colonnes
	if (n == 1){
		if ((plateau[0] == plateau[3]) & (plateau[3] == plateau[6])){
			return plateau[0];
		}
		else{
			return 0;
		}
	}
	if (n == 2){
		if ((plateau[1] == plateau[4]) & (plateau[4] == plateau[7])){
			return plateau[1];
		}
		else{
			return 0;
		}
	}
	else{
		if ((plateau[2] == plateau[5]) & (plateau[5] == plateau[8])){
			return plateau[8];
		}
		else{
			return 0;
		}
	}
}


int win(int plateau[9]){// renvoie le joueur ayant gagné la partie ou 0 si la partie n'a pas (encore) été gagnée
	if ((line(plateau,1) == 1) | (line(plateau,2) == 1) | (line(plateau,3) == 1)){
		return 1;
	}
	if ((line(plateau,1) == 2) | (line(plateau,2) == 2) | (line(plateau,3) == 2)){
		return 2;
	}
	if ((col(plateau,1) == 1) | (col(plateau,2) == 1) | (col(plateau,3) == 1)){
		return 1;
	}
	if ((col(plateau,1) == 2) | (col(plateau,2) == 2) | (col(plateau,3) == 2)){
		return 2;
	}
	if ((diag(plateau,1) == 1) | (diag(plateau,2) == 1)){
		return 1;
	}
	if ((diag(plateau,1) == 2) | (diag(plateau,2) == 2)){
		return 2;
	}
	return 0;
}

int end(int plateau[9]){// booléen indiquant qu'aucune case n'est libre
	int res = 1;
	for (int i = 0; i < 9; i++){
		if (plateau[i] == 0){
			res = 0;
		}
	}
	return res;
}


void nextFromKey(){// permet au joueur humain de choisir une case
	unsigned char key;
	bool test = true;
	while (test){
		cin.get();
		cin >> key;
		if (key == '1'){
			if (plateau[0] == 0){
				plateau[0] = 1;
				vide[0] = 0;
				return;
			}
		}
		if (key == '2'){
			if (plateau[1] == 0){
				plateau[1] = 1;
				vide[1] = 0;
				return;
			}
		}
		if (key == '3'){
			if (plateau[2] == 0){
				plateau[2] = 1;
				vide[2] = 0;
				return;
			}
		}
		if (key == '4'){
			if (plateau[3] == 0){
				plateau[3] = 1;
				vide[3] = 0;
				return;
			}
		}
		if (key == '5'){
			if (plateau[4] == 0){
				plateau[4] = 1;
				vide[4] = 0;
				return;
			}
		}
		if (key == '6'){
			if (plateau[5] == 0){
				plateau[5] = 1;
				vide[5] = 0;
				return;
			}
		}
		if (key == '7'){
			if (plateau[6] == 0){
				plateau[6] = 1;
				vide[6] = 0;
				return;
			}
		}
		if (key == '8'){
			if (plateau[7] == 0){
				plateau[7] = 1;
				vide[7] = 0;
				return;
			}
		}
		if (key == '9'){
			if (plateau[8] == 0){
				plateau[8] = 1;
				vide[8] = 0;
				return;
			}
		}
	}
	return;
}


int eval(int plateau[9], int turn){// détermine si le plateau est favorable au joueur "turn"
	if (win(plateau) != 0){
		if (win(plateau) == turn){
			return -1;
		}
		return 1;
	}
	if (end(plateau)==1){
		return 0;
	}
	for (int i = 0; i < 9; i++){
		ptest[i] = plateau[i];
	}
	int pvic=-1;
	int pnull = -1;
	int pdef = -1;
	for (int i = 0; i < 9; i++){
		if (vide[i] == 1){
			ptest[i] = turn;
			vide[i] = 0;
			int evaluation = eval(ptest, turn - (int)(2 * (turn - 1.5f)));
			if (evaluation == 1){
				pvic = i;
			}
			if (evaluation == 0){
				pnull = i;
			}
			if (evaluation == -1){
				pdef = i;
			}
			ptest[i] = 0;
			vide[i] = 1;
		}
	}
	if (pvic != -1){
		return -1;
	}
	if (pnull != -1){
		return 0;
	}
	if (pdef != -1){
		return 1;
	}
	printf("eval pas normal");
	return 1;
}

void nextFromComp(){// permet à l'orinateur de choisir une case
	int ptest[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	for (int i = 0; i < 9; i++){
		ptest[i] = plateau[i];
	}
	int pnull = -1;
	int pdef = -1;
	for (int i = 0; i < 9; i++){
		if (vide[i] == 1){
			ptest[i] = 2;
			vide[i] = 0;
			int evaluation = eval(ptest, 1);
			if (evaluation==1){
				plateau[i] = 2;
				return;
			}
			if (evaluation == 0){
				pnull = i;
			}
			else{
				pdef = i;
			}
			ptest[i] = 0;
			vide[i] = 1;
		}
	}
	if (pnull != -1){
		plateau[pnull] = 2;
		vide[pnull] = 0;
		return;
	}
	if (pdef != -1){
		plateau[pdef] = 2;
		vide[pdef] = 0;
		return;
	}
	return;
}

unsigned char partie(){// lance une partie de morpion et retourne le caractère entré par l'utilisateur pour savoir s'il veut rejouer ou quitter
	for (int i = 0; i < 9; i++){
		plateau[i] = 0;
		vide[i] = 1;
	}
	afficher(plateau);
	//printf("     |     |\n  0  |  0  |  0 \n-----+-----+-----\n     |     |\n  0  |  0  |  0\n-----+-----+-----\n     |     |\n  0  |  0  |  0\n");
	while ((win(plateau) == 0) & (end(plateau) == 0)){
		if (turn == 1){
			nextFromKey();
			turn = 2;
		}
		else{
			nextFromComp();
			turn = 1;
		}
		//printf("     |     |\n  %i  |  %i  |  %i \n-----+-----+-----\n     |     |\n  %i  |  %i  |  %i\n-----+-----+-----\n     |     |\n  %i  |  %i  |  %i\n\n\n\n",
			//plateau[6], plateau[7], plateau[8], plateau[3], plateau[4], plateau[5], plateau[0], plateau[1], plateau[2]);
		afficher(plateau);
	}
	printf("The Winner IS %i\nType r to replay, q to quit\n", win(plateau));
	unsigned char key='o';
	while ((key != 'r') & (key != 'R') & (key != 'q') & (key != 'Q')){
		key = cin.get();
		//cin >> key;
	}
	return key;
}

int main(int argc, char* argv[]){
	unsigned char key='r';
	while ((key == 'r') | (key == 'R')){
		key=partie();
	}
}
