#ifndef ABOUTDIALOG_H
#define ABOUTDIALOG_H

#include <QtWidgets>

#include "drawingwidget.h"

namespace Ui {
class AboutDialog;
}

class AboutDialog : public QDialog{
public:
    explicit AboutDialog(QWidget *parent = nullptr);
    ~AboutDialog();
private:
    Ui::AboutDialog *ui;
};


#endif // ABOUTDIALOG_H
