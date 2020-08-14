#ifndef _PERUNENGINE_SHADER_H
#define _PERUNENGINE_SHADER_H

namespace perun
{
    class GraphicsAPI;

    enum class ShaderType
    {
        Vertex,
        Geometry,
        Fragment,
    };

    using ShaderInfo = struct
    {
        const std::string& filePath;
        ShaderType type;
    };

    class PERUNENGINE_API ShaderProgram
    {
    public:
        virtual ~ShaderProgram();

        [[nodiscard]] inline uint32_t GetId() const noexcept
        {
            return id;
        }

        void LoadUniformLocation(const std::string& uniformName);

        [[nodiscard]] static std::unique_ptr<ShaderProgram> Create(std::unique_ptr<GraphicsAPI>& api, const std::vector<ShaderInfo>& shaders);

    protected:
        explicit ShaderProgram(std::unique_ptr<GraphicsAPI>& api)
            : api{api}
            , id{0}
        {
        }

        std::unique_ptr<GraphicsAPI>& api;
        uint32_t id;
        std::map<std::string, int32_t> uniformLocations;
    };
} // namespace perun

#endif //_PERUNENGINE_SHADER_H
