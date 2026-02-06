#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QWidget>
#include <QByteArray>
#include <QString>
#include <QDebug>
#include <QScreen>
#include <QSettings>
#include <unistd.h>
#include <pwd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <QMessageBox>
#include <QCoreApplication>
#include <QProcess>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    QSettings settings("~/.config/tint2/tint2rc", QSettings::defaultFormat());
    QString fontsize = settings.value("task_font").toString();
    QString styles;
    styles= "QPushButton { font-size: %1;}";
    MainWindow::setStyleSheet(styles.arg(fontsize));

    ui->setupUi(this);
    QByteArray user = qgetenv("USER");
    if (!user.isEmpty()) {
        QString username = QString::fromLocal8Bit(user);
        ui->YOURNAME->setText(username);
    } else {
        qDebug() << "could not find username";
    }
    //system("bash /etc/userscripts/menu/window.sh");

    QApplication::setQuitOnLastWindowClosed(true);
}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::on_Files_clicked()
{
    pid_t p;
    p = fork();
    if (p == 0){

        system("bash /etc/userscripts/menu/files.sh");

    }

}


void MainWindow::changeEvent(QEvent * e) {

    if(e->type() == QEvent::ActivationChange && this->isActiveWindow()) {

    }else{

        close();
    }
}

void MainWindow::on_Shutdown_clicked()
{

    pid_t p;
    p = fork();
    if (p == 0){

        system("bash /etc/userscripts/menu/shutdown.sh");

    }


}


void MainWindow::on_Hibernate_clicked()
{

    pid_t p;
    p = fork();
    if (p == 0){

        system("bash /etc/userscripts/menu/hibernate.sh");

    }

}


void MainWindow::on_Sleep_clicked()
{

pid_t p;
p = fork();
if (p == 0){
    system("bash /etc/userscripts/menu/sleep.sh");

}

}


void MainWindow::on_Logoff_clicked()
{
    pid_t p;
    p = fork();
    if (p == 0){
        system("bash /etc/userscripts/menu/logoff.sh");

    }
}


void MainWindow::on_Restart_clicked()
{
    pid_t p;
    p = fork();
    if (p == 0){
        system("bash /etc/userscripts/menu/reboot.sh");

    }
}


void MainWindow::on_Search_clicked()
{
    pid_t p;
    p = fork();
    if (p == 0){
        system("bash /etc/userscripts/menu/search.sh");
    }
}


void MainWindow::on_Settings_clicked()
{
    pid_t p;
    p = fork();
    if (p == 0){
        system("bash /etc/userscripts/menu/settings.sh");

    }
}


void MainWindow::on_Apps_clicked()
{
    pid_t p;
    p = fork();
    if (p == 0){
        system("bash /etc/userscripts/menu/apps.sh");

    }
}


void MainWindow::on_Switch_pressed()
{
    pid_t p;
    p = fork();
    if (p == 0){
        system("bash /etc/userscripts/menu/switchuser.sh");

    }
}


void MainWindow::on_Lock_pressed()
{
    pid_t p;
    p = fork();
    if (p == 0){
        system("bash /etc/userscripts/menu/lock.sh");

    }
}

