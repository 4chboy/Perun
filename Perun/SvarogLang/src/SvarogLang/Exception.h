#ifndef _SVAROGLANG_EXCEPTION_H
#define _SVAROGLANG_EXCEPTION_H

namespace svarog {

    class Exception {
    public:
        virtual ~Exception() = default;

        SVAROGLANG_NODISCARD virtual std::string GetMessage() const;
    };
}

#endif //_SVAROGLANG_EXCEPTION_H
