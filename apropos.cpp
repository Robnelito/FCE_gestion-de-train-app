#include "apropos.h"
#include "ui_apropos.h"

Apropos::Apropos(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Apropos)
{
    ui->setupUi(this);
    this->setFixedSize(830,540);
    this->setWindowTitle("A propos");
    //this->setWindowFlags(Qt::WindowTitleHint);
    //this->setWindowFlags(Qt::CustomizeWindowHint);
    //this->setWindowFlags(Qt::WindowCloseButtonHint);
}

Apropos::~Apropos()
{
    delete ui;
}
