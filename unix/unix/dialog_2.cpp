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
    setWindowTitle("Search");
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
    int a_money[2000];
    QString a_itemname[2000];
    QString a_place[2000];
    int row_count = 0;

    while (file>>money >> itemname >> place )
    {
       // qDebug() << money << "  " << itemname << "  "<< place << endl;

       a_money[row_count] = money;
       a_itemname[row_count] = QString::fromStdString(itemname);
       a_place[row_count] = QString::fromStdString(place);

//       ui->tableWidget->insertRow(row_count);
//       ui->tableWidget->setItem(row_count,0,new QTableWidgetItem(QString::number(money)));
//       ui->tableWidget->setItem(row_count,1,new QTableWidgetItem(itemname));
//       ui->tableWidget->setItem(row_count,2,new QTableWidgetItem(place));
       row_count++;
    }
    //sort_by_price();



    for ( int i = 0 ; i < row_count ; i++)
    {
        for( int j = i+1; j < row_count ; j++ )
        {
            if (a_money[i] > a_money[j])
            {
                QString t_place, t_itemname;
                int t_price;
                t_price= a_money[i];
                t_place = a_place[i];
                t_itemname = a_itemname[i];

                a_money[i] = a_money[j];
                a_place[i] = a_place[j];
                a_itemname[i] = a_itemname[j];

                a_money[j] = t_price;
                a_place[j] = t_place;
                a_itemname[j] = t_itemname;
//                ui->tableWidget->setItem(i, 0, ui->tableWidget->item(j,0));
//                ui->tableWidget->setItem(i, 2, ui->tableWidget->item(j,2));
//                ui->tableWidget->setItem(i, 1, ui->tableWidget->item(j,1));


//                ui->tableWidget->setItem(j, 0, new QTableWidgetItem(t_price));
//                ui->tableWidget->setItem(j, 2, new QTableWidgetItem(t_place));
//                ui->tableWidget->setItem(j, 1, new QTableWidgetItem(t_itemname));
            }
        }
    }

    for ( int i = 0 ; i < row_count; i++)
    {
        ui->tableWidget->insertRow(i);
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString::number(a_money[i])));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(a_itemname[i]));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(a_place[i]));
    }

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

//void Dialog_2::sort_by_price()
//{
// //     QString a_cash = ui->tableWidget->item(current_row,0)->text();
//    int row_count = ui->tableWidget->rowCount();
//    int price[2000];
//    for ( int i =0 ; i < row_count ; i++)
//    {
//        price[i] = ui->tableWidget->item(i,0)->text().toInt();
//    }

//    for ( int i = 0 ; i < row_count ; i++)
//    {
//        for( int j = i+1; j <row_count ; j++ )
//        {
//            if (price[i] > price[j])
//            {
//                QString t_price, t_place, t_itemname;
//                t_price=( ui->tableWidget->item(i,0)->text());
//                t_place = ( ui->tableWidget->item(i,2)->text());
//                t_itemname = (  ui->tableWidget->item(i,1)->text());

//                ui->tableWidget->setItem(i, 0, ui->tableWidget->item(j,0));
//                ui->tableWidget->setItem(i, 2, ui->tableWidget->item(j,2));
//                ui->tableWidget->setItem(i, 1, ui->tableWidget->item(j,1));

//                ui->tableWidget->itemChanged(
////                ui->tableWidget->setItem(j, 0, new QTableWidgetItem(t_price));
////                ui->tableWidget->setItem(j, 2, new QTableWidgetItem(t_place));
////                ui->tableWidget->setItem(j, 1, new QTableWidgetItem(t_itemname));
//            }
//        }
//    }

//}
