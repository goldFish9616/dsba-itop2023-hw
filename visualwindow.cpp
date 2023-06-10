#include "visualwindow.h"
#include "ui_visualwindow.h"

VisualWindow::VisualWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::VisualWindow)
{
    ui->setupUi(this);

    graphicsView = new QGraphicsView();
    graphicsView->setRenderHint(QPainter::Antialiasing);
    graphicsView->setScene(new QGraphicsScene());

    QComboBox* combo_box = new QComboBox;

    combo_box->addItem("By income category");
    combo_box->addItem("By age");
    combo_box->addItem("By educational level");

    QObject::connect(combo_box, QOverload<int>::of(&QComboBox::currentIndexChanged), [=](int index){
        mode = index;
        update();
    });

    QHBoxLayout* layout = new QHBoxLayout();
    layout->addWidget(combo_box, 1);
    layout->addWidget(graphicsView, 3);

    QWidget* widget = new QWidget();
    widget->setLayout(layout);


    this->setCentralWidget(widget);
    this->resize(1100, 600);

}

int VisualWindow::getMode()
{
    return mode;
}


void VisualWindow::set_data(QList<QList<QString>>  _data)
{
    raw_data = _data;
}

void VisualWindow::update()
{

    parseInfo();
    show_data();
}

void VisualWindow::show_data()
{
    chart = new QChart();

    series = new QBarSeries();

    set_bars = new QBarSet("");

    for (auto& e : showData)
    {
        *set_bars << e;
    }

    series->append(set_bars);

    chart->addSeries(series);

    QBarCategoryAxis* axisX = new QBarCategoryAxis();

    if (mode == 0)
    {
        set_bars->setLabel("Client's Income Categories diagram");
        axisX->append("Less $40K");
        axisX->append("$40K - $60K");
        axisX->append("$60K - $80K");
        axisX->append("$80K - $120K");
        axisX->append("$120K+");
        chart->setMinimumWidth(750);

    }
    else if (mode == 1)
    {
        set_bars->setLabel("Client's Age diagram");
        axisX->append("26 - 40");
        axisX->append("40 - 50");
        axisX->append("50 - 60");
        axisX->append("60 - 73");
    }
    else if (mode == 2)
    {
        set_bars->setLabel("Client's Educational Level diagram");
        axisX->append("Graduate");
        axisX->append("Uneducated");
        axisX->append("Post-Graduate");
        axisX->append("High School");
        axisX->append("Doctorate");
        axisX->append("College");
    }

    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis* axisY = new QValueAxis();
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    QChartView* chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setFixedSize(750, 400);

    graphicsView->scene()->addWidget(chartView);
}


void VisualWindow::parseInfo()
{
    QVector<int> counter_clients;
    if (mode == 0)
    {
        counter_clients.resize(5);
        for (auto& row : raw_data)
        {
            QList<QString>::iterator it_colm = row.begin() + 5;

            if (*it_colm == QString("Less than $40K"))
            {
                counter_clients[0] += 1;
            }
            else if (*it_colm == QString("$40K - $60K"))
            {
                counter_clients[1] += 1;
            }
            else if (*it_colm == QString("$60K - $80K"))
            {
                counter_clients[2] += 1;
            }
            else if (*it_colm == QString("$80K - $120K"))
            {
                counter_clients[3] += 1;
            }
            else if (*it_colm == QString("$120K +"))
            {
                counter_clients[4] += 1;
            }
        }

        showData = counter_clients;
    }
    else if (mode == 1)
    {

        counter_clients.resize(4);
        for (auto& row : raw_data)
        {
            auto it_colm = row.begin() + 1;
            int age = (*it_colm).toInt();
            if (26 <= age && age < 40){

                counter_clients[0] += 1;
            }
            else if (40 <= age && age < 50)
            {

                counter_clients[1] += 1;
            }
            else if (50 <= age && age < 60)
            {

                counter_clients[2] += 1;
            }
            else if (60 <= age && age < 73)
            {

                counter_clients[3] += 1;
            }
        }

        showData = counter_clients;
    }
    else if (mode == 2)
    {

        counter_clients.resize(6);
        for (auto& row : raw_data)
        {
            auto it_colm = row.begin() + 3;

            if (*it_colm == QString("Graduate"))
            {

                    counter_clients[0] += 1;
            }
            else if (*it_colm == QString("Uneducated"))
            {

                    counter_clients[1] += 1;
            }
            else if (*it_colm == QString("Post-Graduate"))
            {

                counter_clients[2] += 1;
            }
            else if (*it_colm == QString("High School"))
            {

                    counter_clients[3] += 1;
            }
            else if (*it_colm == QString("Doctorate"))
            {

                counter_clients[4] += 1;
            }
            else if (*it_colm == QString("College"))
            {

                counter_clients[5] += 1;
            }
        }
        showData = counter_clients;
    }
}


VisualWindow::~VisualWindow()
{
    delete ui;
}
