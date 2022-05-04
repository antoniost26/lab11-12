//
// Created by Antonio on 4/19/2022.
//
#include <vector>

#ifndef LAB9_10_IREPO_H
#define LAB9_10_IREPO_H

template<class T>
class IRepo {
public:
    virtual void add(T t) = 0;

    virtual void remove(int _id) = 0;

    virtual void update(T t) = 0;

    virtual T get(int _id) = 0;

    virtual std::vector<T> getAll() = 0;

    virtual int getSize() = 0;
};

#endif //LAB9_10_IREPO_H
