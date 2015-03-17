#include "mpu_9150.h"

MPU_9150::MPU_9150()
{

}

bool MPU_9150::open(double port, const char* dll_file)
{

    // Load IMU's dll file, and determint the IMU's functions
    const char* c_mpu1 = dll_file;
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

    OpenCom(port) ;
    return MPU_OK;
}

bool MPU_9150::close()
{
    return MPU_OK;
}

void MPU_9150::getAngle(double* roll, double* yaw, double* pitch)
{

    GetAllAngle(roll, yaw, pitch);
}
