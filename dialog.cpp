#include "dialog.h"
#include "ui_dialog.h"
#include "gestion_de_train.h"
#include "ui_gestion_de_train.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    connect(ui->valider,SIGNAL(clicked()),this,SLOT(accept()));
    connect(ui->annuler,SIGNAL(clicked()),this,SLOT(reject()));
    connect(ui->designtrain,SIGNAL(textChanged(QString)),this,SLOT(Chek()));
    this->setWindowTitle("Train");
    this->setFixedSize(410,340);
}

Ui::Dialog *Dialog::getUi()
{
    return ui;
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_un_clicked()
{
    ui->designtrain->setText("Récent");
}

void Dialog::on_deux_clicked()
{
    ui->designtrain->setText("Ancien");
}

void Dialog::Check()
{
    if(ui->designtrain->text()!="")
    {
        ui->valider->setDisabled(false);
    }
    else {
        ui->valider->setDisabled(true);
    }
}
