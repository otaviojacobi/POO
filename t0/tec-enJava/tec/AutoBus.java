class AutoBus {

    private long max_assis;
    private long max_debout;

    private long assis;
    private long debout;
    private Passanger[] passangers = new Passanger[100];
    private int arret;

    AutoBus(long max_assis, long max_debout) {
        this.set_max_assis(max_assis);
        this.set_max_debout(max_debout);
        this.set_assis(0);
        this.set_debout(0);
        this.set_arret(0);
    }

    public boolean a_place_assise() {
        return this.get_assis() < this.get_max_assis();
    }

    public boolean a_place_debout() {
        return this.get_debout() < this.get_max_debout();
    }

    public int aller_arret_suivant() {
        this.increment_arret();

        for(int i = 0; i < 100; i++) {
            if(passangers[i] != null) {
                passangers[i].nouvel_arret(this, this.get_arret());
            }
        }

        return this.get_arret();
    }

    public void affiche_etat() {
        System.out.printf("[arret %d] assis<%d> debout<%d>\n", 
        this.get_arret(), (int) (this.get_max_assis() - this.get_assis()),
        (int) (this.get_max_debout() - this.get_debout()));
    }

    // COUPLING BETWEEN PASSANGER AND AUTOBUS
    public void arret_demander_sortie(Passanger passanger) {

        this.supprimer_passanger(passanger);

        if (passanger.est_debout()) {
            this.decrement_debout();
        }

        if (passanger.est_assis()) {
            this.decrement_assis();
        }

        passanger.set_debout(false);
        passanger.set_assis(false);
    }

    public void montee_demander_assis(Passanger passanger) {
        this.ajouter_passanger(passanger);

        this.increment_assis();
        passanger.set_assis(true);
        passanger.set_debout(false);
    }

    public void montee_demander_debout(Passanger passanger) {
        this.ajouter_passanger(passanger);

        this.increment_debout();
        passanger.set_debout(true);
        passanger.set_assis(false);
    }

    public void arret_demander_debout(Passanger passanger) {
        this.decrement_assis();
        this.increment_debout();
        passanger.set_debout(true);
        passanger.set_assis(false);
    }

    public void arret_demander_assis(Passanger passanger) {
        this.decrement_debout();
        this.increment_assis();
        passanger.set_assis(true);
        passanger.set_debout(false);
    }

    // PRIVATES
    private int recherche_passager(Passanger passanger) {
        for(int i = 0; i < 100; i++) {
            if(passanger == this.passangers[i]) {
                return i;
            }
        }
        return -999999;
    }

    private void ajouter_passanger(Passanger passanger) {
        int k = this.recherche_passager(null);
        passangers[k] = passanger;
    }

    private void supprimer_passanger(Passanger passanger) {
        int k = this.recherche_passager(passanger);
        this.passangers[k] = null;
    }

    // PRIVATE UTILS
    private void increment_arret() {
        this.set_arret(this.get_arret() + 1);
    }

    private void increment_debout() {
        this.set_debout(this.get_debout() + 1);
    }

    private void decrement_debout() {
        this.set_debout(this.get_debout() - 1);
    }

    private void increment_assis() {
        this.set_assis(this.get_assis() + 1);
    }

    private void decrement_assis() {
        this.set_assis(this.get_assis() - 1);
    }


    // GETTERS AND SETTERS - "POJO"
    public void set_max_assis(long max_assis) {
        this.max_assis = max_assis;
    }

    public long get_max_assis() {
        return this.max_assis;
    }

    public void set_max_debout(long max_debout) {
        this.max_debout = max_debout;
    }

    public long get_max_debout() {
        return this.max_debout;
    }

    public void set_assis(long assis) {
        this.assis = assis;
    }

    public long get_assis() {
        return this.assis;
    }

    public void set_debout(long debout) {
        this.debout = debout;
    }

    public long get_debout() {
        return this.debout;
    }

    public void set_arret(int arret) {
        this.arret = arret;
    }

    public int get_arret() {
        return this.arret;
    }
}