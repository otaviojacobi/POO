/*
 * Scenario avec trois passager standard
 *  L'autobus a 1 place assise et 2 places debout.
 *  Le passager K monte a l'arret numero 1 destination arret 4
 *  Le passager J monte a l'arret numero 2 destination arret 4 
 *  Le passager I monte a l'arret numero 3 destination arret 5
 */

#include <stdio.h>

#include "autobus.h"
#include "ps_standard.h"

int main() {
  struct autobus *serenity = ab__creer(1, 2);

  struct ps_standard *kaylee = ps__creer("Kaylee", 4);
  struct ps_standard *jayne = ps__creer("Jayne", 4);
  struct ps_standard *inara = ps__creer("Inara", 5);

  //0
  ab__affiche_etat(serenity);

  //1
  ab__aller_arret_suivant(serenity);
  ps__monter_dans(kaylee, serenity);

  ab__affiche_etat(serenity);
  ps__affiche_etat(kaylee);
  
  //2
  ab__aller_arret_suivant(serenity);
  ps__monter_dans(jayne, serenity);

  ab__affiche_etat(serenity);
  ps__affiche_etat(kaylee);
  ps__affiche_etat(jayne);

  //3
  ab__aller_arret_suivant(serenity);
  ps__monter_dans(inara, serenity);

  ab__affiche_etat(serenity);
  ps__affiche_etat(kaylee);
  ps__affiche_etat(jayne);
  ps__affiche_etat(inara);
 
  //4
  ab__aller_arret_suivant(serenity);

  ab__affiche_etat(serenity);
  ps__affiche_etat(kaylee);
  ps__affiche_etat(jayne);
  ps__affiche_etat(inara);

  //5
  ab__aller_arret_suivant(serenity);

  ab__affiche_etat(serenity);
  ps__affiche_etat(kaylee);
  ps__affiche_etat(jayne);
  ps__affiche_etat(inara);
 
  ab__liberer(serenity);
  ps__liberer(kaylee);
  ps__liberer(jayne);
  ps__liberer(inara);
}

/* Resulat de l'execution.
[arret 0] assis<1> debout<2>
[arret 1] assis<0> debout<2>
Kaylee <assis>
[arret 2] assis<0> debout<1>
Kaylee <assis>
Jayne <debout>
[arret 3] assis<0> debout<0>
Kaylee <assis>
Jayne <debout>
Inara <debout>
[arret 4] assis<1> debout<1>
Kaylee <endehors>
Jayne <endehors>
Inara <debout>
[arret 5] assis<1> debout<2>
Kaylee <endehors>
Jayne <endehors>
Inara <endehors>
*/
