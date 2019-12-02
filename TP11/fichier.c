/*! \file Programmation/2007-2008/Cours/Cours10/fichier.c
 *  \author Florent Devin <florent.devin@eisti.fr>
 *  \version 0.1
 *  \date Thu Dec 13 15:07:40 2007
 *
 *  \brief Exemple de manipulation de fichier
 *
 *
 */

// Inclusion des ent�tes de librairie
#include <stdlib.h>
#include <stdio.h>
// Inclusion pour pouvoir utiliser open
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
// Inclusion pour errno
#include <errno.h>
// Inclusion pour strerro
#include <string.h>

// D�finition de constantes
/*! \def PROG_OK
 *	Constante pour d�finir une terminaison correcte
 */
#define PROG_OK 0


/*! \def ERREUR_SYS
 *  Constante pour d�finir une terminaison par erreur
 *  syst�me
 */
#define ERREUR_SYS -1

/*! \fn int main (int argc, char** argv)
 *  \author Florent Devin <florent.devin@eisti.fr>
 *  \version 0.1
 *  \date Thu Dec 13 15:09:34 2007
 *
 *  \brief Fonction principale
 *
 *
 * \param argc : Nombre d'argument
 * \param argv : Tableau des arguments
 *�\return 0 : le programme doit se terminer normalement
 *
 * \remarks 
 */

int main (int argc, char** argv) {
	int int_fd;      // Descripteur de fichier
	int int_retour;  // Valeur de retour des fonctions
	
	// Ouverture du fichier et test de l'ouverture
	int_fd = open("toto" ,O_RDWR, S_IRUSR|S_IWUSR);
	if (int_fd == -1) {
		// Si pb alors on affiche un message
		fprintf (stderr,
						 "Probl�me d'ouverture du fichier : %s\n", strerror (errno));
		// et on quitte
		return (ERREUR_SYS);
	}

	// Ecriture de ab dans le fichier
	int_retour = write(int_fd, "ab", 2);
	// ATTENTION A LA TAILLE : EXEMPLE
	//	int_retour = write(int_fd, "ab", 7);
	if (int_retour == -1) {
		// Si pb d'ecriture, on affiche un message
		fprintf (stderr, "Probl�me d'�criture : %s\n", strerror (errno));
		// et on quitte, mais on ferme le fichier avant
		int_retour = close (int_fd);
		if (int_retour == -1) {
			// Si il y a un pb de fermeture alors on affiche un message 
			fprintf (stderr,
							 "Probl�me de fermeture du fichier : %s\n", strerror (errno));
		}
		return (ERREUR_SYS);
	}

	// Dans tous les cas, ici on ferme le fichier
	int_retour = close (int_fd);
	if (int_retour == -1) {
		// Si il y a un pb de fermeture alors on affiche un message 
		fprintf (stderr,
						 "Probl�me de fermeture du fichier : %s\n", strerror (errno));
		return (ERREUR_SYS);
	}
	
	//Fin du programme, Il se termine normalement, et donc retourne 0
	return (PROG_OK);
}