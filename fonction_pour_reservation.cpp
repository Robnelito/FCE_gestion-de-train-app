#include "gestion_de_train.h"
#include "ui_gestion_de_train.h"
#include "train.h"
#include "reservation.h"
#include "ui_reservation.h"


void Gestion_de_Train::editTabAjoutReservation(char *nomFic, FILE *f)
{
    f=fopen(nomFic, "r");
    ui->Reservationtab->setRowCount(0);
    Reservation ReservationExist;
    ReservationExist.numreservation=-1;
    int k=0;
    do{
        fscanf(f, "%d > %d > %d > %d > %d > %d > %s > %s > %s > %d \n", &ReservationExist.numreservation,&ReservationExist.numtrain,&ReservationExist.jour,&ReservationExist.mois,&ReservationExist.annee,&ReservationExist.place,ReservationExist.nom,ReservationExist.prenom,ReservationExist.ville,&ReservationExist.money);
        if(ReservationExist.numreservation==-1){
            ui->Reservationtab->setRowCount(0);
        }
        else
        {
            QString nom = this->read(ReservationExist.nom);
            QString prenom = this->read(ReservationExist.prenom);
            QString ville=this->read(ReservationExist.ville);
            ui->Reservationtab->insertRow(k);
            QTableWidgetItem *reserve = new QTableWidgetItem;
            QTableWidgetItem *train = new QTableWidgetItem;
            QTableWidgetItem *jr = new QTableWidgetItem;
            QTableWidgetItem *ms = new QTableWidgetItem;
            QTableWidgetItem *an = new QTableWidgetItem;
            QTableWidgetItem *nombre = new QTableWidgetItem;
            QTableWidgetItem *mon = new QTableWidgetItem;
            int numreserve = ReservationExist.numreservation;
            int numtr = ReservationExist.numtrain;
            int j = ReservationExist.jour;
            int m = ReservationExist.mois;
            int a = ReservationExist.annee;
            int nbr = ReservationExist.place;
            int money = ReservationExist.money;
            reserve->setData(Qt::DisplayRole,numreserve);
            train->setData(Qt::DisplayRole,numtr);
            jr->setData(Qt::DisplayRole,j);
            ms->setData(Qt::DisplayRole,m);
            an->setData(Qt::DisplayRole,a);
            nombre->setData(Qt::DisplayRole,nbr);
            mon->setData(Qt::DisplayRole,money);
            ui->Reservationtab->setItem(k,0,reserve);
            ui->Reservationtab->setItem(k,1,train);
            ui->Reservationtab->setItem(k,2,jr);
            ui->Reservationtab->setItem(k,3,ms);
            ui->Reservationtab->setItem(k,4,an);
            ui->Reservationtab->setItem(k,5,nombre);
            ui->Reservationtab->setItem(k,6,new QTableWidgetItem(nom));
            ui->Reservationtab->setItem(k,7,new QTableWidgetItem(prenom));
            ui->Reservationtab->setItem(k,8,new QTableWidgetItem(ville));
            ui->Reservationtab->setItem(k,9,mon);
            k++;
        }
       }while (!feof(f));
   ui->Reservationtab->sortItems(0);
   fclose(f);

}

