#ifndef TABLEMODEL_H
#define TABLEMODEL_H

#include <QAbstractTableModel>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QTableView>

#include "client.h"

class TableModel: public QAbstractTableModel
{
    Q_OBJECT



public:
    explicit TableModel(QObject *parent = nullptr);
    ~TableModel();

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    QList<QString> operator[](int i);

    void appendRow(const QList<QString>& newRow);
    bool removeRow(int rowIndex);
    QList<QList<QString>>& getDataTable();

    void set_filename(QString name);

private:
    QString filename;
    QList<QList<QString>> dataTable;
    QString header;
};

#endif // TABLEMODEL_H
