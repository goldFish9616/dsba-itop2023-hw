#include "groupmodel.h"

GroupModel::GroupModel(TableModel* model, QString& category, QObject *parent)
    : QAbstractTableModel(parent)
{
    for (QList<QString>& row : model->getDataTable())
    {
        for (QString& el : row)
        {
            if (el == category)
            {
                local_table.append(row);
            }
        }
    }
}

GroupModel::~GroupModel()
{

}
