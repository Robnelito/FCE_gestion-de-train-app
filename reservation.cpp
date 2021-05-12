#include "reservation.h"
#include "ui_reservation.h"
#include "gestion_de_train.h"
#include "ui_gestion_de_train.h"
#include "destination.h"
#include "ui_destination.h"

reservation::reservation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::reservation)
{
    ui->setupUi(this);
    connect(ui->valider,SIGNAL(clicked()),this,SLOT(accept()));
    connect(ui->annuler,SIGNAL(clicked()),this,SLOT(reject()));
    connect(ui->nom,SIGNAL(textChanged(QString)),this,SLOT(checkNom()));
    connect(ui->prenom,SIGNAL(textChanged(QString)),this,SLOT(checkNom()));
    this->setWindowTitle("Réservation");
    this->setFixedSize(370,390);
    //this->setWindowFlags(Qt::CustomizeWindowHint);
    //this->setWindowFlags(Qt::WindowCloseButtonHint);
}

Ui::reservation *reservation::getUi()
{
    return ui;
}

reservation::~reservation()
{
    delete ui;
}
void reservation::checkNom()
{
    if(ui->nom->text()!=""&&
            ui->prenom->text()!="")
        ui->valider->setEnabled(true);
}

void reservation::on_pushButton_clicked()
{
    Destination *s=new Destination(this);
    s->exec();

    ui->ville->setText(s->getUi()->lineEdit->text());
    ui->vola->setValue(s->getUi()->spinBox->value());
}
