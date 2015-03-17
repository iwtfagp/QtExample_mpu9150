#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "mpu_9150.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void updateView();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QTimer* timer_;
    MPU_9150 *mpu;
};

#endif // MAINWINDOW_H
