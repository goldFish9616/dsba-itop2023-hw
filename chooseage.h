#ifndef CHOOSEAGE_H
#define CHOOSEAGE_H

#include <QDialog>

namespace Ui {
class ChooseAge;
}

class ChooseAge : public QDialog
{
    Q_OBJECT

public:
    explicit ChooseAge(QWidget *parent = nullptr);
    ~ChooseAge();

private:
    Ui::ChooseAge *ui;
};

#endif // CHOOSEAGE_H
