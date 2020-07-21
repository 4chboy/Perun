#include "SvarogLangPCH.h"
#include "LoggerHub.h"

#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>

namespace svarog {

    LoggerException::LoggerException(std::string loggerName)
        : uninitializedLoggerName{ std::move(loggerName) } { }

    SVAROGLANG_NODISCARD std::string LoggerException::GetMessage() const {
        return "Logger Exception: Attempt to use uninitialized logger " + uninitializedLoggerName;
    }

    void LoggerHub::InitLogger(const std::string& loggerName, const SinkData& data) {
        auto& logSink = data.sink;
        logSink->set_pattern(data.pattern);
        auto logLevel = data.level;
        auto logger = std::make_shared<spdlog::logger>(loggerName, logSink);
        spdlog::register_logger(logger);
        logger->set_level(logLevel);
        logger->flush_on(logLevel);
        loggers[loggerName] = std::move(logger);
    }

    SVAROGLANG_NODISCARD LoggerPtr& LoggerHub::GetLogger(const std::string& loggerName) noexcept {
        if (const auto& loggerIter = loggers.find(loggerName); loggerIter != loggers.end()) {
            return loggerIter->second;
        }

        return loggers["Svarog"];
    }

    SVAROGLANG_NODISCARD static LoggerPtr CreateDefaultLogger() {
        std::vector<spdlog::sink_ptr> logSinks;
        logSinks.emplace_back(std::make_shared<spdlog::sinks::stdout_color_sink_st>());
        logSinks.emplace_back(std::make_shared<spdlog::sinks::basic_file_sink_st>("SvarogDebug.log", true));
        logSinks[0]->set_pattern("%^[%r] %n: %v%$");
        logSinks[1]->set_pattern("[%L, %r] %n: %v");

        auto svarogLogger = std::make_shared<spdlog::logger>("Svarog", std::begin(logSinks), std::end(logSinks));
        spdlog::register_logger(svarogLogger);
        svarogLogger->set_level(LogLevel::info);
        svarogLogger->flush_on(LogLevel::info);
    }

    std::map<std::string, LoggerPtr> LoggerHub::loggers = { { "Svarog", std::move(CreateDefaultLogger()) } };
}
