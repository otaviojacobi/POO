#ifndef AUTOBUS_H 
#define AUTOBUS_H 

#include <stdbool.h>

struct ps_standard;
struct autobus;

struct autobus*  ab__creer(long max_assis, long max_debout);
void ab__liberer(struct autobus *);

//retourne le numero de l'arret courant
bool ab__a_place_assise(const struct autobus*);
bool ab__a_place_debout(const struct autobus*);

int ab__aller_arret_suivant(struct autobus *);

// debogue
void ab__affiche_etat(struct autobus *);
#endif //AUTOBUS_H 
