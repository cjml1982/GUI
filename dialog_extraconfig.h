#ifndef DIALOG_EXTRACONFIG_H
#define DIALOG_EXTRACONFIG_H

#include <QDialog>
using namespace std;

extern string extraConfigContent;

namespace Ui {
class Dialog_extraConfig;
}

class Dialog_extraConfig : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_extraConfig(QWidget *parent = 0);
    ~Dialog_extraConfig();

private slots:

    void on_Save_clicked();

    void on_Close_clicked();

private:
    Ui::Dialog_extraConfig *ui;
};

#endif // DIALOG_EXTRACONFIG_H
