#ifndef DIALOG1_H
#define DIALOG1_H

#include <QDialog>

namespace Ui {
class Dialog1;
}

class Dialog1 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog1(QWidget *parent = 0);
    Ui::Dialog1* getUi();
    ~Dialog1();

private slots:
    void on_Browse_clicked();
    void on_projectName_textChanged(const QString &arg1);
    void checkText();

private:
    Ui::Dialog1 *ui;
};

#endif // DIALOG1_H
