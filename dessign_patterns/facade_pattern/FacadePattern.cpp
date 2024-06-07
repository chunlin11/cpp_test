// 代理模式
// 时间：2024/06/07
// 作者：@coonceal

#include <iostream>
using namespace std;

// 定义一个基类
class System {
public:
    virtual void Start() = 0;
    virtual void Stop() = 0;
};

// 定义一个子类:程序1
class Program1 : public System {
public:
    void Start() override {
        cout << "Program1: Start.\n";
    }

    void Stop() override {
        cout << "Program1: Stop.\n";
    }
};

// 定义一个子类:程序2
class Program2 : public System {
public:
    void Start() override {
        cout << "Program2: Start.\n";
    }

    void Stop() override {
        cout << "Program2: Stop.\n";
    }
};

// 定义一个外观类
class Facade {
private:
    System *program1_;
    System *program2_;

public:
    Facade() {
        program1_ = new Program1;
        program2_ = new Program2;
    }

    ~Facade() {
        delete program1_;
        delete program2_;
    }

    void Start() {
        program1_->Start();
        program2_->Start();
    }

    void Stop() {
        program1_->Stop();
        program2_->Stop();
    }
};

int main() {
    Facade *facade = new Facade;
    facade->Start();
    facade->Stop();
    delete facade;
    return 0;
}