#include "openfile.h"
#include "ui_openfile.h"


OpenFile::OpenFile(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OpenFile)
{
    ui->setupUi(this);
    namespace fs = std::filesystem;

    fs::path currentPath = fs::current_path();
    while (true)
    {
        std::string stem{currentPath.stem()};
        if (stem == std::string{"myProject"} && currentPath.extension() == ""){
            qDebug() << "path: " << std::string{currentPath};
            break;
        }
        else
        {
            currentPath = currentPath.parent_path();
        }
    }

    currentPath += "/data";

    for (const auto& entry : fs::directory_iterator(currentPath))
    {
        if (entry.path().extension() == ".csv")
        {
            qDebug()<<"str: " << std::string{entry.path()};
            QString tmp = QString::fromStdString(std::string{entry.path()});
            ui->comboBox->addItem(tmp);
        }
    }
}



OpenFile::~OpenFile()
{
    delete ui;
}

void OpenFile::on_pushButton_clicked()
{
//    MainWindow* ptr = new MainWindow(ui->comboBox->currentText());
//    ptr->get_tableModel()->set_filename(ui->comboBox->currentText());
//    ptr->show();
//    qDebug() << "combobox" << ui->comboBox->currentText();
//    hide();
}

