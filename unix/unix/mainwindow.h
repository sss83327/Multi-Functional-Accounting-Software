#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include <QStringList>
#include <dialog.h>
#include <dialog_2.h>
extern QSqlDatabase mydb;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void total_budget();
    ~MainWindow();
    QComboBox *returncombobox();
   void show_shop_data();
private Q_SLOTS:
    void on_calendarWidget_clicked(const QDate &tdate);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

private:
    Ui::MainWindow *ui;

    void db_connection();
    void statistic_date();
    Dialog *dialog;
    Dialog_2 *dialog_2;
     void show_statistic_data();


    int from_python(int);
};

#endif // MAINWINDOW_H
