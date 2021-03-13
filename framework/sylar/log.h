/*************************************************************************
	> File Name: log.h
	> Author: Pelhans
	> Mail: me@pelhans.com
	> Created Time: Sat 13 Mar 2021 09:59:43 PM CST
 ************************************************************************/

#ifndef _LOG_H
#define _LOG_H

#include <string>
#include <stdint.h>
#include <memory>

namespace sylar {

// 日志事件
class LogEvent {
public:
    typedef std::shared_ptr<LogEvent> ptr;
    LogEvent();
private:
    const char* m_fiile = nullptr;
    int32_t m_line = 0;
    uint32_t m_elapse = 0;
    uint32_t = m_threadId = 0;
    uint32_t m_fiberId = 0;         // 协程 id
    uint64_t m_time;
    std::string m_content;
};

class LogLevel {
public:
    enum Level {
        DEBUG = 1,
        INFO = 2,
        WARN = 3,
        ERROR = 4;
        FATAL = 5
    };
};

class LogFormatter {
public:
    typedef std::shared_ptr<LogFormatter> ptr;
    std::string format(LogEvent::ptr event);
private:
};

// 日志输出的地方
class LogAppender {
public:
    typedef std::shared_ptr<LogAppender> ptr;
    virtual ~LogAppender() {};
    void log(LogLevel::Level level, LogEvent::ptr event);
private:
    LogLevel::Level m_level;
};

// 日志器
class Logger {
public:
    typedef std::shared_ptr<Logger> ptr;
    Logger(const std::string& name = "root");
    void log(LogLevel::Level LEVEL, LogEvent::ptr event);
private:
    std::string m_name;
    LogLevel::Level m_level;
    LogAppender::ptr;
};

// 输出到控制台
class StdoutLogAppender : public LogAppender {
};

// 输出到文件
class FileLogAppender : public LogAppender {
};

}

#endif
