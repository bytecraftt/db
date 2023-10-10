#pragma once

#include <string>

#include "Trace.h"

class Driver
{
public:
    virtual ~Driver() = default;

    virtual void Connect(const std::string &host, const std::string &user, const std::string &password) = 0;
    virtual void Disconnect() = 0;

    virtual bool Connected() const = 0;
};