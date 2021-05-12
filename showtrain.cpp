#include "train.h"
#include "gestion_de_train.h"
#include "ui_gestion_de_train.h"
#include "qstring.h"


QString Gestion_de_Train::write(char word[])
{
    QString nombre=QString::fromLatin1(word);
    QString espace=" ";
    QString wordFinal;
    QString star="***";
    wordFinal=nombre.replace(espace, star);
    return wordFinal;

}

QString Gestion_de_Train::read(char word[])
{
    QString nombre=QString::fromLatin1(word);
    QString star="***";
    QString wordFinal;
    QString espace=" ";
    wordFinal=nombre.replace(star,espace);
    return wordFinal;
}
 /*
void Gestion_de_Train::findtrain(char *nomFic, FILE *f)
{
    f=fopen(nomFic, "r");
    ui->traintab->setRowCount(0);
    Train TrainExist;
    TrainExist.numtrain=-1;
    int k=0;
        do
        {
        fscanf(f, "%d > %s > %d %d\n", &TrainExist.numtrain,TrainExist.design, &TrainExist.nbrplace,&TrainExist.numitineraire);
        if(TrainExist.numtrain!=ui->spinBox->value())
        ui->traintab->setRowCount(0);
        if(TrainExist.numtrain==ui->spinBox->value())
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
*/
