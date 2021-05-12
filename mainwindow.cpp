#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QChart>
#include <QtCharts>
#include <QChartView>
#include <QBarSet>
#include <QBarSeries>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QBarSet *set0 = new QBarSet("Jane");
     QBarSet *set1 = new QBarSet("John");
     QBarSet *set2 = new QBarSet("Axel");
     QBarSet *set3 = new QBarSet("Mary");
     QBarSet *set4 = new QBarSet("Samantha");
     *set0 << 10 << 20 << 30 << 40 << 50 << 60;
     *set1 << 50 << 70 << 40 << 45 << 80 << 70;
     *set2 << 30 << 50 << 80 << 13 << 80 << 50;
     *set3 << 50 << 60 << 70 << 30 << 40 << 25;
     *set4 << 90 << 70 << 50 << 30 << 16 << 42;
     QBarSeries *series = new QBarSeries();
     series->append(set0);
     series->append(set1);
     series->append(set2);
      series->append(set3);
      series->append(set4);

      QChart *chart = new QChart();
      chart->addSeries(series);
      chart->setTitle("Student Performance");
      chart->setAnimationOptions(QChart::SeriesAnimations);
      QStringList categories;
      categories << "Jan" << "Feb" << "Mar" << "Apr" << "May" << "Jun";
      QBarCategoryAxis *axis = new QBarCategoryAxis();
      axis->append(categories);
      chart->createDefaultAxes();
      chart->setAxisX(axis, series);

      QChartView *chartView = new QChartView(chart);
      chartView->setParent(ui->verticalFrame);
}

MainWindow::~MainWindow()
{
    delete ui;
}
