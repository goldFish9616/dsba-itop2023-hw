#ifndef GROUPCLIENTS_H
#define GROUPCLIENTS_H

#include <QMainWindow>

#include "tablemodel.h"
#include "groupmodel.h"

namespace Ui {
class GroupClients;
}

class GroupClients : public QMainWindow
{
    Q_OBJECT

public:
    explicit GroupClients(TableModel* model, QWidget *parent = nullptr);
    ~GroupClients();

private slots:
    void on_comboBox_currentIndexChanged(TableModel* model, int index);

private:
    Ui::GroupClients *ui;
    QList<QList<QString>> local_data;
};

#endif // GROUPCLIENTS_H
