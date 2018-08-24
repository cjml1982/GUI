#ifndef DIALOG_DONATE_H
#define DIALOG_DONATE_H

#include <QDialog>
#include <QClipboard>

namespace Ui {
class Dialog_donate;
}

class Dialog_donate : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_donate(QWidget *parent = 0);
    ~Dialog_donate();

private slots:
    void on_Close_clicked();

    void on_copyAddress_clicked();

private:
    Ui::Dialog_donate *ui;
    QClipboard *clipborad;
};

#endif // DIALOG_DONATE_H
