#pragma once
#include "logginglevels.h"

class logOutputLogger {
public:
    virtual ~logOutputLogger() = default;
    virtual bool output(const char *, const loggingLevel) = 0;
};
