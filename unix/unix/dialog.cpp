#include "dialog.h"
#include "ui_dialog.h"
#include "mainwindow.h"
#include <QTableView>
#include <QTextCodec>
#include <QtSql/QtSql>
#include <QMessageBox>
#include <QInputDialog>
#include <QSqlTableModel>

MainWindow *parent_main;

Dialog::Dialog(const QDate tdate,QWidget *parent) :
    date(tdate),QDialog(parent),
    ui(new Ui::Dialog)

{
    ui->setupUi(this);
    get_category();
    set_date_format();
    //MainWindow *parent_main;
    parent_main = (MainWindow*)parent;
 //   parent->
//    QDate c;
//    qDebug() << c;
 //   parent_main_windows = (MainWindow*)parent->parent();

}

Dialog::~Dialog()
{
    delete ui;
}



void Dialog::on_pushButton_clicked()    // add category
{
    bool isok;
    QString a_category = QInputDialog::getText(this, "Add Category", "Input add category: ",QLineEdit::Normal,
                                               "your category",
                                               &isok);

    if(isok)
    {
        QSqlQuery query;
        query.prepare("Insert into Category (Category)"
                  "Values (:category)");
        query.bindValue(":category", a_category);
        qDebug() << query.exec() << endl;
        query.exec("Select * from Category");
  //  qDebug() << query.exec("Alter Table Category Add testcate CHAR") <<endl;
        query.last();
        ui->comboBox->addItem(query.value(0).toString());
        parent_main->returncombobox()->addItem(query.value(0).toString());
    }
}

void Dialog::get_category()  // from database
{
    QSqlQuery q("Select * from Category");
    while(q.next())
    {
        ui->comboBox->addItem(q.value(0).toString().trimmed());
    }
}

void Dialog::on_buttonBox_accepted()    // save
{
    QString t_money = ui->lineEdit->text();
//    int money = t_money.toInt();

    QString t_category = ui->comboBox->currentText();

    QDate t_date = date;
    QSqlQuery query;
    query.prepare("Insert into Expense (Category, Date, Cash) "
                    "Values (:category, :date, :cash)");
    query.bindValue(":category", t_category);
    query.bindValue(":date", t_date);
    query.bindValue(":cash", t_money);
    QMessageBox::about(NULL, "About", "added into Database");
    qDebug() << query.exec() << endl;



    parent_main->total_budget();
}

void Dialog::set_date_format()
{
    QString temp = date.toString("yyyy-M-dd");
    this->setWindowTitle(temp);
}
