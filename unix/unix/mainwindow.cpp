#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextCodec>
#include <QtSql>
#include <dialog.h>
#include <QMessageBox>
#include <QInputDialog>
#include <iostream>
#include <string>
#include <QProcess>
#include <Python.h>
#include <fstream>
#include <string>
#include "dialog_2.h"
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Easy Pay");
    db_connection();
    statistic_date();
    show_statistic_data();
    show_shop_data();
    total_budget();
//    ui->dateEdit->setDate(QDate::currentDate());
//    ui->dateEdit->set

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_calendarWidget_clicked(const QDate &tdate) // add expense
{

    dialog = new Dialog(tdate, this);
    dialog->show();
    //qDebug() << ui->calendarWidget->selectedDate();
}

void MainWindow::db_connection()
{
    QSqlDatabase mydb;
    mydb=QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("/home/sss83327/database/unixdb");

    mydb.open();
    QSqlQuery q("Select * from Category");
    while(q.next())
    {
        ui->comboBox->addItem(q.value(0).toString().trimmed());
    }
}



void MainWindow::on_pushButton_clicked()   // set budget
{

    QSqlDatabase mydb;
    bool isok = 0;
    int t_budget = QInputDialog::getInt(this, "Set Budget", "Input Budget", 0, 0,INT_MAX, 1, &isok,0);
    if (isok)
    {
        QString temp = QString::number(t_budget);
        ui->label_2->setText(temp);
        QSqlQuery *query = new QSqlQuery(mydb);
        query->prepare("Update Budget Set budget = :budget ");
        query->bindValue(":budget", t_budget);
    //    qDebug() << query->exec();
        query->exec();
        total_budget();
    }

}

void MainWindow::on_pushButton_2_clicked()  // select
{
    QSqlDatabase mydb;
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery *query = new QSqlQuery(mydb);
    QString t_date1 = ui->dateEdit->date().toString("yyyy-MM-dd");
    QString t_date2 = ui->dateEdit_2->date().toString("yyyy-MM-dd");

    query->prepare("Select * From Expense "
                   "Where Date Between :date1 And :date2 "
                   "Order by Date ");


    query->bindValue(":date1", t_date1);
    query->bindValue(":date2", t_date2);
//    qDebug() << mydb.close() ;
    qDebug() << query->exec()<< endl << t_date1 << "   " << t_date2;
    model->setQuery(*query);
   // cout << ui->tableView->columnWidth(1)<< ui->tableView->columnWidth(2)<<"asd";
    ui->tableView->setModel(model);
   // qDebug() << ui->tableView->columnWidth(0)<<ui->tableView->columnWidth(1)<< ui->tableView->columnWidth(2)<<"asd";
 //   cout << ui->tableView->columnWidth(1)<< ui->tableView->columnWidth(2)<<"asd";
   // ui->label_3->setText(t_date2);//.toString("yyyy-MM-dd"));
}

void MainWindow::statistic_date()   // set date to current date
{
    QDate t_date;
    QDate c_date = QDate::currentDate();
    t_date.setDate(c_date.year(),c_date.month(),1);
    ui->dateEdit->setDate(t_date);
    t_date.setDate(c_date.year(),c_date.month(),c_date.daysInMonth());
    ui->dateEdit_2->setDate(t_date);
}

void MainWindow::show_statistic_data()  // show statistic data
{
    QSqlDatabase mydb;

    QSqlTableModel *model;
    model = new QSqlTableModel(0, mydb);
    model->setTable("Expense");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);

    model->select();

    ui->tableView->setModel(model);
   // qDebug() << ui->tableView->columnWidth(0)<<ui->tableView->columnWidth(1)<< ui->tableView->columnWidth(2)<<"asd";
    ui->tableView->setColumnWidth(0,344);
    ui->tableView->setColumnWidth(1,171);
    ui->tableView->setColumnWidth(2,174);
}

void MainWindow::total_budget()   // calculate total budget
{
    QSqlDatabase mydb;
    QSqlQuery *query = new QSqlQuery(mydb);
    qDebug() << query->exec("Select budget From Budget");
    query->first();
    int budget = query->value(0).toInt();

    query->prepare("Select Cash From Expense");
    qDebug() << query->exec() << "total_budget" << budget << endl;
  //  int budget = ui->label_2->text().toInt();

    int total_cost = 0;
    while(query->next())
    {
     //   total -= query->value(0).toInt();
        total_cost += query->value(0).toInt();
    }
    ui->label_2->setText(QString::number(budget-total_cost));
    //ui->label_3->setText(QString::number(total_cost));
}

