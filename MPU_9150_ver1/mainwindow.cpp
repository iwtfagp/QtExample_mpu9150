#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLibrary>
#include <QMessageBox>
#include "Windows.h"
#include <iostream>
double Roll_Ankle = 0, Yaw_Ankle = 0, Pitch_Ankle = 0;


HINSTANCE IMU_data ;
int (*OpenCom)(unsigned short);
void (*CloseCom)(void);
void (*GetAllAngle)(double*, double*, double*) ;
int Port = 5;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer_ = new QTimer(this);
    timer_->stop();
    timer_->setInterval(20);
    QObject::connect(timer_, SIGNAL(timeout()), this, SLOT(updateView()));



    // Load IMU's dll file, and determint the IMU's functions
    char c_mpu1[] = "mpu9150_v5_1";
    WCHAR w_mpu1[14];
    swprintf(w_mpu1, L"%S", c_mpu1);
    LPCWSTR L_mp1 = w_mpu1;

    IMU_data=LoadLibrary(L_mp1);
    if (IMU_data == NULL)
    {
        QMessageBox::information(0,0,"MPU IMU #1 Dll  Loading Fail") ;
    }
    (FARPROC &) OpenCom = GetProcAddress(IMU_data, "OpenCOM");
    (FARPROC &) CloseCom = GetProcAddress(IMU_data, "CloseCOM");
    (FARPROC &) GetAllAngle = GetProcAddress(IMU_data, "GetAllAngles");

    OpenCom(Port) ;
    timer_->start();

}
void MainWindow::updateView()
{

    QString string;

    GetAllAngle(&Roll_Ankle, &Yaw_Ankle, &Pitch_Ankle);

    string.append("Roll_Ankle() = ");
    string.append(QString::number(Roll_Ankle));
    string.append(" Yaw_Ankle() = ");
    string.append(QString::number(Yaw_Ankle));
    string.append(" Pitch_Ankle() = ");
    string.append(QString::number(Pitch_Ankle));
    string.append("\n");
    std::cout<<string.toStdString()<<std::endl;
    ui->textBrowser->insertPlainText(string);
    ui->textBrowser->moveCursor(QTextCursor::End);




}
MainWindow::~MainWindow()
{
    CloseCom();
    delete ui;
}

