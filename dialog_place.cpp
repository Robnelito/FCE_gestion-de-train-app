#include "dialog_place.h"
#include "ui_dialog_place.h"

Dialog_Place::Dialog_Place(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_Place)
{
    ui->setupUi(this);
    connect(ui->save,SIGNAL(clicked()),this,SLOT(accept()));
    connect(ui->annuler,SIGNAL(clicked()),this,SLOT(reject()));
}
Ui::Dialog_Place *Dialog_Place::getUi()
{
    return ui;
}
Dialog_Place::~Dialog_Place()
{
    delete ui;
}
void Dialog_Place::Check()
{
    if(ui->numplace->value()==0)
    {
        ui->save->setDisabled(false);
    }
    else
    {
        ui->save->setDisabled(true);
    }
}
