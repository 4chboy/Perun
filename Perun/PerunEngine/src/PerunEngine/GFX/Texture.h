#ifndef _PERUNENGINE_TEXTURE_H
#define _PERUNENGINE_TEXTURE_H

namespace perun {

    class GraphicsAPI;

    class PERUNENGINE_API Texture {
    public:
        virtual ~Texture();

        [[nodiscard]] inline uint32_t GetId() const noexcept { return id; }
        [[nodiscard]] inline uint32_t GetWidth() const noexcept { return width; }
        [[nodiscard]] inline uint32_t GetHeight() const noexcept { return height; }
        [[nodiscard]] inline uint8_t* GetData() noexcept { return data; }
        [[nodiscard]] inline const uint8_t* GetData() const noexcept { return data; }

        [[nodiscard]] inline uint8_t& operator [] (size_t index) noexcept { return data[index]; }
        [[nodiscard]] inline uint8_t operator [] (size_t index) const noexcept { return data[index]; }

        [[nodiscard]] static std::unique_ptr<Texture> Create(std::unique_ptr<GraphicsAPI>& api,
                uint32_t textureWidth, uint32_t textureHeight);
        [[nodiscard]] static std::unique_ptr<Texture> Load(std::unique_ptr<GraphicsAPI>& api,
                const std::string& filePath);

    protected:
        Texture(std::unique_ptr<GraphicsAPI>& api, uint32_t textureWidth, uint32_t textureHeight);
        Texture(std::unique_ptr<GraphicsAPI>& api, const std::string& filePath);

        uint32_t id;
        uint32_t width, height;
        uint8_t* data;
        bool loaded;
        std::unique_ptr<GraphicsAPI>& api;
    };
}

#endif //_PERUNENGINE_TEXTURE_H
