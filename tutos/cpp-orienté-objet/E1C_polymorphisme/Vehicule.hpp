#ifndef VEHICULE_HPP
#define VEHICULE_HPP

#include <vector>

class Vehicule
{
    public:
    Vehicule(int prix, int annee);
    virtual void affiche() const;  //Affiche une description du Vehicule
    virtual int nbrRoues() const = 0;
    virtual ~Vehicule();

    protected:
    int m_prix;  //Chaque véhicule a un prix
    int m_anneeFabrication;
};

class Voiture : public Vehicule //Une Voiture EST UN Vehicule
{
    public:
    Voiture(int prix, int m_anneeFabrication, int m_portes);
    virtual void affiche() const;
    virtual int nbrRoues() const;
    virtual ~Voiture();

    private:
    int m_portes;  //Le nombre de portes de la voiture
};

class Moto : public Vehicule  //Une Moto EST UN Vehicule
{
    public:
    Moto(int prix, int m_anneeFabrication, double m_vitesse);
    virtual void affiche() const;
    virtual int nbrRoues() const;
    virtual ~Moto();
 
    private:
    double m_vitesse;  //La vitesse maximale de la moto
};

class Camion : public Vehicule
{
    public:
    Camion(int prix, int m_anneeFabrication, int charge);
    virtual void affiche() const;
    virtual int nbrRoues() const;
    virtual ~Camion();
 
    private:
    int m_charge;  //La charge maximale transportable par le camion
};

class Garage
{
    public:
    Garage();
    void ajouterVehicule(Vehicule & v);
    void supprimerVehicule();
    void afficherTous() const;    

    private:
    std::vector<Vehicule*> m_vehicules;
};


#endif