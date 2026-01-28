#include "mainwindow.h"
#include <QScreen>
#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QWidget>
#include <QDebug>
#include <string>
#include <qsettings.h>
#include <QLabel>
#include <QProcess>
#include <QSystemTrayIcon>
#include <QIcon>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QApplication::quitOnLastWindowClosed();
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->geometry();
    int height = screenGeometry.height();
    int width = screenGeometry.width();
    QSettings settings("/home/evan/.config/tint2/tint2rc", QSettings::defaultFormat());
    QString side = settings.value("panel_position").toString();
    QString size = settings.value("panel_size").toString();
    size =size.remove("100%");
    w.setGeometry(0,height-size.toInt()-w.height(),w.width(),w.height());


    w.setWindowFlags(Qt::FramelessWindowHint);
    w.show();
    QObject::connect(&a, &QApplication::focusChanged, [&a](QWidget *old, QWidget *now) {
        if (now == nullptr) { // No widget in our app has focus
            a.quit();
        }
    });
    return a.exec();
}


