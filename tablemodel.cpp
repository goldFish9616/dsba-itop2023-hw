#include "tablemodel.h"
#include <QFile>

TableModel::~TableModel()
{
    QFile inputFile("/Users/czinuj/prg/myProject/data/data.csv");
    inputFile.open(QFile::WriteOnly | QFile::Text);
    QTextStream inputStream(&inputFile);

    inputStream << header << '\n';

    for (const QList<QString>& i: dataTable)
    {

        int count_colm = 0;
        for (const QString& j: i)
        {
            if (count_colm == i.size() - 1)
            {
                inputStream << j;
            }
            else
            {
                inputStream << j << ';';
            }
            count_colm++;
        }
        inputStream << '\n';
    }
    inputFile.close();

}

void TableModel::set_filename(QString name){

    filename = name;

}

TableModel::TableModel(QObject *parent)
    : QAbstractTableModel(parent)
{
    QFile inputFile("/Users/czinuj/prg/myProject/data/data.csv");
    inputFile.open(QFile::ReadOnly | QFile::Text);
    QTextStream inputStream(&inputFile);

    header = inputStream.readLine();

    while(!inputStream.atEnd())
    {
        QString line = inputStream.readLine();
        if (line == '\n')
            continue;

        QList<QString> dataRow;
        for (QString& item : line.split(";"))
        {

            dataRow.append(item);
        }
        dataTable.append(dataRow);
    }
    inputFile.close();

}

int TableModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;
    return dataTable.count();
//    return 3;
}

int TableModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;
    return dataTable[0].count();
//    return 4;
}

QVariant TableModel::data(const QModelIndex &index, int role) const
{

    if (role == Qt::DisplayRole || role == Qt::EditRole)
    {
        if (!index.isValid())
        {
            return QVariant();
        }
        return dataTable[index.row()][index.column()];
    }
    return QVariant();
}

QVariant TableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if ((role == Qt::DisplayRole) && orientation == (Qt::Horizontal))
    {
        return header.split(';')[section];
    }
    return QVariant();
}

QList<QList<QString>>& TableModel::getDataTable()
{
    return dataTable;
}


void TableModel::appendRow(const QList<QString>& newRow)
{
    beginInsertRows(QModelIndex(), dataTable.size(), dataTable.size());
    dataTable.append(newRow);
    endInsertRows();
}


bool TableModel::removeRow(int rowIndex)
{
    if (rowIndex >= dataTable.size())
    {
        return false;
    }
    beginRemoveRows(QModelIndex(), rowIndex, rowIndex);
    dataTable.removeAt(rowIndex);
    endRemoveRows();
    return true;
}

QList<QString> TableModel::operator[](int i)
{
    return dataTable[i];
}
