#ifndef VISUALWINDOW_H
#define VISUALWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QPushButton>
#include <QHBoxLayout>
#include <QChart>
#include <QBarSeries>
#include <QBarSet>
#include <QBarCategoryAxis>
#include <QValueAxis>
#include <QChartView>
#include <QVector>
#include <QComboBox>

namespace Ui {
class VisualWindow;
}

class VisualWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit VisualWindow(QWidget *parent = nullptr);
    ~VisualWindow();

    void update();

    void parseInfo();

    int getMode();

    void set_data(QList<QList<QString>> raw_data);
    void show_data();

private:
    Ui::VisualWindow *      ui;
    QGraphicsView*          graphicsView = nullptr;
    QList<QList<QString>>   data;
    int mode = 0;
    QVector<int> showData;

    QList<QList<QString>> raw_data;

    QChart* chart = nullptr;

    QBarSeries* series = nullptr;

    QBarSet* set_bars = nullptr;

};

#endif // VISUALWINDOW_H
