#include "PerunEnginePCH.h"
#include "OpenGLAPI.h"
#include "OpenGLContext.h"

#define PERUNENGINE_GET_GLCONTEXT(context) **dynamic_cast<OpenGLContext*>(context.get())

namespace perun {

    OpenGLAPI::OpenGLAPI(std::unique_ptr<GraphicsContext>& context) :
        GraphicsAPI{ context } {
        auto& glContext = PERUNENGINE_GET_GLCONTEXT(context);
        glContext.Enable(GL_DEPTH);
        glContext.Enable(GL_STENCIL);
    }

    OpenGLAPI::~OpenGLAPI() = default;

    void OpenGLAPI::SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height) const {
        auto& glContext = PERUNENGINE_GET_GLCONTEXT(context);
        glContext.Viewport(x, y, width, height);
    }

    void OpenGLAPI::Clear(float red, float green, float blue, float alpha) const {
        auto& glContext = PERUNENGINE_GET_GLCONTEXT(context);
        glContext.ClearColor(red, green, blue, alpha);
        glContext.Clear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
    }

    void OpenGLAPI::AlphaBlending(bool enable) const {
        auto& glContext = PERUNENGINE_GET_GLCONTEXT(context);
        glContext.Enable(GL_BLEND);
        glContext.BlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    }

    uint32_t OpenGLAPI::GenerateTexture(const std::unique_ptr<Texture>& texture) const {
        uint32_t id;
        auto& glContext = PERUNENGINE_GET_GLCONTEXT(context);
        glContext.CreateTextures(GL_TEXTURE_2D, 1, &id);
        glContext.BindTexture(GL_TEXTURE_2D, id);
        glContext.TexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glContext.TexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glContext.TexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glContext.TexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glContext.TexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, texture->GetWidth(), texture->GetHeight(),
                0, GL_RGBA, GL_UNSIGNED_BYTE, reinterpret_cast<const void*>(texture->GetData()));
        glContext.GenerateMipmap(GL_TEXTURE_2D);
        return id;
    }

    [[nodiscard]] uint32_t OpenGLAPI::GenerateTexture(uint32_t width, uint32_t height, const uint8_t* data) const {
        uint32_t id;
        auto& glContext = PERUNENGINE_GET_GLCONTEXT(context);
        glContext.CreateTextures(GL_TEXTURE_2D, 1, &id);
        glContext.BindTexture(GL_TEXTURE_2D, id);
        glContext.TexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glContext.TexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glContext.TexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glContext.TexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glContext.TexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height,
                             0, GL_RGBA, GL_UNSIGNED_BYTE, reinterpret_cast<const void*>(data));
        glContext.GenerateMipmap(GL_TEXTURE_2D);
        return id;
    }

    void OpenGLAPI::BindTexture(uint32_t textureId) const {
        auto& glContext = PERUNENGINE_GET_GLCONTEXT(context);
        glContext.BindTexture(GL_TEXTURE_2D, textureId);
    }

    void OpenGLAPI::DeleteTexture(uint32_t textureId) const {
        auto& glContext = PERUNENGINE_GET_GLCONTEXT(context);
        glContext.DeleteTextures(1, &textureId);
    }

    static GLenum ToOpenGLShaderType(ShaderType shaderType) {
        switch (shaderType) {
        case ShaderType::Vertex:   return GL_VERTEX_SHADER;
        case ShaderType::Geometry: return GL_GEOMETRY_SHADER;
        case ShaderType::Fragment: return GL_FRAGMENT_SHADER;
        default:                   return GL_NONE;
        }
    }

    uint32_t OpenGLAPI::GenerateShaderProgram(const std::vector<ShaderInfo>& shaders) const {
        std::vector<uint32_t> shaderIds(shaders.size());
        for (size_t i = 0; i < shaders.size(); ++i) {
            shaderIds[i] = GenerateShader(shaders[i]);
        }

        auto& glContext = PERUNENGINE_GET_GLCONTEXT(context);
        auto id = glContext.CreateProgram();
        for (auto shaderId : shaderIds) {
            glContext.AttachShader(id, shaderId);
        }
        glContext.LinkProgram(id);

        int32_t linkStatus;
        glContext.GetProgramiv(id, GL_LINK_STATUS, &linkStatus);
        if (!linkStatus) {
            constexpr const auto infoLogLength = 512;
            GLchar infoLog[infoLogLength];
            glContext.GetProgramInfoLog(id, infoLogLength, nullptr, infoLog);
        }

        for (auto shaderId : shaderIds) {
            glContext.DetachShader(id, shaderId);
            glContext.DeleteShader(shaderId);
        }

        return id;
    }

    uint32_t OpenGLAPI::GenerateShader(const ShaderInfo& shaderInfo) const {
        auto shaderFile = std::ifstream{ shaderInfo.filePath };
        auto shaderSource = std::string{ std::istreambuf_iterator<char>{ shaderFile },
                                         std::istreambuf_iterator<char>{ } };
        auto shaderCode = shaderSource.c_str();

        auto& glContext = PERUNENGINE_GET_GLCONTEXT(context);
        auto shaderId = glContext.CreateShader(ToOpenGLShaderType(shaderInfo.type));
        glContext.ShaderSource(shaderId, 1, &shaderCode, nullptr);
        glContext.CompileShader(shaderId);

        int32_t compileStatus;
        glContext.GetShaderiv(shaderId, GL_COMPILE_STATUS, &compileStatus);
        if (!compileStatus) {
            constexpr const auto infoLogLength = 512;
            GLchar infoLog[infoLogLength];
            glContext.GetShaderInfoLog(shaderId, infoLogLength, nullptr, infoLog);
        }
        
        return shaderId;
    }

    int32_t OpenGLAPI::GetUniformLocation(uint32_t programId, const std::string& uniformName) const {
        auto& glContext = PERUNENGINE_GET_GLCONTEXT(context);
        glContext.GetUniformLocation(programId, uniformName.c_str());
    }
}
