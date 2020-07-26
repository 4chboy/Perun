#ifndef _SVAROGLANG_SCANNER_H
#define _SVAROGLANG_SCANNER_H
#include "Exception.h"
#include "Reader.h"
#include "Token.h"

namespace svarog {

    class SVAROGLANG_API Scanner final {
    public:
        explicit Scanner(Reader* reader);

        std::vector<Token> Tokenize();
        Reader* GetReader();
        void SetReader(Reader* reader);

    private:
        Token GetNextToken();
        void Advance();
        char Peek(std::size_t offset = 1);

        Reader* currentReader;
        char currentChar;
    };
}

#endif //_SVAROGLANG_SCANNER_H
