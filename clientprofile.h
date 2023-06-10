#ifndef CLIENTPROFILE_H
#define CLIENTPROFILE_H

#include <QDialog>
#include <QDataWidgetMapper>


#include "tablemodel.h"

namespace Ui {
class ClientProfile;
}

class ClientProfile : public QDialog
{
    Q_OBJECT

public:
    ClientProfile(TableModel* model, QWidget *parent = nullptr);
    explicit ClientProfile(TableModel* model, const QModelIndex &index, QWidget *parent = nullptr);
    ~ClientProfile();

    void showData(TableModel* model, const QModelIndex &index);
    void showData(QList<QString> it);
    void saveData(TableModel *model, const QModelIndex &index);

private slots:
    void on_okButton_clicked();

    void on_cancelButton_clicked();

    void on_removeButton_clicked();

private:
    Ui::ClientProfile *ui;

private:
    QModelIndex index_ptr;
    TableModel* table_model_ptr = nullptr;
};

#endif // CLIENTPROFILE_H
