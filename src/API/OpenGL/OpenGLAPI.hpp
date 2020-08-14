#ifndef _PERUNENGINE_OPENGL_API_H
#define _PERUNENGINE_OPENGL_API_H
#include "PerunEngine/GFX/GraphicsAPI.hpp"

namespace perun
{
    class PERUNENGINE_API OpenGLAPI final : public GraphicsAPI
    {
    public:
        explicit OpenGLAPI(std::unique_ptr<GraphicsContext>& context);
        ~OpenGLAPI() override;

        void SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height) const override;
        void Clear(float red, float green, float blue, float alpha) const override;
        void AlphaBlending(bool enable) const override;

        [[nodiscard]] uint32_t GenerateTexture(uint32_t width, uint32_t height, const uint8_t* data) const override;
        void BindTexture(uint32_t textureId) const override;
        void DeleteTexture(uint32_t textureId) const override;

        [[nodiscard]] uint32_t GenerateShaderProgram(const std::vector<ShaderInfo>& shaders) const override;
        [[nodiscard]] uint32_t GenerateShader(const ShaderInfo& shaderInfo) const override;
        [[nodiscard]] int32_t GetUniformLocation(uint32_t programId, const std::string& uniformName) const override;
    };
} // namespace perun

#endif //_PERUNENGINE_OPENGL_API_H