void Gestion_de_Train::ajoutReservation(char *nomFic, FILE *f)
{
    bool ok;
    int numreservation = QInputDialog::getInt(this, "Numero" , "Veuillez saisir le numero de réservation",
                                              1, 0, 999999999, 1, &ok);
    if(ok){
        Reservation reserva, ReservationExist;
        reservation *dialogreserv = new reservation(this);
        f= fopen(nomFic, "r");
        reserva.numreservation = numreservation;
        ReservationExist.numreservation = -1;
        dialogreserv->getUi()->numreservation->setValue(numreservation);
        fscanf(f, "%d > %d > %d > %d > %d > %d > %s > %s > %s > %d \n", &ReservationExist.numreservation,&ReservationExist.numtrain,&ReservationExist.jour,&ReservationExist.mois,&ReservationExist.annee,&ReservationExist.place,ReservationExist.nom,ReservationExist.prenom,ReservationExist.ville,&ReservationExist.money);

        if(ReservationExist.numreservation==-1)
        {
            fclose(f);
            int res = dialogreserv->exec();
            strcpy(reserva.nom,dialogreserv->getUi()->nom->text().toUpper().toLatin1().data());
            strcpy(reserva.prenom,dialogreserv->getUi()->prenom->text().toLatin1().data());
            strcpy(reserva.ville,dialogreserv->getUi()->ville->text().toLatin1().data());
            QString nom = write(reserva.nom);
            QString ville = write(reserva.ville);
            QString prenom = write(reserva.prenom);
            if(nom==""||prenom==""||ville==""){
                nom = "***";
                prenom = "***";
                ville ="***";
            }
            reserva.numreservation = dialogreserv->getUi()->numreservation->value();
            reserva.numtrain = dialogreserv->getUi()->numtrain->value();
            reserva.jour = dialogreserv->getUi()->jour->value();
            reserva.mois = dialogreserv->getUi()->mois->value();
            reserva.annee = dialogreserv->getUi()->annee->value();
            reserva.place = dialogreserv->getUi()->place->value();
            reserva.money = dialogreserv->getUi()->vola->value();
            reserva.money = reserva.money*reserva.place;
            strcpy(reserva.nom, nom.toLatin1().toUpper().data());
            strcpy(reserva.prenom, prenom.toLatin1().data());
            strcpy(reserva.ville, ville.toLatin1().data());
            if(res == QDialog::Accepted){
               FILE*ro=NULL;
               ro=fopen(ficPlace.toLatin1().data(),"r");
               Place PlaceExist;
               while(!feof(ro))
               {
                   fscanf(ro, "%d > %d > %d\n",&PlaceExist.numtrain,&PlaceExist.nbrplace,&PlaceExist.noccupation);
                   if(PlaceExist.numtrain==reserva.numtrain)
                   {
                       if(PlaceExist.nbrplace>PlaceExist.noccupation+reserva.place)
                       {
                           f=fopen(nomFic, "a+");
                           fprintf(f, "%d > %d > %d > %d > %d > %d > %s > %s > %s > %d \n", reserva.numreservation,reserva.numtrain,reserva.jour,reserva.mois,reserva.annee,reserva.place,reserva.nom,reserva.prenom,reserva.ville,reserva.money);
                           QMessageBox::information(this,"Succès", "Reservation enrégistré avec succès");
                           fclose(f);
                           this->occupation();
                           this->afficherecette();
                           this->modifoccup();
                       }
                       else
                       {
                           QMessageBox::information(this,"Failed","Train plein!, Veuillez Ajouter un autre!");
                           res=QDialog::Rejected;
                       }
                   }
               }
            }
            /*if(res == QDialog::Accepted){
                this->occupation();
                this->afficherecette();
                this->modifoccup();
            }*/
        }
        else{
            while (!feof(f) && ReservationExist.numreservation!=reserva.numreservation) {
                fscanf(f, "%d > %d > %d > %d > %d > %d > %s > %s > %s > %d \n",&ReservationExist.numreservation,&ReservationExist.numtrain,&ReservationExist.jour,&ReservationExist.mois,&ReservationExist.annee,&ReservationExist.place,ReservationExist.nom,ReservationExist.prenom,ReservationExist.ville,&ReservationExist.money);
            }

            if(ReservationExist.numreservation!=reserva.numreservation)
            {
                fclose(f);
                f=fopen(nomFic, "a+");
                int res = dialogreserv->exec();
                strcpy(reserva.nom,dialogreserv->getUi()->nom->text().toLatin1().toUpper().data());
                strcpy(reserva.prenom,dialogreserv->getUi()->prenom->text().toLatin1().data());
                strcpy(reserva.ville,dialogreserv->getUi()->ville->text().toLatin1().data());
                QString ville = write(reserva.ville);
                QString nom = write(reserva.nom);
                QString prenom = write(reserva.prenom);
                if(nom==""||prenom==""||ville==""){
                    nom = "***";
                    prenom = "***";
                    ville = "***";
                }
                reserva.numreservation = dialogreserv->getUi()->numreservation->value();
                reserva.numtrain = dialogreserv->getUi()->numtrain->value();
                reserva.jour = dialogreserv->getUi()->jour->value();
                reserva.mois = dialogreserv->getUi()->mois->value();
                reserva.annee = dialogreserv->getUi()->annee->value();
                reserva.place = dialogreserv->getUi()->place->value();
                reserva.money = dialogreserv->getUi()->vola->value();
                reserva.money = reserva.money*reserva.place;
                strcpy(reserva.nom, nom.toLatin1().toUpper().data());
                strcpy(reserva.prenom, prenom.toLatin1().data());
                strcpy(reserva.ville, ville.toLatin1().data());
                if(res == QDialog::Accepted){
                    FILE*ro=NULL;
                    ro=fopen(ficPlace.toLatin1().data(),"r");
                    Place PlaceExist;
                    while(!feof(ro))
                    {
                        fscanf(ro, "%d > %d > %d\n",&PlaceExist.numtrain,&PlaceExist.nbrplace,&PlaceExist.noccupation);
                        if(PlaceExist.numtrain==reserva.numtrain)
                        {
                            if(PlaceExist.nbrplace>PlaceExist.noccupation+reserva.place)
                            {
                                f=fopen(nomFic, "a+");
                                fprintf(f, "%d > %d > %d > %d > %d > %d > %s > %s > %s > %d \n", reserva.numreservation,reserva.numtrain,reserva.jour,reserva.mois,reserva.annee,reserva.place,reserva.nom,reserva.prenom,reserva.ville,reserva.money);
                                QMessageBox::information(this,"Succès", "Reservation enrégistré avec succès");
                                fclose(f);
                                this->occupation();
                                this->afficherecette();
                                this->modifoccup();
                            }
                            else
                            {
                                QMessageBox::information(this,"Failed","Train plein!, Veuillez Ajouter un autre!");
                                res=QDialog::Rejected;
                            }
                        }
                    }
                }
            }
            else{
                QMessageBox::warning(this,"error", "Reservation déjà saisie");
                fclose(f);
            }
        }
    }
}


