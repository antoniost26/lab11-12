//
// Created by Antonio on 4/15/2022.
//
#include <string>
#include <iostream>

#ifndef LAB9_10_PRODUCT_H
#define LAB9_10_PRODUCT_H

class Product {
private:
    int id;
    std::string name;
    double price;
    int quantity;
public:
    /**
     * Constructor
     */
    Product();

    /**
     * Constructor
     * @param args arguments
     */
    Product(std::string args);

    /**
     * Constructor
     * @param id an id
     * @param name a name
     * @param price a price
     * @param quantity a quantity
     */
    Product(int id, std::string name, double price, int quantity);

    /**
     * copy constructor
     * @param product a product
     */
    Product(const Product &product);

    /**
     * destructor
     */
    ~Product();

    /**
     * getter for id
     * @return id
     */
    int getId() const;

    /**
     * getter for name
     * @return name
     */
    std::string getName() const;

    /**
     * getter for price
     * @return price
     */
    double getPrice() const;

    /**
     * getter for quantity
     * @return quantity
     */
    int getQuantity() const;

    /**
     * setter for id
     * @param id an id
     */
    void setId(int id);

    /**
     * setter for name
     * @param name a name
     */
    void setName(std::string name);

    /**
     * setter for price
     * @param price a price
     */
    void setPrice(double price);

    /**
     * setter for quantity
     * @param quantity a quantity
     */
    void setQuantity(int quantity);

    /**
     * Overload to << operator
     * @param os an output stream
     * @param product a product
     * @return the output stream
     */
    friend std::ostream &operator<<(std::ostream &os, const Product &product);

    /**
     * Overload to >> operator
     * @param is an input stream
     * @param product a product
     * @return the input stream
     */
    friend std::istream &operator>>(std::istream &is, Product &product);

    /**
     * Overload to == operator
     * @param product a product
     * @return true if they are equal, false otherwise
     */
    bool operator==(const Product &product) const;

    /**
     * Overload to != operator
     * @param product a product
     * @return true if they are not equal, false otherwise
     */
    bool operator!=(const Product &product) const;

    /**
     * Overload to < operator
     * @param product a product
     * @return true if the second product's price is greater than the first's, false otherwise
     */
    bool operator<(const Product &product) const;

    /**
     * Overload to > operator
     * @param product a product
     * @return true if the first product's price is greater than the second's, false otherwise
     */
    bool operator>(const Product &product) const;

    /**
     * Overload to <= operator
     * @param product a product
     * @return true if the second product's price is greater than or equal to the first's, false otherwise
     */
    bool operator<=(const Product &product) const;

    /**
     * Overload to >= operator
     * @param product a product
     * @return true if the first product's price is greater than or equal to the second's, false otherwise
     */
    bool operator>=(const Product &product) const;

    /**
     * Overload to = operator
     * @param product a product
     * @return a product
     */
    Product &operator=(const Product &product);

    /**
     * Formats entity to a string
     * @return a string
     */
    std::string toString();

    /**
     * Reads entity from a string
     * @param args
     */
    void fromString(std::string args);
};


#endif //LAB9_10_PRODUCT_H
