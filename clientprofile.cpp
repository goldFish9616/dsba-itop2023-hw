#include "clientprofile.h"
#include "ui_clientprofile.h"

#include <QDataWidgetMapper>
#include <QItemSelectionModel>

ClientProfile::ClientProfile(TableModel* model, const QModelIndex &index, QWidget *parent)//, TableModel* model) :
    : QDialog(parent)
    , ui(new Ui::ClientProfile)
{
    ui->setupUi(this);
    showData(model, index);
    index_ptr = index;
    table_model_ptr = model;
}

ClientProfile::ClientProfile(TableModel* model, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ClientProfile)
{
    ui->setupUi(this);
    table_model_ptr = model;
}

ClientProfile::~ClientProfile()
{
    delete ui;
}


void ClientProfile::showData(TableModel *model, const QModelIndex &index)//, const QModelIndex &index)
{
    QList<QString> sourceDataRow = (*model)[index.row()];
    ui->numEdit->setText(sourceDataRow[0]);
    ui->ageSpin->setValue(sourceDataRow[1].toInt());
    ui->genderBox->setCurrentText(sourceDataRow[2]);
    ui->marBox->setCurrentText(sourceDataRow[4]);
    ui->educationBox->setCurrentText(sourceDataRow[3]);
    ui->incomeBox->setCurrentText(sourceDataRow[5]);
    ui->cardBox->setCurrentText(sourceDataRow[6]);
    ui->balanceEdit->setText(sourceDataRow[7]);
    ui->limitEdit->setText(sourceDataRow[8]);
    ui->utilEdit->setText(sourceDataRow[9]);

}

void ClientProfile::showData(QList<QString> it)
{
    ui->numEdit->setText(it[0]);
    ui->ageSpin->setValue(it[1].toInt());
    ui->genderBox->setCurrentText(it[2]);
    ui->marBox->setCurrentText(it[4]);
    ui->educationBox->setCurrentText(it[3]);
    ui->incomeBox->setCurrentText(it[5]);
    ui->cardBox->setCurrentText(it[6]);
    ui->balanceEdit->setText(it[7]);
    ui->limitEdit->setText(it[8]);
    ui->utilEdit->setText(it[9]);
}


void ClientProfile::saveData(TableModel* model, const QModelIndex &index)
{
    for (size_t i = 1; i < (*model)[index.row()].size(); ++i)
    {
        if (i == 1)
            ((model->getDataTable())[index.row()])[i] = QString::number(ui->ageSpin->value());
        if (i == 2)
            ((model->getDataTable())[index.row()])[i] = ui->genderBox->currentText();
        if (i == 3)
            ((model->getDataTable())[index.row()])[i] = ui->educationBox->currentText();
        if (i == 4)
            ((model->getDataTable())[index.row()])[i] = ui->marBox->currentText();
        if (i == 5)
            ((model->getDataTable())[index.row()])[i] = ui->incomeBox->currentText();
        if (i == 6)
            ((model->getDataTable())[index.row()])[i] = ui->cardBox->currentText();
        if (i == 7)
            ((model->getDataTable())[index.row()])[i] = ui->balanceEdit->text();
        if (i == 8)
            ((model->getDataTable())[index.row()])[i] = ui->limitEdit->text();
        if (i == 9)
            ((model->getDataTable())[index.row()])[i] = ui->utilEdit->text();
        }
}

void ClientProfile::on_okButton_clicked()
{
    accept();
}



void ClientProfile::on_cancelButton_clicked()
{
    reject();
}


void ClientProfile::on_removeButton_clicked()
{
    table_model_ptr->removeRow(index_ptr.row());
    hide();
}

