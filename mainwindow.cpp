#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFile"
#include "QTextStream"
//#include <unistd.h>
//#include <sys/wait.h>
//#include <sys/prctl.h>
//#include<signal.h>
#include "QMessageBox"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //avoid more than one miner runing when the software exit in exceptional situation
    system("killall cpuminer 2> /dev/null");
    system("killall ccminer_cuda9 2> /dev/null");
    system("rm ./*.log 2> /dev/null");

    //set timer to update accepted share
    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(systimer()));
    timer->start(2000);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::systimer()
{
    proShaAcc = new QProcess(this);
    connect(proShaAcc, SIGNAL(readyRead()), this, SLOT(readoutput()));
    proShaAcc->start("grep -c Accepted ./Miner.log");
    proShaAcc->waitForStarted();
}

void MainWindow::readoutput()
{

    if(!proShaAcc) return;
    QString shareAccepted = "Share Accepted: ";
    shareAccepted.append(proShaAcc->readAll());//get the accepted share number
    statusBar()->showMessage(shareAccepted);
}


void MainWindow::on_actionQuit_triggered()
{
    system("killall cpuminer 2> /dev/null");
    system("killall ccminer_cuda9 2> /dev/null");
    system("rm ./*.log 2> /dev/null");
    exit(0);
}


int clickNum = 1;
void MainWindow::on_StartMining_clicked()
{
    if(clickNum == 1)
    {
        string command;
        string miner;
        string server;
        string username;
        string password;
        string algorithm;
        string cpu_affinity;


        server = " -o ";
        cpu_affinity = " --cpu-affinity=";
        algorithm = " -a ";
        username = " --user=";
        password = " --pass=";


        server.append(ui->Server_content->currentText().toStdString().c_str());
        cpu_affinity.append(ui->CPUAffinity_content->currentText().toStdString().c_str());
        algorithm.append(ui->Algorithm_content->currentText().toStdString().c_str());
        username.append(ui->Username_content->text().toStdString().c_str());
        password.append(ui->Password_content->text().toStdString().c_str());
        miner.append(ui->Miner_content->currentText().toStdString().c_str());

        if(!strcmp(miner.c_str(),"CPU Miner"))
        {
            command = "./cpuminer ";
        }
        else if(!strcmp(miner.c_str(),"CUDA Miner"))
        {
            command = "./ccminer_cuda9 ";
        }

        command.append(algorithm.c_str());
        command.append(server.c_str());
        command.append(username.c_str());
        command.append(password.c_str());
        command.append(cpu_affinity.c_str());
        command.append(" --no-color");
        command.append(extraConfigContent.c_str());
        command.append(" >./Miner.log &");
        statusBar()->showMessage("Start mining...",1000);
        system(command.c_str());
        //mySystem(command.c_str());
        clickNum = 0;
        ui->StartMining->setText("Stop");
        ui->StartMining->setToolTip("Click to stop minging");

    }
    else
    {

        clickNum = 1;
        ui->StartMining->setText("Start");
        ui->StartMining->setToolTip("Click to start minging");
        statusBar()->showMessage("Stop mining...",1000);
        if(!strcmp(ui->Miner_content->currentText().toStdString().c_str(),"CPU Miner"))
        {
            system("killall cpuminer");
        }
        if(!strcmp(ui->Miner_content->currentText().toStdString().c_str(),"CUDA Miner"))
        {
            system("killall ccminer_cuda9");
        }
    }
}

//int MainWindow::mySystem(const char *cmdstring)
//{
//    pid_t pid;
//    int status;

//    if((pid=fork()) < 0)
//    {
//        //start error
//        statusBar()->showMessage("Start mining error...",1000);
//    }
//    else if(pid > 0)
//    {
//        waitpid(pid, &status, 0);
//        return status;
//    }
//    else
//    {
//        prctl(PR_SET_PDEATHSIG, SIGHUP);
//        prctl(PR_SET_PDEATHSIG, SIGKILL, 0, 0, 0);
//        execl("/bin/sh", "sh", "-c", cmdstring, (char *)0);
//        return -1;
//    }
//}


void MainWindow::on_Console_triggered()
{
    dialog_log = new Dialog_log(this);
    dialog_log->setModal(false);
    QPoint moveTo = dialog_log->mapFromGlobal(QPoint(300,200));
    moveTo += QPoint(300,200);
    dialog_log->move(moveTo);
    dialog_log->show();
}

void MainWindow::on_About_triggered()
{
    dialog = new Dialog(this);
    dialog->setModal(false);
    QPoint moveTo = dialog->mapFromGlobal(QPoint(300,200));
    moveTo += QPoint(300,200);
    dialog->move(moveTo);
    dialog->show();
}

