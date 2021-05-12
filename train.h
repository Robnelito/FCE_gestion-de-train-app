#ifndef TRAIN_H
#define TRAIN_H

#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <QApplication>
#include <QtWidgets>

typedef struct Train
{
    int numtrain;
    char design[100];
    int nbrplace;
    int numitineraire;
}Train;

typedef struct Affec
{
    int numtrain;
    char design[100];
    int nbrplace;
    int numitineraire;
}Affec;

typedef struct Place
{
    int numtrain;
    int nbrplace;
    int noccupation;
}Place;

typedef struct itineraire
{
    int numitineraire;
    char depart[100];
    char arrivee[100];
    int frais;
}itineraire;

typedef struct Reservation
{
    int numreservation;
    int numtrain;
    int jour;
    int mois;
    int annee;
    int place;
    char nom[100];
    char prenom[100];
    char ville[100];
    int money;
}Reservation;

typedef struct Recette
{
    int numtrtain;
    int montant;
    int occupation;
}Recette;

#endif // TRAIN_H
