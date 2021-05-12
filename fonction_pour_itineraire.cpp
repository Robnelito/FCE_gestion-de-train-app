#include "gestion_de_train.h"
#include "ui_gestion_de_train.h"
#include "train.h"
#include "itineraire.h"
#include "ui_itineraire.h"

void Gestion_de_Train::editTabAjoutItineraire(char *nomFic, FILE *f)
{
    f=fopen(nomFic, "r");
    ui->itinerairetab->setRowCount(0);
    itineraire ItineraireExist;
    ItineraireExist.numitineraire=-1;
    int k=0;
        do
        {
        fscanf(f,"%d\t %s\t %s\t %d\n", &ItineraireExist.numitineraire, ItineraireExist.depart, ItineraireExist.arrivee, &ItineraireExist.frais);
        if(ItineraireExist.numitineraire==-1)
        ui->itinerairetab->setRowCount(0);
        else
        {


                QString departitin=this->read(ItineraireExist.depart);
                QString arriveitin=this->read(ItineraireExist.arrivee);
                ui->itinerairetab->insertRow(k);
                QTableWidgetItem *item = new QTableWidgetItem;
                QTableWidgetItem *ite = new QTableWidgetItem;
                int numitin = ItineraireExist.numitineraire;
                int vola = ItineraireExist.frais;
                item->setData(Qt::DisplayRole,numitin);
                ite->setData(Qt::DisplayRole,vola);
                ui->itinerairetab->setItem(k,0, item);
                ui->itinerairetab->setItem(k,1, new QTableWidgetItem(departitin));
                ui->itinerairetab->setItem(k,2, new QTableWidgetItem(arriveitin));
                ui->itinerairetab->setItem(k,3,ite);
                k++;
            }
        }while(!feof(f));
    ui->traintab->sortItems(0);
    fclose(f);


}

void Gestion_de_Train::ajoutItineraire(char *nomFic, FILE *f)
{
    bool ok;

    int numbitineraire= QInputDialog::getInt(this, "Numero", "Veulliez saisir le numero de l'itineraire",
                                            1, 0, 999999999, 1,&ok);

         if(ok)
         {
             itineraire itinaka, itineraireExist;
             Itineraire *dialog=new Itineraire(this);
             f=fopen(nomFic, "r");
             itinaka.numitineraire=numbitineraire;
             itineraireExist.numitineraire=-1;
             dialog->getUi()->numitineraire->setValue(numbitineraire);
             fscanf(f,"%d\t %s\t %s\t %d\n", &itineraireExist.numitineraire, itineraireExist.depart, itineraireExist.arrivee, &itineraireExist.frais);
             if(itineraireExist.numitineraire==-1)
             {
                 fclose(f);
                 int res = dialog->exec();
                 strcpy(itinaka.depart,dialog->getUi()->depart->text().toLatin1().data());
                 strcpy(itinaka.arrivee,dialog->getUi()->arrivee->text().toLatin1().data());
                 QString depart=write(itinaka.depart);
                 QString arrivee=write(itinaka.arrivee);
                 if(depart==""||arrivee==""){
                     depart="***";
                     arrivee="***";
                 }
                 itinaka.numitineraire=dialog->getUi()->numitineraire->value();
                 itinaka.frais=dialog->getUi()->frais->value();
                 strcpy(itinaka.depart, depart.toLatin1().data());
                 strcpy(itinaka.arrivee, arrivee.toLatin1().data());
                 if(res == QDialog::Accepted)
                 {
                     f=fopen(nomFic, "a+");
                     fprintf(f,"%d\t %s\t %s\t %d\n", itinaka.numitineraire, itinaka.depart, itinaka.arrivee, itinaka.frais);
                     QMessageBox::information(this, "Succès", "Itineraire enregistré avec succès");
                     fclose(f);
                 }

             }

             else
             {
                 while(!feof(f) && itineraireExist.numitineraire!=itinaka.numitineraire)
                 {
                     fscanf(f,"%d\t %s\t %s\t %d\n", &itineraireExist.numitineraire, itineraireExist.depart, itineraireExist.arrivee, &itineraireExist.frais);
                 }

                 if(itineraireExist.numitineraire!=itinaka.numitineraire)
                 {
                     fclose(f);
                     f=fopen(nomFic, "a+");
                     int res = dialog->exec();
                     strcpy(itinaka.depart,dialog->getUi()->depart->text().toLatin1().data());
                     strcpy(itinaka.arrivee,dialog->getUi()->arrivee->text().toLatin1().data());
                     QString depart=write(itinaka.depart);
                     QString arrivee=write(itinaka.arrivee);
                     if(depart=="")
                         depart="***";
                     itinaka.numitineraire=dialog->getUi()->numitineraire->value();
                     itinaka.frais=dialog->getUi()->frais->value();
                     strcpy(itinaka.depart, depart.toLatin1().data());
                     strcpy(itinaka.arrivee, arrivee.toLatin1().data());
                     if(res == QDialog::Accepted)
                     {
                         fprintf(f,"%d\t %s\t %s\t %d\n", itinaka.numitineraire, itinaka.depart, itinaka.arrivee, itinaka.frais);
                         QMessageBox::information(this, " Succés", "Itineraire enregistré avec succès");
                     }
                 }
                 else
                     QMessageBox::critical(this , "error", "Itineraire déjà saisie");

                 fclose(f);
             }


         }

}
//*******************************************************************************************************************************************************************************************

