#include "gestion_de_train.h"
#include "ui_gestion_de_train.h"
#include "train.h"
#include "dialog.h"
#include "ui_dialog.h"


void Gestion_de_Train::editTabAjoutTrain(char *nomFic, FILE *f)
{
    f=fopen(nomFic, "r");
    ui->traintab->setRowCount(0);
    Train TrainExist;
    TrainExist.numtrain=-1;
    int k=0;
        do
        {
        fscanf(f, "%d > %s > %d %d\n", &TrainExist.numtrain,TrainExist.design, &TrainExist.nbrplace,&TrainExist.numitineraire);
        if(TrainExist.numtrain==-1)
        ui->traintab->setRowCount(0);
        else
        {


                QString designtrain=this->read(TrainExist.design);
                ui->traintab->insertRow(k);
                QTableWidgetItem *item = new QTableWidgetItem;
                QTableWidgetItem *ite = new QTableWidgetItem;
                QTableWidgetItem *it=new QTableWidgetItem;
                int numbtrain = TrainExist.numtrain;
                int placetrain = TrainExist.nbrplace;
                int itintrain= TrainExist.numitineraire;
                item->setData(Qt::DisplayRole,numbtrain);
                ite->setData(Qt::DisplayRole,placetrain);
                it->setData(Qt::DisplayRole,itintrain);
                ui->traintab->setItem(k,0, item);
                ui->traintab->setItem(k,1, new QTableWidgetItem(designtrain));
                ui->traintab->setItem(k,2,ite);
                ui->traintab->setItem(k,3, it);
                k++;
            }
        }while(!feof(f));
    ui->traintab->sortItems(0);
    fclose(f);


}

void Gestion_de_Train::ajoutTrain(char *nomFic,FILE *f)
{
    bool ok;
   int numbtrain= QInputDialog::getInt(this, "Numero", "Veuillez saisir le numero du train",
                                        1, 0, 999999999, 1,&ok);
       if(ok)
        {
        FILE *file;
        FILE *fule;
        Train lamasin, trainExist;
        Place pilasy;
        Recette recette;
        Reservation rese;
        rese.place=0;
        recette.occupation=0;
        recette.montant=0;
        Dialog *dialog=new Dialog(this);
        f=fopen(nomFic, "r");
        file=fopen(ficPlace.toLatin1().data(),"r");
        fule=fopen(ficRecette.toLatin1().data(),"r");
        lamasin.numtrain=numbtrain;
        pilasy.numtrain=lamasin.numtrain;
        recette.numtrtain=lamasin.numtrain;
        trainExist.numtrain=-1;
        dialog->getUi()->numbtrain->setValue(numbtrain);

        fscanf(f, "%d > %s > %d %d\n", &trainExist.numtrain,trainExist.design, &trainExist.nbrplace,&trainExist.numitineraire);
        fscanf(file,"%d > %d > %d\n" , &pilasy.numtrain,&pilasy.nbrplace,&rese.place);
        fscanf(fule,"%d > %d > %d\n" , &recette.numtrtain,&recette.montant,&recette.occupation);

        if(trainExist.numtrain==-1)
        {
            fclose(f);
            int res =dialog->exec();
            strcpy(lamasin.design,dialog->getUi()->designtrain->text().toLatin1().data());
            QString designtrain=write(lamasin.design);
            if(designtrain=="")
                designtrain="***";
            lamasin.nbrplace=dialog->getUi()->placetrain->value();
            pilasy.nbrplace=lamasin.nbrplace;
            lamasin.numitineraire=dialog->getUi()->itintrain->value();
            strcpy(lamasin.design, designtrain.toLatin1().data());
            if(res == QDialog::Accepted)
            {
                file = fopen(ficPlace.toLatin1().data(),"a+");
                fprintf(file, "%d > %d > %d\n" , pilasy.numtrain,pilasy.nbrplace,rese.place);
                fclose(file);
                fule = fopen(ficRecette.toLatin1().data(),"a+");
                fprintf(fule,"%d > %d > %d\n" , recette.numtrtain,recette.montant,recette.occupation);
                fclose(fule);
                f=fopen(nomFic, "a+");
                fprintf(f, "%d > %s > %d %d\n", lamasin.numtrain,lamasin.design, lamasin.nbrplace,lamasin.numitineraire);
                QMessageBox::information(this, "Succès", "Train enregistré avec succès");
                fclose(f);
            }
        }

        else
        {
            while(!feof(f) && !feof(file) && !feof(fule) && trainExist.numtrain!=lamasin.numtrain)
            {
                fscanf(file,"%d > %d > %d\n" , &pilasy.numtrain,&pilasy.nbrplace,&rese.place);
                fscanf(f, "%d > %s > %d %d\n", &trainExist.numtrain,trainExist.design, &trainExist.nbrplace,&trainExist.numitineraire);
                fscanf(fule,"%d > %d > %d\n" , &recette.numtrtain,&recette.montant,&recette.occupation);
             }


            if(trainExist.numtrain!=lamasin.numtrain)
            {
                fclose(f);
                fclose(file);
                fclose(fule);
                f=fopen(nomFic, "a+");
                file=fopen(ficPlace.toLatin1().data(), "a+");
                fule=fopen(ficRecette.toLatin1().data(),"a+");
                int res = dialog->exec();
                strcpy(lamasin.design,dialog->getUi()->designtrain->text().toLatin1().data());
                QString designtrain=write(lamasin.design);
                if(designtrain=="")
                    designtrain="***";
                lamasin.nbrplace=dialog->getUi()->placetrain->value();
                pilasy.nbrplace=lamasin.nbrplace;
                lamasin.numitineraire=dialog->getUi()->itintrain->value();
                rese.place=0;
                recette.numtrtain=lamasin.numtrain;
                recette.montant=0;
                recette.occupation=0;
                strcpy(lamasin.design, designtrain.toLatin1().data());
                if(res == QDialog::Accepted)
                {
                    fprintf(fule,"%d > %d > %d\n" , recette.numtrtain,recette.montant,recette.occupation);
                    fprintf(file, "%d > %d > %d\n" , lamasin.numtrain,pilasy.nbrplace,rese.place);
                    fprintf(f, "%d > %s > %d %d\n", lamasin.numtrain,lamasin.design, lamasin.nbrplace,lamasin.numitineraire);
                    QMessageBox::information(this, "Succès", "Train enregistré avec succès");
                }
            }
            else
                QMessageBox::critical(this, "error", "Train déjà saisie");


         fclose(file);
         fclose(f);
         fclose(fule);
        }
        }
}

