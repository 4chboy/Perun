#ifndef _SVAROGLANG_UTILITIES_INL
#define _SVAROGLANG_UTILITIES_INL

namespace svarog {

    template <typename Key, typename Value>
    static std::map<Key, Value> GenerateInverseMap(const std::map<Value, Key>& mapToInverse) {
        auto resultMap = std::map<Key, Value>{ };
        for (auto& invIter : mapToInverse) {
            resultMap.insert(std::make_pair(invIter.second, invIter.first));
        }
        return resultMap;
    }

    inline bool IsSpace(char character) {
        return std::isspace(character) != 0;
    }

    inline bool IsDigit(char character) {
        return std::isdigit(character) != 0;
    }

    inline bool IsAlpha(char character) {
        return std::isalpha(character) != 0;
    }

    inline bool IsAlnum(char character) {
        return std::isalnum(character) != 0;
    }
}

#endif //_SVAROGLANG_UTILITIES_INL
