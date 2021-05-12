#include "gestion_de_train.h"
#include "ui_gestion_de_train.h"
#include "train.h"
#include "reservation.h"
#include "ui_reservation.h"
#include "dialog1.h"
#include "ui_dialog1.h"
#include "itineraire.h"
#include "ui_itineraire.h"


void Gestion_de_Train::afficherecette()
{
    FILE*f=NULL;
    FILE*file=NULL;
    Recette recette,recetteExiste,recetteTab[50];
    Reservation ReservationExist;
    f=fopen(ficRecette.toLatin1().data(),"r");
    int r=0;
    while(!feof(f))
    {
        fscanf(f, "%d > %d > %d\n", &recetteExiste.numtrtain, &recetteExiste.montant, &recetteExiste.occupation);
        file=fopen(ficReservation.toLatin1().data(),"r");
        while(!feof(file))
        {
            fscanf(file, "%d > %d > %d > %d > %d > %d > %s > %s > %s > %d \n",&ReservationExist.numreservation,&ReservationExist.numtrain,&ReservationExist.jour,&ReservationExist.mois,&ReservationExist.annee,&ReservationExist.place,ReservationExist.nom,ReservationExist.prenom,ReservationExist.ville,&ReservationExist.money);
            if(recetteExiste.numtrtain==ReservationExist.numtrain)
            {
                recette.numtrtain=ReservationExist.numtrain;
                recette.montant=recetteExiste.montant+ReservationExist.money;
                recette.occupation=recetteExiste.occupation;

                recetteTab[r]=recette;
            }
            else
            {
                recetteTab[r]=recetteExiste;
            }

        }
        r++;
    }
    fclose(file);

    fclose(f);
    f=fopen(ficRecette.toLatin1().data(), "w");
    for(int v=0;v<=r-1;v++)
    {
        fprintf(f, "%d > %d > %d\n",
                recetteTab[v].numtrtain,
                recetteTab[v].montant,
                recetteTab[v].occupation);
    }
    fclose(f);
}

void Gestion_de_Train::modifoccup()
{
    FILE*f=NULL;
    FILE*file=NULL;
    Recette recette,recetteExiste,recetteTab[50];
    Reservation ReservationExist;
    f=fopen(ficRecette.toLatin1().data(),"r");
    int r=0;
    while(!feof(f))
    {
        fscanf(f, "%d > %d > %d\n", &recetteExiste.numtrtain, &recetteExiste.montant, &recetteExiste.occupation);
        file=fopen(ficReservation.toLatin1().data(),"r");
        while(!feof(file))
        {
            fscanf(file, "%d > %d > %d > %d > %d > %d > %s > %s > %s > %d \n",&ReservationExist.numreservation,&ReservationExist.numtrain,&ReservationExist.jour,&ReservationExist.mois,&ReservationExist.annee,&ReservationExist.place,ReservationExist.nom,ReservationExist.prenom,ReservationExist.ville,&ReservationExist.money);
            if(recetteExiste.numtrtain==ReservationExist.numtrain)
            {
                recette.numtrtain=ReservationExist.numtrain;
                recette.montant=recetteExiste.montant;
                recette.occupation=recetteExiste.occupation+ReservationExist.place;

                recetteTab[r]=recette;
            }
            else
            {
                recetteTab[r]=recetteExiste;
            }

        }
        r++;
    }
    fclose(file);

    fclose(f);
    f=fopen(ficRecette.toLatin1().data(), "w");
    for(int v=0;v<=r-1;v++)
    {
        fprintf(f, "%d > %d > %d\n",
                recetteTab[v].numtrtain,
                recetteTab[v].montant,
                recetteTab[v].occupation);
    }
    fclose(f);
}

void Gestion_de_Train::calculerecette()
{
    FILE*f;
    f=NULL;
    f=fopen(ficRecette.toLatin1().data(), "r");
    ui->recettetab->setRowCount(0);
    Recette PlaceExist;
    PlaceExist.numtrtain=-1;
    int k=0;
    do
    {
        fscanf(f, "%d > %d > %d\n", &PlaceExist.numtrtain, &PlaceExist.montant, &PlaceExist.occupation);
        if(PlaceExist.numtrtain==-1)
            ui->recettetab->setRowCount(0);
        else
        {
            ui->recettetab->insertRow(k);
            QTableWidgetItem *item = new QTableWidgetItem;
            QTableWidgetItem *ite = new QTableWidgetItem;
            QTableWidgetItem *it = new QTableWidgetItem;
            int numbtrain = PlaceExist.numtrtain;
            int numplace = PlaceExist.montant;
            int occupation = PlaceExist.occupation;
            item->setData(Qt::DisplayRole,numbtrain);
            ite->setData(Qt::DisplayRole,numplace);
            it->setData(Qt::DisplayRole,occupation);
            ui->recettetab->setItem(k,0,item);
            ui->recettetab->setItem(k,1,ite);
            ui->recettetab->setItem(k,2,it);
            k++;
        }
    }
    while(!feof(f));
    ui->recettetab->sortItems(1);
    fclose(f);

}

