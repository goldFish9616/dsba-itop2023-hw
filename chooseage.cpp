#include "chooseage.h"
#include "ui_chooseage.h"

ChooseAge::ChooseAge(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChooseAge)
{
    ui->setupUi(this);
}

ChooseAge::~ChooseAge()
{
    delete ui;
}
