#include "searchwindow.h"
#include "ui_searchwindow.h"


SearchWindow::SearchWindow(TableModel* model, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SearchWindow)
{
    ui->setupUi(this);
    model_ptr = model;
}

SearchWindow::~SearchWindow()
{
    delete ui;
}

void SearchWindow::on_pushButton_clicked()
{
    QList<QList<QString>>::iterator it_result = std::find_if((model_ptr->getDataTable()).begin(), (model_ptr->getDataTable()).end(), [=](QList<QString> row){
        if (*row.begin() == ui->lineEdit->text())
        {
            return true;
        }

        return false;
    });

    client_pointer = new ClientProfile(model_ptr);
    client_pointer->showData(*it_result);
    client_pointer->show();

    hide();
}

