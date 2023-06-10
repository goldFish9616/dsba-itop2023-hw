#ifndef GROUPMODEL_H
#define GROUPMODEL_H

#include <QAbstractTableModel>

#include "tablemodel.h"

class GroupModel : public QAbstractTableModel
{
    Q_OBJECT


public:
    explicit GroupModel(TableModel* model, QString& category, QObject *parent);
    ~GroupModel();
private:
    QList<QList<QString>> local_table;

};

#endif // GROUPMODEL_H
