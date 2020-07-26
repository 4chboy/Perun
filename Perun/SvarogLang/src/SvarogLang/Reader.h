#ifndef _SVAROGLANG_READER_H
#define _SVAROGLANG_READER_H
#include "Exception.h"

namespace svarog {

    class SVAROGLANG_API ReaderException final : public Exception {
    protected:
        friend class Reader;

        explicit ReaderException(std::string fileLocation);
        SVAROGLANG_NODISCARD std::string GetErrorMessage() const override;

    protected:
        std::string unavailableFileLocation;
    };

    class SVAROGLANG_API Reader final {
    public:
        Reader() noexcept;
        explicit Reader(std::string filePath);

        void LoadFile(std::string filePath);
        void ReloadFile();

        SVAROGLANG_NODISCARD char GetCurrent() const noexcept;
        SVAROGLANG_NODISCARD char Peek(std::size_t offset) const noexcept;
        SVAROGLANG_NODISCARD std::size_t GetColumn() const noexcept;
        SVAROGLANG_NODISCARD std::size_t GetLine() const noexcept;

        void Advance() noexcept;

    private:
        std::string szFileLocation;
        std::string szSource;
        char currentCharacter;
        std::size_t position, column, line;
    };
}

#endif //_SVAROGLANG_READER_H
