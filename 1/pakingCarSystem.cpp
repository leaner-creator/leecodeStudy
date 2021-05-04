
/* 
�����һ��ͣ�������һ��ͣ��ϵͳ��ͣ�����ܹ������ֲ�ͬ��С�ĳ�λ�����к�С��ÿ�ֳߴ�ֱ��й̶���Ŀ�ĳ�λ��

����ʵ��?ParkingSystem?�ࣺ

ParkingSystem(int big, int medium, int small)?��ʼ��?ParkingSystem?�࣬���������ֱ��Ӧÿ��ͣ��λ����Ŀ��
bool addCar(int carType)?����Ƿ���?carType?��Ӧ��ͣ��λ��?carType?���������ͣ����У�С���ֱ�������?1��?2?��?3?��ʾ��һ����ֻ��ͣ��??carType?��Ӧ�ߴ��ͣ��λ�С����û�пճ�λ���뷵��?false?�����򽫸ó�ͣ�복λ������?true?��

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/design-parking-system
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/ 

/*���˼· 
������˽�б����������ֳߴ�ĳ�λ������������ʱ��ʼ����λ��������ÿ��ͣ������switch�жϳ��ͣ�
default��ֹ�û������������֣���Ӧ�����ö�Ӧ�ĺ�������Ӧ��λ�Ƿ��п��࣬���ҶԳ�λ��������
�����ӻ����Ժ�����ӳ����뿪ͣ��λ�Ĳ�����
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

bool ParkingSystem::addCar(int carType) //���ݳ���ͣ�� 
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
//���ֳ���ͣ���������� 
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
	std::cout<<parkingSystem->addCar(1)<<std::endl; // ���� true ����Ϊ�� 1 ���յĴ�λ
	std::cout<<parkingSystem->addCar(2)<<std::endl; // ���� true ����Ϊ�� 1 ���յ��г�λ
	std::cout<<parkingSystem->addCar(3)<<std::endl; // ���� false ����Ϊû�пյ�С��λ
	std::cout<<parkingSystem->addCar(1)<<std::endl;
 } 
