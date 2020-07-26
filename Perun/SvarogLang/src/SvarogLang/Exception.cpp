#include "SvarogLangPCH.h"
#include "Exception.h"

namespace svarog {

    SVAROGLANG_NODISCARD std::string Exception::GetErrorMessage() const {
        return "Undefined Exception";
    }

    SVAROGLANG_NODISCARD const char* Exception::what() const noexcept {
        return "Use GetMessage method instead of what for all Svarog exceptions";
    }
}
