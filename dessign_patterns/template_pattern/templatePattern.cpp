// 模板方法模式

#include <iostream>
using namespace std;

// 抽象类
class AbstractClass {
public:
    AbstractClass() {}
    virtual ~AbstractClass() {}

    // 模板方法
    void TemplateMethod() {
        PrimitiveOperation1();
        PrimitiveOperation2();
    }

    // 基本方法
    virtual void PrimitiveOperation1() = 0;
    virtual void PrimitiveOperation2() = 0;
};

// 具体类
class ConcreteClassA : public AbstractClass {
public:
    ConcreteClassA() {}
    ~ConcreteClassA() {}

    void PrimitiveOperation1() {
        cout << "ConcreteClassA PrimitiveOperation1" << endl;
    }

    void PrimitiveOperation2() {
        cout << "ConcreteClassA PrimitiveOperation2" << endl;
    }
};



int main() {
    AbstractClass* p1 = new ConcreteClassA();
    p1->TemplateMethod();
    delete p1;

    return 0;
}
