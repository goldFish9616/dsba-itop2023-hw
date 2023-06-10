#ifndef SEARCHWINDOW_H
#define SEARCHWINDOW_H

#include <QMainWindow>

#include "tablemodel.h"
#include "clientprofile.h"

namespace Ui {
class SearchWindow;
}

class SearchWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SearchWindow(TableModel* model, QWidget *parent = nullptr);
    ~SearchWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::SearchWindow *ui;
    TableModel* model_ptr = nullptr;
    ClientProfile* client_pointer = nullptr;
};

#endif // SEARCHWINDOW_H
