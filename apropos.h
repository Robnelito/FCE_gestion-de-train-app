#ifndef APROPOS_H
#define APROPOS_H

#include <QMainWindow>

namespace Ui {
class Apropos;
}

class Apropos : public QMainWindow
{
    Q_OBJECT

public:
    explicit Apropos(QWidget *parent = 0);
    ~Apropos();

private:
    Ui::Apropos *ui;
};

#endif // APROPOS_H
