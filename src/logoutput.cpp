#include "logoutput.h"

logOutput::logOutput() {}

bool logOutput::isActive() const {
    return writeOutput != nullptr || writeOutputClass != nullptr;
}

void logOutput::setLoggingLevel(loggingLevel newLevel) {
    for (uint8_t i = 0; i < static_cast<uint8_t>(subSystem::nmbrOfSubsystems); i++) {
        theLoggingLevel[i] = newLevel;
    }
}

void logOutput::setLoggingLevel(subSystem theSubSystem, loggingLevel newLevel) {
    theLoggingLevel[static_cast<uint8_t>(theSubSystem)] = newLevel;
}

loggingLevel logOutput::getLoggingLevel(subSystem theSubSystem) const {
    return theLoggingLevel[static_cast<uint8_t>(theSubSystem)];
}

void logOutput::setFormattedOutput(bool newSetting) {
    formattedOutput = newSetting;
}

bool logOutput::isFormattedOutput() const {
    return formattedOutput;
}

void logOutput::setColoredOutput(bool newSetting) {
    colorOutput = newSetting;
}

void logOutput::setIncludeTimestamp(bool newSetting) {
    addTimestamp = newSetting;
}

void logOutput::setOutputDestination(bool (*aFunction)(const char *)) {
    writeOutput = aFunction;
}

void logOutput::setOutputFunction(bool (*aFunction)(const char *)) {
    writeOutput = aFunction;
}

void logOutput::setOutputClass(logOutputLogger* aClass) {
    writeOutputClass = aClass;
}

bool logOutput::write(const char *theContents, const loggingLevel logLevel) const {
    if (writeOutputClass  != nullptr) {
        return (*writeOutputClass).output(theContents, logLevel);
    } else {
        return (*writeOutput)(theContents);
    }
}

bool logOutput::isColoredOutput() const {
    return colorOutput;
}

bool logOutput::hasTimestampIncluded() const {
    return addTimestamp;
}
