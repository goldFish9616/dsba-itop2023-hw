#ifndef ADDCLIENT_H
#define ADDCLIENT_H

#include <QDialog>

#include "errorwindow.h"

namespace Ui {
class AddClient;
}

class AddClient : public QDialog
{
    Q_OBJECT

public:
    explicit AddClient(QWidget *parent = nullptr);
    ~AddClient();

public:
    unsigned short getClientAge() const { return _clientAge; }
    QString getClientGender() const { return _clientGender; }
    QString getClientMarStatus() const { return _clientMarriage; }
    QString getClientEdu() const { return _clientEducation; }
    QString getClientIncome() const { return _clientIncome; }
    QString getClientCardCateg() const { return _clientCard; }
    unsigned int getClientBalance() const { return _clientBalance; }
    unsigned int getClientLimit() const { return _clientLimit; }
    double getClientRatio() const {return _clientRatio; }
    bool getNewRow();

private:
    void extractAndCheckData();

private slots:
    void on_pushButton_2_clicked();

private:
    unsigned short _clientAge;
    QString _clientGender;
    QString _clientMarriage;
    QString _clientEducation;
    QString _clientIncome;
    QString _clientCard;
    unsigned int _clientBalance;
    unsigned int _clientLimit;
    double _clientRatio;


    ErrorWindow* _errorDlg;

private:
    Ui::AddClient *ui;

};

#endif // ADDCLIENT_H
