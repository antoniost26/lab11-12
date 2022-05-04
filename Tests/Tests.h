//
// Created by Antonio on 4/16/2022.
//
#include "../Domain/Product.h"
#include "../Repository/MemoryRepository.h"
#include "../ProductValidator/ProductValidator.h"
#include "../ProductService/ProductService.h"
#include "../Repository/FileRepository.h"
#include <cassert>
#include <chrono>
#include <thread>

#ifndef LAB9_10_TESTS_H
#define LAB9_10_TESTS_H

class Tests {
public:
    static void testProduct() {
        Product p1(1, "p1", 1, 10);
        Product p2(2, "p2", 2, 11);
        Product p3(3, "p3", 3, 12);
        assert(p1.getId() == 1);
        assert(p1.getName() == "p1");
        assert(p1.getPrice() == 1);
        assert(p2.getId() == 2);
        assert(p2.getName() == "p2");
        assert(p2.getPrice() == 2);
        assert(p3.getId() == 3);
        assert(p3.getName() == "p3");
        assert(p3.getPrice() == 3);
    }

    static void testMemoryRepository() {
        MemoryRepository<Product> r;
        IRepo<Product> &repo = r;
        Product p1(1, "p1", 1, 10);
        Product p2(2, "p2", 2, 11);
        Product p3(3, "p3", 3, 12);
        repo.add(p1);
        assert(repo.getSize() == 1);
        repo.add(p2);
        assert(repo.getSize() == 2);
        repo.add(p3);
        assert(repo.getSize() == 3);
        assert(repo.get(1) == p1);
        assert(repo.get(2) == p2);
        assert(repo.get(3) == p3);
        std::vector<Product> v = repo.getAll();
        assert(v[0] == p1);
        assert(v[1] == p2);
        assert(v[2] == p3);
        repo.remove(p1.getId());
        assert(repo.getSize() == 2);
        repo.remove(p2.getId());
        assert(repo.getSize() == 1);
        repo.remove(p3.getId());
        assert(repo.getSize() == 0);
    }

    static void testFileRepository() {
        FileRepository<Product> r("./test.txt");
        IRepo<Product> &repo = r;
        Product p1(1, "p1", 1, 10);
        Product p2(2, "p2", 2, 11);
        Product p3(3, "p3", 3, 12);
        repo.add(p1);
        assert(repo.getSize() == 1);
        repo.add(p2);
        assert(repo.getSize() == 2);
        repo.add(p3);
        assert(repo.getSize() == 3);
        assert(repo.get(1) == p1);
        assert(repo.get(2) == p2);
        assert(repo.get(3) == p3);
        std::vector<Product> v = repo.getAll();
        assert(v[0] == p1);
        assert(v[1] == p2);
        assert(v[2] == p3);

        repo.update(Product(1, "p1test", 1, 10));
        assert(repo.get(1).getName() == "p1test");

        std::vector<Product> testVector;
        std::string line;
        std::ifstream myFile("./test.txt");
        while (getline(myFile, line)) {
            Product p(line);
            testVector.push_back(p);
        }
        assert(testVector[0].getName() == "p1test");
        assert(testVector[0].getPrice() == 1);
        assert(testVector[0].getId() == 1);
        assert(testVector[0].getQuantity() == 10);
        assert(testVector[1] == p2);
        assert(testVector[2] == p3);

        repo.remove(p1.getId());
        assert(repo.getSize() == 2);
        repo.remove(p2.getId());
        assert(repo.getSize() == 1);
        repo.remove(p3.getId());
        assert(repo.getSize() == 0);

        remove("./test.txt");
    }

    static void testService() {
        FileRepository<Product> r("./test.txt");
        IRepo<Product> &repo = r;
        ProductValidator v(repo);
        ProductService s(repo, v);
        Product p1(1, "p1", 1, 10);
        Product p2(2, "p2", 2, 11);
        Product p3(3, "p3", 3, 12);
        s.addProduct(p1);
        assert(s.getSize() == 1);
        s.addProduct(p2);
        assert(s.getSize() == 2);
        s.addProduct(p3);
        assert(s.getSize() == 3);
        assert(s.getProduct(1) == p1);
        assert(s.getProduct(2) == p2);
        assert(s.getProduct(3) == p3);
        std::vector<Product> v1 = s.getAll();
        assert(v1[0] == p1);
        assert(v1[1] == p2);
        assert(v1[2] == p3);
        s.updateProduct(Product(1, "p1test", 2, 11));
        assert(s.getProduct(1).getName() == "p1test");
        assert(s.getProduct(1).getPrice() == 2);
        assert(s.getProduct(1).getId() == 1);
        assert(s.getProduct(1).getQuantity() == 11);
        assert(s.getProduct(1) != p1);
        s.updateProduct(2, 19.99);
        assert(s.getProduct(2).getPrice() == 19.99);
        assert(s.getProduct(2).getId() == 2);
        assert(s.getProduct(2).getQuantity() == 11);
        assert(s.getProduct(2) != p2);
        s.updateProduct(3, 20);
        assert(s.getProduct(3).getPrice() == 3);
        assert(s.getProduct(3).getId() == 3);
        assert(s.getProduct(3).getQuantity() == 20);
        assert(s.getProduct(3) != p3);
        s.removeProduct(p1.getId());
        assert(repo.getSize() == 2);
        s.removeProduct(p2.getId());
        assert(repo.getSize() == 1);
        s.removeProduct(p3.getId());
        assert(repo.getSize() == 0);
        remove("./test.txt");
    }

    static void testAll() {
        std::cout << "Running tests..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        Tests::testProduct();
        Tests::testMemoryRepository();
        Tests::testFileRepository();
        Tests::testService();
        std::cout << "All tests passed!" << std::endl;
    }
};

#endif //LAB9_10_TESTS_H
