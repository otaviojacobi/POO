class Passanger {

    private String nom;
    private boolean debout;
    private boolean assis;
    private long arret_destination;

    Passanger(String nom, long arret_destination) {
        this.set_nom(nom);
        this.set_arret_destination(arret_destination);
        this.set_debout(false);
        this.set_assis(false);
    }

    public void monter_dans(AutoBus auto_bus) {
        if(auto_bus.a_place_assise()) {
            auto_bus.montee_demander_assis(this);
        }

        else if(auto_bus.a_place_debout()) {
            auto_bus.montee_demander_debout(this);
        }
    }

    public boolean est_dehors() {
        return !this.est_assis() && !this.est_debout();
    }

    public boolean est_assis() {
        return this.get_assis();
    }

    public boolean est_debout() {
        return this.get_debout();
    }

    public void affiche_etat() {
        System.out.printf("%s <", this.get_nom());
        if(this.get_assis())
            System.out.printf("assis");
        else if (this.get_debout())
            System.out.printf("debout");
        else
            System.out.printf("endehors");
        System.out.printf(">\n");
    }

    // COUPLING BETWEEN PASSANGER AND AUTOBUS
    public void nouvel_arret(AutoBus a, int numero_arret) {
        if(this.get_arret_destination() <= numero_arret) {
            a.arret_demander_sortie(this);
        }
    }

    // GETTERS AND SETTERS - "POJO"
    public void set_nom(String nom) {
        this.nom = nom;
    }

    public String get_nom() {
        return this.nom;
    }

    public void set_debout(boolean debout) {
        this.debout = debout;
    }

    public boolean get_debout() {
        return this.debout;
    }

    public void set_assis(boolean assis) {
        this.assis = assis;
    }

    public boolean get_assis() {
        return this.assis;
    }

    public void set_arret_destination(long arret_destination) {
        this.arret_destination = arret_destination;
    }

    public long get_arret_destination() {
        return this.arret_destination;
    }
}