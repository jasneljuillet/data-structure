#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//declaraion des methodes

typedef struct ListeDouble LD;
struct ListeDouble {
	int donnee;
	LD *suivant;
	LD *precedent;
};

LD *tete, *nouveau;

void initialiser();
void ajouttete(int x);
void ajoutfin(int x);
void afficher();

int main() {
	int x, i, n;
	
	do {
		printf("Entrez n\t");
		scanf("%d", &n);
	} while( n <= 0);
	
	initialiser();
	for (i = 1; i <= n; i++) {
		printf("Entrer la donner a la tete ");
		scanf("%d", &x);
		ajouttete(x);
	}
	
	system("cls");
	afficher();
	getch();
	system("cls");
	
	printf("Entrer la donner a la fin ");
	scanf("%d", &x);
	ajoutfin(x);
	system("cls");
	afficher();
	getch();

}

void initialiser() {
	tete = NULL;
}

void ajouttete(int x) {
	nouveau = new LD;
	nouveau -> donnee = x;
	
	if(tete != NULL) {
		nouveau -> suivant = tete;
		tete -> precedent = nouveau;
		tete = nouveau;
	} else {
		nouveau -> suivant = tete;
		tete = nouveau;
	}
}

void ajoutfin(int x) {
	LD *p;
	nouveau = new LD;
	nouveau -> donnee = x;
	nouveau -> suivant = NULL;
	
	if(tete != NULL) {
		p = tete;
		
		while(p -> suivant != NULL)
			p = p -> suivant;
			nouveau -> precedent = p;
			p -> suivant = nouveau;
	}
	
}

void afficher() {
	LD *p;
	
	if(tete != NULL) {
		p = tete;
		
		while( p != NULL) {
			printf("%d\t",p -> donnee);
			p = p -> suivant;
		}
	}
}
