#include <iostream>
#include <string>
using namespace std;

class Item {
protected:
    string name;
public:
    Item(const string& name) : name(name) {}
    virtual void prepare() = 0;
};

// Burger class
class Burger : public Item {
public:
    Burger(const string& name) : Item(name) {}
    void prepare() override {
        cout << name << " is being prepared." << endl;
    }
};

// Cheeseburger class
class Cheeseburger : public Burger {
public:
    Cheeseburger() : Burger("Cheeseburger") {}
    void prepare() override {
        cout << "Cheeseburger is being prepared." << endl;
    }
};

// VeggieBurger class
class VeggieBurger : public Burger {
public:
    VeggieBurger() : Burger("Veggie Burger") {}
    void prepare() override {
        cout << "Veggie Burger is being prepared." << endl;
    }
};

// ItemFactory class
class ItemFactory {
public:
    static Item* createItem(const string& type) {
        if (type == "burger") {
            return new Burger("Burger");
        } else if (type == "cheeseburger") {
            return new Cheeseburger();
        } else if (type == "veggieburger") {
            return new VeggieBurger();
        } else {
            return nullptr;
        }
    }
};

// FastFoodStore class
class FastFoodStore {
private:
    ItemFactory itemFactory;
public:
    Item* orderItem(const string& type) {
        Item* item = ItemFactory::createItem(type);
        if (item) {
            item->prepare();
        } else {
            cout << "Invalid item type." << endl;
        }
        return item;
    }
};

int main() {
    FastFoodStore store;

    Item* burger = store.orderItem("burger");
    Item* cheeseburger = store.orderItem("cheeseburger");
    Item* veggieburger = store.orderItem("veggieburger");


    return 0;
}
