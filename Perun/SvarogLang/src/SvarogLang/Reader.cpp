#include "SvarogLangPCH.h"
#include "Reader.h"

namespace svarog {

    ReaderException::ReaderException(std::string fileLocation)
        : unavailableFileLocation{ std::move(fileLocation) } { }

    SVAROGLANG_NODISCARD std::string ReaderException::GetErrorMessage() const {
        return "Reader Exception: Cannot open file at location " + unavailableFileLocation;
    }

    Reader::Reader() noexcept
        : currentCharacter{ 0 }, position{ 0 }, column{ 1 }, line{ 1 } { }

    Reader::Reader(std::string filePath)
        : Reader{ } {
        LoadFile(std::move(filePath));
    }

    void Reader::LoadFile(std::string filePath) {
        fileLocation = std::move(filePath);
        ReloadFile();
    }

    void Reader::ReloadFile() {
        auto sourceFile = std::ifstream(fileLocation);
        if (!sourceFile) {
            throw ReaderException{ fileLocation };
        }

        source = std::string{ std::istreambuf_iterator<char>{ sourceFile }, std::istreambuf_iterator<char>{ } };
        currentCharacter = source[0];
        sourceFile.close();
    }

    SVAROGLANG_NODISCARD char Reader::GetCurrent() const noexcept {
        return currentCharacter;
    }

    SVAROGLANG_NODISCARD char Reader::Peek(std::size_t offset) const noexcept {
        auto peekPosition = position + offset;
        if (peekPosition < source.length()) {
            return source[peekPosition];
        }
        return 0;
    }

    SVAROGLANG_NODISCARD std::size_t Reader::GetColumn() const noexcept {
        return column;
    }

    SVAROGLANG_NODISCARD std::size_t Reader::GetLine() const noexcept {
        return line;
    }

    void Reader::Advance() noexcept {
        if (currentCharacter == '\n') {
            line += 1;
            column = 0;
        }

        position += 1;
        if (position < source.length()) {
            column += 1;
            currentCharacter = source[position];
        }
        else {
            currentCharacter = 0;
        }
    }
}
