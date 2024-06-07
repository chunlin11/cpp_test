// 代理模式
// 时间：2024/06/07
// 作者：@coonceal
#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

// 抽象主题
class Subject {
public:
    virtual void Request() = 0;
};

// 真实主题
class RealSubject : public Subject {
public:
    void Request() override {
        cout << "RealSubject: Handling request.\n";
    }
};

// 代理
class Proxy : public Subject {
private:
    RealSubject *real_subject_;

    bool CheckAccess() {
        // 一些真实的检查
        cout << "Proxy: Checking access prior to firing a real request.\n";
        return true;
    }

    void LogAccess() {
        // 一些真实的日志记录
        cout << "Proxy: Logging the time of request.\n";
    }

public:
    Proxy(RealSubject *real_subject) : real_subject_(new RealSubject(*real_subject)) {}

    ~Proxy() {
        delete real_subject_;
    }

    void Request() override {
        if (this->CheckAccess()) {
            this->real_subject_->Request();
            this->LogAccess();
        }
    }
};

// 测试
int main() {
    cout << "Client: Executing the client code with a real subject:\n";
    RealSubject *real_subject = new RealSubject;
    real_subject->Request();

    cout << "\n";

    cout << "Client: Executing the same client code with a proxy:\n";
    Proxy *proxy = new Proxy(real_subject);
    proxy->Request();

    delete real_subject;
    delete proxy;

    return 0;
}