#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <vector>
#include <QOpenGLShaderProgram>
#include <QOpenGLTexture>

class Triangle
{
public:
    Triangle( QOpenGLShaderProgram *program,
              int vertexAttr, int textureAttr,
              int textureUniform );
    ~Triangle();

    void draw();

private:
    void initVertices();
    void initTextureCoord();

    std::vector<float> m_vertices;
    std::vector<float> m_textureCoodrs;

    QOpenGLShaderProgram *m_program;
    int m_vertexAttr;
    int m_textureAttr;
    int m_textureUniform;

    QOpenGLTexture *m_texture;
};

#endif // TRIANGLE_H
