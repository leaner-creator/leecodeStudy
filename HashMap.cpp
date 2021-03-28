/*
不使用任何内建的哈希表库设计一个哈希映射（HashMap）。

实现 MyHashMap 类：

MyHashMap() 用空映射初始化对象
void put(int key, int value) 向 HashMap 插入一个键值对 (key, value) 。如果 key 已经存在于映射中，则更新其对应的值 value 。
int get(int key) 返回特定的 key 所映射的 value ；如果映射中不包含 key 的映射，返回 -1 。
void remove(key) 如果映射中存在 key 的映射，则移除 key 和它所对应的 value 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/design-hashmap
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/ 


/*
利用两个vector<int>分别存储hash的键和值，通过下标完成关系的映射。
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
void MyHashMap::put(int key, int value) //根据key的 hashKey 找到对应得下标i，在 hashValue[i]里存取value 
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
int MyHashMap::get(int key)//根据key的 hashKey 找到对应得下标i，返回 hashValue[i]里存取的value 
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
void MyHashMap::remove(int key) //根据key的 hashKey 找到对应得下标i，移除 hashKey[i]和hashValue[i] 
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
	myHashMap->put(1, 1); // myHashMap 现在为 [[1,1]]
	myHashMap->put(2, 2); // myHashMap 现在为 [[1,1], [2,2]]
	myHashMap->get(1);    // 返回 1 ，myHashMap 现在为 [[1,1], [2,2]]
	myHashMap->get(3);    // 返回 -1（未找到），myHashMap 现在为 [[1,1], [2,2]]
	myHashMap->put(2, 1); // myHashMap 现在为 [[1,1], [2,1]]（更新已有的值）
	myHashMap->get(2);    // 返回 1 ，myHashMap 现在为 [[1,1], [2,1]]
	myHashMap->remove(2); // 删除键为 2 的数据，myHashMap 现在为 [[1,1]]
	myHashMap->get(2);    // 返回 -1（未找到），myHashMap 现在为 [[1,1]]

}
