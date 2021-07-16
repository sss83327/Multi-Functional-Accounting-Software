/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *mainPage;
    QWidget *personal;
    QVBoxLayout *verticalLayout_2;
    QCalendarWidget *calendarWidget;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_3;
    QDateEdit *dateEdit_2;
    QDateEdit *dateEdit;
    QPushButton *pushButton_2;
    QTableView *tableView;
    QPushButton *pushButton_5;
    QWidget *tab_3;
    QPushButton *pushButton_4;
    QTableView *tableView_2;
    QLineEdit *lineEdit;
    QComboBox *comboBox;
    QPushButton *pushButton_3;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(752, 487);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        mainPage = new QTabWidget(centralWidget);
        mainPage->setObjectName(QStringLiteral("mainPage"));
        mainPage->setGeometry(QRect(10, 1, 734, 442));
        mainPage->setStyleSheet(QStringLiteral("background-color: qlineargradient(sprergba(255, 255, 255, 0)ad:pad, x1:0, y1:0, x2:0.894555, y2:0.92, stop:0 rgba(205, 95, 95, 255), stop:1 rgba(139, 163, 255, 255));"));
        personal = new QWidget();
        personal->setObjectName(QStringLiteral("personal"));
        verticalLayout_2 = new QVBoxLayout(personal);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        calendarWidget = new QCalendarWidget(personal);
        calendarWidget->setObjectName(QStringLiteral("calendarWidget"));
        calendarWidget->setBaseSize(QSize(0, 0));
        QFont font;
        font.setFamily(QStringLiteral("Ubuntu"));
        font.setPointSize(17);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(7);
        calendarWidget->setFont(font);
        calendarWidget->setStyleSheet(QStringLiteral("font: 57 17pt \"Ubuntu\";"));
        calendarWidget->setGridVisible(false);
        calendarWidget->setHorizontalHeaderFormat(QCalendarWidget::ShortDayNames);
        calendarWidget->setVerticalHeaderFormat(QCalendarWidget::ISOWeekNumbers);
        calendarWidget->setNavigationBarVisible(true);
        calendarWidget->setDateEditEnabled(true);

        verticalLayout_2->addWidget(calendarWidget);

        label = new QLabel(personal);
        label->setObjectName(QStringLiteral("label"));
        QFont font1;
        font1.setPointSize(28);
        label->setFont(font1);

        verticalLayout_2->addWidget(label);

        label_2 = new QLabel(personal);
        label_2->setObjectName(QStringLiteral("label_2"));
        QFont font2;
        font2.setPointSize(26);
        label_2->setFont(font2);

        verticalLayout_2->addWidget(label_2);

        pushButton = new QPushButton(personal);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout_2->addWidget(pushButton);

        mainPage->addTab(personal, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        verticalLayout_3 = new QVBoxLayout(tab_2);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        dateEdit_2 = new QDateEdit(tab_2);
        dateEdit_2->setObjectName(QStringLiteral("dateEdit_2"));
        dateEdit_2->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        dateEdit_2->setDateTime(QDateTime(QDate(2016, 6, 30), QTime(0, 0, 0)));

        verticalLayout_3->addWidget(dateEdit_2);

        dateEdit = new QDateEdit(tab_2);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        dateEdit->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        dateEdit->setDateTime(QDateTime(QDate(2016, 6, 1), QTime(0, 0, 0)));
        dateEdit->setTimeSpec(Qt::LocalTime);

        verticalLayout_3->addWidget(dateEdit);

        pushButton_2 = new QPushButton(tab_2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        verticalLayout_3->addWidget(pushButton_2);

        tableView = new QTableView(tab_2);
        tableView->setObjectName(QStringLiteral("tableView"));

        verticalLayout_3->addWidget(tableView);

        pushButton_5 = new QPushButton(tab_2);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));

        verticalLayout_3->addWidget(pushButton_5);

        mainPage->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        pushButton_4 = new QPushButton(tab_3);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(520, 80, 201, 161));
        tableView_2 = new QTableView(tab_3);
        tableView_2->setObjectName(QStringLiteral("tableView_2"));
        tableView_2->setGeometry(QRect(9, 75, 491, 331));
        lineEdit = new QLineEdit(tab_3);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(15, 9, 491, 27));
        lineEdit->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        comboBox = new QComboBox(tab_3);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(15, 42, 491, 27));
        comboBox->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        pushButton_3 = new QPushButton(tab_3);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(519, 9, 201, 61));
        pushButton_6 = new QPushButton(tab_3);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(520, 250, 201, 151));
        mainPage->addTab(tab_3, QString());
        pushButton_7 = new QPushButton(centralWidget);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(580, 430, 99, 27));
        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        mainPage->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        label->setText(QApplication::translate("MainWindow", "Balance:", 0));
        label_2->setText(QString());
        pushButton->setText(QApplication::translate("MainWindow", "Budget", 0));
        mainPage->setTabText(mainPage->indexOf(personal), QApplication::translate("MainWindow", "Personal", 0));
        dateEdit_2->setDisplayFormat(QApplication::translate("MainWindow", "yyyy-MM-dd", 0));
        dateEdit->setDisplayFormat(QApplication::translate("MainWindow", "yyyy-MM-dd", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "select", 0));
        pushButton_5->setText(QApplication::translate("MainWindow", "Delete", 0));
        mainPage->setTabText(mainPage->indexOf(tab_2), QApplication::translate("MainWindow", "Statistic", 0));
        pushButton_4->setText(QApplication::translate("MainWindow", "Crawler", 0));
        pushButton_3->setText(QApplication::translate("MainWindow", "Add ", 0));
        pushButton_6->setText(QApplication::translate("MainWindow", "Delete", 0));
        mainPage->setTabText(mainPage->indexOf(tab_3), QApplication::translate("MainWindow", "Shopping List", 0));
        pushButton_7->setText(QApplication::translate("MainWindow", "PushButton", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
