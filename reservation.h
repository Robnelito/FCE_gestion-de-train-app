#ifndef RESERVATION_H
#define RESERVATION_H

#include <QDialog>

namespace Ui {
class reservation;
}

class reservation : public QDialog
{
    Q_OBJECT

public:
    explicit reservation(QWidget *parent = 0);
    Ui::reservation *getUi();
    ~reservation();
private slots:
    void checkNom();

    void on_pushButton_clicked();

private:
    Ui::reservation *ui;
};

#endif // RESERVATION_H
