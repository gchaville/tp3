//
//  main.cpp
//  tp3
//
//  Created by Daehli Nadeau Otis on 2015-03-25.
//  Copyright (c) 2015 Daehli Nadeau-Otis. All rights reserved.
//

/*----------------Bibliothèque----------------*/
#include <iostream>
#include <fstream>
#include <string>
#include "Header.h"
using namespace std;

/*----------------Function----------------*/
string lireFichier(string lecture);
void enrFichier(string);
void commande(string lecture);

/*----------------Classe----------------*/
ABR :: ABR(){
    racine = NULL;
}

ABR ::~ABR(){
    racine = NULL;
}

void ABR ::Inserer(noeud *&racine, int d){
    if (racine == NULL){
        noeud *racine = new noeud;
        racine->valeur=d;
        racine->gauche=NULL;
        racine->droit=NULL;
    }
    
    if (racine->valeur >= d){
        Inserer(racine->gauche,d);
    }
    else {
        Inserer(racine->droit,d);
    }
}

noeud* ABR:: getRacine(){
    return racine;
}
void ABR::Supprimer(noeud *racine, int d){
    
        if ( racine == NULL )
            cout << d << "n'est pas dans l'arbre \n";
        else if (d < racine->valeur){
            Supprimer(racine->gauche, d);
        }
        else if (d > racine->valeur){
            Supprimer(racine->droit,d);
        }
        else {
            if (racine->gauche==NULL && racine->droit==NULL ) {
                delete racine;
            }
            
            else if (racine->gauche == NULL){
                racine = racine->droit;
            }
            else if (racine->droit == NULL) {
                    racine = racine->gauche;
                }
            else {
                noeud *tampon = new noeud;
                tampon = supprimerMin(racine->droit);
                racine->valeur=tampon->valeur;
                Supprimer(tampon,tampon->valeur);
                }
            }
        }
void ABR:: Afficher_Arbre(noeud *racine, int niveau){
    if (racine == NULL) cout << "L'arbre est vide" << endl;
    else{
    Afficher_Arbre(racine->gauche,niveau+1);
    for (int i = 0; i <niveau;i++){
        cout << "" << endl;
        cout << racine ->valeur;
    }
    Afficher_Arbre(racine->droit, niveau++);
}

noeud* ABR :: supprimerMin(noeud *&racine){
    if( racine->gauche != NULL )
        return supprimerMin((racine->gauche));
    else
        return racine;
}
int ABR :: Afficher_hauteur(noeud *&racine,int niveau){
    if (racine == NULL) cout <<"La hauteur de l'arbre est" << niveau << endl;
    else{
    Afficher_hauteur(racine->gauche, niveau+1);
        
        Afficher_hauteur(racine->droit, niveau+1);
    }
    
    
    
}
void ABR:: Afficher_Ascendant(noeud *racine, int d){
    if (racine == d){// Function récursive
        if (racine->gauche != NULL && Racine->droit !=NULL){/*Si la valeur de d est atteint il y a maintenant des ascedant à faire apparaitre */
            cout << racine->gauche->valeur<< endl;
            cout << racine ->droit << endl;
            if (racine->gauche!=NULL){// Condition pour continuer à faire apparaitre les ascendant
                Afficher_Ascendant(racine->gauche, racine->valeur);
            }
            else if (racine ->droit!=NULL){ // Même condition Ici
                Afficher_Ascendant(racine->droit, racine->valeur)

        }
        else if (racine->gauche!=NULL){ // Si il y a seulement des enfants à gauche
            cout << racine->valeur << endl;
            Afficher_Ascendant(racine->gauche, racine->valeur);
        }
        else if (racine ->droit!=NULL){ // Si il y a seulement des enfants à droite
            cout< racine->valeur << endl;
            Afficher_Ascendant(racine->droit, racine->valeur)
        }
    }
    else if (d < racine->valeur) // Pour trouver nôtre valeur
        Afficher_Ascendant(racine->gauche, d);
    else // Pour trouver nôtre valeur
        Afficher_Ascendant(racine->droit, d);
    
}
void ABR:: Archiver (noeud *racine){
    
}



int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
/* -------------------------------------------------------------------------------*/
/* DESCRIPTION :      Fonction principale du programmme								*/
/* PARAMETRES :		  Aucun															*/
/* VALEUR DE RETOUR : Aucune 														*/
/* REMARQUE : 		  Aucune														*/
/* -------------------------------------------------------------------------------*/

string lireFichier (string lecture){
    ifstream lire(lecture.c_str(), ios::in);
    if  (lire.fail()){
        cout << "Erreur pour l'ouverture du fichier" <<endl;
    }
    else{
        while (!lire.eof()) {// Je vais esseyer un drôle de code
            char commande;
            int valeur;
            // si non  getline(lire, commande, ','); // la virgule serait délimiteur
            lire >> commande >> valeur // Permet de lire dans un fichier les élément qui y sont inscrit
            cout << commande;//Pour voir l'intérieur du fichier contenu
            cout << valeur;
            tolower(Instruction(commande,valeur))
            
            
        }
    }
};
void Instruction(char lecture,int valeur){
    
    switch (lecture)
case 'I' : Inserer(racine, valeur);// Appel de la classe
    break;
case 'S':Supprimer(racine, valeur);// Appel de la classe
    break;
case 'A': Afficher_Arbre(racine, 0);// Appel de la classe
    break;
case 'H' :Afficher_Arbre(racine, );// Appel de la classe
    break;
case 'G' :Afficher_Ascendant(racine, valeur);// Appel de la classe
    break;
case 'T' :Archiver(racine);// Appel de la classe
    break;
    
    
};
void enrFichier(string){
    
};