void Gestion_de_Train::editTabModifItineraire(char *nomFic, FILE *f)
{
    int selectedRow =ui->itinerairetab->currentRow();
    if(selectedRow<0)
        QMessageBox::critical(this, "error" , "Veulliez cliquer sur l'itineraire à modifier");
    else
    {
        Itineraire *dialog=new Itineraire(this);
        FILE *file=NULL;
        itineraire itinaka, itineraireExist, itineraireTab[50];
        itinaka.numitineraire=ui->itinerairetab->item(selectedRow, 0)->text().toInt();
        f=fopen(nomFic, "r");
        int r=0;
        while(!feof(f))
        {
            fscanf(f,"%d %s %s %d\n", &itineraireExist.numitineraire, itineraireExist.depart, itineraireExist.arrivee, &itineraireExist.frais );
            if(itineraireExist.numitineraire!=itinaka.numitineraire)
            {
                itineraireTab[r]=itineraireExist;
            }
            else
            {
                dialog->getUi()->numitineraire->setDisabled(false);
                dialog->getUi()->numitineraire->setReadOnly(false);
                dialog->getUi()->numitineraire->setValue(itineraireExist.numitineraire);
                QString depart=this->read(itineraireExist.depart);
                QString arrivee=this->read(itineraireExist.arrivee);
                dialog->getUi()->depart->setText(depart);
                dialog->getUi()->arrivee->setText(arrivee);
                dialog->getUi()->frais->setValue(itineraireExist.frais);
                int res=dialog->exec();

                strcpy(itinaka.depart,dialog->getUi()->depart->text().toLatin1().data());
                depart=this->write(itinaka.depart);
                strcpy(itinaka.depart, depart.toLatin1().data());

                itinaka.numitineraire= dialog->getUi()->numitineraire->value();

                strcpy(itinaka.arrivee,dialog->getUi()->arrivee->text().toLatin1().data());
                arrivee=this->write(itinaka.arrivee);
                strcpy(itinaka.arrivee, arrivee.toLatin1().data());

                itinaka.frais= dialog->getUi()->frais->value();
                if(res==QDialog::Accepted)
                {
                    itineraireTab[r]=itinaka;
                    QMessageBox::information(this, "Succès", "Itineraire modifié avec succès");

                }
                else
                    itineraireTab[r]=itineraireExist;
                }
            r++;
        }

        fclose(file);

        fclose(f);
        f=fopen(nomFic, "w");
        for(int v=0;v<=r-1;v++)
        {
            fprintf(f, "%d %s %s %d\n",
                    itineraireTab[v].numitineraire,
                    itineraireTab[v].depart,
                    itineraireTab[v].arrivee,
                    itineraireTab[v].frais);
        }
    }
    fclose(f);
}


//****************************************************


void Gestion_de_Train::editTabSupprItineraire(char *nomFic, FILE *f)
{
    QList<QTableWidgetItem*> list = ui->itinerairetab->selectedItems();

    if(list.size()==0)
    {
        QMessageBox::critical(this, "Error" , "Veuillez cliquer l'itineraire à supprimer");

    }

    else
    {
        f=fopen(nomFic,"r");
        itineraire itinaka,itineraireExist,itineraireTab[50];
        itinaka.numitineraire=-1;
        int i,j=0;
        while(!feof(f))
        {
            fscanf(f, "%d %s %s %d\n", &itineraireExist.numitineraire,itineraireExist.depart,itineraireExist.arrivee,&itineraireExist.frais);
            i=0;
            while (i<list.size() && itineraireExist.numitineraire!=itinaka.numitineraire)
            {
                itinaka.numitineraire=list[i]->text().toInt();
                i+=4;
            }
            if(itineraireExist.numitineraire!=itinaka.numitineraire)
            {
                itineraireTab[j]=itineraireExist;
                j++;
            }
            else
            {
                QMessageBox::information(this,"info","Itineraire supprimer avec sccès");
            }
        }
        fclose(f);
        f=fopen(nomFic,"w");
        for(int e=0;e<=j-1;e++)
        {
            fprintf(f, "%d %s %s %d\n",
                    itineraireTab[e].numitineraire,
                    itineraireTab[e].depart,
                    itineraireTab[e].arrivee,
                    itineraireTab[e].frais);
        }
        fclose(f);
    }

}
