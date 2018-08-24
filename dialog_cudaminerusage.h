#ifndef DIALOG_CUDAMINERUSAGE_H
#define DIALOG_CUDAMINERUSAGE_H

#include <QDialog>

namespace Ui {
class Dialog_CUDAMinerUsage;
}

class Dialog_CUDAMinerUsage : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_CUDAMinerUsage(QWidget *parent = 0);
    ~Dialog_CUDAMinerUsage();

private slots:
    void on_Close_clicked();

private:
    Ui::Dialog_CUDAMinerUsage *ui;
};

#endif // DIALOG_CUDAMINERUSAGE_H
