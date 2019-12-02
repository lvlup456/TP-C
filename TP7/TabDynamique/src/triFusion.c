/**
 * @file triFusion.c
 * @author Durand Thomas
 * @brief ensemble des foncions lie au tri Fusion
 * @version 0.1
 * @date 2019-11-12
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief creer un sous tableau et copie les valeurs du tableau dedans 
 * 
 * @param src tableau source
 * @param debut debut des valeurs a copie
 * @param fin fin des valeurs a copie
 * @return int* le sous tableau cree
 */
int* copieSousTableau(int* src,int debut,int fin){
    int* dest = malloc((fin - debut)*sizeof(int));
    int j = 0;
    for (int i = debut; i < fin; i++){
        dest[j] = src[i];
        j++;
    }
    return dest;
}

/**
 * @brief fusionne 2 tableau en les triants
 * 
 * @param tab1 premier tableau
 * @param taille1 taille du premier tableau
 * @param tab2 deuxieme tableau
 * @param taille2 taille du deuxieme tableau
 * @param tabRes tableau resultat qui vas accueillir la fusion trie 
 */
void fusion(int* tab1, int taille1, int* tab2, int taille2,int* tabRes){
    int indice1 = 0;
    int indice2 = 0;
    int indiceRes = 0;
    while (indice1 < taille1 && indice2 < taille2){
        if (tab1[indice1] < tab2[indice2]){
            tabRes[indiceRes] = tab1[indice1];
            indice1 ++;
        }else{
            tabRes[indiceRes] = tab2[indice2];
            indice2 ++;
        }
        indiceRes ++;
    }
    if (indice1 < taille1){
        for (int i = indice1; i < taille1; i++){
            tabRes[indiceRes] = tab1[i];
            indiceRes++;
        }
    }else if (indice2 < taille2){
        for (int i = indice2; i < taille2; i++){
            tabRes[indiceRes] = tab2[i];
            indiceRes++;
        }
    }

}
/**
 * @brief execute le tri fusion sur un tableau
 * 
 * @param tab le tableau a trie
 * @param taille taille du tableau
 */
void triFusion(int* tab, int taille){
    if (taille > 1){
        int millieu = taille/2;
        int* tab1 = copieSousTableau(tab,0,millieu);
        int* tab2 = copieSousTableau(tab,millieu,taille);
        triFusion(tab1,millieu);
        triFusion(tab2,taille-millieu);
        fusion(tab1,millieu,tab2,taille-millieu,tab);
        free(tab1);
        free(tab2);
    }
}