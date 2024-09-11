#include "shader.h"

#include <glad/glad.h>

#include <fstream>
#include <string>

Shader::Shader(const char* vert_path, const char* frag_path) {
    /* Read in shader code */
    std::ifstream vert_file(vert_path);
    std::ifstream frag_file(vert_path);
    std::string vert_string( (std::istreambuf_iterator<char>(vert_file)), 
                             (std::istreambuf_iterator<char>()         ) );
    std::string frag_string( (std::istreambuf_iterator<char>(vert_file)), 
                             (std::istreambuf_iterator<char>()         ) );
    const char* vert_code = vert_string.c_str();
    const char* frag_code = vert_string.c_str();

    /* Create shaders from raw code */
    u32 vert;
    u32 frag;
}

Shader::~Shader() {}

void Shader::use() const {
    glUseProgram(m_id);
}

void Shader::setBool(const char* name, bool value) const {
    glUniform1i(glGetUniformLocation(m_id, name), (int)value);
}

void Shader::setInt(const char* name, int value) const {
    glUniform1i(glGetUniformLocation(m_id, name), value);
}

void Shader::setFloat(const char* name, float value) const {
    glUniform1f(glGetUniformLocation(m_id, name), value);
}
