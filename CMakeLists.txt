cmake_minimum_required(VERSION 3.21)
project(lab11_12)

set(CMAKE_CXX_STANDARD 14)

add_executable(lab11_12 main.cpp Domain/Product.cpp Domain/Product.h ProductService/ProductService.cpp ProductService/ProductService.h Tests/Tests.h Repository/MemoryRepository.h Repository/IRepo.h ProductValidator/ProductValidator.cpp ProductValidator/ProductValidator.h Repository/FileRepository.h VendingMachineUI/VendingMachineUI.cpp VendingMachineUI/VendingMachineUI.h Domain/MyException.h)