void Gestion_de_Train::editTabModifTrain(char *nomFic, FILE *f)
{

    int selectedRow =ui->traintab->currentRow();
    if(selectedRow<0)
        QMessageBox::critical(this,"Error", "Veuillez cliquer sur le train à modifier");
    else
    {
        Dialog *dialog=new Dialog(this);
        FILE *file=NULL;
        Train lamasin, trainExist,trainTab[50];
        Place pilasyeo, pilasytab[50];
        pilasyeo.noccupation=0;

        lamasin.numtrain=ui->traintab->item(selectedRow, 0)->text().toInt();

        f=fopen(nomFic, "r");
        file=fopen(ficPlace.toLatin1().data(),"r");

        int r=0,i=0;
        while(!feof(f))
            {
                fscanf(f, "%d > %s > %d %d\n", &trainExist.numtrain,trainExist.design, &trainExist.nbrplace,&trainExist.numitineraire);

                if(trainExist.numtrain!=lamasin.numtrain)
                {
                    trainTab[r]=trainExist;

                }

                else
                    {
                    dialog->getUi()->numbtrain->setDisabled(false);
                    dialog->getUi()->numbtrain->setReadOnly(true);
                    dialog->getUi()->numbtrain->setValue(trainExist.numtrain);
                    QString designtrain=this->read(trainExist.design);
                    dialog->getUi()->designtrain->setText(designtrain);
                    dialog->getUi()->placetrain->setValue(trainExist.nbrplace);
                    dialog->getUi()->itintrain->setValue(trainExist.numitineraire);

                    int res=dialog->exec();

                    strcpy(lamasin.design,dialog->getUi()->designtrain->text().toLatin1().data());
                    designtrain=this->write(lamasin.design);
                    lamasin.numtrain= dialog->getUi()->numbtrain->value();
                    strcpy(lamasin.design,  designtrain.toLatin1().data());
                    lamasin.nbrplace= dialog->getUi()->placetrain->value();
                    lamasin.numitineraire= dialog->getUi()->itintrain->value();

                    if(res==QDialog::Accepted)
                    {
                    trainTab[r]=lamasin;

                    file=fopen(ficPlace.toLatin1().data(),"r");
                    while(!feof(file))
                    {
                        fscanf(file,"%d > %d > %d\n" , &pilasyeo.numtrain,&pilasyeo.nbrplace,&pilasyeo.noccupation);
                        if(pilasyeo.numtrain==-1)
                            break;
                        else if(trainExist.numtrain==pilasyeo.numtrain)
                        {
                            pilasyeo.numtrain=lamasin.numtrain;
                            pilasyeo.nbrplace=lamasin.nbrplace;
                            pilasytab[i]=pilasyeo;
                        }
                        else
                            pilasytab[i]=pilasyeo;
                        i++;

                    }
                    QMessageBox::information(this, "Succès", "Train modifié avec succès");

                    }
                    else
                        trainTab[r]=trainExist;
                    }
                r++;
            }

        fclose(file);
        if(pilasyeo.numtrain!=-1)
        {
        file=fopen(ficPlace.toLatin1().data(),"w");
        for(int v=0;v<=r-1;v++)
        {
            fprintf(file, "%d > %d > %d\n" ,
                    pilasytab[v].numtrain,
                    pilasytab[v].nbrplace,
                    pilasytab[v].noccupation);
        }
        fclose(file);
        }

        fclose(f);
        f=fopen(nomFic,"w");
        for(int v=0;v<=r-1;v++)
        {
            fprintf(f, "%d > %s > %d %d\n",
                   trainTab[v].numtrain,
                   trainTab[v].design,
                   trainTab[v].nbrplace,
                   trainTab[v].numitineraire);

        }
        }
    fclose(f);

}

