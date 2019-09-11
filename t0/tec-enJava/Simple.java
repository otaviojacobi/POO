class Simple 
{ 
    // Your program begins with a call to main(). 
    // Prints "Hello, World" to the terminal window. 
    public static void main(String args[]) { 
        AutoBus serenity = new AutoBus(1, 2);

        Passanger kaylee = new Passanger("Kaylee", 4);
        Passanger jayne = new Passanger("Jayne", 4);
        Passanger inara = new Passanger("Inara", 5);

        // 0
        serenity.affiche_etat();

        // 1
        serenity.aller_arret_suivant();
        kaylee.monter_dans(serenity);

        serenity.affiche_etat();
        kaylee.affiche_etat();

        // 2
        serenity.aller_arret_suivant();
        jayne.monter_dans(serenity);
        
        serenity.affiche_etat();
        kaylee.affiche_etat();
        jayne.affiche_etat();

        // 3
        serenity.aller_arret_suivant();
        inara.monter_dans(serenity);
        
        serenity.affiche_etat();
        kaylee.affiche_etat();
        jayne.affiche_etat();
        inara.affiche_etat();

        // 4
        serenity.aller_arret_suivant();

        serenity.affiche_etat();
        kaylee.affiche_etat();
        jayne.affiche_etat();
        inara.affiche_etat();

        // 5
        serenity.aller_arret_suivant();

        serenity.affiche_etat();
        kaylee.affiche_etat();
        jayne.affiche_etat();
        inara.affiche_etat();


        // No need to free memory as java has a GC
    } 
}