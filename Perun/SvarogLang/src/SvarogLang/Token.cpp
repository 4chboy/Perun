#include "SvarogLangPCH.h"
#include "Token.h"

namespace svarog {

    std::map<std::string, TokenType> s_map;

    SVAROGLANG_NODISCARD TokenType GetTokenTypeByName(const std::string& name) {

    }

    Token::Token(TokenType tokenType)
        : type{ tokenType } { }

    Token::Token(TokenType tokenType, TokenValue tokenValue)
        : type{ tokenType }, value{ std::move(tokenValue) } { }
}
