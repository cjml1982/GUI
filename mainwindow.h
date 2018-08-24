#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <dialog_help.h>
#include <dialog_log.h>
#include <dialog_donate.h>
#include <dialog_cpuminerusage.h>
#include <dialog_cudaminerusage.h>
#include <dialog_extraconfig.h>
#include <QProcess>
#include <QTimer>
#include <QLabel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_actionQuit_triggered();

    void on_About_triggered();

    void on_StartMining_clicked();

    void on_Console_triggered();

    void on_Donate_triggered();

    void on_actionCPU_Miner_triggered();

    void on_actionCUDA_Miner_triggered();

    void on_actionExtra_Config_triggered();

    void readoutput();//output the information into textEdit real time

    void systimer();

    //int mySystem(const char *cmdstring);
    void on_actionSave_setting_triggered();

    void on_actionLoad_setting_triggered();

private:
    Ui::MainWindow *ui;
    Dialog *dialog;
    Dialog_log *dialog_log;
    Dialog_donate *dialog_donate;
    Dialog_CPUMinerUsage *dialog_CPUMinerUsage;
    Dialog_CUDAMinerUsage *dialog_CUDAMinerUsage;
    Dialog_extraConfig * dialog_extraConfig;
    QProcess *proShaAcc;
    QTimer *timer;
    QLabel *msgLabel;

};

#endif // MAINWINDOW_H