void Gestion_de_Train::occupation()
{
    FILE *f=NULL;
    FILE *file=NULL;
    Place lamasin, placeExist, placeTab[50];
    Reservation ReservationExist;
    f=fopen(ficPlace.toLatin1().data(), "r");
    int r=0;
    while(!feof(f))
    {
        fscanf(f, "%d > %d > %d\n", &placeExist.numtrain, &placeExist.nbrplace, &placeExist.noccupation);

        file=fopen(ficReservation.toLatin1().data(),"r");
        while(!feof(file))
        {
            fscanf(file, "%d > %d > %d > %d > %d > %d > %s > %s > %s > %d \n",&ReservationExist.numreservation,&ReservationExist.numtrain,&ReservationExist.jour,&ReservationExist.mois,&ReservationExist.annee,&ReservationExist.place,ReservationExist.nom,ReservationExist.prenom,ReservationExist.ville,&ReservationExist.money);
            if(placeExist.numtrain==ReservationExist.numtrain)
            {
            lamasin.numtrain=ReservationExist.numtrain;
            lamasin.nbrplace=placeExist.nbrplace;
            lamasin.noccupation=placeExist.noccupation+ReservationExist.place;

                placeTab[r]=lamasin;
            }
            else
            {
                placeTab[r]=placeExist;
            }
        }
        r++;
    }
    fclose(file);

    fclose(f);
    f=fopen(ficPlace.toLatin1().data(), "w");
    for(int v=0;v<=r-1;v++)
    {
        fprintf(f, "%d > %d > %d\n",
                placeTab[v].numtrain,
                placeTab[v].nbrplace,
                placeTab[v].noccupation);
    }
    fclose(f);
}
///////////////////////////////////////en cas de suppression de reservation
void Gestion_de_Train::supproccupation()
{
    int selectedRow = ui->Reservationtab->currentRow();
    if(selectedRow<0)
        QMessageBox::critical(this, "Error", "Veuillez selectionner une ligne");
    else
    {
        FILE *file=NULL;
        Place lamasin,placeExist, placeTab[50];
        lamasin.numtrain=ui->Reservationtab->item(selectedRow, 1)->text().toInt();
        file=fopen(ficPlace.toLatin1().data(), "r");
        int r=0;
        while(!feof(file))
        {
            fscanf(file, "%d > %d > %d\n", &placeExist.numtrain, &placeExist.nbrplace, &placeExist.noccupation);
            if(placeExist.numtrain!=lamasin.numtrain)
            {
                placeTab[r]=placeExist;
            }
            else
            {
                FILE*f=NULL;
                Reservation ReservationExist;
                f=fopen(ficReservation.toLatin1().data(),"r");
                while(!feof(f))
                {
                    fscanf(f, "%d > %d > %d > %d > %d > %d > %s > %s > %s > %d \n", &ReservationExist.numreservation,&ReservationExist.numtrain,&ReservationExist.jour,&ReservationExist.mois,&ReservationExist.annee,&ReservationExist.place,ReservationExist.nom,ReservationExist.prenom,ReservationExist.ville,&ReservationExist.money);
                    int trainnum = ReservationExist.numreservation;
                    if (placeExist.numtrain==trainnum)
                    {
                        lamasin.numtrain=ReservationExist.numtrain;
                        lamasin.nbrplace=placeExist.nbrplace;
                        lamasin.noccupation=placeExist.noccupation-ReservationExist.place;

                            placeTab[r]=lamasin;
                    }

                }
                fclose(f);

            }
            r++;
        }
        fclose(file);

        file=fopen(ficPlace.toLatin1().data(), "w");
        for(int v=0;v<=r-1;v++)
        {
            fprintf(file, "%d > %d > %d\n",
                    placeTab[v].numtrain,
                    placeTab[v].nbrplace,
                    placeTab[v].noccupation);
        }
        fclose(file);
    }
}

void Gestion_de_Train::suprerecette()
{
    int selectedRow = ui->Reservationtab->currentRow();
    if(selectedRow<0)
        QMessageBox::critical(this, "Error", "Veuillez selectionner une ligne");
    else
    {
        FILE *file=NULL;
        Recette lamasin,placeExist, placeTab[50];
        lamasin.numtrtain=ui->Reservationtab->item(selectedRow, 1)->text().toInt();
        file=fopen(ficRecette.toLatin1().data(), "r");
        int r=0;
        while(!feof(file))
        {
            fscanf(file, "%d > %d > %d\n", &placeExist.numtrtain, &placeExist.montant, &placeExist.occupation);
            if(placeExist.numtrtain!=lamasin.numtrtain)
            {
                placeTab[r]=placeExist;
            }
            else
            {
                FILE*f=NULL;
                Reservation ReservationExist;
                f=fopen(ficReservation.toLatin1().data(),"r");
                while(!feof(f))
                {
                    fscanf(f, "%d > %d > %d > %d > %d > %d > %s > %s > %s > %d \n", &ReservationExist.numreservation,&ReservationExist.numtrain,&ReservationExist.jour,&ReservationExist.mois,&ReservationExist.annee,&ReservationExist.place,ReservationExist.nom,ReservationExist.prenom,ReservationExist.ville,&ReservationExist.money);
                    int trainnum = ReservationExist.numreservation;
                    if (placeExist.numtrtain==trainnum)
                    {
                        lamasin.numtrtain=ReservationExist.numtrain;
                        lamasin.montant=((placeExist.montant))-((ReservationExist.money));
                        lamasin.occupation=placeExist.occupation-ReservationExist.place;

                            placeTab[r]=lamasin;
                    }

                }
                fclose(f);

            }
            r++;
        }
        fclose(file);

        file=fopen(ficRecette.toLatin1().data(), "w");
        for(int v=0;v<=r-1;v++)
        {
            fprintf(file, "%d > %d > %d\n",
                    placeTab[v].numtrtain,
                    placeTab[v].montant,
                    placeTab[v].occupation);
        }
        fclose(file);
    }
}

