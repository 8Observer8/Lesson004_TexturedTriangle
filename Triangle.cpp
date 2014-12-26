#include "Triangle.h"

Triangle::Triangle(QOpenGLShaderProgram *program,
                    int vertexAttr, int textureAttr, int textureUniform) :
    m_program( program ),
    m_vertexAttr( vertexAttr ),
    m_textureAttr( textureAttr ),
    m_textureUniform( textureUniform )
{
    initVertices();
    initTextureCoord();

    m_texture = new QOpenGLTexture( QImage( ":/Textures/Blocks.jpg" ) );
}

Triangle::~Triangle()
{
    delete m_texture;
}

void Triangle::draw()
{
    m_texture->bind();
    m_program->setAttributeArray( m_vertexAttr, m_vertices.data(), 3 );
    m_program->setAttributeArray( m_textureAttr, m_textureCoodrs.data(), 2 );
    m_program->setUniformValue( m_textureUniform, 0 );

    m_program->enableAttributeArray( m_vertexAttr );
    m_program->enableAttributeArray( m_textureAttr );

    glDrawArrays( GL_TRIANGLES, 0, m_vertices.size() / 3 );

    m_program->disableAttributeArray( m_vertexAttr );
    m_program->disableAttributeArray( m_textureAttr );
}

void Triangle::initVertices()
{
    m_vertices.resize( 9 );

    // 0
    m_vertices[0] = -0.5f;
    m_vertices[1] = -0.5f;
    m_vertices[2] = 0.0f;

    // 1
    m_vertices[3] = 0.5f;
    m_vertices[4] = -0.5f;
    m_vertices[5] = 0.0f;

    // 2
    m_vertices[6] = 0.0f;
    m_vertices[7] = 0.5f;
    m_vertices[8] = 0.0f;
}

void Triangle::initTextureCoord()
{
    m_textureCoodrs.resize( 6 );

    // 0
    m_textureCoodrs[0] = 0.0f;
    m_textureCoodrs[1] = 0.0f;

    // 1
    m_textureCoodrs[2] = 1.0f;
    m_textureCoodrs[3] = 0.0f;

    // 2
    m_textureCoodrs[4] = 0.5f;
    m_textureCoodrs[5] = 1.0f;
}
