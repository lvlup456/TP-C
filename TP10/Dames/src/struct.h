#ifndef __STRUCT_H_
#define __STRUCT_H_

    typedef enum valeurs valeurs;

    enum valeurs {
        AS = 1,
        DEUX = 2,
        TROIS = 3,
        QUATRE = 4,
        CINQUE = 5,
        SIX = 6,
        SEPT = 7,
        HUIT = 8,
        NEUF = 9,
        DIX = 10,
        VALLET = 11,
        DAME = 12,
        ROI = 13
    };

    typedef enum couleurs couleurs;

    enum couleurs {
        PIQUE = 1,
        COEUR = 2,
        TREFLE = 3,
        CARREAU = 4,
        NUL = 5
    };

    typedef struct carte carte;

    struct carte{
        valeurs val;
        couleurs coul;
    };

    typedef struct joueur joueur;
 
    struct joueur{
        int tailleMain;
        carte* main;
        int points;
    };

    
    
#endif