// 实现享元模式
#include <iostream>
#include <map>
using namespace std;

// 享元基类
class Flyweight {
public:
    Flyweight() {}
    virtual ~Flyweight() {}

    virtual void Operation() = 0;
};

// 具体享元类
class ConcreteFlyweight : public Flyweight {
public:
    ConcreteFlyweight() {}
    ~ConcreteFlyweight() {}

    void Operation() {
        cout << "ConcreteFlyweight Operation" << endl;
    }
};

// 不需要共享的享元类
class UnsharedConcreteFlyweight : public Flyweight {
public:
    UnsharedConcreteFlyweight() {}
    ~UnsharedConcreteFlyweight() {}

    void Operation() {
        cout << "UnsharedConcreteFlyweight Operation" << endl;
    }
};

// 创建一个享元工厂
class FlyweightFactory {
public:
    FlyweightFactory() {
        InitFactory();
    }
    ~FlyweightFactory() {}

    // 初始化享元工厂
    void InitFactory() {
        m_flyweightMap["key1"] = new ConcreteFlyweight();
        m_flyweightMap["key2"] = new ConcreteFlyweight();
    }
    // 获取享元对象
    Flyweight* GetFlyweight(string key) {
        if (m_flyweightMap.find(key) == m_flyweightMap.end()) {
            m_flyweightMap[key] = new ConcreteFlyweight();
        }
        return m_flyweightMap[key];
    }


private:
    map<string, Flyweight*> m_flyweightMap;
};
// 
int main() {
    FlyweightFactory* factory = new FlyweightFactory();
    factory->InitFactory();
    Flyweight* flyweight = factory->GetFlyweight("key1");
    flyweight->Operation();
}