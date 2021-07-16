#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QtSql>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QDate, QWidget *parent = 0);

    ~Dialog();

private Q_SLOTS:
    void on_pushButton_clicked();

    void on_buttonBox_accepted();

private:
    Ui::Dialog *ui;
    QDate date;



    void dbcategory();
    void get_category();
    void set_date_format();
};

#endif // DIALOG_H
