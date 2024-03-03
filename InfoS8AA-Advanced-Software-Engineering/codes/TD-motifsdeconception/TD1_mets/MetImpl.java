public abstract class MetImpl implements Met {

    public boolean estSucreSale() {
        return (this.estSucre() && this.estSale());
    }

    public boolean estDietetique() {
        return (this.nombreDeCalories() < 200);
    }


    

    public static void main(String[] arg) {
        MetComposite boeufCarottes = new MetComposite();
        boeufCarottes.ajouter(new Boeuf());
        boeufCarottes.ajouter(new Carotte());
        System.out.println("Plat : " + boeufCarottes);
        System.out.println("Calories : " + boeufCarottes.nombreDeCalories());
        System.out.println(boeufCarottes.estDietetique() ? "Dietetique : OUI" : "Dietetique : NON");
        System.out.println();

        MetComposite poireBelleHelene = new MetComposite();
        poireBelleHelene.ajouter(new Poire());
        poireBelleHelene.ajouter(new Chocolat());
        System.out.println("Plat : " + poireBelleHelene);
        System.out.println("Calories : " + poireBelleHelene.nombreDeCalories());
        System.out.println(poireBelleHelene.estDietetique() ? "Dietetique : OUI" : "Dietetique : NON");
        System.out.println();

        Boeuf b = new Boeuf();
        System.out.println("Plat : " + b);
        System.out.println("Calories : " + b.nombreDeCalories());
        System.out.println(b.estDietetique() ? "Dietetique : OUI" : "Dietetique : NON");
        System.out.println();

        Met ba = new Allege(new Boeuf());
        System.out.println("Plat : " + ba);
        System.out.println("Calories : " + ba.nombreDeCalories());
        System.out.println(ba.estDietetique() ? "Dietetique : OUI" : "Dietetique : NON");
        System.out.println();

        Met bca = new Allege(boeufCarottes);
        System.out.println("Plat : " + bca);
        System.out.println("Calories : " + bca.nombreDeCalories());
        System.out.println(bca.estDietetique() ? "Dietetique : OUI" : "Dietetique : NON");
        System.out.println();

        MetComposite bcapc = new MetComposite();
        bcapc.ajouter(bca);
        bcapc.ajouter(poireBelleHelene);
        System.out.println("Plat : " + bcapc);
        System.out.println("Calories : " + bcapc.nombreDeCalories());
        System.out.println(bcapc.estDietetique() ? "Dietetique : OUI" : "Dietetique : NON");
        System.out.println();
        
        Met bcapca = new Allege(bcapc);
        System.out.println("Plat : " + bcapca);
        System.out.println("Calories : " + bcapca.nombreDeCalories());
        System.out.println(bcapca.estDietetique() ? "Dietetique : OUI" : "Dietetique : NON");
        System.out.println();
    }    
}
