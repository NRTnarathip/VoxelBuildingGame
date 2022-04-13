#pragma once
#include <gainput/gainput.h>
enum Keys {
    Forward,
    Backward,
};
enum MouseAxis {
    Vertical, Horizontal
};
class Input
{
public:
    //Singletons should not be cloneable.
    Input(Input& other) = delete;
    //Singletons should not be assignable.
    void operator=(const Input&) = delete;

    static Input& GetInstance() { return instance; }
    gainput::InputMap map;
    gainput::InputManager manager;
    void initMap();
private:
    Input() : map(manager) {
        mouseID = manager.CreateDevice<gainput::InputDeviceMouse>();
        keyboardID = manager.CreateDevice<gainput::InputDeviceKeyboard>();
    };
    gainput::DeviceId mouseID = -1;
    gainput::DeviceId keyboardID = -1;
    static Input instance;
};

