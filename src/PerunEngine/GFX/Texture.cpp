#include "PerunEnginePCH.h"
#include "Texture.hpp"
#include "GraphicsAPI.hpp"

#include "stb/stb_image.h"

namespace perun {

    Texture::Texture(std::unique_ptr<GraphicsAPI>& api, uint32_t textureWidth, uint32_t textureHeight) :
        api{ api },
        width{ textureWidth },
        height{ textureHeight },
        data{ new uint8_t[textureWidth * textureHeight] },
        loaded{ false } {
        id = api->GenerateTexture(width, height, data);
    }

    Texture::Texture(std::unique_ptr<GraphicsAPI>& api, const std::string& filePath) :
        api{ api } {
        int textureWidth, textureHeight, textureChannels;
        constexpr int desiredChannels = 4;
        data = reinterpret_cast<uint8_t*>(
                stbi_load(filePath.c_str(), &textureWidth, &textureHeight, &textureChannels, desiredChannels)
        );
        if (data) {
            width = static_cast<uint32_t>(textureWidth);
            height = static_cast<uint32_t>(textureHeight);
            id = api->GenerateTexture(width, height, data);
            loaded = true;
        }
    }

    Texture::~Texture() {
        if (data != nullptr) {
            if (loaded) {
                stbi_image_free(reinterpret_cast<void *>(data));
            }
            else {
                delete[] data;
            }
            api->DeleteTexture(id);
        }
    }

    std::unique_ptr<Texture> Texture::Create(std::unique_ptr<GraphicsAPI>& api,
            uint32_t textureWidth, uint32_t textureHeight) {
        return std::unique_ptr<Texture>{ new Texture{ api, textureWidth, textureHeight } };
    }

    std::unique_ptr<Texture> Texture::Load(std::unique_ptr<GraphicsAPI>& api,
            const std::string& filePath) {
        return std::unique_ptr<Texture>{ new Texture{ api, filePath } };
    }
}
