//
// Created by Antonio on 4/19/2022.
//
#include <vector>
#include "../Domain/MyException.h"
#include "IRepo.h"

#ifndef LAB9_10_REPOSITORY_H
#define LAB9_10_REPOSITORY_H

template <class T>
class MemoryRepository: public IRepo<T> {
private:
    std::vector<T> entities;

    /**
     * Gets the position of an entity in the repository
     * @param _id entity id
     * @return entity position in repository
     */
    int getPosition(int _id) {
        int index = 0;
        for (const auto& it : this->entities) {
            if (it.getId() == _id) {
                return index;
            }
            index++;
        }
        return -1;
    };
public:
    /**
     * default constructor
     */
    MemoryRepository() = default;

    /**
     * constructor with a given vector of entities
     */
    explicit MemoryRepository(std::vector<T> _entities) {
        this->entities = _entities;
    };

    /**
     * copy constructor
     * @param _repo other repository
     */
    MemoryRepository(MemoryRepository<T> const &_repo) {
        this->entities = _repo.entities;
    };

    /**
     * overload assignment operator
     * @param _repo other repository
     * @return self
     */
    MemoryRepository<T> &operator=(MemoryRepository<T> const &_repo) {
        this->entities = _repo.entities;
        return *this;
    };

    /**
     * default destructor
     */
    ~MemoryRepository() = default;

    /**
     * Adds an entity to repository.
     * @param entity an entity to be added.
     */
    void add(T entity) override {
        this->entities.push_back(entity);
    }

    /**
     * Removes an entity from repository.
     * @param entity an entity to be removed.
     */
    void remove(int _id) override {
        if (getPosition(_id) != -1) {
            this->entities.erase(this->entities.begin() + getPosition(_id));
        }
    }

    /**
     * Updates an entity in repository.
     * @param entity an entity to be updated.
     */
    void update(T entity) override {
        for (auto &e : this->entities) {
            if (e.getId() == entity.getId()) {
                e = entity;
            }
        }
    }

    /**
     * Gets all entities from repository.
     * @return a vector of entities.
     */
    std::vector<T> getAll() override {
        return this->entities;
    }

    /**
     * Gets an entity from repository.
     * @param id an id of an entity.
     * @return an entity.
     */
    T get(int _id) override {
        for (auto it : this->entities) {
            if (it.getId() == _id) {
                return it;
            }
        }
        throw MyException((char*)("No element with id " + std::to_string(_id)).c_str());;
    }

    /**
     * Gets the size of repository.
     * @return the size of repository.
     */
    int getSize() override {
        return this->entities.size();
    }
};


#endif //LAB9_10_REPOSITORY_H
