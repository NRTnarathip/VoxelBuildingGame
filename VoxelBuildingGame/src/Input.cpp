#include "Input.h"
#include <iostream>
Input Input::instance;

void Input::initMap() {
    printf("keyboardID:%d | mouseID:%d \n", keyboardID, mouseID);
    map.MapFloat(MouseAxis::Horizontal, mouseID, gainput::MouseAxisX);
    map.MapFloat(MouseAxis::Vertical, mouseID, gainput::MouseAxisY);
    map.MapBool(Forward, keyboardID, gainput::KeyW);
    map.MapBool(Backward, keyboardID, gainput::KeyS);
}