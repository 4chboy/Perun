#ifndef _SVAROGLANG_LOGGER_H
#define _SVAROGLANG_LOGGER_H
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>
#include <spdlog/sinks/ostream_sink.h>

#include "Exception.h"

namespace svarog {

    class SVAROGLANG_API LoggerException final : public Exception {
    protected:
        friend class LoggerHub;

        explicit LoggerException(std::string loggerName);
        SVAROGLANG_NODISCARD std::string GetErrorMessage() const override;

    private:
        std::string uninitializedLoggerName;
    };

    using LogLevel    = spdlog::level::level_enum;
    using SinkPtr     = std::shared_ptr<spdlog::sinks::sink>;
    using OstreamSink = spdlog::sinks::ostream_sink_st;
    using LoggerPtr   = std::shared_ptr<spdlog::logger>;

    struct SVAROGLANG_API SinkData final {
        SinkPtr pSink;
        std::string szPattern;
        LogLevel eLevel;
    };

    class SVAROGLANG_API LoggerHub final {
    public:
        static void InitLogger(const std::string& loggerName, const SinkData& data);
        SVAROGLANG_NODISCARD static LoggerPtr& GetLogger(const std::string& loggerName) noexcept;

    private:
        static std::map<std::string, LoggerPtr> s_mapLoggers;
    };
}

#endif //_SVAROGLANG_LOGGER_H
