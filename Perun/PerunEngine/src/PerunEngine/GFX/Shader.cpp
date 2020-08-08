#include "PerunEnginePCH.h"
#include "Shader.h"

#include "GraphicsAPI.h"

namespace perun {

    ShaderProgram::~ShaderProgram() {

    }

    void ShaderProgram::LoadUniformLocation(const std::string& uniformName) {
        uniformLocations[uniformName] = api->GetUniformLocation(id, uniformName);
    }

    std::unique_ptr<ShaderProgram> ShaderProgram::Create(std::unique_ptr<GraphicsAPI>& api,
            const std::vector<ShaderInfo>& shaders) {
        auto program = new ShaderProgram{ api };
        program->id = api->GenerateShaderProgram(shaders);
        return std::unique_ptr<ShaderProgram>{ program };
    }
}
