#ifndef MYPROXYMODEL_H
#define MYPROXYMODEL_H

#include <QSortFilterProxyModel>
#include <QObject>


class MyProxyModel : public QSortFilterProxyModel
{
    Q_OBJECT
public:
    explicit MyProxyModel(QObject *parent = nullptr);

    void sortByNum(QList<QList<QString>>& data, int _sortMode);

    void sortByAge(QList<QList<QString>>& data, int _sortMode);
    void sortByCreditLimit(QList<QList<QString>>& data, int _sortMode);

    void sortByRevolvBalance(QList<QList<QString>>& data, int _sortMode);

    void sortByUtilRatio(QList<QList<QString>>& data, int _sortMode);

private:



};

#endif // MYPROXYMODEL_H
