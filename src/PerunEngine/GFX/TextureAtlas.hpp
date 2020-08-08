#ifndef _PERUNENGINE_TEXTURE_ATLAS_H
#define _PERUNENGINE_TEXTURE_ATLAS_H
#include "Texture.hpp"

namespace perun {

    class TextureAtlas final : public Texture {
    public:
        ~TextureAtlas() override = default;

        [[nodiscard]] inline uint32_t GetUnitWidth() const noexcept { return unitWidth; }
        [[nodiscard]] inline uint32_t GetUnitHeight() const noexcept { return unitHeight; }

        [[nodiscard]] static std::unique_ptr<TextureAtlas> Create(std::unique_ptr<GraphicsAPI>& api,
                uint32_t atlasWidth, uint32_t atlasHeight,
                uint32_t atlasUnitWidth, uint32_t atlasUnitHeight);
        [[nodiscard]] static std::unique_ptr<TextureAtlas> Load(std::unique_ptr<GraphicsAPI>& api,
                const std::string& filePath, uint32_t atlasUnitWidth, uint32_t atlasUnitHeight);

    private:
        TextureAtlas(std::unique_ptr<GraphicsAPI>& api, uint32_t width, uint32_t height,
                uint32_t unitWidth, uint32_t unitHeight);
        TextureAtlas(std::unique_ptr<GraphicsAPI>& api, const std::string& filePath,
                uint32_t unitWidth, uint32_t unitHeight);

        uint32_t unitWidth, unitHeight;
    };
}

#endif //_PERUNENGINE_TEXTURE_ATLAS_H
