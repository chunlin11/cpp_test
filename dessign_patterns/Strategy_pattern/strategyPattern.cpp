#include <iostream>
#include <string>

// 抽象策略类
class Strategy {
public:
    virtual ~Strategy() {}
    virtual void AlgorithmInterface() = 0;
};

// 具体策略类A
class ConcreteStrategyA : public Strategy {
public:
    void AlgorithmInterface() override {
        std::cout << "Implementing Algorithm A" << std::endl;
    }
};

// 具体策略类B
class ConcreteStrategyB : public Strategy {
public:
    void AlgorithmInterface() override {
        std::cout << "Implementing Algorithm B" << std::endl;
    }
};

// 上下文
class Context {
private:
    Strategy* strategy;
public:
    Context(Strategy* strategy) : strategy(strategy) {}
    ~Context() {
        delete strategy;
    }
    void ContextInterface() {
        strategy->AlgorithmInterface();
    }
};

// 客户端代码
int main() {
    Strategy* strategyA = new ConcreteStrategyA();
    Context* context = new Context(strategyA);
    context->ContextInterface();

    delete context; // 注意适时释放资源

    Strategy* strategyB = new ConcreteStrategyB();
    context = new Context(strategyB);
    context->ContextInterface();

    delete context; // 注意适时释放资源

    return 0;
}