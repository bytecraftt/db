#include "MySQLDriver.h"

MySQLDriver::MySQLDriver() : driver_(sql::mysql::get_mysql_driver_instance()), connection_(nullptr)
{
    Trace trace(Level::DEBUG, __func__);
}

MySQLDriver::~MySQLDriver()
{
    Trace trace(Level::DEBUG, __func__);
}

void MySQLDriver::Connect(const std::string &host, const std::string &user, const std::string &password)
{
    Trace trace(Level::DEBUG, __func__);

    if (Connected())
    {
        Disconnect();
    }

    connection_ = driver_->connect(host, user, password);
    //connection_->setSchema(schema);
}

void MySQLDriver::Disconnect()
{
    Trace trace(Level::DEBUG, __func__);

    if (!Connected())
    {
        throw std::runtime_error(Trace(Level::ERROR, "Disconnect is not possible"));
    }

    delete connection_;
}

bool MySQLDriver::Connected() const
{
    Trace trace(Level::DEBUG, __func__);
    
    return connection_ && connection_->isValid();
}