#ifndef __TRANSFORMATION_H_
#define __TRANSFORMATION_H_

#include "structures.h"

sImage niveauDeGris(sImage image);
sImage seuillage(sImage image, int val);
sImage applyMatrice(sNoyau noyau, sImage image);


#endif
