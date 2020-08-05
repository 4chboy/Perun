#ifndef _PERUNENGINE_GRAPHICS_API_H
#define _PERUNENGINE_GRAPHICS_API_H
#include "GraphicsContext.h"
#include "Texture.h"
#include "TextureAtlas.h"
#include "Shader.h"

namespace perun {

    class PERUNENGINE_API GraphicsAPI {
    public:
        virtual ~GraphicsAPI() = default;

        virtual void SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height) const = 0;
        virtual void Clear(float red, float green, float blue, float alpha) const = 0;
        virtual void AlphaBlending(bool enable) const = 0;

        [[nodiscard]] virtual uint32_t GenerateTexture(uint32_t width, uint32_t height, const uint8_t* data) const = 0;
        virtual void BindTexture(uint32_t textureId) const = 0;
        virtual void DeleteTexture(uint32_t textureId) const = 0;

        [[nodiscard]] virtual uint32_t GenerateShaderProgram(const std::vector<ShaderInfo>& shaders) const = 0;
        [[nodiscard]] virtual uint32_t GenerateShader(const ShaderInfo& shaderInfo) const = 0;
        [[nodiscard]] virtual int32_t GetUniformLocation(uint32_t programId, const std::string& uniformName) const = 0;

        [[nodiscard]] inline const std::string& GetVersion() const noexcept { return version; }
        [[nodiscard]] inline GraphicsAPIType GetType() const noexcept { return context->GetType(); }

        [[nodiscard]] static std::unique_ptr<GraphicsAPI> Create(std::unique_ptr<GraphicsContext>& context);

    protected:
        explicit GraphicsAPI(std::unique_ptr<GraphicsContext>& context) noexcept :
            context{ context } { }

        std::string version;
        std::unique_ptr<GraphicsContext>& context;
    };
}

#endif //_PERUNENGINE_GRAPHICS_API_H