void Gestion_de_Train::editTabModifReservation(char *nomFic, FILE *f)
{
    int selectedRow = ui->Reservationtab->currentRow();
    if(selectedRow < 0){
        QMessageBox::warning(this,"Error","Veuillez selectionner le reservation à modifier");
    }
    else{
        reservation *dialogreserv = new reservation(this);
        FILE *file = NULL;
        Reservation reserva, ReservationExist, reservationtab[50];
        reserva.numreservation = ui->Reservationtab->item(selectedRow, 0)->text().toInt();
        f=fopen(nomFic, "r");
        int r = 0;
        while (!feof(f)) {
            fscanf(f, "%d > %d > %d > %d > %d > %d > %s > %s > %s > %d \n",&ReservationExist.numreservation,&ReservationExist.numtrain,&ReservationExist.jour,&ReservationExist.mois,&ReservationExist.annee,&ReservationExist.place,ReservationExist.nom,ReservationExist.prenom,ReservationExist.ville,&ReservationExist.money);
            if(ReservationExist.numreservation!=reserva.numreservation){
                reservationtab[r] = ReservationExist;
            }
            else{
                dialogreserv->getUi()->numreservation->setDisabled(false);
                dialogreserv->getUi()->numreservation->setReadOnly(false);
                dialogreserv->getUi()->numreservation->setValue(ReservationExist.numreservation);
                QString nom = this->read(ReservationExist.nom);
                QString prenom = this->read(ReservationExist.prenom);
                QString ville = this->read(ReservationExist.ville);
                dialogreserv->getUi()->nom->setText(nom);
                dialogreserv->getUi()->prenom->setText(prenom);
                dialogreserv->getUi()->ville->setText(ville);
                dialogreserv->getUi()->numreservation->setValue(ReservationExist.numreservation);
                dialogreserv->getUi()->numtrain->setValue(ReservationExist.numtrain);
                dialogreserv->getUi()->jour->setValue(ReservationExist.jour);
                dialogreserv->getUi()->mois->setValue(ReservationExist.mois);
                dialogreserv->getUi()->annee->setValue(ReservationExist.annee);
                dialogreserv->getUi()->place->setValue(ReservationExist.place);
                dialogreserv->getUi()->vola->setValue(ReservationExist.money/ReservationExist.place);
                int res = dialogreserv->exec();
                strcpy(reserva.nom, dialogreserv->getUi()->nom->text().toLatin1().toUpper().data());
                nom = this->write(reserva.nom);
                strcpy(reserva.prenom, dialogreserv->getUi()->prenom->text().toLatin1().data());
                prenom = this->write(reserva.prenom);
                strcpy(reserva.ville, dialogreserv->getUi()->ville->text().toLatin1().data());
                ville = this->write(reserva.ville);
                reserva.numreservation = dialogreserv->getUi()->numreservation->value();
                strcpy(reserva.nom, nom.toLatin1().toUpper().data());
                strcpy(reserva.prenom, prenom.toLatin1().data());
                strcpy(reserva.ville,ville.toLatin1().data());
                reserva.numtrain = dialogreserv->getUi()->numtrain->value();
                reserva.jour = dialogreserv->getUi()->jour->value();
                reserva.mois = dialogreserv->getUi()->mois->value();
                reserva.annee = dialogreserv->getUi()->annee->value();
                reserva.place = dialogreserv->getUi()->place->value();
                reserva.money = dialogreserv->getUi()->vola->value();
                reserva.money = reserva.money*reserva.place;
                if(res == QDialog::Accepted){
                    reservationtab[r] = reserva;
                    QMessageBox::information(this,"Succès","Reservation modifié avec succès");
                    ////////////////////////////////////////////////////////////////////////////
                    FILE *q=NULL;
                                        FILE *qile=NULL;
                                        Place lamasin, placeExist, placeTab[50];
                                        Reservation ReservationExist;
                                        q=fopen(ficPlace.toLatin1().data(), "r");
                                        int numtrainreserve = ui->Reservationtab->item(selectedRow, 1)->text().toInt();
                                        int r=0;
                                        while(!feof(q))
                                        {
                                            fscanf(q, "%d > %d > %d\n", &placeExist.numtrain, &placeExist.nbrplace, &placeExist.noccupation);

                                            qile=fopen(ficReservation.toLatin1().data(),"r");
                                            while(!feof(qile))
                                            {
                                                fscanf(qile, "%d > %d > %d > %d > %d > %d > %s > %s > %s > %d \n",&ReservationExist.numreservation,&ReservationExist.numtrain,&ReservationExist.jour,&ReservationExist.mois,&ReservationExist.annee,&ReservationExist.place,ReservationExist.nom,ReservationExist.prenom,ReservationExist.ville,&ReservationExist.money);
                                                if(placeExist.numtrain==numtrainreserve)
                                                {
                                                lamasin.numtrain=reserva.numtrain;
                                                lamasin.nbrplace=placeExist.nbrplace;
                                                lamasin.noccupation=placeExist.noccupation-ReservationExist.place+reserva.place;

                                                    placeTab[r]=lamasin;
                                                }
                                                else
                                                {
                                                    placeTab[r]=placeExist;
                                                }
                                            }
                                            r++;
                                        }
                                        fclose(qile);

                                        fclose(q);
                                        q=fopen(ficPlace.toLatin1().data(), "w");
                                        for(int v=0;v<=r-1;v++)
                                        {
                                            fprintf(q, "%d > %d > %d\n",
                                                    placeTab[v].numtrain,
                                                    placeTab[v].nbrplace,
                                                    placeTab[v].noccupation);
                                        }
                                        fclose(q);
                                        ////////////////////////////////////////////////////////////////////////////////
                                        FILE *zile=NULL;
                                        Recette zamasin,zlaceExist, zlaceTab[50];
                                        FILE*z=NULL;
                                        Reservation zeservationExist;
                                        zile=fopen(ficRecette.toLatin1().data(), "r");
                                        int t=0;
                                        while(!feof(zile))
                                        {
                                            fscanf(zile, "%d > %d > %d\n", &zlaceExist.numtrtain, &zlaceExist.montant, &zlaceExist.occupation);


                                                z=fopen(ficReservation.toLatin1().data(),"r");
                                                while(!feof(z))
                                                {
                                                    fscanf(z, "%d > %d > %d > %d > %d > %d > %s > %s > %s > %d \n", &zeservationExist.numreservation,&zeservationExist.numtrain,&zeservationExist.jour,&zeservationExist.mois,&zeservationExist.annee,&zeservationExist.place,zeservationExist.nom,zeservationExist.prenom,zeservationExist.ville,&zeservationExist.money);
                                                    if (zlaceExist.numtrtain==numtrainreserve && numtrainreserve==zeservationExist.numtrain)
                                                    {
                                                        zamasin.numtrtain=zlaceExist.numtrtain;
                                                        zamasin.montant=((zlaceExist.montant))-zeservationExist.money+reserva.money;
                                                        zamasin.occupation=zlaceExist.occupation-zeservationExist.place+reserva.place;

                                                            zlaceTab[t]=zamasin;
                                                    }
                                                    else
                                                    {
                                                        zlaceTab[t]=zlaceExist;
                                                    }

                                                }
                                                t++;
                                        }
                                        fclose(z);
                                        fclose(zile);

                                        zile=fopen(ficRecette.toLatin1().data(), "w");
                                        for(int v=0;v<=t-1;v++)
                                        {
                                            fprintf(zile, "%d > %d > %d\n",
                                                    zlaceTab[v].numtrtain,
                                                    zlaceTab[v].montant,
                                                    zlaceTab[v].occupation);
                                        }
                                        fclose(zile);
                                        ///////////////////////////////////////////////////////////////////////////////////
                }
                else
                    reservationtab[r] = ReservationExist;
            }
                r++;


        }
        fclose(file);
        fclose(f);
        f=fopen(nomFic, "w");
        for(int v=0;v<=r-1;v++){
            fprintf(f, "%d > %d > %d > %d > %d > %d > %s > %s > %s > %d \n",
                    reservationtab[v].numreservation,
                    reservationtab[v].numtrain,
                    reservationtab[v].jour,
                    reservationtab[v].mois,
                    reservationtab[v].annee,
                    reservationtab[v].place,
                    reservationtab[v].nom,
                    reservationtab[v].prenom,
                    reservationtab[v].ville,
                    reservationtab[v].money);
        }
    }
    fclose(f);
}


