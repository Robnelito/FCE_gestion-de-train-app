#include "gestion_de_train.h"
#include "ui_gestion_de_train.h"
#include "train.h"
#include "dialog_place.h"
#include "ui_dialog_place.h"

void Gestion_de_Train::editTabAjoutPlace(char *nomFic, FILE *f)
{
    f=fopen(nomFic, "r");
    ui->placetab->setRowCount(0);
    Place PlaceExist;
    PlaceExist.numtrain=-1;
    int k=0;
    do
    {
        fscanf(f, "%d > %d > %d\n", &PlaceExist.numtrain, &PlaceExist.nbrplace, &PlaceExist.noccupation);
        if(PlaceExist.numtrain==-1)
            ui->placetab->setRowCount(0);
        else
        {
            ui->placetab->insertRow(k);
            QTableWidgetItem *item = new QTableWidgetItem;
            QTableWidgetItem *ite = new QTableWidgetItem;
            QTableWidgetItem *it = new QTableWidgetItem;
            int numbtrain = PlaceExist.numtrain;
            int numplace = PlaceExist.nbrplace;
            int occupation = PlaceExist.noccupation;
            item->setData(Qt::DisplayRole,numbtrain);
            ite->setData(Qt::DisplayRole,numplace);
            it->setData(Qt::DisplayRole,occupation);
            ui->placetab->setItem(k,0,item);
            ui->placetab->setItem(k,1,ite);
            ui->placetab->setItem(k,2,it);
            k++;
        }
    }
    while(!feof(f));
    ui->placetab->sortItems(1);
    fclose(f);
}
void Gestion_de_Train::ajoutPlace(char *nomFic, FILE *f)
{
    bool ok;
    int numbtrain = QInputDialog::getInt(this, "Numero", "Veuillez saisir le numero de train",
                                        1, 0, 99999999, 1, &ok);
    if(ok)
    {
        Place lamasin, placeExist;
        Dialog_Place *dialog=new Dialog_Place(this);
        f=fopen(nomFic, "r");
        lamasin.numtrain=numbtrain;
        placeExist.numtrain=-1;
        dialog->getUi()->numbtrain->setValue(numbtrain);
        fscanf(f, "%d > %d > %d\n", &placeExist.numtrain, &placeExist.nbrplace, &placeExist.noccupation);
        if(placeExist.numtrain==-1)
        {
            fclose(f);
            int res = dialog->exec();
            lamasin.nbrplace=dialog->getUi()->numplace->value();
            lamasin.noccupation=dialog->getUi()->occupation->value();
            if(res==QDialog::Accepted)
            {
                f=fopen(nomFic, "a+");
                fprintf(f, "%d > %d > %d\n", lamasin.numtrain, lamasin.nbrplace, lamasin.noccupation);
                QMessageBox::information(this, "Succès", "Place enregistré avec succès");
                fclose(f);
            }
        }
        else
        {
            while(!feof(f) && placeExist.numtrain!=lamasin.numtrain)
            {
                fscanf(f, "%d > %d > %d\n", &placeExist.numtrain, &placeExist.nbrplace, &placeExist.noccupation);
            }
            if(placeExist.numtrain!=lamasin.numtrain)
            {
                fclose(f);
                f=fopen(nomFic, "a+");
                int res = dialog->exec();
                lamasin.nbrplace=dialog->getUi()->numplace->value();
                lamasin.noccupation=dialog->getUi()->occupation->value();
                if(res==QDialog::Accepted)
                {
                    fprintf(f, "%d > %d > %d\n", lamasin.numtrain, lamasin.nbrplace, lamasin.noccupation);
                    QMessageBox::information(this, "Succès", "Place enregister avec succès");
                }
                else
                    QMessageBox::critical(this, "Error", "Place déjà prise");
            }
            fclose(f);
        }
    }
}
void Gestion_de_Train::editTabModifPlace(char *nomFic, FILE *f)
{
    int selectedRow = ui->placetab->currentRow();
    if(selectedRow<0)
        QMessageBox::critical(this, "Error", "Veuillez selectionner une ligne");
    else
    {
        Dialog_Place *dialog=new Dialog_Place(this);
        FILE *file=NULL;
        Place lamasin, placeExist, placeTab[50];
        lamasin.numtrain=ui->placetab->item(selectedRow, 0)->text().toInt();
        f=fopen(nomFic, "r");
        int r=0;
        while(!feof(f))
        {
            fscanf(f, "%d > %d > %d\n", &placeExist.numtrain, &placeExist.nbrplace, &placeExist.noccupation);
            if(placeExist.numtrain!=lamasin.numtrain)
            {
                placeTab[r]=placeExist;
            }
            else
            {
                dialog->getUi()->numbtrain->setDisabled(false);
                dialog->getUi()->numbtrain->setReadOnly(false);
                dialog->getUi()->numbtrain->setValue(placeExist.numtrain);
                dialog->getUi()->numplace->setValue(placeExist.nbrplace);
                dialog->getUi()->occupation->setValue(placeExist.noccupation);
                int res = dialog->exec();
                lamasin.numtrain=dialog->getUi()->numbtrain->value();
                lamasin.nbrplace=dialog->getUi()->numplace->value();
                lamasin.noccupation=dialog->getUi()->occupation->value();
                if(res==QDialog::Accepted)
                {
                    placeTab[r]=lamasin;
                    QMessageBox::information(this, "Succès", "Place modifié avec succèe");
                }
                else
                    placeTab[r]=placeExist;
            }
            r++;
        }
        fclose(file);

        fclose(f);
        fopen(nomFic, "w");
        for(int v=0;v<=r-1;v++)
        {
            fprintf(f, "%d > %d > %d\n",
                    placeTab[v].numtrain,
                    placeTab[v].nbrplace,
                    placeTab[v].noccupation);
        }
        fclose(f);
    }
}
void Gestion_de_Train::editTabSupprPlace(char *nomFic, FILE *f)
{
    QList<QTableWidgetItem*> list = ui->placetab->selectedItems();
    if(list.size()==0)
    {
        QMessageBox::critical(this, "Error", "Veuillez selectionner une ligne");
    }
    else
    {
        f=fopen(nomFic, "r");
        Place lamasin, placeExist, placeTab[50];
        lamasin.numtrain=-1;
        int i, j=0;
        while(!feof(f))
        {
            fscanf(f, "%d > %d > %d\n", &placeExist.numtrain, &placeExist.nbrplace, &placeExist.noccupation);
            i=0;
            while(i<list.size() && placeExist.numtrain!=lamasin.numtrain)
            {
                lamasin.numtrain=list[i]->text().toInt();
                i+=3;
            }
            if(placeExist.numtrain!=lamasin.numtrain)
            {
                placeTab[j]=placeExist;
                j++;
            }
            else
            {
                //int l=0;
                int choix = QMessageBox::critical(this, "Supprimer", "Voulez-vous supprimer?",
                                      QMessageBox::Yes | QMessageBox::No,
                                      QMessageBox::No);
                //QMessageBox::information(this, "Info", "Place supprimé avec succèe");
                if(choix==QMessageBox::Yes)
                {
                    QMessageBox::information(this, "Info", "Place supprimer avec succes");
                }
            }
        }
        fclose(f);
        f=fopen(nomFic, "w");
        for(int e=0;e<=j-1;e++)
        {
            fprintf(f, "%d > %d > %d\n",
                    placeTab[e].numtrain,
                    placeTab[e].nbrplace,
                    placeTab[e].noccupation);
        }
        fclose(f);
    }
}