void MainWindow::on_Donate_triggered()
{
    dialog_donate = new Dialog_donate(this);
    dialog_donate->setModal(false);
    QPoint moveTo = dialog_donate->mapFromGlobal(QPoint(300,200));
    moveTo += QPoint(300,200);
    dialog_donate->move(moveTo);
    dialog_donate->show();
}


void MainWindow::on_actionCPU_Miner_triggered()
{
    dialog_CPUMinerUsage = new Dialog_CPUMinerUsage(this);
    dialog_CPUMinerUsage->setModal(false);
    QPoint moveTo = dialog_CPUMinerUsage->mapFromGlobal(QPoint(300,200));
    moveTo += QPoint(300,200);
    dialog_CPUMinerUsage->move(moveTo);
    dialog_CPUMinerUsage->show();
}

void MainWindow::on_actionCUDA_Miner_triggered()
{
    dialog_CUDAMinerUsage = new Dialog_CUDAMinerUsage(this);
    dialog_CUDAMinerUsage->setModal(true);
    QPoint moveTo = dialog_CUDAMinerUsage->mapFromGlobal(QPoint(300,200));
    moveTo += QPoint(300,200);
    dialog_CUDAMinerUsage->move(moveTo);
    dialog_CUDAMinerUsage->show();
}

void MainWindow::on_actionExtra_Config_triggered()
{
    dialog_extraConfig = new Dialog_extraConfig(this);
    dialog_extraConfig->setModal(true);
    QPoint moveTo = dialog_extraConfig->mapFromGlobal(QPoint(300,200));
    moveTo += QPoint(300,200);
    dialog_extraConfig->move(moveTo);
    dialog_extraConfig->show();
}

void MainWindow::on_actionSave_setting_triggered()
{
    QString miner;
    QString server;
    QString username;
    QString password;
    QString algorithm;
    QString cpu_affinity;

    miner="Miner%";
    algorithm = "Algorithm%";
    server = "Server%";
    password = "Password%";
    username = "Username%";
    cpu_affinity = "CPU Affinity%";

    miner.append(ui->Miner_content->currentText().toStdString().c_str());
    algorithm.append(ui->Algorithm_content->currentText().toStdString().c_str());
    server.append(ui->Server_content->currentText().toStdString().c_str());
    password.append(ui->Password_content->text().toStdString().c_str());
    username.append(ui->Username_content->text().toStdString().c_str());
    cpu_affinity.append(ui->CPUAffinity_content->currentText().toStdString().c_str());

    QFile file("configure.ini");

    if(!file.open(QFile::WriteOnly | QFile::Truncate))  //Truncate to clean the file
    {
        QMessageBox::information(this,"Error Message", "The text file not exist or Truncate fail.");
        return;
    }

    QTextStream out(&file);
    out << miner<<endl;
    out << algorithm<<endl;
    out << server<<endl;
    out << password<<endl;
    out << username<<endl;
    out << cpu_affinity<<endl;

    file.close();

}

void MainWindow::on_actionLoad_setting_triggered()
{
    QString miner;
    QString server;
    QString username;
    QString password;
    QString algorithm;
    QString cpu_affinity;

    miner="Miner";
    algorithm = "Algorithm";
    server = "Server";
    password = "Password";
    username = "Username";
    cpu_affinity = "CPU Affinity";

    QFile file("configure.ini");
    if(!file.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(this,tr("Error"),tr("Read file configure.ini error : %1").arg(file.errorString()));
        return;
    }

    QTextStream in(&file);
    file.seek(0);
    try
    {
        while(!in.atEnd())
        {
            QString line=in.readLine();
            QString strFrame =line.simplified();
            QStringList sections = strFrame.split(QRegExp( "[%]"));

            if (miner == sections[0])
            {
                int j = ui->Miner_content->findText(sections[1]);
                ui->Miner_content->setCurrentIndex(j);
            }
            else if (algorithm == sections[0])
            {
                int j = ui->Algorithm_content->findText(sections[1]);
                ui->Algorithm_content->setCurrentIndex(j);
            }
            else if(server == sections[0])
            {
                int j = ui->Server_content->findText(sections[1]);
                ui->Server_content->setCurrentIndex(j);
            }
            else if (password == sections[0])
            {
                ui->Password_content->setText(sections[1]);
            }
            else if (username == sections[0])
            {
                ui->Username_content->setText(sections[1]);
            }
            else if (cpu_affinity == sections[0])
            {
                int j = ui->CPUAffinity_content->findText(sections[1]);
                ui->CPUAffinity_content->setCurrentIndex(j);
                /*
                int count=ui->CPUAffinity_content.count();
                for(int i=0;i<count;i++)
                {
                    if(ui->CPUAffinity_content.itemText(i)==sections[1])
                    {
                        ui->CPUAffinity_content->setCurrentIndex(i);
                        break;
                    }
                }
                */
            }
        }
        file.close();

    }
    catch (int e)
    {
        QMessageBox::information(NULL,"Information",QString::number(e));
    }

}
