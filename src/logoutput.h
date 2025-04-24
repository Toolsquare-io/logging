#pragma once
#include <stdint.h>
#include "logginglevels.h"
#include "logOutputLogger.h"
#ifdef customSubsystems
#include "./mysubsystems.h"
#else
#include "subsystems.h"
#endif   

// represents a destination to which we can send logging output, such as serial port, network, SD card, MQTT Broker, etc.

class logOutput {
  public:
    explicit logOutput();

    void setOutputDestination(bool (*aFunction)(const char *));                 // sets a pointer to a function handling the output of the logging to eg serial, network or file on SD card, etc.
    void setOutputFunction(bool (*aFunction)(const char *));                    // sets a pointer to a function handling the output of the logging to eg serial, network or file on SD card, etc.
    void setOutputClass(logOutputLogger* aClass);                               // sets a pointer to a class handling the output of the logging to eg serial, network or file on SD card, etc.
    bool isActive() const;                                                      //
    void setFormattedOutput(bool newSetting);                                   // set output formatting
    bool isFormattedOutput() const;                                             // check wether the output should be formatted
    void setColoredOutput(bool newSetting);                                     // set the colorize output option
    bool isColoredOutput() const;                                               //
    void setIncludeTimestamp(bool newSetting);                                  // set the includeTimestamp option
    bool hasTimestampIncluded() const;                                          //
    void setLoggingLevel(loggingLevel newLevel);                                // set the loggingLevel for a all subsystem
    void setLoggingLevel(subSystem theSubSystem, loggingLevel newLevel);        // set the loggingLevel for a given subsystem
    loggingLevel getLoggingLevel(subSystem theSubSystem) const;                 // returns the current loggingLevel for given subsystem
    bool write(const char *, const loggingLevel logLevel) const;                // send cstyle string to the output

  private:
    bool (*writeOutput)(const char *){nullptr};                                                                 // pointer to function outputting the logged data - 1 goes to eg serial port
    logOutputLogger* writeOutputClass = nullptr;                                                                // pointer to class outputting the logged data - 1 goes to eg serial port
    bool formattedOutput{false};                                                                                // does this output wants formatting
    bool colorOutput{false};                                                                                    // does this output wants colorization
    bool addTimestamp{false};                                                                                   // does this output wants timestamps added
    loggingLevel theLoggingLevel[static_cast<uint8_t>(subSystem::nmbrOfSubsystems)]{loggingLevel::None};        // for each subsystem, the loggingLevel for this output
};
