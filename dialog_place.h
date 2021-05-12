#ifndef DIALOG_PLACE_H
#define DIALOG_PLACE_H

#include <QDialog>

namespace Ui {
class Dialog_Place;
}

class Dialog_Place : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_Place(QWidget *parent = 0);
    Ui::Dialog_Place*getUi();
    ~Dialog_Place();

private slots:
    void Check();

private:
    Ui::Dialog_Place *ui;
};

#endif // DIALOG_PLACE_H
