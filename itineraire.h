#ifndef ITINERAIRE_H
#define ITINERAIRE_H

#include <QDialog>

namespace Ui {
class Itineraire;
}

class Itineraire : public QDialog
{
    Q_OBJECT

public:
    explicit Itineraire(QWidget *parent = 0);
    Ui::Itineraire*getUi();
    ~Itineraire();

private slots:
    void on_fianaraA_clicked();

    void on_ManakA_clicked();

    void on_fianaraB_clicked();

    void on_manakB_clicked();

    void on_mille_clicked();

    void on_deuxmille_clicked();

    void on_pushButton_clicked();

    void on_fianaraA_2_clicked();

    void on_ManakA_2_clicked();

    void on_pushButton_2_clicked();

    void on_comboBox_2_currentTextChanged(const QString &arg1);

    void on_comboBox_3_currentTextChanged(const QString &arg1);

private:
    Ui::Itineraire *ui;
};

#endif // ITINERAIRE_H