void MainWindow::on_pushButton_3_clicked()  // add shoping list
{
    QSqlDatabase mydb;
    QString item = ui->lineEdit->text();
    QString a_category = ui->comboBox->currentText();
    QSqlQuery query;
    query.prepare("Insert into Shoplist (Category, Itemname)"
                  "Values (:category, :itemname)");
    query.bindValue(":category", a_category);
    query.bindValue(":itemname", item);
    qDebug() << query.exec() << endl;
    show_shop_data();

}

void MainWindow::on_pushButton_4_clicked()  //  crawler
{

    fstream file( "new.txt", ios::in ) ;
    if(!file)
    {
        cout << "not opne "<< endl;
        file.close();
        fstream file("new.txt", ios::out);
    }
    else
    {
        fstream file("new.txt", ios::out);
        cout << "open" <<endl;
        // load
    }

//    QString str;
//    QByteArray byteArray=str.toLocal8Bit ();
//    char *c=byteArray.data();

    QString item = ui->lineEdit->text();
    QByteArray byteArray=item.toLocal8Bit ();
    char *str = byteArray.data();
    char cmd[100] = "python crawler5.py ";// + str + " new.txt";
    //char cmd3[100] = "python crawler6.py ";
    //char cmd4[100] = "python crawler7.py ";

    strcat(cmd,str);
    strcat(cmd," >> new.txt");
    //strcat(cmd3,str);
    //strcat(cmd3," >> new.txt");
    //strcat(cmd4,str);
    //strcat(cmd4," >> new.txt");
    //qDebug() << cmd;
    system(cmd);
    //system(cmd3);
    //system(cmd4);
    //system("拖把");
    file.close();

    dialog_2 = new Dialog_2(this);
    dialog_2->show();
}


void MainWindow::show_shop_data()  // show shpping list data
{
    QSqlDatabase mydb;

    QSqlTableModel *model;
    model = new QSqlTableModel(0, mydb);
    model->setTable("Shoplist");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);

    model->select();

    ui->tableView_2->setModel(model);
    ui->tableView_2->setColumnWidth(0,250);
    ui->tableView_2->setColumnWidth(1,222);
}



void MainWindow::on_pushButton_5_clicked() // delete statistic data
{
    QSqlDatabase mydb;
    QSqlQuery query;
    QSqlTableModel *model;
    model = new QSqlTableModel(0, mydb);
    model->setTable("Expense");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();

    int c_row = ui->tableView->currentIndex().row();
    QModelIndex index = model->index(c_row,0,QModelIndex());
//   qDebug() << ui->tableView->model()->data(index).toString() << endl << c_row;
    QString d_category = ui->tableView->model()->data(index).toString();
    index  = model->index(c_row,1,QModelIndex());
    QString d_date = ui->tableView->model()->data(index).toString();
    index = model->index(c_row,2,QModelIndex());
    QString d_cash = ui->tableView->model()->data(index).toString();
    qDebug() << d_category << endl << d_date<<endl << d_cash <<endl;
    query.prepare("Delete From Expense Where Category = :category And Date = :date And Cash = :cash");
    query.bindValue(":category", d_category);
    query.bindValue(":date", d_date);
    query.bindValue(":cash", d_cash);
    qDebug() << query.exec();
    show_statistic_data();
    total_budget();
   //ui->tableView->metric()
   //query.prepare("Delete From Expense Where ")
}

void MainWindow::on_pushButton_6_clicked() // delete shoplist data
{
    QSqlDatabase mydb;
    QSqlQuery query;
    QSqlTableModel *model;
    model = new QSqlTableModel(0, mydb);
    model->setTable("Shoplist");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();

    int c_row = ui->tableView_2->currentIndex().row();
    QModelIndex index = model->index(c_row,0,QModelIndex());
    QString d_category = ui->tableView_2->model()->data(index).toString();
    index  = model->index(c_row,1,QModelIndex());
    QString d_itemname = ui->tableView_2->model()->data(index).toString();

    qDebug() << d_category << endl << d_itemname<<endl;
    query.prepare("Delete From Shoplist Where Category = :category And Itemname = :itemname");
    query.bindValue(":category", d_category);
    query.bindValue(":itemname", d_itemname);

    qDebug() << query.exec();
    show_shop_data();
}



void MainWindow::on_pushButton_7_clicked()  // open dialog_2
{
    dialog_2 = new Dialog_2(this);
    dialog_2->show();
}

QComboBox * MainWindow::returncombobox()
{
    return ui->comboBox;
}
