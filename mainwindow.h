#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QMainWindow>
#include <QChartView>
#include <QBarSet>
#include <QStandardItemModel>

#include "addclient.h"
#include "tablemodel.h"
#include "myproxymodel.h"
#include "visualwindow.h"
#include "clientprofile.h"
#include "searchwindow.h"
#include "aboutdialog.h"
#include "groupclients.h"

#include <QHeaderView>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void run_sort();

private slots:
    void on_addButton_clicked();

    void on_sortBox_currentIndexChanged(int index);

    void on_visualButton_clicked();

    void on_myTable_doubleClicked(const QModelIndex &index);

    void on_radioButton_clicked();


    void on_searchButton_clicked();

    void on_pushButton_clicked();


private:
    MyProxyModel* _proxy;
    Ui::MainWindow *ui;
    AddClient* _addClientDlg;
    TableModel *model;
    VisualWindow* visualWindow = nullptr;
    ClientProfile* _clientProfile = nullptr;

    int index_sort = 0;

    int sortMode = 1;

    SearchWindow* _searchWind = nullptr;

private:
    void openDataFile();
};
#endif // MAINWINDOW_H


