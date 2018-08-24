#ifndef DIALOG_LOG_H
#define DIALOG_LOG_H

#include <QDialog>

namespace Ui {
class Dialog_log;
}

class Dialog_log : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_log(QWidget *parent = 0);
    ~Dialog_log();

private slots:
    void on_RefleshLog_clicked();

    void on_Close_clicked();

private:
    Ui::Dialog_log *ui;
};

#endif // DIALOG_LOG_H
