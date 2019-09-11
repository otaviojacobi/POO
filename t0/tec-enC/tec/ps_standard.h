#ifndef PS_STANDARD_H 
#define PS_STANDARD_H 

#include <stdbool.h>

struct autobus;
struct ps_standard;

struct ps_standard *ps__creer(char * nom, long arret_destination);
void ps__liberer(struct ps_standard *);

void ps__monter_dans(struct ps_standard *, struct autobus *);

bool ps__est_dehors(const struct ps_standard *);
bool ps__est_assis(const struct ps_standard *);
bool ps__est_debout(const struct ps_standard *);
char *ps__nom(const struct ps_standard *);

// debogue
void ps__affiche_etat(struct ps_standard *);
#endif //PS_STANDARD_H 
