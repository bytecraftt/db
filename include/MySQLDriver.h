#pragma once

#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/statement.h>

#include "Driver.h"

class MySQLDriver : public Driver
{
public:
    MySQLDriver();
    virtual ~MySQLDriver();

    virtual void Connect(const std::string &host, const std::string &user, const std::string &password);
    virtual void Disconnect();

    virtual bool Connected() const;

private:
    sql::mysql::MySQL_Driver *driver_;
    sql::Connection *connection_;
};