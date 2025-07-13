#include "data_loader.h"
#include <iostream>

DataLoader::DataLoader() {
    std::cout << "DataLoader created" << std::endl;
}

DataLoader::~DataLoader() {
    std::cout << "DataLoader destroyed" << std::endl;
}

void DataLoader::loadData() {
    std::cout << "Loading data..." << std::endl;
    // Data loading logic
}
