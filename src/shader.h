#pragma once

#include "util/types.h"

class Shader
{
public:
    Shader(const char* vert_path, const char* frag_path);
    ~Shader();

    void use() const;

    void setBool(const char* name, bool value) const;
    void setInt(const char* name, int value) const;
    void setFloat(const char* name, float value) const;

private:
    u32 m_id;
};
