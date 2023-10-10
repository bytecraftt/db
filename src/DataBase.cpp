#include "DataBase.h"

DataBase::DataBase(std::unique_ptr<Driver> driver, const std::string &host, const std::string &user, const std::string &password) : driver_(std::move(driver))
{
    Trace trace(Level::DEBUG, __func__);

    driver_->Connect(host, user, password);

    assert((void("Database connection failed"), driver_->Connected()));
}

DataBase::~DataBase()
{
    Trace trace(Level::DEBUG, __func__);
    
    driver_->Disconnect();
}