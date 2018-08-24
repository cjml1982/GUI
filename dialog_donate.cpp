#include "dialog_donate.h"
#include "ui_dialog_donate.h"


Dialog_donate::Dialog_donate(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_donate)
{
    ui->setupUi(this);
}

Dialog_donate::~Dialog_donate()
{
    delete ui;
}

void Dialog_donate::on_Close_clicked()
{
    close();
}

void Dialog_donate::on_copyAddress_clicked()
{
    clipborad = QApplication::clipboard();
    clipborad->setText(ui->donate_label3->text());
}
