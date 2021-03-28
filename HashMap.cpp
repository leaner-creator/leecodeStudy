/*
��ʹ���κ��ڽ��Ĺ�ϣ������һ����ϣӳ�䣨HashMap����

ʵ�� MyHashMap �ࣺ

MyHashMap() �ÿ�ӳ���ʼ������
void put(int key, int value) �� HashMap ����һ����ֵ�� (key, value) ����� key �Ѿ�������ӳ���У���������Ӧ��ֵ value ��
int get(int key) �����ض��� key ��ӳ��� value �����ӳ���в����� key ��ӳ�䣬���� -1 ��
void remove(key) ���ӳ���д��� key ��ӳ�䣬���Ƴ� key ��������Ӧ�� value ��

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/design-hashmap
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/ 


/*
��������vector<int>�ֱ�洢hash�ļ���ֵ��ͨ���±���ɹ�ϵ��ӳ�䡣
*/
#include <iostream>
#include<vector>

using namespace std;

class MyHashMap {
public:
    MyHashMap();
    void put(int key, int value) ;
    int get(int key);
    void remove(int key);
private:
    vector<int> hashKey;
    vector<int> hashValue;
};

MyHashMap::MyHashMap() 
{
    hashKey.clear();
    hashValue.clear();
}
void MyHashMap::put(int key, int value) //����key�� hashKey �ҵ���Ӧ���±�i���� hashValue[i]���ȡvalue 
{
    for(int i=0;i<hashKey.size();i++)
    {
        if(key == hashKey.at(i))
        {
            hashValue[i]=value;
            return ;
        }
    } 
}
int MyHashMap::get(int key)//����key�� hashKey �ҵ���Ӧ���±�i������ hashValue[i]���ȡ��value 
{
    for(int i=0;i<hashKey.size();i++)
    {
        if(key == hashKey.at(i))
        {
            return hashValue.at(i);
        }
    }
    return -1;
}
void MyHashMap::remove(int key) //����key�� hashKey �ҵ���Ӧ���±�i���Ƴ� hashKey[i]��hashValue[i] 
{
        
    for(int i=0;i<hashKey.size();i++)
    {
	    if(key == hashKey.at(i))
        {
            hashKey.erase(hashKey.begin()+i);
            hashValue.erase(hashValue.begin()+i);
        }
    }
}
int main()
{
	MyHashMap *myHashMap = new MyHashMap();
	myHashMap->put(1, 1); // myHashMap ����Ϊ [[1,1]]
	myHashMap->put(2, 2); // myHashMap ����Ϊ [[1,1], [2,2]]
	myHashMap->get(1);    // ���� 1 ��myHashMap ����Ϊ [[1,1], [2,2]]
	myHashMap->get(3);    // ���� -1��δ�ҵ�����myHashMap ����Ϊ [[1,1], [2,2]]
	myHashMap->put(2, 1); // myHashMap ����Ϊ [[1,1], [2,1]]���������е�ֵ��
	myHashMap->get(2);    // ���� 1 ��myHashMap ����Ϊ [[1,1], [2,1]]
	myHashMap->remove(2); // ɾ����Ϊ 2 �����ݣ�myHashMap ����Ϊ [[1,1]]
	myHashMap->get(2);    // ���� -1��δ�ҵ�����myHashMap ����Ϊ [[1,1]]

}
