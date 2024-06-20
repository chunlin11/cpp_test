#include <vector>
#include <iostream>

class Component {
public:
    virtual void operation() = 0;
    virtual ~Component() {}
};

class Leaf : public Component {
public:
    void operation() override {
        std::cout << "Leaf operation.\n";
    }
};

class Composite : public Component {
private:
    std::vector<Component*> children;
public:
    void add(Component* component) {
        children.push_back(component);
    }

    void operation() override {
        for (Component* child : children) {
            child->operation();
        }
    }
};

int main() {
    Composite composite;
    composite.add(new Leaf());
    composite.add(new Leaf());
    composite.add(new Leaf());
    composite.operation();
}
