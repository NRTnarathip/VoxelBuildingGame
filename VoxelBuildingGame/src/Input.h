#pragma once

class Input
{
public:
    Input() {
        instance = this;
    };
    //Singletons should not be cloneable.
    Input(Input& other) = delete;
    //Singletons should not be assignable.
    void operator=(const Input&) = delete;

    static Input& GetInstance() { return *instance; }
    void initMap();
    bool isKey(int keyCode);
    bool isKeyDown(int keyCode);
    bool isKeyUp(int keyCode);
private:
    int arrKeyDowns[256] = { 0 };
    static Input* instance;
};


