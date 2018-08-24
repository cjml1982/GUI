#include "dialog_cudaminerusage.h"
#include "ui_dialog_cudaminerusage.h"

Dialog_CUDAMinerUsage::Dialog_CUDAMinerUsage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_CUDAMinerUsage)
{
    ui->setupUi(this);
}

Dialog_CUDAMinerUsage::~Dialog_CUDAMinerUsage()
{
    delete ui;
}

void Dialog_CUDAMinerUsage::on_Close_clicked()
{
    close();
}
