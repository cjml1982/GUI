#include "dialog_log.h"
#include "ui_dialog_log.h"
#include "QFile"
#include "QTextStream"
#include "unistd.h"

Dialog_log::Dialog_log(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_log)
{
    ui->setupUi(this);
}

Dialog_log::~Dialog_log()
{
    delete ui;
}

void Dialog_log::on_RefleshLog_clicked()
{
    //delete the escape character
    //system("cat Miner.log | col -b > MinerFilter.log");
    //system("sed -i 's/3.m//g' ./MinerFilter.log");
    //system("sed -i 's/90m//g' ./MinerFilter.log");
    //system("sed -i 's/0m//g' ./MinerFilter.log");
    //system("sed -i 's/01;//g' ./MinerFilter.log");


    QFile file("./Miner.log");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        printf("Open Miner.log error");
    }
    QTextStream  temp(&file);
    QString data;
    temp.setCodec("UTF-8");
    //temp.setCodec("zh_CN.GB2312");
    while (!temp.atEnd())
    {
        QString line = temp.readLine();
        line = line + "\n";
        data = data + line;
    }
    file.close();
    ui->MinerLog->setText(data);

}


void Dialog_log::on_Close_clicked()
{
    close();
}
