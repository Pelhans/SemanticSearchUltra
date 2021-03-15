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

//日志级别
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
    virtual void log(LogLevel::Level level, LogEvent::ptr event) = 0;

    void setFormatter(LogFormatter::ptr val) { m_formatter = val;}
    LogFormatter::ptr getFormatter() const { return m_formatter;}
private:
    LogLevel::Level m_level;
    LogFormatter::ptr m_formatter;
};

// 日志器
class Logger {
public:
    typedef std::shared_ptr<Logger> ptr;
    Logger(const std::string& name = "root");
    void log(LogLevel::Level level, LogEvent::ptr event);

    void debug(LogEvent::ptr event);
    void info(LogEvent::ptr event);
    void warn(LogEvent::ptr event);
    void error(LogEvent::ptr event);
    void fatal(LogEvent::ptr event);

    void addAppender(LogAppender::ptr appender);
    void defAppender(LogAppender::ptr appender);
    LogLevel::Level getLevel() const {return m_level;}
    void setLevel(LogLevel::Level val) {m_level = val;}
private:
    std::string m_name;
    LogLevel::Level m_level;
    std::list<LogAppender::ptr> m_appenders;
};

// 输出到控制台
class StdoutLogAppender : public LogAppender {
public:
    typedef std::shared_ptr<StdoutLogAppender> ptr;
    void log(LogLevel::Level level, LogEvent::ptr event) override;
};

// 输出到文件
class FileLogAppender : public LogAppender {
public:
    typedef shared_ptr<FileLogAppender> ptr;
    FileLogAppender(const std::string* filename);
    void log(LogLevel::Level level, LogEvent::ptr event) override;

    bool reopen();
private:
    std::string m_filename;
    std::ofstream m_filestream;
};

}

#endif
