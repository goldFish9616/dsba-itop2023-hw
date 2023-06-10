#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QObject>
#include <QRandomGenerator>
#include <QDataWidgetMapper>


MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWindow)
    , model(new TableModel)
{
    ui->setupUi(this);
    ui->myTable->setSortingEnabled(true);
    ui->myTable->setModel(model);

    _addClientDlg = new AddClient(this);
}


void MainWindow::on_addButton_clicked()
{
    if(_addClientDlg->exec() == QDialog::Accepted)
    {
        if (_addClientDlg->getNewRow() == true)
        {

            int age = _addClientDlg->getClientAge();
            QString gender =  _addClientDlg->getClientGender();
            QString marStatus = _addClientDlg->getClientMarStatus();
            QString edu = _addClientDlg->getClientEdu();
            QString income = _addClientDlg->getClientIncome();
            QString card = _addClientDlg->getClientCardCateg();
            int balance = _addClientDlg->getClientBalance();
            int limit = _addClientDlg->getClientLimit();
            double utilRatio = _addClientDlg->getClientRatio();

            QList<QString> newDataRow;

            newDataRow.append(QString::number(model->rowCount() + 1));
            newDataRow.append(QString::number(age));
            newDataRow.append(gender);
            newDataRow.append(marStatus);
            newDataRow.append(edu);
            newDataRow.append(income);
            newDataRow.append(card);
            newDataRow.append(QString::number(balance));
            newDataRow.append(QString::number(limit));
            newDataRow.append(QString::number(utilRatio));
            model->appendRow(newDataRow);
            run_sort();
        }
    }

}

void MainWindow::run_sort()
{
    if (index_sort == 0)
    {
        ui->myTable->reset();
        _proxy->sortByNum(model->getDataTable(), sortMode);
        ui->myTable->setModel(model);
    }
    else if (index_sort == 1)
    {
        ui->myTable->reset();
        _proxy->sortByAge(model->getDataTable(), sortMode);
        ui->myTable->setModel(model);
    }
    else if (index_sort == 2)
    {
        ui->myTable->reset();
        _proxy->sortByCreditLimit(model->getDataTable(), sortMode);
        ui->myTable->setModel(model);
    }
    else if (index_sort == 3)
    {
        ui->myTable->reset();
        _proxy->sortByRevolvBalance(model->getDataTable(), sortMode);
        ui->myTable->setModel(model);
    }
    else if (index_sort == 4)
    {
        ui->myTable->reset();
        _proxy->sortByUtilRatio(model->getDataTable(), sortMode);
        ui->myTable->setModel(model);
    }

}

void MainWindow::on_sortBox_currentIndexChanged(int index)
{
    index_sort = index;
    run_sort();
}


MainWindow::~MainWindow()
{
    delete ui;
    delete model;
}


void MainWindow::on_visualButton_clicked()
{
    if (!visualWindow)
    {
        visualWindow = new VisualWindow;
    }

    visualWindow->show();
    visualWindow->set_data(model->getDataTable());
    visualWindow->update();
}


void MainWindow::on_myTable_doubleClicked(const QModelIndex &index)
{
    _clientProfile = new ClientProfile(model, index, this);
    _clientProfile->show();
    if(_clientProfile->exec() == QDialog::Accepted)
    {
        _clientProfile->saveData(model, index);
        run_sort();
        _clientProfile->close();
    }
}


void MainWindow::on_radioButton_clicked()
{
    sortMode = ui->radioButton->isChecked();
    run_sort();
}


void MainWindow::on_searchButton_clicked()
{
    _searchWind = new SearchWindow(model);
    _searchWind->show();

}




void MainWindow::on_pushButton_clicked()
{
    AboutDialog* ptr = new AboutDialog();
    ptr->show();
    if (ptr->exec() == QDialog::Accepted)
    {
        hide();
    }
}


