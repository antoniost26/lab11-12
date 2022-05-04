//
// Created by Antonio on 4/16/2022.
//

#include "ProductService.h"

void ProductService::addProduct(Product p) {
    this->validator.setProduct(p);
    this->validator.validate();
    this->repo.add(p);
}

void ProductService::removeProduct(int _id) {
    this->repo.remove(_id);
}

void ProductService::updateProduct(Product p) {
    this->validator.setProduct(p);
    this->validator.update();
    this->repo.update(p);
}

std::vector<Product> ProductService::getAll() {
    return this->repo.getAll();
}

int ProductService::getSize() {
    return this->repo.getSize();
}

Product ProductService::getProduct(int i) {
    return this->repo.get(i);
}

void ProductService::updateProduct(int _id, int _quantity) {
    Product newProduct = this->repo.get(_id);
    newProduct.setQuantity(_quantity);
    this->validator.setProduct(newProduct);
    this->validator.update();
    this->repo.update(newProduct);
}

void ProductService::updateProduct(int _id, std::string _name) {
    Product newProduct = this->repo.get(_id);
    newProduct.setName(_name);
    this->validator.setProduct(newProduct);
    this->validator.update();
    this->repo.update(newProduct);
}

void ProductService::updateProduct(int _id, double price) {
    Product newProduct = this->repo.get(_id);
    newProduct.setPrice(price);
    this->validator.setProduct(newProduct);
    this->validator.update();
    this->repo.update(newProduct);
}
