#include <iostream>
#include <string>

using namespace std;



class SportsCar{
    private:
    string brand;
    string model;
    bool isEngineOn;
    int currentSpeed;
    int currentGear;
    string tyre;

    public:
    SportsCar(string b,string m){
        this->brand = b;
        this->model = m;
        isEngineOn = false;
        currentSpeed = 0;
        currentGear = 0;
    }

    //getter and setter
    int getCurrentSpeed(){
        return this->currentSpeed;
    }
    string getTyre(){
        return this->tyre;
    }

    void setTyre(string tyre){
       // validation or checker
       this->tyre = tyre;
    }
    
    //behavior or Methods
    void startEngine(){
        isEngineOn=true;
        cout<<brand <<" "<<model << ": Engine start with a roar!"<< endl;
    }

    void shiftGear(int gear){
        if(!isEngineOn){
            cout<<brand <<" "<<model << ": Engine is off! Cannot shift gear."<< endl;
            return ;
        }
        currentGear  = gear;
        cout<<brand <<" "<<model << ": Shifted to gear "<<currentGear<< endl;
    }

    void accelerate(){
        if(!isEngineOn){
            cout<<brand <<" "<<model << ": Engine is off! cannot accelerate."<< endl;
            return;
        }
        currentSpeed+=20;
        cout<<brand <<" "<<model << ": Accelerating to  "<<currentSpeed<<" km/h"<< endl;
    }
    void brake(){
        currentSpeed -= 20;
        if(currentSpeed<0) currentSpeed = 0;
        cout<<brand <<" "<<model << ": Braking! Speed is now "<<currentSpeed <<" km/h "<< endl;
    }

    void stopEngine(){
        isEngineOn = false;
        currentGear = 0;
        currentSpeed = 0;
        cout<<brand <<" "<<model << ": Engine turned off. "<< endl;
    }

};

int main(){

    SportsCar* myCar = new SportsCar("Ford" , "Mustang");

    myCar->startEngine();
    myCar->shiftGear(1);
    myCar->accelerate();
    myCar->shiftGear(2);
    myCar->brake();
    myCar->stopEngine();

    //Setting arbitary value to speed.
    //myCar->currentSpeed = 500;  // if data not private

    //cout<<currentSpeed of myCar is set to be <<myCar->currentSpeed<<endl;

    cout<<myCar->getCurrentSpeed();

    delete myCar;

    return 0;
}