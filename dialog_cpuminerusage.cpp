#include "dialog_cpuminerusage.h"
#include "ui_dialog_cpuminerusage.h"

Dialog_CPUMinerUsage::Dialog_CPUMinerUsage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_CPUMinerUsage)
{
    ui->setupUi(this);
}

Dialog_CPUMinerUsage::~Dialog_CPUMinerUsage()
{
    delete ui;
}

void Dialog_CPUMinerUsage::on_Close_clicked()
{
    close();
}