void Gestion_de_Train::editTabSupprTrain(char *nomFic, FILE *f)
{
    QList<QTableWidgetItem*> list = ui->traintab->selectedItems();


    if(list.size()==0)
    {
        QMessageBox::critical(this,"Error", "Veuillez cliquer sur le professeur à supprimer");
    }

    else
    {
        f=fopen(nomFic,"r");
        FILE *file=NULL;
        FILE *fule=NULL;
        Train lamasin,trainExist,trainTab[50];
        Place affecExist,affecTab[50];
        Recette recetteExist, recetteTab[50];
        lamasin.numtrain=-1;
        int i,j=0;
        while(!feof(f))
        {
            fscanf(f, "%d > %s > %d %d\n", &trainExist.numtrain,trainExist.design, &trainExist.nbrplace,&trainExist.numitineraire);
             i=0;
            while(i<list.size() && trainExist.numtrain!=lamasin.numtrain)
            {
                lamasin.numtrain=list[i]->text().toInt();
                i+=4;
            }
            if(trainExist.numtrain!=lamasin.numtrain)
            {
                trainTab[j]=trainExist;
                j++;
            }
            else
            {
                int l=0,k=0;
                QMessageBox::information(this,"info", "Train supprimé avec succès");
                file=fopen(ficPlace.toLatin1().data(),"r");
                fule=fopen(ficRecette.toLatin1().data(),"r");
                affecExist.numtrain=-1;
                recetteExist.numtrtain=-1;
                while(!feof(file))
                {
                    fscanf(file,"%d > %d > %d\n",
                           &affecExist.numtrain,
                           &affecExist.nbrplace,
                           &affecExist.noccupation);
                 if(lamasin.numtrain!=affecExist.numtrain)
                 {
                     affecTab[l]=affecExist;
                     l++;
                 }
                }
                fclose(file);
                while(!feof(fule))
                {
                    fscanf(fule,"%d > %d > %d\n",
                           &recetteExist.numtrtain,
                           &recetteExist.montant,
                           &recetteExist.occupation);
                    if(lamasin.numtrain!=recetteExist.numtrtain)
                    {
                        recetteTab[k]=recetteExist;
                        k++;
                    }
                }
                fclose(fule);
                if(affecTab[0].numtrain!=-1)
                {
                file=fopen(ficPlace.toLatin1().data(),"w");
                for(int n=0;n<=l-1;n++)
                {
                    fprintf(file,"%d > %d > %d\n",
                            affecTab[n].numtrain,
                            affecTab[n].nbrplace,
                            affecTab[n].noccupation);
                }
                fclose(file);
                }
                if(recetteTab[0].numtrtain!=-1)
                {
                fule=fopen(ficRecette.toLatin1().data(),"w");
                for(int n=0;n<=k-1;n++)
                {
                    fprintf(fule,"%d > %d > %d\n",
                            recetteTab[n].numtrtain,
                            recetteTab[n].montant,
                            recetteTab[n].occupation);
                }
                fclose(fule);
                }
            }

        }
        fclose(f);
        f=fopen(nomFic,"w");
        for(int e=0;e<=j-1;e++)
        {
            fprintf(f, "%d > %s > %d %d\n",
                   trainTab[e].numtrain,
                   trainTab[e].design,
                   trainTab[e].nbrplace,
                   trainTab[e].numitineraire);
        }
        fclose(f);
    }

}
