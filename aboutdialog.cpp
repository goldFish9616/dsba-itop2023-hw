#include "aboutdialog.h"
#include "ui_aboutdialog.h"

AboutDialog::AboutDialog(QWidget *parent):
      QDialog(parent),
      ui(new Ui::AboutDialog)
{
    QHBoxLayout* layout = new QHBoxLayout(this);
    QTextEdit* text_edit = new QTextEdit(this);

    QFont font;
    font.setPointSize(20);
    text_edit->setFont(font);
    text_edit->setReadOnly(true);


    QString description = "This project focuses on the analysis of credit card customers'\n"
                   "behavior based on a dataset from Kaggle.\n"
                   "The dataset contains various attributes of the customers\n"
                   "which can be used to analyze their actions.\n"
                   "\n"
                   "\n"
                   "Id: 1632";

    text_edit->setPlainText(description);

    QPalette pal = palette();
    QColor windowColor = pal.color(QPalette::Midlight);

    text_edit->setStyleSheet("background-color: " + windowColor.name() + ";");

    DrawingWidget* drawingWidget = new DrawingWidget(this);
    layout->addWidget(text_edit, 1);
    layout->addWidget(drawingWidget, 1);

    setLayout(layout);
}


AboutDialog::~AboutDialog()
{
    delete ui;
}
