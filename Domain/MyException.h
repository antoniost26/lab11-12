//
// Created by Antonio on 5/4/2022.
//

#ifndef LAB9_10_MYEXCEPTION_H
#define LAB9_10_MYEXCEPTION_H


class MyException : std::exception {
private:
    const char *message;
public:
    /**
     * Constructor
     * @param message
     */
    MyException(const char *message) : message(message) {}

    /**
     * Getter for exception message
     * @return
     */
    const char *what() const noexcept override {
        return message;
    }
};


#endif //LAB9_10_MYEXCEPTION_H
