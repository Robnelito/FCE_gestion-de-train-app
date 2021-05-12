#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    Ui::Dialog*getUi();
    ~Dialog();

private slots:
    void on_un_clicked();
    void Check();
    void on_deux_clicked();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
