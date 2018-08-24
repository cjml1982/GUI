#include "dialog_extraconfig.h"
#include "ui_dialog_extraconfig.h"

string extraConfigContent = "";
Dialog_extraConfig::Dialog_extraConfig(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_extraConfig)
{
    ui->setupUi(this);
}

Dialog_extraConfig::~Dialog_extraConfig()
{
    delete ui;
}



void Dialog_extraConfig::on_Save_clicked()
{
    extraConfigContent = ui->ExtraConfig_content->toPlainText().toStdString().c_str();
}

void Dialog_extraConfig::on_Close_clicked()
{
    close();
}
