/*
 * Copyright (c) 2010-2011 OTClient <https://github.com/edubart/otclient>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef LOGGER_H
#define LOGGER_H

#include "../util/tools.h"
#include "../const.h"
#include <vector>
#include <functional>

struct LogMessage {
  LogMessage(LogLevel level, const std::string& message, std::size_t when) : level(level), message(message), when(when) { }
  LogLevel level;
  std::string message;
  std::size_t when;
};

class Logger
{
    typedef std::function<void(LogLevel, std::string, std::size_t)> OnLogCallback;

public:
    Logger();

    void log(LogLevel level, std::string message);
    void logFunc(LogLevel level, const std::string& message, std::string prettyFunction);

    void fireOldMessages();
    void setOnLog(const OnLogCallback& onLog) { m_onLog = onLog; }

private:
    std::vector<LogMessage> m_logMessages;
    OnLogCallback m_onLog;
    bool m_terminated;
};

extern Logger g_logger;

// specialized logging
#define logDebug(...) g_logger.log(LogDebug, fw::mkstr(__VA_ARGS__))
#define logInfo(...) g_logger.log(LogInfo, fw::mkstr(__VA_ARGS__))
#define logWarning(...) g_logger.log(LogWarning, fw::mkstr(__VA_ARGS__))
#define logError(...) g_logger.log(LogError, fw::mkstr(__VA_ARGS__))
#define logFatal(...) g_logger.log(LogFatal, fw::mkstr(__VA_ARGS__))

#define logTrace() g_logger.logFunc(LogDebug, "", __PRETTY_FUNCTION__)
#define logTraceDebug(...) g_logger.logFunc(LogDebug, fw::mkstr(__VA_ARGS__), __PRETTY_FUNCTION__)
#define logTraceInfo(...) g_logger.logFunc(LogInfo, fw::mkstr(__VA_ARGS__), __PRETTY_FUNCTION__)
#define logTraceWarning(...) g_logger.logFunc(LogWarning, fw::mkstr(__VA_ARGS__), __PRETTY_FUNCTION__)
#define logTraceError(...) g_logger.logFunc(LogError, fw::mkstr(__VA_ARGS__), __PRETTY_FUNCTION__)

#endif