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
#include "Header.h"
using namespace std;

/*----------------Function----------------*/
string lireFichier(string lecture);
void enrFichier(string);

/*----------------Classe----------------*/
ABR :: ABR(){
    racine = NULL;
}

ABR ::~ABR(){
    racine = NULL;
}

void ABR ::Inserer(noeud *racine, int d){
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
//    noeud *feuille = new noeud;
//    feuille->valeur=d;
//    if (racine == NULL){
//        racine = feuille;
//    };
//    
//    noeud *courant = new noeud; // créer une nouvelle structure
//    courant = racine;
//    noeud *parent = new noeud; // créer une nouvelle structure
//    while(courant != NULL)
//    {
//        parent = courant;
//        if(d <= courant->valeur)
//        {
//            courant = courant->gauche;
//            
//        } else
//        {
//            courant= courant->droit;
//            
//        }
//    }
//    
//    //courant = feuille;
//    if(feuille->valeur <= parent->valeur)
//        parent->gauche=feuille;
//    else
//        parent->droit=feuille;
//
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
            else if (racine->droit==NULL) {
                    racine = racine->gauche;
                }
            else {
                noeud *tamp = new noeud;
                tamp = racine;
                // À continuer
                }
            }
        }
void ABR:: Afficher_Arbre(noeud *racine){

}

void ABR :: supprimerMin(noeud *racine,){
    if( racine != NULL ) ; // on vérifie que l'arbre n'est pas vide
    if ( racine->gauche != NULL ) // on continue à gauche
    return supprimerMin (racine->gauche) ;
    else // le minimum est trouvé à ce stade
    {
        noeud *temp = new noeud;
        temp = racine->droit;
        return temp ;
    }
}
int ABR ::Afficher_hauteur(noeud *racine){
}
void ABR:: Afficher_Ascendant(noeud *racine, int d){
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

string lireFichier(string lecture ){
    ifstream lire(lecture.c_str(), ios::in);
    if  (lire.fail()){
        cout << "Erreur pour l'ouverture du fichier" <<endl;
    }
    else{
        while (!lire.eof()) {
            string commande;
            getline(lire,commande);
            cout << commande; //Pour voir l'intérieur tu contenu.
            
            
        }
    }
    
    
    
};

void enrFichier(string){
}
