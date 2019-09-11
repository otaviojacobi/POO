#include <stdio.h>
#include <stdlib.h>

static const char const *version __attribute__((unused))="Vers: 2.1";

#include "autobus.h"
#include "ps_standard.h"
#include "__internes.h"

struct ps_standard* ps__creer(char *nom, long arret_destination) {
  struct ps_standard* st = malloc(sizeof(struct ps_standard));
    st->nom = nom;
    st->debout = st->assis = false;
    st->destination = arret_destination;
    return st;
}

void ps__liberer(struct ps_standard *p) {
  free(p);
}

void ps__monter_dans(struct ps_standard *p, struct autobus *a) {
  if (ab__a_place_assise(a))
    __ab__montee_demander_assis(a, p);
  else if (ab__a_place_debout(a))
    __ab__montee_demander_debout(a, p);
}

char *ps__nom(const struct ps_standard *p) {
  return p->nom;
}

bool ps__est_dehors(const struct ps_standard *p) {
  return !ps__est_assis(p) && !ps__est_debout(p);
}

bool ps__est_assis(const struct ps_standard *p) {
  return p->assis;
}

bool ps__est_debout(const struct ps_standard *p) {
  return p->debout;
}

void ps__affiche_etat(struct ps_standard *p) {
  printf("%s <", p->nom);
  if (p->assis)
    printf("assis");
  else if (p->debout)
    printf("debout");
  else 
    printf("endehors");
  printf(">\n");
}

// fonctions internes
void __ps__nouvel_arret(struct ps_standard *p, 
			   struct autobus *a, int numero_arret) {
  if (p->destination <= numero_arret)
    __ab__arret_demander_sortie(a, p);
  /*
  if (ps__est_debout(p) && ab__a_place_assise(a))
    __ab__arret_demander_assis(a, p);
  */
}

