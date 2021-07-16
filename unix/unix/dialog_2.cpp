#include "dialog_2.h"
#include "ui_dialog_2.h"
#include <fstream>
#include <iostream>
#include "mainwindow.h"
using namespace std;

MainWindow *parent_main2;

Dialog_2::Dialog_2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_2)
{
    ui->setupUi(this);
    show_item();

    parent_main2 = (MainWindow*)parent;
}

Dialog_2::~Dialog_2()
{
    delete ui;
}

void Dialog_2::show_item()
{
    QStringList header;
    ui->tableWidget->setColumnCount(3);
    header << "Cash" << "Itemname" << "Place";
    ui->tableWidget->setHorizontalHeaderLabels(header);
    ui->tableWidget->setColumnWidth(0,86);
    ui->tableWidget->setColumnWidth(1,361);
    ui->tableWidget->setColumnWidth(2,150);
    fstream file("new.txt", ios::in);

    int money;
    char itemname[100];
    char place[100];
    while (file>>money >> itemname >> place )
    {
       // qDebug() << money << "  " << itemname << "  "<< place << endl;
       int row_count = ui->tableWidget->rowCount();
       ui->tableWidget->insertRow(row_count);
       ui->tableWidget->setItem(row_count,0,new QTableWidgetItem(QString::number(money)));
       ui->tableWidget->setItem(row_count,1,new QTableWidgetItem(itemname));
       ui->tableWidget->setItem(row_count,2,new QTableWidgetItem(place));
       row_count++;
    }

//    int row_count = ui->tableWidget->rowCount();
//    ui->tableWidget->insertRow(row_count);
//    ui->tableWidget->setItem(row_count,0,new QTableWidgetItem("1234"));
//    ui->tableWidget->setItem(row_count,1,new QTableWidgetItem("123"));
//    ui->tableWidget->setItem(row_count,2,new QTableWidgetItem("124"));


    file.close();
}

void Dialog_2::on_buttonBox_accepted()
{
    int current_row = ui->tableWidget->currentIndex().row();
    //QModelIndex index = model->index(current_row,0,QModelIndex());
    ui->tableWidget->item(current_row,0);
    QString a_category = parent_main2->returncombobox()->currentText();//ui->tableWidget->item(current_row,0)->text();
    //index  = model->index(current_row,2,QModelIndex());
    QString a_place = ui->tableWidget->item(current_row,2)->text();
    //index = model->index(current_row,0,QModelIndex());
    QString a_cash = ui->tableWidget->item(current_row,0)->text();
    //index = model->index(current_row,1,QModelIndex());
    QString a_itemname =ui->tableWidget->item(current_row,1)->text();


//    qDebug() << a_category << endl << a_place<<endl << a_cash << endl << a_itemname <<endl;

    QSqlQuery query;
    query.prepare("Insert into Shoplist (Category, Itemname, Cash, Place) "
                  "Values (:category, :itemname, :cash, :place)");
    query.bindValue(":category", a_category);
    query.bindValue(":itemname", a_itemname);
    query.bindValue(":cash", a_cash);
    query.bindValue(":place", a_place);
    qDebug() << query.exec();
    parent_main2->show_shop_data();
//            int c_row = ui->tableView->currentIndex().row();
//            QModelIndex index = model->index(c_row,0,QModelIndex());
//        //   qDebug() << ui->tableView->model()->data(index).toString() << endl << c_row;
//            QString d_category = ui->tableView->model()->data(index).toString();
//            index  = model->index(c_row,1,QModelIndex());
//            QString d_date = ui->tableView->model()->data(index).toString();
//            index = model->index(c_row,2,QModelIndex());
//            QString d_cash = ui->tableView->model()->data(index).toString();
//            qDebug() << d_category << endl << d_date<<endl << d_cash <<endl;
//            query.prepare("Delete From Expense Where Category = :category And Date = :date And Cash = :cash");
//            query.bindValue(":category", d_category);
//            query.bindValue(":date", d_date);
//            query.bindValue(":cash", d_cash);
//            qDebug() << query.exec();
}

void Dialog_2::on_pushButton_clicked()
{
       qDebug() << ui->tableWidget->columnWidth(0) <<  ui->tableWidget->columnWidth(1)  << ui->tableWidget->columnWidth(2) ;
}
