#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static const char const *version __attribute__((unused))="Vers: 2.1";

#include "ps_standard.h"
#include "autobus.h"
#include "__internes.h"

static int recherche_passager(struct ps_standard **passagers, 
			      const struct ps_standard *p) {
  for (int i = 0; i < MAX; i++)
    if (p == passagers[i])
      return i;
  return -999999;
}

static void ajouter_passager(struct ps_standard **passagers, 
			     const struct ps_standard *p) {
  int k = recherche_passager(passagers, NULL);
  passagers[k] = (struct ps_standard *) p;
}

static void supprimer_passager(struct ps_standard **passagers, 
			      const struct ps_standard *p) {
  
  int k = recherche_passager(passagers, p);
  passagers[k] = NULL;
}

struct autobus*  ab__creer(long max_assis, long max_debout) {
  struct autobus *a = calloc(1, sizeof(struct autobus));
  a->debout = a->assis = 0;
  a->max_assis = max_assis;
  a->max_debout = max_debout;
  a->arret = 0;
  return a;
}

void ab__liberer(struct autobus *a) {
  free(a);
}

bool ab__a_place_assise(const struct autobus *a) {
  return a->assis < a->max_assis;
}

bool ab__a_place_debout(const struct autobus *a) {
  return a->debout < a->max_debout;
}

int ab__aller_arret_suivant(struct autobus *a) {
  a->arret++;

  for (int i = 0; i < MAX; i++)
    if (NULL != a->passagers[i])
      __ps__nouvel_arret(a->passagers[i], a, a->arret);

  return a->arret;
}

void ab__affiche_etat(struct autobus *a) {
  printf("[arret %d] assis<%d> debout<%d>\n", 
	 a->arret, (int) (a->max_assis - a->assis), 
	 (int) (a->max_debout - a->debout));
}

// fonctions internes
void __ab__montee_demander_assis(struct autobus *a, struct ps_standard *p) {
  ajouter_passager(a->passagers, p);

  a->assis++;
  p->assis = true;
  p->debout = false;

}

void __ab__montee_demander_debout(struct autobus *a, struct ps_standard *p) {
  ajouter_passager(a->passagers, p);

  a->debout++;
  p->debout = true;
  p->assis = false;
}

void __ab__arret_demander_debout(struct autobus *a, struct ps_standard *p) {
  a->assis--;
  a->debout++;
  p->debout = true;
  p->assis = false;
}

void __ab__arret_demander_assis(struct autobus *a, struct ps_standard *p) {
  a->debout--;
  a->assis++;
  p->assis = true;
  p->debout = false;
}

void __ab__arret_demander_sortie(struct autobus *a, struct ps_standard *p) {
  supprimer_passager(a->passagers, p);

  if (ps__est_debout(p)) {
    a->debout--;
  }
  
  if (ps__est_assis(p)) {
    a->assis--;
  }
  p->debout = p->assis = false;
}
