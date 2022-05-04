//
// Created by Antonio on 4/15/2022.
//

#include "Product.h"

#include <utility>
#include <vector>
#include <sstream>

Product::Product() {
    this->id = -1;
    this->name = "";
    this->price = 0;
    this->quantity = 0;
}

Product::Product(int _id, std::string _name, double _price, int _quantity) {
    this->id = _id;
    this->name = std::move(_name);
    this->price = _price;
    this->quantity = _quantity;
}

Product::Product(const Product &product) {
    this->id = product.id;
    this->name = product.name;
    this->price = product.price;
    this->quantity = product.quantity;
}

Product::~Product() = default;

int Product::getId() const {
    return this->id;
}

std::string Product::getName() const {
    return this->name;
}

double Product::getPrice() const {
    return this->price;
}

void Product::setId(int _id) {
    this->id = _id;
}

void Product::setName(std::string _name) {
    this->name = _name;
}

void Product::setPrice(double _price) {
    this->price = _price;
}

bool Product::operator==(const Product &product) const {
    return (this->id == product.id && this->name == product.name &&
            this->price == product.price && this->quantity == product.quantity);
}

bool Product::operator!=(const Product &product) const {
    return !(*this == product);
}

bool Product::operator<(const Product &product) const {
    return (this->price < product.price);
}

bool Product::operator>(const Product &product) const {
    return !(*this < product);
}

bool Product::operator<=(const Product &product) const {
    return (*this < product || *this == product);
}

bool Product::operator>=(const Product &product) const {
    return !(*this < product || *this != product);
}

Product &Product::operator=(const Product &product) {
    this->id = product.id;
    this->name = product.name;
    this->price = product.price;
    this->quantity = product.quantity;
    return *this;
}

std::ostream &operator<<(std::ostream &os, const Product &product) {
    os << "(id " << product.getId() << ") - [name: '" << product.getName() <<
       "', price: " << product.getPrice() << ", quantity: " << product.getQuantity() << "]"
       << std::endl;
    return os;
}

std::istream &operator>>(std::istream &is, Product &product) {
    is >> product.id >> product.name >> product.price >> product.quantity;
    return is;
}

int Product::getQuantity() const {
    return this->quantity;
}

void Product::setQuantity(int _quantity) {
    this->quantity = _quantity;
}

std::string Product::toString() {
    return std::to_string(this->id) + " " + this->name + " " + std::to_string(this->price) + " " +
           std::to_string(this->quantity) + ",";
}

void Product::fromString(std::string args) {
    std::vector<std::string> elements;
    std::stringstream ss(args);
    std::string item;
    while (getline(ss, item, ' ')) {
        elements.push_back(item);
    }
    if (elements.size() == 4) {
        std::stringstream i(elements[0]);
        i >> this->id;
        std::stringstream n(elements[1]);
        n >> this->name;
        std::stringstream p(elements[2]);
        p >> this->price;
        std::stringstream q(elements[3]);
        q >> this->quantity;
    }
}

Product::Product(std::string args) {
    this->fromString(args);
}
