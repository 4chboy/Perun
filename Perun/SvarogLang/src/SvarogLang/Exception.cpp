#include "SvarogLangPCH.h"
#include "Exception.h"

namespace svarog {

    SVAROGLANG_NODISCARD std::string Exception::GetMessage() const {
        return "Undefined Exception";
    }
}
