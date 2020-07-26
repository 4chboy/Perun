#ifndef _SVAROGLANG_TOKEN_H
#define _SVAROGLANG_TOKEN_H

namespace svarog {

    enum class TokenCategory : std::size_t {
        Undefined = 0x00000000,
        System    = 0x00010000,
        Constant  = 0x00100000,
        Operator  = 0x01000000,
        Keyword   = 0x10000000,
    };

    SVAROGLANG_NODISCARD static inline constexpr std::size_t SetTokenTypeCategory(std::size_t tokenTypeValue,
            TokenCategory tokenCategory) noexcept {
        return tokenTypeValue | static_cast<std::size_t>(tokenCategory);
    }

    enum class TokenType : std::size_t {
        Undefined        = SetTokenTypeCategory(0x00, TokenCategory::Undefined),
        // System
        EndOfFile        = SetTokenTypeCategory(0x00, TokenCategory::System),
        // Constants
        NullConstant     = SetTokenTypeCategory(0x00, TokenCategory::Constant),
        BooleanConstant  = SetTokenTypeCategory(0x01, TokenCategory::Constant),
        IntegerConstant  = SetTokenTypeCategory(0x02, TokenCategory::Constant),
        FloatingConstant = SetTokenTypeCategory(0x03, TokenCategory::Constant),
        StringConstant   = SetTokenTypeCategory(0x04, TokenCategory::Constant),
        // Operators
        OperatorAssign   = SetTokenTypeCategory(0x00, TokenCategory::Operator),
        OperatorPlus     = SetTokenTypeCategory(0x01, TokenCategory::Operator),
        OperatorMinus    = SetTokenTypeCategory(0x02, TokenCategory::Operator),
        OperatorMultiply = SetTokenTypeCategory(0x03, TokenCategory::Operator),
        OperatorDivide   = SetTokenTypeCategory(0x04, TokenCategory::Operator),
        OperatorModulo   = SetTokenTypeCategory(0x05, TokenCategory::Operator),
        // Keywords
        KeywordVariable  = SetTokenTypeCategory(0x00, TokenCategory::Keyword),
        KeywordReference = SetTokenTypeCategory(0x01, TokenCategory::Keyword),
        KeywordFunction  = SetTokenTypeCategory(0x02, TokenCategory::Keyword),
        KeywordClass     = SetTokenTypeCategory(0x03, TokenCategory::Keyword),
        KeywordIf        = SetTokenTypeCategory(0x04, TokenCategory::Keyword),
        KeywordElif      = SetTokenTypeCategory(0x05, TokenCategory::Keyword),
        KeywordElse      = SetTokenTypeCategory(0x06, TokenCategory::Keyword),
        KeywordFor       = SetTokenTypeCategory(0x07, TokenCategory::Keyword),
        KeywordIn        = SetTokenTypeCategory(0x08, TokenCategory::Keyword),
        KeywordWhile     = SetTokenTypeCategory(0x09, TokenCategory::Keyword),
        KeywordDo        = SetTokenTypeCategory(0x0A, TokenCategory::Keyword),
        KeywordTrue      = SetTokenTypeCategory(0x0B, TokenCategory::Keyword),
        KeywordFalse     = SetTokenTypeCategory(0x0C, TokenCategory::Keyword),
        KeywordNot       = SetTokenTypeCategory(0x0D, TokenCategory::Keyword),
        KeywordAnd       = SetTokenTypeCategory(0x0E, TokenCategory::Keyword),
        KeywordOr        = SetTokenTypeCategory(0x0F, TokenCategory::Keyword),
    };

    SVAROGLANG_NODISCARD static inline constexpr bool IsTokenTypeInCategory(TokenType tokenType,
            TokenCategory tokenCategory) noexcept {
        return static_cast<bool>(static_cast<std::size_t>(tokenType) & static_cast<std::size_t>(tokenCategory));
    }

    SVAROGLANG_NODISCARD TokenType GetTokenTypeByName(const std::string& name);

    using TokenValue = std::variant<bool, int, float, std::string>;

    struct Token {
        TokenType type;
        TokenValue value;

        explicit Token(TokenType tokenType);
        Token(TokenType tokenType, TokenValue tokenValue);

        friend std::ostream& operator << (std::ostream& os, const Token& token);
    };
}

#endif
