#include "gestion_de_train.h"
#include "ui_gestion_de_train.h"
#include "dialog1.h"
#include "ui_dialog1.h"
#include "dialog.h"
#include "ui_dialog.h"
#include "train.h"
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QApplication>
#include "mainwindow.h"
//#include "ui_mainwindow.h"
QT_CHARTS_USE_NAMESPACE

Gestion_de_Train::Gestion_de_Train(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Gestion_de_Train)
{
    ui->setupUi(this);
    ui->pushButton->setHidden(true);
    ui->Train->setHidden(true);
    ui->pushButton_2->setHidden(true);
    ui->pushButton_3->setHidden(true);
    ui->pushButton_4->setHidden(true);
    ui->pushButton_5->setHidden(true);
    //ui->pushButton_6->setHidden(true);
    ui->Reservationtab->setColumnWidth(0,250);
    ui->Reservationtab->setColumnWidth(1,150);
    ui->stackedWidget->setCurrentIndex(5);
    this->setWindowIcon(QIcon(":/image/vrai.ico"));
    this->setWindowTitle("FCE - MADAGASCAR");
    this->setFont(QFont("Century Gothic"));
    qApp->setWindowIcon(QIcon(":/image/icone.ico"));
    this->setFixedSize(830,540);
    this->setWindowFlags(Qt::CustomizeWindowHint);
    this->setWindowFlags(Qt::WindowTitleHint);
    this->setWindowFlags(Qt::WindowSystemMenuHint);
    this->setWindowFlags(Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint);
}

Gestion_de_Train::~Gestion_de_Train()
{
    delete ui;

}

void Gestion_de_Train::on_nouveau_clicked()
{
    this->creationFichier();
}

void Gestion_de_Train::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void Gestion_de_Train::on_pushButton_7_clicked()
{
    QString file=QFileDialog::getOpenFileName(this, "Fichier", QString(), "Text files(*.hco)");
    if(!file.isEmpty())
   {
        int taille=file.size()-4;
        QString reduced=file.left(taille);
        ficTrain=reduced+".bin";
        ficPlace=reduced+".dat";
        ficItineraire=reduced+".dot";
        ficReservation=reduced+".txt";
        ficRecette=reduced+".docx";
        ui->pushButton->setHidden(false);
        ui->Train->setHidden(false);
        ui->pushButton_2->setHidden(false);
        ui->pushButton_3->setHidden(false);
        ui->pushButton_4->setHidden(false);
        ui->pushButton_5->setHidden(false);
        //ui->pushButton_6->setHidden(false);
    }
}

//train==============================================================

void Gestion_de_Train::on_Train_clicked()
{
    FILE *f=NULL;
    this->editTabAjoutTrain(ficTrain.toLatin1().data(),f);
    ui->stackedWidget->setCurrentIndex(0);
}

void Gestion_de_Train::on_ajouter_clicked()
{
    FILE *f=NULL;
    this->ajoutTrain(ficTrain.toLatin1().data(),f);
    this->editTabAjoutTrain(ficTrain.toLatin1().data(),f);
}

void Gestion_de_Train::on_Modifi_clicked()
{
    FILE*f=NULL;
    this->editTabModifTrain(ficTrain.toLatin1().data(),f);
    this->editTabAjoutTrain(ficTrain.toLatin1().data(),f);
}

void Gestion_de_Train::on_suprimer_clicked()
{
    FILE *f=NULL;
    this->editTabSupprTrain(ficTrain.toLatin1().data(),f);
    this->editTabAjoutTrain(ficTrain.toLatin1().data(),f);
}

//fintrain=============================================================

//place================================================================

void Gestion_de_Train::on_pushButton_2_clicked()
{
    FILE *f=NULL;
    this->editTabAjoutPlace(ficPlace.toLatin1().data(),f);
    ui->stackedWidget->setCurrentIndex(2);
}

