#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    int widthWin = 400;
    int heightWin = 256;
    QLabel myLabel;
    void quitter();
private slots:
    void on_Files_clicked();
    void changeEvent(QEvent *);
    void on_Shutdown_clicked();

    void on_Hibernate_clicked();

    void on_Sleep_clicked();

    void on_Logoff_clicked();

    void on_Restart_clicked();

    void on_Search_clicked();

    void on_Settings_clicked();

    void on_Apps_clicked();

    void on_Lock_pressed();

    void on_Switch_pressed();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
