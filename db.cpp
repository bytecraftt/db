#include "DataBase.h"
#include "MySQLDriver.h"

int main(int argc, char **argv)
{
    Trace::SetFileName("db.txt");
    Trace::SetTraceLevelFlag(Level::ALL);
    std::unique_ptr<Driver> driver = std::make_unique<MySQLDriver>();
    DataBase db(std::move(driver), "localhost", "root", "12345678");

    return 0;
}