#include <iostream>
using namespace std;

#define ID_LEN  20
#define MAX_SPD     200
#define FUEL_STEP   2
#define ACC_STEP    10
#define BRK_STEP    10

struct Car{
    char gamerID[ID_LEN];   // 소유자 ID
    int fuelGauge;          // 연료량
    int curSpeed;           // 현재 속도

};

void ShowCarState(const Car &car ){
    cout<<"소유자 ID: "<<car.gamerID<<endl;
    cout<<"연료량: "<< car.fuelGauge<<endl;
    cout<<"현재속도: "<<car.curSpeed<<endl;
}

void Accel(Car &car){
    if(car.fuelGauge <= 0){
        return;
    }
    else 
        car.fuelGauge -= FUEL_STEP;
    if(car.curSpeed+ACC_STEP >= MAX_SPD){
        car.curSpeed = MAX_SPD;
        return;
    }
    car.curSpeed += ACC_STEP;
}

void Brake(Car &car){
    if (car.curSpeed<BRK_STEP){
        car.curSpeed = 0;
        return;
    }
    car.curSpeed -= BRK_STEP;
}

int main(void){
    Car run99 = {"run99", 100, 0};
    Accel(run99);
    Accel(run99);
    ShowCarState(run99);
    Brake(run99);
    ShowCarState(run99);

    Car spd77 = {"spd77", 100, 0};
    Accel(spd77);
    Brake(spd77);
    ShowCarState(spd77);
    return 0;

}
