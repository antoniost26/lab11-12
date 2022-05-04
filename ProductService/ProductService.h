//
// Created by Antonio on 4/16/2022.
//
#include <utility>

#include "../Domain/Product.h"
#include "../Repository/MemoryRepository.h"
#include "../ProductValidator/ProductValidator.h"

#ifndef LAB9_10_PRODUCTSERVICE_H
#define LAB9_10_PRODUCTSERVICE_H


class ProductService {
private:
    IRepo<Product> &repo;
    ProductValidator validator;
public:
    /**
     * Constructor for the ProductService class
     * @param otherRepository a repository
     * @param _validator a prduct validator
     */
    explicit ProductService(IRepo<Product> &otherRepository, ProductValidator _validator) : repo{otherRepository},
                                                                                            validator{std::move(
                                                                                                    _validator)} {};

    /**
     * Destructor
     */
    ~ProductService() = default;

    /**
     * Adds a product to the repository
     * @param p a product
     */
    void addProduct(Product p);

    /**
     * Removes a product from the repository
     * @param _id product id
     */
    void removeProduct(int _id);

    /**
     * Updates a product in the repository
     * @param p a product
     */
    void updateProduct(Product p);

    /**
     * Updates a product in the repository
     * @param _id product id
     * @param _quantity product quantity
     */
    void updateProduct(int _id, int _quantity);

    /**
     * Updates a product in the repository
     * @param _id product id
     * @param _name product name
     */
    void updateProduct(int _id, std::string _name);

    /**
     * Updates a product in the repository
     * @param _id product id
     * @param price product price
     */
    void updateProduct(int _id, double price);

    /**
     * Gets all products from the repository
     * @return a vector containing all products
     */
    std::vector<Product> getAll();

    /**
     * Gets repository size
     * @return repository size
     */
    int getSize();

    /**
     * Gets a product from the repository
     * @param i product id
     * @return a product
     */
    Product getProduct(int i);
};


#endif //LAB9_10_PRODUCTSERVICE_H
