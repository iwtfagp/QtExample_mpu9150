#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qwt_dial_needle.h>
#include <iostream>

double Roll_Ankle = 0, Yaw_Ankle = 0, Pitch_Ankle = 0;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //Set Timer
    timer_ = new QTimer(this);
    timer_->stop();
    timer_->setInterval(20);
    QObject::connect(timer_, SIGNAL(timeout()), this, SLOT(updateView()));

}

void MainWindow::updateView()
{
    //        mpu->getAngle(&Roll_Ankle, &Yaw_Ankle, &Pitch_Ankle);
    mpu->getAngle();
    Roll_Ankle = mpu->get_roll();
    Yaw_Ankle = mpu->get_yaw();
    Pitch_Ankle = mpu->get_pitch();


    if(Roll_Ankle<0)
        Roll_Ankle += 360;
    if(Yaw_Ankle<0)
        Yaw_Ankle += 360;
    if(Pitch_Ankle<0)
        Pitch_Ankle += 360;

    std::cout<<Roll_Ankle<<", "<<Yaw_Ankle<<", "<<Pitch_Ankle
            <<", "<<std::endl;

    ui->Dial->setNeedle(new QwtDialSimpleNeedle( QwtDialSimpleNeedle::Arrow ,true , Qt::red ));
    ui->Dial->setValue(Roll_Ankle);
    ui->Dial_2->setNeedle(new QwtDialSimpleNeedle( QwtDialSimpleNeedle::Arrow ,true , Qt::red ));
    ui->Dial_2->setValue(Yaw_Ankle);
    ui->Dial_3->setNeedle(new QwtDialSimpleNeedle( QwtDialSimpleNeedle::Arrow ,true , Qt::red ));
    ui->Dial_3->setValue(Pitch_Ankle);

}
MainWindow::~MainWindow()
{
    //    mpu->close();


    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    mpu = new MPU_9150();
    mpu->open(ui->spinBox->value(), "MPU9150-1.dll");
    timer_->start();
    ui->spinBox->setDisabled(true);
}
