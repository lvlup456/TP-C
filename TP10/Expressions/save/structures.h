
#ifndef __STRUCTURE_H_
#define __STRUCTURE_H_

typedef struct nombreComplexe nombreComplexe;

struct nombreComplexe{
    float reelle;
    float imaginaire;
};

typedef struct solutionEqu2d solutionEqu2d;

struct solutionEqu2d{
    struct nombreComplexe racine1;
    struct nombreComplexe racine2;
};

typedef struct solutionEqu3d solutionEqu3d;

struct solutionEqu3d{
    struct nombreComplexe racine1;
    struct nombreComplexe racine2;
    struct nombreComplexe racine3;
};

#endif