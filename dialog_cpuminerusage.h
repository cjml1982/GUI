#ifndef DIALOG_CPUMINERUSAGE_H
#define DIALOG_CPUMINERUSAGE_H

#include <QDialog>

namespace Ui {
class Dialog_CPUMinerUsage;
}

class Dialog_CPUMinerUsage : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_CPUMinerUsage(QWidget *parent = 0);
    ~Dialog_CPUMinerUsage();

private slots:
    void on_Close_clicked();

private:
    Ui::Dialog_CPUMinerUsage *ui;
};

#endif // DIALOG_CPUMINERUSAGE_H