void Gestion_de_Train::on_suprimerplace_clicked()
{
    FILE *f=NULL;
    this->editTabSupprPlace(ficPlace.toLatin1().data(),f);
    this->editTabAjoutPlace(ficPlace.toLatin1().data(),f);
}

//finplace=========================================================

//itineraire=======================================================

void Gestion_de_Train::on_pushButton_3_clicked()
{
    FILE *f=NULL;
    this->editTabAjoutItineraire(ficItineraire.toLatin1().data(),f);
    ui->stackedWidget->setCurrentIndex(3);
}

void Gestion_de_Train::on_Ajoutpalce_2_clicked()
{
    FILE *f=NULL;
    this->ajoutItineraire(ficItineraire.toLatin1().data(),f);
    this->editTabAjoutItineraire(ficItineraire.toLatin1().data(),f);
}

void Gestion_de_Train::on_Modifplace_2_clicked()
{
    FILE *f=NULL;
    this->editTabModifItineraire(ficItineraire.toLatin1().data(),f);
    this->editTabAjoutItineraire(ficItineraire.toLatin1().data(),f);
}

void Gestion_de_Train::on_suprimerplace_2_clicked()
{
    FILE *f=NULL;
    this->editTabSupprItineraire(ficItineraire.toLatin1().data(),f);
    this->editTabAjoutItineraire(ficItineraire.toLatin1().data(),f);
}

//finitineraire======================================================

//Reservation========================================================

void Gestion_de_Train::on_pushButton_4_clicked()
{

    FILE *f=NULL;
    this->editTabAjoutReservation(ficReservation.toLatin1().data(),f);
    ui->stackedWidget->setCurrentIndex(4);
    ui->Reservationtab->setColumnWidth(0,100);
    ui->Reservationtab->setColumnWidth(1,50);
    ui->Reservationtab->setColumnWidth(2,50);
    ui->Reservationtab->setColumnWidth(3,50);
    ui->Reservationtab->setColumnWidth(4,60);
    ui->Reservationtab->setColumnWidth(5,100);
    ui->Reservationtab->setColumnWidth(6,125);
    ui->Reservationtab->setColumnWidth(7,125);
    ui->Reservationtab->setColumnWidth(8,80);
    ui->Reservationtab->setColumnWidth(9,50);
}

void Gestion_de_Train::on_Ajoutpalce_3_clicked()
{
    FILE *f=NULL;
    this->ajoutReservation(ficReservation.toLatin1().data(),f);
    this->editTabAjoutReservation(ficReservation.toLatin1().data(),f);
}

void Gestion_de_Train::on_Modifplace_3_clicked()
{
    FILE *f=NULL;
    this->editTabModifReservation(ficReservation.toLatin1().data(),f);
    this->editTabAjoutReservation(ficReservation.toLatin1().data(),f);
}

void Gestion_de_Train::on_suprimerplace_3_clicked()
{
    FILE *f=NULL;
    this->editTabSupprReservation(ficReservation.toLatin1().data(),f);
    this->editTabAjoutReservation(ficReservation.toLatin1().data(),f);
}

//finreservation=====================================================

//find===============================================================

void Gestion_de_Train::on_pushButton_11_clicked()
{
    QString searchName=ui->Chercher->text();
    QString nom;
    int i=0,res;
    while(i<ui->traintab->rowCount())
    {
        nom=ui->traintab->item(i,0)->text();
        res=nom.indexOf(searchName,0,Qt::CaseInsensitive);
        if(res==-1)
        {
        nom=ui->traintab->item(i,1)->text();
        res=nom.indexOf(searchName,0,Qt::CaseInsensitive);
        if(res==-1)
        {
            nom=ui->traintab->item(i,2)->text();
            res=nom.indexOf(searchName,0,Qt::CaseInsensitive);
            if(res!=-1)
            {
                ui->traintab->setRowHidden(i,false);
            }
            else
                ui->traintab->setRowHidden(i,true);
        }
        else
        {
            ui->traintab->setRowHidden(i,false);

        }
        }
        else
            ui->traintab->setRowHidden(i,false);
        i++;
    }
}

