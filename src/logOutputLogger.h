#pragma once
#include "logginglevels.h"

class logOutputLogger {
public:
    virtual ~logOutputLogger() = default;
    virtual bool output(const char *, const loggingLevel) = 0;
    virtual bool debug(const char *) = 0;
    virtual bool info(const char *) = 0;
    virtual bool warning(const char *) = 0;
    virtual bool error(const char *) = 0;
};
