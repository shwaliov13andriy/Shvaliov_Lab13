#include <iostream>
#include <string>

using namespace std;

class Product {
protected:
    string name;
    double price;

public:
    Product(const string& n, double p) : name(n), price(p) {}
    virtual ~Product() {}
    string getName() const {
        return name;
    }
    void setName(const string& n) {
        name = n;
    }
    double getPrice() const {
        return price;
    }
    void setPrice(double p) {
        price = p;
    }
    virtual double getFinalPrice() const = 0;
};
class Discountable {
public:
    virtual double applyDiscount(double price) const = 0;
};
class Book : public Product, public Discountable {
public:
    Book(const string& n, double p) : Product(n, p) {}

    double applyDiscount(double price) const override {
        return price * 0.5;
    }
    double getFinalPrice() const override {
        return applyDiscount(price);
    }
};
class Clip : public Product, public Discountable {
public:
    Clip(const string& n, double p) : Product(n, p) {}

    double applyDiscount(double price) const override {
        if (price > 5.0) {
            return price - 5.0;
        } else {
            return price;
        }
    }
    double getFinalPrice() const override {
        return applyDiscount(price);
    }
};
int main() {
    Book book("C++ Programming for teapots and Andriys", 1000.0);
    Book therapy("Psycology therapy", 0.0);

    Clip paperclip1("Golden paperclip", 10000.0);
    Clip paperclip2("galvanite square steel", 1.0);
    cout << "Name: " << book.getName() << ", Original Price: " << book.getPrice() << ", Price after discount: " << book.getFinalPrice() << endl;
    cout << "Name: " << therapy.getName() << ", Original Price: " << therapy.getPrice() << ", Price after discount: " << therapy.getFinalPrice() << endl;

    cout << "Name: " << paperclip1.getName() << ", Original Price: " << paperclip1.getPrice() << ", Price after discount: " << paperclip1.getFinalPrice() << endl;
    cout << "Name: " << paperclip2.getName() << ", Original Price: " << paperclip2.getPrice() << ", Price after discount: " << paperclip2.getFinalPrice() << endl;

    return 0;
}
