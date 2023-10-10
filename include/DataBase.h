#pragma once

#include "Driver.h"

class DataBase
{
public:
    DataBase(std::unique_ptr<Driver> driver, const std::string &host, const std::string &user, const std::string &password);
    ~DataBase();
    
private:
    std::unique_ptr<Driver> driver_;
};