#ifndef DIALOG_2_H
#define DIALOG_2_H

#include <QDialog>
#include <QtCore>
#include <QtGui>
namespace Ui {
class Dialog_2;
}

class Dialog_2 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_2(QWidget *parent = 0);
    ~Dialog_2();

private Q_SLOTS:
    void on_buttonBox_accepted();

    void on_pushButton_clicked();

private:
    Ui::Dialog_2 *ui;
    void show_item();
    QStringListModel model;
};

#endif // DIALOG_2_H
