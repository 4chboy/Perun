#include "PerunEnginePCH.h"
#include "Shader.h"

namespace perun {

    ShaderProgram::~ShaderProgram() {

    }

    void ShaderProgram::LoadUniformLocation(const std::string& uniformName) {
        uniformLocations[uniformName] = location;
    }

    std::unique_ptr<ShaderProgram> ShaderProgram::Create(std::unique_ptr<GraphicsAPI>& api,
            const std::vector<ShaderInfo>& filePaths) {

    }
}
