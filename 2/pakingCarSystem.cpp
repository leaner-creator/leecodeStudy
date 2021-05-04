
/* 
请你给一个停车场设计一个停车系统。停车场总共有三种不同大小的车位：大，中和小，每种尺寸分别有固定数目的车位。

请你实现?ParkingSystem?类：

ParkingSystem(int big, int medium, int small)?初始化?ParkingSystem?类，三个参数分别对应每种停车位的数目。
bool addCar(int carType)?检查是否有?carType?对应的停车位。?carType?有三种类型：大，中，小，分别用数字?1，?2?和?3?表示。一辆车只能停在??carType?对应尺寸的停车位中。如果没有空车位，请返回?false?，否则将该车停入车位并返回?true?。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/design-parking-system
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/ 

/*题解思路 
用三个私有变量代表三种尺寸的车位数量，创建类时初始化车位的数量，每次停车都用switch判断车型，
default防止用户输入其他数字；对应车型用对应的函数检查对应车位是否还有空余，并且对车位数操作。
这样子还可以后续添加车辆离开停车位的操作。
*/ 

#include <iostream>

class ParkingSystem {
public:
    ParkingSystem(int big, int medium, int small) ; 
    bool addCar(int carType) ;

private:
    bool bigCarPaking();
    bool mediumCarPaking();
    bool smallCarPaking();
private:
    int bigTypeNumb;
    int mediumTypeNumb;
    int smallTypeNumb;
};
ParkingSystem::ParkingSystem(int big, int medium, int small) 
{
    this->bigTypeNumb=big;
    this->mediumTypeNumb=medium;
    this->smallTypeNumb=small;
}

bool ParkingSystem::addCar(int carType) //根据车型停车 
{
    switch(carType)
    {
    case 1:return bigCarPaking();
            break;  
    case 2:return mediumCarPaking();
            break;
    case 3:return smallCarPaking();
            break;  
    default:return false;
    }

}
//三种车型停车操作函数 
bool ParkingSystem::bigCarPaking()
{
    if(this->bigTypeNumb > 0)
    {
        this->bigTypeNumb--;
        return true;
    }   
    else
    {
        return false;
    }

    }
bool ParkingSystem::mediumCarPaking()
{
    if(this->mediumTypeNumb > 0)
    {
        this->mediumTypeNumb--;
        return true;
    }   
    else
    {
        return false;
    }

}
bool ParkingSystem::smallCarPaking()
{
    if(this->smallTypeNumb > 0)
    {
        this->smallTypeNumb--;
        return true;
    }   
    else
    {
        return false;
    }
}

int main()
{
	ParkingSystem *parkingSystem = new ParkingSystem(1,1,0);
	std::cout<<parkingSystem->addCar(1)<<std::endl; // 返回 true ，因为有 1 个空的大车位
	std::cout<<parkingSystem->addCar(2)<<std::endl; // 返回 true ，因为有 1 个空的中车位
	std::cout<<parkingSystem->addCar(3)<<std::endl; // 返回 false ，因为没有空的小车位
	std::cout<<parkingSystem->addCar(1)<<std::endl;
 } 
