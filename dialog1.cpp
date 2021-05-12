#include "dialog1.h"
#include "ui_dialog1.h"
#include "gestion_de_train.h"
#include "ui_gestion_de_train.h"

Dialog1::Dialog1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog1)
{
    ui->setupUi(this);
    connect(ui->savebtn, SIGNAL(clicked(bool)),this,SLOT(accept()));
    connect(ui->cancel, SIGNAL(clicked(bool)),this,SLOT(reject()));
    connect(ui->projectName,SIGNAL(textChanged(QString)),this,SLOT(checkText()));
    connect(ui->ficTrain,SIGNAL(textChanged(QString)),this,SLOT(checkText()));
    connect(ui->ficPlace,SIGNAL(textChanged(QString)),this,SLOT(checkText()));
    connect(ui->ficItineraire,SIGNAL(textChanged(QString)),this,SLOT(checkText()));
    connect(ui->ficReservation,SIGNAL(textChanged(QString)),this,SLOT(checkText()));
    connect(ui->ficRecette,SIGNAL(textChanged(QString)),this,SLOT(checkText()));
    this->setWindowTitle("Création des fichiers");
}

Ui::Dialog1 *Dialog1::getUi()
{
    return ui;
}

void Gestion_de_Train::creationFichier()
{
    QString dir= QFileDialog::getExistingDirectory(this);
    QString ficT,ficP,ficI,ficR,ficRt;
    QDir directory(dir);
    Dialog1 *dialog=new Dialog1(this);
    FILE *file=NULL;
    if(!dir.isEmpty())
    {
    dialog->getUi()->chemin->setText(dir);
    int res=dialog->exec();
    if(res==QDialog::Accepted)
    {
        directory.mkdir(dialog->getUi()->projectName->text());
        ficT=dialog->getUi()->ficTrain->text();
        ficP=dialog->getUi()->ficPlace->text();
        ficI=dialog->getUi()->ficItineraire->text();
        ficR=dialog->getUi()->ficReservation->text();
        ficRt=dialog->getUi()->ficRecette->text();
        file=fopen(QString(dir+"/"+dialog->getUi()->projectName->text()+"/"+ficT).toLatin1().data(),"w");
        fclose(file);
        file=fopen(QString(dir+"/"+dialog->getUi()->projectName->text()+"/"+ficP).toLatin1().data(),"w");
        fclose(file);
        file=fopen(QString(dir+"/"+dialog->getUi()->projectName->text()+"/"+ficI).toLatin1().data(),"w");
        fclose(file);
        file=fopen(QString(dir+"/"+dialog->getUi()->projectName->text()+"/"+ficR).toLatin1().data(),"w");
        fclose(file);
        file=fopen(QString(dir+"/"+dialog->getUi()->projectName->text()+"/"+ficRt).toLatin1().data(),"w");
        fclose(file);
        file=fopen((dir+"/"+dialog->getUi()->projectName->text()+"/"+dialog->getUi()->projectName->text()+".hco").toLatin1().data(),"w");
        fclose(file);
        ficTrain=dir+"/"+dialog->getUi()->projectName->text()+"/"+ficT;
        ficPlace=dir+"/"+dialog->getUi()->projectName->text()+"/"+ficP;
        ficItineraire=dir+"/"+dialog->getUi()->projectName->text()+"/"+ficI;
        ficReservation=dir+"/"+dialog->getUi()->projectName->text()+"/"+ficR;
        ficRecette=dir+"/"+dialog->getUi()->projectName->text()+"/"+ficRt;
        ui->pushButton->setHidden(false);
        ui->Train->setHidden(false);
        ui->pushButton_2->setHidden(false);
        ui->pushButton_3->setHidden(false);
        ui->pushButton_4->setHidden(false);
        ui->pushButton_5->setHidden(false);
        //ui->pushButton_6->setHidden(false);

    }

    }
}

Dialog1::~Dialog1()
{
    delete ui;
}

void Dialog1::checkText()
{
    if(ui->projectName->text()!=""&&
       ui->ficTrain->text()!=""&&
       ui->ficPlace->text()!=""&&
       ui->ficItineraire->text()!=""&&
       ui->ficReservation->text()!=""&&
       ui->ficRecette->text()!="")

        ui->savebtn->setEnabled(true);
}

void Dialog1::on_projectName_textChanged(const QString &arg1)
{
    ui->ficTrain->setText(arg1+".bin");
    ui->ficPlace->setText(arg1+".dat");
    ui->ficItineraire->setText(arg1+".dot");
    ui->ficReservation->setText(arg1+".txt");
    ui->ficRecette->setText(arg1+".docx");
}

void Dialog1::on_Browse_clicked()
{
    QString dir= QFileDialog::getExistingDirectory(this);
    if(!dir.isEmpty())
    ui->chemin->setText(dir);
}
