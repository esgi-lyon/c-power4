// #pragma warning(disable : 4996) // pas besoin su mac
// includes expliqué dans l'exercice 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Définition d'une structure avec :
// une chaine de caractère d'une taille de 20 octets
// Une chaine de caractère c
// Un entier date
struct eleve { char nom[20]; char c; int date; } ;
// Typedef permet de rendre cette structure valable comme un type
// classe est une structure sans attributs
// pclasse est un alias de eleve (pointeur une structure eleve)
typedef struct eleve classe,*pclasse;

int main()
{
  // Définition de variables
	pclasse tab; // Variable du type de la structure classe, avec pour l'instant un NULL pointer
	int i,n, k;
	char m;

  // Allocation de l'espace mémoire nécéssaire pour le type structure pclasse
	tab = (pclasse) malloc(sizeof(struct eleve));
	/* tab pointeur sur zone mémoire de type classe*/
	printf("\n tab %p\n", tab);

  // Sauvegarde de la taille en octes de la structure eleve
	int S = sizeof(struct eleve);
	printf ("\n int S %d \n",S);

  // Affectations diverses
	n = 3;
	i = 0;

	k = 2000;
	m = 'B';
  // Chaine de caractère limitée à 20 octets
	char NOM[20] = "Hello World";
  // Copy d'une chaine de caractère vers le champ de la structure tab
	strcpy(tab->nom,"Hello World");
  // affectation d'entiers aux attributs de la structure tab
	tab->c = m;
	tab->date = k;
  // On affiche ici :
  // - la valeur de l'entier i
  // - la valeur de la chaine contenu dans l'attribut nom de la structure eleve
  // - Affichage d'une chaine de caractère en utilisant une valeur directement mais pas le pointeur comme avec %s
  // - Affichage entier de la structure
	printf("\n i = %d \t tab->nom =  %s\t tab->c = %c\t tab->date = %d \n",i, tab->nom,  tab->c, tab->date);

	printf("\n saisir un caractere : \n");
	// Entréer une chaine de caractère depuis la console, prend un espace mémoire en paramètre pour ensuite
	// copier la valeur du buffer vers cet espace mémoire
	scanf("%c", &m); // J'ai enlevé le _s car je suis sur mac
	// Affectation dans la structure de la valeur récupérée depuis la console avec scanf
	tab->c = m;
	// Affichage de l'entier i et
	// Affichage des attributs de la structure et son pointeur
	printf("\n tab %p\t i = %d \t tab->nom = %s\t tab->c = %c\t tab->j = %d \n\n", tab, i, tab->nom, tab->c, tab->date);

	printf("boucle d'ecriture sur la meme zone memoire : tab->date est reecrite\n");
	// Incrémenter date à chaque fois pour afficher une nouvelle année à chaque fois mais
	// aussi faire la mutation dans le champ de tab
	for (i = 0; i < n; i++)
	{
		// Copiee de la chaine NOM dans la zone mémoire de l'attribut nom de tab (structure eleve)
		strcpy(tab->nom,NOM);
		tab->c = m;
		tab->date = k++;
		// Affichage des attributs de la structure et son pointeur
		printf("\n tab %p\t i = %d \t tab->nom = %s\t tab->c = %c\t tab->j = %d \n",tab, i, tab->nom, tab->c, tab->date);
	}

	// Récupération de la taille de la chaine de caractère dans un entier g
	 int g = strlen(tab->nom);
	 // Affichage de cettte taille
	 printf("\n Longueur de Tab->nom : %d \n", g);
	 // afficher à chaque fois un certain nombre de la chaine de caractère en partant de la fin
	 // le fait de commencer avec la taille de l'attribut nom de tab permet de commencer
	 // à la position de fin de la chaine puis à chaque itéation d'afficher un caractère de plus
	 // jusqu'a atteindre 0
	 for (i = g; i >= 0; i--)
	 {
		 printf("\n nom eleve : %s \n",tab->nom + i);
	 }
	 // afficher à chaque fois un certain nombre de la chaine de caractère en partant du début
	 // Même chose que pour la boucle précédente sauf que cette fois on commence en affichant toute la chaine
	 // et au fur et à mesure on réduit les caractère affichés
	 for(i = 0; i < g; i++)
	 {
		 printf("\n nom eleve : %s \n",tab->nom + i);
	 }
	 printf("\n\n");

	// Libérer l'espace mémoire pris par tab
	free(tab);


} // tout est perdu, la zone mémoire est libérée, rendue au systeme
