#include <Windows.h>
#include <Xinput.h>
#include <iostream>
#include <cstdlib>
#include <thread>

#pragma comment(lib, "Xinput.lib")

void Vibration(int ctrlId, float left_motor, float right_motor) {
    XINPUT_VIBRATION recoil;

    recoil.wLeftMotorSpeed = static_cast<WORD>(left_motor * 65535);
    recoil.wRightMotorSpeed = static_cast<WORD>(right_motor * 65535);

    XInputSetState(ctrlId, &recoil);
}

int main() {
    SetConsoleTitle(TEXT("Controller Vibrator"));
    const int ctrlId = 0;

    while (true) {
        if (GetAsyncKeyState(0x58) && 0x8000) {
            system("cls");
            std::cout << "toggle: on" << std::endl;
            Vibration(ctrlId, 1.0f, 1.0f);
        }

        else {
            system("cls");
            std::cout << "toggle: off" << std::endl;
            Vibration(ctrlId, 0.0f, 0.0f);
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(20));
    }
    return 0;
}