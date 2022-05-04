//
// Created by Antonio on 4/22/2022.
//
#include "../Domain/Product.h"
#include "../Repository/IRepo.h"
#include "../Domain/MyException.h"
#include <algorithm>

#ifndef LAB9_10_PRODUCTVALIDATOR_H
#define LAB9_10_PRODUCTVALIDATOR_H


class ProductValidator {
private:
    Product product;
    IRepo<Product> &repo;
public:
    /**
     * Constructor
     * @param _repo product repository
     */
    explicit ProductValidator(IRepo<Product> &_repo) : repo{_repo} {};

    /**
     * Validates a product
     */
    void validate();

    /**
     * Sets the product
     * @param other a product
     */
    void setProduct(Product other) { this->product = other; };

    /**
     * Checks to see if the product exists in the repository
     * @return true if it exists, false otherwise
     */
    bool doesExit();

    /**
     * Validates the product's name, price and quantity
     */
    void update();
};


#endif //LAB9_10_PRODUCTVALIDATOR_H
