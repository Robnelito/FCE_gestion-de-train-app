#include "gestion_de_train.h"
#include <QApplication>
#include <QSplashScreen>
#include <QTimer>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSplashScreen *train = new QSplashScreen;
    train->setPixmap(QPixmap(":/image/image/logo.png"));
    train->show();
    train->startTimer(2000);
    Gestion_de_Train w;
    QTimer::singleShot(2000,&w,SLOT(show()));
    QTimer::singleShot(2000,train,SLOT(close()));
    //w.show();

    return a.exec();
}