void Gestion_de_Train::editTabSupprReservation(char *nomFic, FILE *f)
{
    QList<QTableWidgetItem*> list = ui->Reservationtab->selectedItems();

    if(list.size()==0){
        QMessageBox::warning(this,"Error","Veuillez selection la reservation à supprimer");
    }
    else{
        f=fopen(nomFic, "r");
        Reservation reserva, ReservationExist, reservationtab[50];
        reserva.numreservation=-1;
        int i, j=0;
        while(!feof(f)){
            fscanf(f, "%d > %d > %d > %d > %d > %d > %s > %s > %s > %d \n", &ReservationExist.numreservation,&ReservationExist.numtrain,&ReservationExist.jour,&ReservationExist.mois,&ReservationExist.annee,&ReservationExist.place,ReservationExist.nom,ReservationExist.prenom,ReservationExist.ville,&ReservationExist.money);
            i=0;
            while(i<list.size() && ReservationExist.numreservation!=reserva.numreservation){
                reserva.numreservation = list[i]->text().toInt();
                i+=4;
            }
            if(ReservationExist.numreservation!=reserva.numreservation){
                reservationtab[j] = ReservationExist;
                j++;
            }
            else{
                QMessageBox::information(this,"Info","Reservation supprimer avec succès");
                this->supproccupation();
                this->suprerecette();
            }
        }
        fclose(f);
        f=fopen(nomFic, "w");
        for(int e=0;e<=j-1;e++){
            fprintf(f, "%d > %d > %d > %d > %d > %d > %s > %s > %s > %d \n",
                    reservationtab[e].numreservation,
                    reservationtab[e].numtrain,
                    reservationtab[e].jour,
                    reservationtab[e].mois,
                    reservationtab[e].annee,
                    reservationtab[e].place,
                    reservationtab[e].nom,
                    reservationtab[e].prenom,
                    reservationtab[e].ville,
                    reservationtab[e].money);
        }
        fclose(f);
    }
}




