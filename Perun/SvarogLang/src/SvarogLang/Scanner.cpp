#include "SvarogLangPCH.h"
#include "Scanner.h"

namespace svarog {

    Scanner::Scanner(Reader* reader)
        : currentReader{ nullptr } {
        SetReader(reader);
        currentChar = currentReader->GetCurrent();
    }

    std::vector<Token> Scanner::Tokenize() {
        auto tokens = std::vector<Token>{ };
        auto currentToken = GetNextToken();
        while (currentToken.type != TokenType::EndOfFile) {
            tokens.emplace_back(currentToken);
            currentToken = GetNextToken();
        }
        tokens.emplace_back(currentToken);
        return tokens;
    }

    Reader* Scanner::GetReader() {
        return currentReader;
    }

    void Scanner::SetReader(Reader* reader) {
        currentReader = reader;
    }

    Token Scanner::GetNextToken() {
        while (currentChar != 0) {

        }
        return Token{ TokenType::EndOfFile };
    }

    void Scanner::Advance() {
        currentReader->Advance();
        currentChar = currentReader->GetCurrent();
    }

    inline char Scanner::Peek(std::size_t offset) {
        return currentReader->Peek(offset);
    }
}
