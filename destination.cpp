#include "destination.h"
#include "ui_destination.h"
#include "reservation.h"
#include "ui_reservation.h"

Destination::Destination(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Destination)
{
    ui->setupUi(this);
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(accept()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(accept()));
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(accept()));
    connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(accept()));
    connect(ui->pushButton_5,SIGNAL(clicked()),this,SLOT(accept()));
    connect(ui->pushButton_6,SIGNAL(clicked()),this,SLOT(accept()));
    connect(ui->pushButton_7,SIGNAL(clicked()),this,SLOT(accept()));
    connect(ui->pushButton_8,SIGNAL(clicked()),this,SLOT(accept()));
    connect(ui->pushButton_9,SIGNAL(clicked()),this,SLOT(accept()));
    connect(ui->pushButton_10,SIGNAL(clicked()),this,SLOT(accept()));
    connect(ui->pushButton_11,SIGNAL(clicked()),this,SLOT(accept()));
    connect(ui->pushButton_12,SIGNAL(clicked()),this,SLOT(accept()));
    connect(ui->pushButton_13,SIGNAL(clicked()),this,SLOT(accept()));
    connect(ui->pushButton_14,SIGNAL(clicked()),this,SLOT(accept()));
    connect(ui->pushButton_15,SIGNAL(clicked()),this,SLOT(accept()));
    connect(ui->pushButton_16,SIGNAL(clicked()),this,SLOT(accept()));
    connect(ui->pushButton_17,SIGNAL(clicked()),this,SLOT(accept()));
    connect(ui->pushButton_18,SIGNAL(clicked()),this,SLOT(accept()));
    connect(ui->pushButton_19,SIGNAL(clicked()),this,SLOT(accept()));
    connect(ui->pushButton_20,SIGNAL(clicked()),this,SLOT(accept()));
    connect(ui->pushButton_21,SIGNAL(clicked()),this,SLOT(accept()));
    connect(ui->pushButton_22,SIGNAL(clicked()),this,SLOT(accept()));
    connect(ui->pushButton_23,SIGNAL(clicked()),this,SLOT(accept()));
    connect(ui->pushButton_24,SIGNAL(clicked()),this,SLOT(accept()));
    connect(ui->pushButton_25,SIGNAL(clicked()),this,SLOT(accept()));
    connect(ui->pushButton_26,SIGNAL(clicked()),this,SLOT(accept()));
    connect(ui->pushButton_27,SIGNAL(clicked()),this,SLOT(accept()));
    connect(ui->pushButton_28,SIGNAL(clicked()),this,SLOT(accept()));
    connect(ui->pushButton_29,SIGNAL(clicked()),this,SLOT(accept()));
    connect(ui->pushButton_30,SIGNAL(clicked()),this,SLOT(accept()));
    connect(ui->pushButton_31,SIGNAL(clicked()),this,SLOT(accept()));
    connect(ui->pushButton_32,SIGNAL(clicked()),this,SLOT(accept()));
    connect(ui->pushButton_33,SIGNAL(clicked()),this,SLOT(accept()));
    connect(ui->pushButton_34,SIGNAL(clicked()),this,SLOT(accept()));
    this->setWindowTitle("Destination");
    this->setFixedSize(445, 530);
}

Destination::~Destination()
{
    delete ui;
}

Ui::Destination*Destination::getUi()
{
    return ui;
}

//vohimasina
void Destination::on_pushButton_2_clicked()
{
    ui->lineEdit->setText("VOHOMASINA");
    ui->spinBox->setValue(1700);
}

void Destination::on_pushButton_clicked()
{
    ui->lineEdit->setText("VOHOMASINA");
    ui->spinBox->setValue(2500);
}
//vohimasina

//sahambavy
void Destination::on_pushButton_3_clicked()
{
    ui->lineEdit->setText("SAHAMBAVY");
    ui->spinBox->setValue(3300);
}

void Destination::on_pushButton_4_clicked()
{
    ui->lineEdit->setText("SAHAMBAVY");
    ui->spinBox->setValue(2200);
}
//sahambavy

//ampitabe
void Destination::on_pushButton_5_clicked()
{
    ui->lineEdit->setText("AMPITABE");
    ui->spinBox->setValue(4700);
}

void Destination::on_pushButton_6_clicked()
{
    ui->lineEdit->setText("AMPITABE");
    ui->spinBox->setValue(3200);
}
//ampitabe

//ranomena
void Destination::on_pushButton_7_clicked()
{
    ui->lineEdit->setText("RANOMENA");
    ui->spinBox->setValue(5800);
}

void Destination::on_pushButton_8_clicked()
{
    ui->lineEdit->setText("RANOMENA");
    ui->spinBox->setValue(3900);
}
//ranomena

