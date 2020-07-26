#ifndef _SVAROGLANG_EXCEPTION_H
#define _SVAROGLANG_EXCEPTION_H

namespace svarog {

    class Exception : public std::exception {
    public:
        SVAROGLANG_NODISCARD virtual std::string GetErrorMessage() const;
        SVAROGLANG_NODISCARD const char* what() const noexcept override;
    };
}

#endif //_SVAROGLANG_EXCEPTION_H
