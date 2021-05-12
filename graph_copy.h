#ifndef GRAPH_H
#define GRAPH_H
#include <QtCharts>
#include <QChartView>
#include <QBarSet>
#include <QBarSeries>

#include <QDialog>

namespace Ui {
class graph;
}

class graph : public QDialog
{
    Q_OBJECT

public:
    explicit graph(QWidget *parent = 0);
    ~graph();

private:
    Ui::graph *ui;
};

#endif // GRAPH_H