//andrambovato
void Destination::on_pushButton_9_clicked()
{
    ui->lineEdit->setText("AMDRAMBOVATO");
    ui->spinBox->setValue(6800);
}

void Destination::on_pushButton_10_clicked()
{
    ui->lineEdit->setText("ANDRAMBOVATO");
    ui->spinBox->setValue(4600);
}
//andrambovato

//madiorano
void Destination::on_pushButton_11_clicked()
{
    ui->lineEdit->setText("MADIORANO");
    ui->spinBox->setValue(7800);
}


void Destination::on_pushButton_12_clicked()
{
    ui->lineEdit->setText("MADIORANO");
    ui->spinBox->setValue(5200);
}
//madiorano

//tolongoina
void Destination::on_pushButton_13_clicked()
{
    ui->lineEdit->setText("TOLONGOINA");
    ui->spinBox->setValue(9100);
}

void Destination::on_pushButton_14_clicked()
{
    ui->lineEdit->setText("TOLONGOINA");
    ui->spinBox->setValue(6100);
}
//tolongoina

//amboanjobe
void Destination::on_pushButton_15_clicked()
{
    ui->lineEdit->setText("AMBOANJOBE");
    ui->spinBox->setValue(10900);
}


void Destination::on_pushButton_16_clicked()
{
    ui->lineEdit->setText("AMBOANJOBE");
    ui->spinBox->setValue(7300);
}
//amboanjobe

//amanampatrana
void Destination::on_pushButton_17_clicked()
{
    ui->lineEdit->setText("AMANAMPATRANA");
    ui->spinBox->setValue(12400);
}


void Destination::on_pushButton_18_clicked()
{
    ui->lineEdit->setText("AMANAMPATRANA");
    ui->spinBox->setValue(8300);
}
//amanampatrana


//ionilahy
void Destination::on_pushButton_19_clicked()
{
    ui->lineEdit->setText("IONILAHY");
    ui->spinBox->setValue(14000);
}


void Destination::on_pushButton_20_clicked()
{

    ui->lineEdit->setText("IONILAHY");
    ui->spinBox->setValue(9400);
}
//IONILAHY

//MAHABAKO
void Destination::on_pushButton_21_clicked()
{

    ui->lineEdit->setText("MAHABAKO");
    ui->spinBox->setValue(15500);

}

void Destination::on_pushButton_22_clicked()
{

    ui->lineEdit->setText("MAHABAKO");
    ui->spinBox->setValue(10300);
}
//MAHABAKO

//FENOMBY
void Destination::on_pushButton_23_clicked()
{

    ui->lineEdit->setText("FENOMBY");
    ui->spinBox->setValue(17100);
}


void Destination::on_pushButton_24_clicked()
{
    ui->lineEdit->setText("FENOMBY");
    ui->spinBox->setValue(11400);
}
//FENOMBY

//SAHASINAKA
void Destination::on_pushButton_25_clicked()
{
    ui->lineEdit->setText("SAHASINAKA");
    ui->spinBox->setValue(18500);
}

void Destination::on_pushButton_26_clicked()
{
    ui->lineEdit->setText("SAHASINAKA");
    ui->spinBox->setValue(12400);
}
//SAHASINAKA

//ANTSAKA
void Destination::on_pushButton_33_clicked()
{
    ui->lineEdit->setText("ANTSAKA");
    ui->spinBox->setValue(20200);
}

void Destination::on_pushButton_34_clicked()
{
    ui->lineEdit->setText("ANTSAKA");
    ui->spinBox->setValue(13500);
}
//ANTSAKA

//MIZILO
void Destination::on_pushButton_27_clicked()
{
    ui->lineEdit->setText("MIZILO");
    ui->spinBox->setValue(21600);
}

void Destination::on_pushButton_28_clicked()
{
    ui->lineEdit->setText("MIZILO");
    ui->spinBox->setValue(14400);
}
//MIZILO

//AMBLILA
void Destination::on_pushButton_29_clicked()
{
    ui->lineEdit->setText("AMBILA");
    ui->spinBox->setValue(23500);
}

void Destination::on_pushButton_30_clicked()
{
    ui->lineEdit->setText("AMBILA");
    ui->spinBox->setValue(15700);
}
//AMBILA

//MANAKARA
void Destination::on_pushButton_31_clicked()
{
    ui->lineEdit->setText("MANAKARA");
    ui->spinBox->setValue(25000);
}

void Destination::on_pushButton_32_clicked()
{
    ui->lineEdit->setText("MANAKARA");
    ui->spinBox->setValue(16000);
}
//MANAKARA
