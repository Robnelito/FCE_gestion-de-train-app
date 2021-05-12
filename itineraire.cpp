#include "itineraire.h"
#include "ui_itineraire.h"

Itineraire::Itineraire(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Itineraire)
{
    ui->setupUi(this);
    connect(ui->valider,SIGNAL(clicked()),this,SLOT(accept()));
    connect(ui->annuler,SIGNAL(clicked()),this,SLOT(reject()));
    this->setWindowTitle("Itinéraire");
    this->setFixedSize(350,345);
    ui->depart->setText("Fianarantsoa");
    ui->arrivee->setText("Manakara");
    ui->frais->setValue(25000);
}

Ui::Itineraire *Itineraire::getUi()
{
    return ui;
}

Itineraire::~Itineraire()
{
    delete ui;
}

//btnitineraire===============================================================

//aller=====

void Itineraire::on_fianaraA_clicked()
{/*
    ui->depart->setText("Ville A");
    QString dep = ui->depart->text();
    if(dep=="Ville A")
    {
       ui->fianaraA_2->setEnabled(false);
       ui->ManakA_2->setEnabled(true);
       ui->pushButton_2->setEnabled(true);
    }*/
}

void Itineraire::on_ManakA_clicked()
{/*
    ui->depart->setText("Ville B");
    QString dep = ui->depart->text();
    if(dep=="Ville B")
    {
        ui->fianaraA_2->setEnabled(true);
        ui->ManakA_2->setEnabled(false);
        ui->pushButton_2->setEnabled(true);
    }*/
}

void Itineraire::on_pushButton_clicked()
{
    /*ui->depart->setText("Ville C");
    QString dep = ui->depart->text();
    if(dep=="Ville C")
    {
        ui->fianaraA_2->setEnabled(true);
        ui->ManakA_2->setEnabled(true);
        ui->pushButton_2->setEnabled(false);
    }*/
}

//arrivee=====

void Itineraire::on_fianaraA_2_clicked()
{
    //ui->arrivee->setText("Ville A");
    //QString dep = ui->arrivee->text();
}

void Itineraire::on_ManakA_2_clicked()
{
    //ui->arrivee->setText("Ville B");
    //QString dep = ui->arrivee->text();
}

void Itineraire::on_pushButton_2_clicked()
{
    //ui->arrivee->setText("Ville C");
    //QString dep = ui->arrivee->text();
}

//fin_btnitineraire===============================================================

void Itineraire::on_mille_clicked()
{
    ui->frais->setValue(1000);
}

void Itineraire::on_deuxmille_clicked()
{
    ui->frais->setValue(2000);
}



void Itineraire::on_comboBox_2_currentTextChanged(const QString &arg1)
{
    ui->depart->setText(arg1);
}

void Itineraire::on_comboBox_3_currentTextChanged(const QString &arg1)
{
    ui->arrivee->setText(arg1);
}
