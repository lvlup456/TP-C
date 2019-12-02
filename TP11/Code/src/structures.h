#ifndef __STRUCTURE_H_
#define __STRUCTURE_H_

typedef struct sPixel sPixel;

struct sPixel{
    int r;
    int v;
    int b;
};

typedef struct sImage sImage;

struct sImage{
    sPixel** image;
    char type;
    char separateur;
    int hauteur;
    int largeur;
    int valMax;  
};

typedef struct sNoyau sNoyau;

struct sNoyau{
    int** matrice;
    int taille;
};



#endif