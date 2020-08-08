#include "PerunEnginePCH.h"
#include "TextureAtlas.h"

#include "GraphicsAPI.h"

namespace perun {

    TextureAtlas::TextureAtlas(std::unique_ptr<GraphicsAPI>& api, uint32_t width, uint32_t height,
            uint32_t unitWidth, uint32_t unitHeight) :
        Texture{ api, width, height },
        unitWidth{ unitWidth },
        unitHeight{ unitHeight } { }

    TextureAtlas::TextureAtlas(std::unique_ptr<GraphicsAPI>& api, const std::string& filePath,
            uint32_t unitWidth, uint32_t unitHeight) :
        Texture{ api, filePath },
        unitWidth{ unitWidth },
        unitHeight{ unitHeight } { }

    std::unique_ptr<TextureAtlas> TextureAtlas::Create(std::unique_ptr<GraphicsAPI>& api,
            uint32_t atlasWidth, uint32_t atlasHeight,
            uint32_t atlasUnitWidth, uint32_t atlasUnitHeight) {
        return std::unique_ptr<TextureAtlas>{ new TextureAtlas{ api, atlasWidth, atlasHeight,
            atlasUnitWidth, atlasUnitHeight } };
    }

    std::unique_ptr<TextureAtlas> TextureAtlas::Load(std::unique_ptr<GraphicsAPI>& api,
            const std::string& filePath, uint32_t atlasUnitWidth, uint32_t atlasUnitHeight) {
        return std::unique_ptr<TextureAtlas>{ new TextureAtlas{ api, filePath,
            atlasUnitWidth, atlasUnitHeight } };
    }
}
