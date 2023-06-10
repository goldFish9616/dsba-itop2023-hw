#include "groupclients.h"
#include "ui_groupclients.h"

GroupClients::GroupClients(TableModel* model, QWidget *parent) :
    QMainWindow(parent)
    , ui(new Ui::GroupClients)
{
    ui->setupUi(this);
}

GroupClients::~GroupClients()
{
    delete ui;
}

void GroupClients::on_comboBox_currentIndexChanged(TableModel* model, int index)
{
    qDebug() << "yes great";

    GroupModel* groupModel = new GroupModel(model, ui->categoryBox->currentText());
    ui->groupTable->setModel(groupModel);
}

