#ifndef _SVAROGLANG_UTILITIES_H
#define _SVAROGLANG_UTILITIES_H
#include <map>

namespace svarog {

    template <typename Key, typename Value>
    static std::map<Key, Value> GenerateInverseMap(const std::map<Value, Key>& mapToInverse);

    inline bool IsSpace(char character);

    inline bool IsDigit(char character);

    inline bool IsAlpha(char character);

    inline bool IsAlnum(char character);
}

#include "Utilities.cpp"

#endif //_SVAROGLANG_UTILITIES_H