void Gestion_de_Train::on_find_clicked()
{
    QString searchName=ui->Chercher_2->text();
    QString nom;
    int i=0,res;
    while(i<ui->placetab->rowCount())
    {
        nom=ui->placetab->item(i,0)->text();
        res=nom.indexOf(searchName,0,Qt::CaseInsensitive);
        if(res==-1)
        {
        nom=ui->placetab->item(i,1)->text();
        res=nom.indexOf(searchName,0,Qt::CaseInsensitive);
        if(res==-1)
        {
            nom=ui->placetab->item(i,2)->text();
            res=nom.indexOf(searchName,0,Qt::CaseInsensitive);
            if(res!=-1)
            {
                ui->placetab->setRowHidden(i,false);
            }
            else
                ui->placetab->setRowHidden(i,true);
        }
        else
        {
            ui->placetab->setRowHidden(i,false);

        }
        }
        else
            ui->placetab->setRowHidden(i,false);
        i++;
    }
}

void Gestion_de_Train::on_find_2_clicked()
{
    QString searchName=ui->Chercher_3->text();
    QString nom;
    int i=0,res;
    while(i<ui->placetab->rowCount())
    {
        nom=ui->itinerairetab->item(i,0)->text();
        res=nom.indexOf(searchName,0,Qt::CaseInsensitive);
        if(res==-1)
        {
        nom=ui->itinerairetab->item(i,1)->text();
        res=nom.indexOf(searchName,0,Qt::CaseInsensitive);
        if(res==-1)
        {
            nom=ui->itinerairetab->item(i,2)->text();
            res=nom.indexOf(searchName,0,Qt::CaseInsensitive);
            if(res!=-1)
            {
                ui->itinerairetab->setRowHidden(i,false);
            }
            else
                ui->itinerairetab->setRowHidden(i,true);
        }
        else
        {
            ui->itinerairetab->setRowHidden(i,false);

        }
        }
        else
            ui->itinerairetab->setRowHidden(i,false);
        i++;
    }
}

void Gestion_de_Train::on_find_3_clicked()
{
    QString searchName=ui->Chercher_4->text();
    QString nom;
    int i=0,res;
    while(i<ui->Reservationtab->rowCount())
    {
        nom=ui->Reservationtab->item(i,0)->text();
        res=nom.indexOf(searchName,0,Qt::CaseInsensitive);
        if(res==-1)
        {
        nom=ui->Reservationtab->item(i,1)->text();
        res=nom.indexOf(searchName,0,Qt::CaseInsensitive);
        if(res==-1)
        {
            nom=ui->Reservationtab->item(i,2)->text();
            res=nom.indexOf(searchName,0,Qt::CaseInsensitive);
            if(res==-1)
            {
                nom=ui->Reservationtab->item(i,3)->text();
                res=nom.indexOf(searchName,0,Qt::CaseInsensitive);
                if(res==-1)
                {
                    nom=ui->Reservationtab->item(i,4)->text();
                    res=nom.indexOf(searchName,0,Qt::CaseInsensitive);
                    if(res==-1)
                    {
                        nom=ui->Reservationtab->item(i,5)->text();
                        res=nom.indexOf(searchName,0,Qt::CaseInsensitive);
                        if(res==-1)
                        {
                            nom=ui->Reservationtab->item(i,6)->text();
                            res=nom.indexOf(searchName,0,Qt::CaseInsensitive);
                            if(res==-1)
                            {
                                nom=ui->Reservationtab->item(i,7)->text();
                                res=nom.indexOf(searchName,0,Qt::CaseInsensitive);
                                if(res==-1)
                                {
                                    nom=ui->Reservationtab->item(i,8)->text();
                                    res=nom.indexOf(searchName,0,Qt::CaseInsensitive);
                                    if(res==-1)
                                    {
                                        nom=ui->Reservationtab->item(i,9)->text();
                                        res=nom.indexOf(searchName,0,Qt::CaseInsensitive);
                                        if(res!=-1)
                                        {
                                            ui->Reservationtab->setRowHidden(i,false);
                                        }
                                        else
                                            ui->Reservationtab->setRowHidden(i,true);
                                    }
                                    else
                                        ui->Reservationtab->setRowHidden(i,false);
                                }
                                else
                                    ui->Reservationtab->setRowHidden(i,false);
                             }
                        else
                            ui->Reservationtab->setRowHidden(i,false);
                        }
                    else
                        ui->Reservationtab->setRowHidden(i,false);
                    }
                else
                    ui->Reservationtab->setRowHidden(i,false);
                }
            else
                ui->Reservationtab->setRowHidden(i,false);
        }
        else
        {
            ui->Reservationtab->setRowHidden(i,false);

        }
        }
        else
            ui->Reservationtab->setRowHidden(i,false);
        i++;
    }
}
}
//finfind===========================================================================

