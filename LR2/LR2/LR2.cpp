#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

using namespace std;

mutex mtx;

void simulateCars(int startX, int endX, int speed) {
    for (int x = startX; x <= endX; x += speed) {

        this_thread::sleep_for(chrono::milliseconds(500));

        lock_guard<mutex> lock(mtx);
        cout << "Car at X = " << x << endl;
    }
    lock_guard<mutex> lock(mtx);
    cout << "Car reached end X = " << endX << endl;
}

void simulateMotorcycles(int startY, int endY, int speed) {
    for (int y = startY; y <= endY; y += speed) {
        this_thread::sleep_for(chrono::milliseconds(500));
        lock_guard<mutex> lock(mtx);
        cout << "Motorcycle at Y = " << y << endl;
    }
    lock_guard<mutex> lock(mtx);
    cout << "Motorcycle reached end Y = " << endY << endl;
}

int main() {

    const int startX = 0;
    const int endX = 50;
    const int startY = 0;
    const int endY = 50;
    const int speed = 10;

    cout << "Simulation started..." << endl;

    thread carThread(simulateCars, startX, endX, speed);
    thread motorcycleThread(simulateMotorcycles, startY, endY, speed);

    carThread.join();
    motorcycleThread.join();

    cout << "Simulation finished!" << endl;

    return 0;
}