#ifndef __INTERNES_H 
#define __INTERNES_H 

//declarations internes à ne pas utiliser par le scenario

//Les deux structures
#define MAX 100

struct autobus {
  long max_assis;
  long max_debout;

  long assis;
  long debout;
  struct ps_standard *passagers[MAX];
  int arret;
};

struct ps_standard {
  char *nom;
  bool assis;
  bool debout;
  long destination;
};

// fonctions d'autobus utilisees par ps_standard.
void __ab__montee_demander_assis(struct autobus*, struct ps_standard*);
void __ab__montee_demander_debout(struct autobus*, struct ps_standard*);

void __ab__arret_demander_sortie(struct autobus*, struct ps_standard*);
void __ab__arret_demander_debout(struct autobus *, struct ps_standard *);
void __ab__arret_demender_assis(struct autobus *, struct ps_standard *);


// fonctions de ps_standard utilisees par autobus.
void __ps__nouvel_arret(struct ps_standard *, struct autobus *, int);

#endif //__INTERNES_H 