//btn_refresh=======================================================================

void Gestion_de_Train::on_actualisertrain_clicked()
{
    FILE *f = NULL;
    this->editTabAjoutTrain(ficTrain.toLatin1().data(),f);
}

void Gestion_de_Train::on_actualiserplace_clicked()
{
    FILE *f = NULL;
    this->editTabAjoutPlace(ficPlace.toLatin1().data(),f);
}

void Gestion_de_Train::on_actualiseritineraire_clicked()
{
    FILE *f = NULL;
    this->editTabAjoutItineraire(ficItineraire.toLatin1().data(),f);
}

void Gestion_de_Train::on_actualisereservation_clicked()
{
    FILE *f = NULL;
    this->editTabAjoutReservation(ficReservation.toLatin1().data(),f);
}

//finbtn_refresh=========================================================================

//recette================================================================================

void Gestion_de_Train::on_pushButton_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    this->calculerecette();
    int r=0,u=0,t=0;
    t=ui->recettetab->rowCount();
    for(r=0;r<t;r++)
    {
        int res=ui->recettetab->item(r,1)->text().toInt();
        u=u+res;



    }
    ui->total->display(u);

}

//=======================================================================================

void Gestion_de_Train::on_actionNouveau_triggered()
{
    this->creationFichier();
}

void Gestion_de_Train::on_actionOuvrir_triggered()
{
    QString file=QFileDialog::getOpenFileName(this, "Fichier", QString(), "Text files(*.hco)");
    if(!file.isEmpty())
   {
        int taille=file.size()-4;
        QString reduced=file.left(taille);
        ficTrain=reduced+".bin";
        ficPlace=reduced+".dat";
        ficItineraire=reduced+".dot";
        ficReservation=reduced+".txt";
        ui->pushButton->setHidden(false);
        ui->Train->setHidden(false);
        ui->pushButton_2->setHidden(false);
        ui->pushButton_3->setHidden(false);
        ui->pushButton_4->setHidden(false);
        ui->pushButton_5->setHidden(false);
        //ui->pushButton_6->setHidden(false);
    }
}

void Gestion_de_Train::on_actionQuitter_triggered()
{
    int choix = QMessageBox::information(this, "Quitter", "Voulez-vous quitter?",
                                         QMessageBox::Yes | QMessageBox::No,
                                         QMessageBox::No);
    if(choix==QMessageBox::Yes)
    {
        QApplication::instance()->quit();
    }
}
/*void Gestion_de_Train::on_pushButton_6_clicked()
{
    Recette recetteExist;
    QPieSeries *series = new QPieSeries(this);
    FILE *file=NULL;
    file=fopen("temp.temp","r");
    int k=0,total;
}*/

void Gestion_de_Train::on_actionA_propos_triggered()
{
    propos = new Apropos(this);
    propos->show();
}
