#include <QFile>

#include "myproxymodel.h"

MyProxyModel::MyProxyModel(QObject* parent)
    : QSortFilterProxyModel(parent)
{
}


bool compareByClientNum(QList<QString>& cl1, QList<QString>& cl2)
{

    int num1 = cl1.at(0).toInt();
    int num2 = cl2.at(0).toInt();
    return num1 > num2;

}

bool compareByClientAge(QList<QString>& cl1, QList<QString>& cl2)
{
    int num1 = cl1.at(1).toInt();
    int num2 = cl2.at(1).toInt();
    return num1 > num2;
}

bool compareByCreditLimit(QList<QString>& cl1, QList<QString>& cl2)
{
    int num1 = cl1.at(7).toInt();
    int num2 = cl2.at(7).toInt();
    return num1 > num2;
}

bool compareByRevolvBalance(QList<QString>& cl1, QList<QString>& cl2)
{
    int num1 = cl1.at(8).toInt();
    int num2 = cl2.at(8).toInt();
    return num1 > num2;
}

bool compareByUtilRatio(QList<QString>& cl1, QList<QString>& cl2)
{
    double num1 = cl1.at(9).toDouble();
    double num2 = cl2.at(9).toDouble();
    return num1 > num2;
}

bool reverseCompareByClientNum(const QList<QString>& cl1, const QList<QString>& cl2)
{

    int num1 = cl1.at(0).toInt();
    int num2 = cl2.at(0).toInt();
    return num1 < num2;

}

bool reverseCompareByClientAge(const QList<QString>& cl1, const QList<QString>& cl2)
{
    int num1 = cl1.at(1).toInt();
    int num2 = cl2.at(1).toInt();
    return num1 < num2;
}

bool reverseCompareByCreditLimit(const QList<QString>& cl1, const QList<QString>& cl2)
{
    int num1 = cl1.at(7).toInt();
    int num2 = cl2.at(7).toInt();
    return num1 < num2;
}

bool reverseCompareByRevolvBalance(const QList<QString>& cl1, const QList<QString>& cl2)
{
    int num1 = cl1.at(8).toInt();
    int num2 = cl2.at(8).toInt();
    return num1 < num2;
}

bool reverseCompareByUtilRatio(const QList<QString>& cl1, const QList<QString>& cl2)
{
    double num1 = cl1.at(9).toDouble();
    double num2 = cl2.at(9).toDouble();
    return num1 < num2;
}


void MyProxyModel::sortByNum(QList<QList<QString>>& data, int _sortMode)
{
    if (_sortMode)
        std::sort(data.begin(), data.end(), compareByClientNum);
    else
        std::sort(data.begin(), data.end(), reverseCompareByClientNum);
}


void MyProxyModel::sortByAge(QList<QList<QString>>& data, int _sortMode)
{
    if (_sortMode)
        std::sort(data.begin(), data.end(), compareByClientAge);
    else
        std::sort(data.begin(), data.end(), reverseCompareByClientAge);
}

void MyProxyModel::sortByCreditLimit(QList<QList<QString>>& data, int _sortMode)
{
    if (_sortMode)
        std::sort(data.begin(), data.end(), compareByCreditLimit);
    else
        std::sort(data.begin(), data.end(), reverseCompareByCreditLimit);
}

void MyProxyModel::sortByRevolvBalance(QList<QList<QString>>& data, int _sortMode)
{
    if (_sortMode)
        std::sort(data.begin(), data.end(), compareByRevolvBalance);
    else
        std::sort(data.begin(), data.end(), reverseCompareByRevolvBalance);
}

void MyProxyModel::sortByUtilRatio(QList<QList<QString>>& data, int _sortMode)
{
    if (_sortMode)
        std::sort(data.begin(), data.end(), compareByUtilRatio);
    else
        std::sort(data.begin(), data.end(), reverseCompareByUtilRatio);
}

