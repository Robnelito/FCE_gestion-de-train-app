#ifndef GESTION_DE_TRAIN_H
#define GESTION_DE_TRAIN_H

#include <QMainWindow>
#include "train.h"
#include "qstring.h"
#include "apropos.h"

namespace Ui {
class Gestion_de_Train;
}

class Gestion_de_Train : public QMainWindow
{
    Q_OBJECT

public:
    explicit Gestion_de_Train(QWidget *parent = 0);
    void ajoutTrain(char *nomFic, FILE *f);
    void editTabAjout(char *nomFic, FILE *f);
    void editTabSuppr(char *nomFic, FILE *f);
    void editTabModif(char *nomFic, FILE *f);
    void editTabAjoutTrain(char *nomFic, FILE *f);
    void editTabModifTrain(char *nomFic, FILE *f);
    void editTabSupprTrain(char *nomFic, FILE *f);
    void ajoutPlace(char *nomFic, FILE *f);
    void editTabAjoutPlace(char *nomFic, FILE *f);
    void editTabModifPlace(char *nomFic, FILE *f);
    void editTabSupprPlace(char *nomFic, FILE *f);
    void ajoutItineraire(char *nomFic, FILE *f);
    void editTabAjoutItineraire(char *nomFic, FILE *f);
    void editTabModifItineraire(char *nomFic, FILE *f);
    void editTabSupprItineraire(char *nomFic, FILE *f);
    void ajoutReservation(char *nomFic, FILE *f);
    void editTabAjoutReservation(char *nomFic, FILE *f);
    void editTabModifReservation(char *nomFic, FILE *f);
    void editTabSupprReservation(char *nomFic, FILE *f);
    void showTrain();
    void creationFichier();
    void findtrain(char *nomFic, FILE *f);
    void findPlace(char *nomFic, FILE *f);
    void findItineraire(char *nomFic, FILE *f);
    void findReservation(char *nomFic, FILE *f);
    void calculerecette();
    void occupation();
    void afficherecette();
    void supproccupation();
    void suprerecette();
    void modifoccup();

    QString write(char word[]);
    QString read(char word[]);
    ~Gestion_de_Train();

private slots:
    void on_nouveau_clicked();

    void on_Train_clicked();

    void on_pushButton_clicked();

    void on_ajouter_clicked();

    void on_Modifier_clicked();

    void on_pushButton_7_clicked();

    void on_Modifi_clicked();

    void on_suprimer_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_11_clicked();

    void on_suprimerplace_clicked();

    void on_Modifplace_clicked();

    void on_Ajoutpalce_clicked();

    void on_Ajoutpalce_2_clicked();

    void on_Modifplace_2_clicked();

    void on_suprimerplace_2_clicked();

    void on_Ajoutpalce_3_clicked();

    void on_Modifplace_3_clicked();

    void on_suprimerplace_3_clicked();

    void on_actualisertrain_clicked();

    void on_actualiserplace_clicked();

    void on_actualiseritineraire_clicked();

    void on_actualisereservation_clicked();

    void on_find_clicked();

    void on_find_2_clicked();

    void on_find_3_clicked();

    void on_pushButton_5_clicked();

    void on_actionNouveau_triggered();

    void on_actionOuvrir_triggered();

    void on_actionQuitter_triggered();

    void on_pushButton_6_clicked();

    void on_actionA_propos_triggered();

private:
    Ui::Gestion_de_Train *ui;
    QString ficTrain;
    QString ficPlace;
    QString ficItineraire;
    QString ficReservation;
    QString ficRecette;
    Apropos *propos;
};

#endif // GESTION_DE_TRAIN_H
