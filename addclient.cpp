#include "addclient.h"
#include "ui_addclient.h"

AddClient::AddClient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddClient)
{
    ui->setupUi(this);
    _errorDlg = new ErrorWindow(this);
}


bool haveLetters(const QString& str)
{
    for (size_t i = 0; i < str.size(); ++i)
    {
        if (str[i].isLower())
            return true;
    }
    return false;
}

void AddClient::extractAndCheckData()
{
    // TODO: extract and validate data for correctness
    if (ui->ageBox->value() == 0)
        throw std::runtime_error("Error");
    if (ui->genderBox->currentText() == "Not chose")
        throw std::runtime_error("Error");
    if (ui->balanceLine->text() == "" || haveLetters(ui->balanceLine->text()) == true)
        throw std::runtime_error("Error");
    if (ui->limitLine->text() == "" || haveLetters(ui->limitLine->text()) == true)
        throw std::runtime_error("Error");
    if (ui->UtilLine->text() == "" || haveLetters(ui->UtilLine->text()) == true)
        throw std::runtime_error("Error");
    _clientAge = ui->ageBox->value();
    _clientGender = ui->genderBox->currentText();
    _clientMarriage = ui->marriageBox->currentText();
    _clientEducation = ui->edBox->currentText();
    _clientIncome = ui->incomeBox->currentText();
    _clientCard = ui->cardBox->currentText();
    _clientBalance = ui->balanceLine->text().toInt();
    _clientLimit = ui->limitLine->text().toInt();
    _clientRatio = ui->UtilLine->text().toDouble();
}

bool AddClient::getNewRow()
{
    try
    {
        extractAndCheckData();
    }
    catch (const std::runtime_error& e)
    {
        _errorDlg->exec();
        return false;
    }
    return true;
}


void AddClient::on_pushButton_2_clicked()
{
    accept();
}


AddClient::~AddClient()
{
    delete ui;
}

