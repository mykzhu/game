#include "GroundPlane.h"
namespace GroundPlane
{
GLuint normBuffer;
GLuint posBuffer;
GLuint texBuffer;
QOpenGLFunctions* s;

}
#include <vector>
#include <math.h>

void GroundPlane::createBuffers(QOpenGLFunctions *s)
{
    GroundPlane::s = s;

     // initialize the buffer
     GLuint buffers[3];
     s->glGenBuffers(3, buffers);
     posBuffer = buffers[0];
     normBuffer = buffers[1];
     texBuffer = buffers[2];

     // generate the data for a box
     std::vector<float> position;
     std::vector<float> normals;
     std::vector<float> uv;

     /*1*/position.push_back(-0.5);
     position.push_back(0);
     position.push_back(0.5);
     normals.push_back(0);
     normals.push_back(1);
     normals.push_back(0);
     uv.push_back(0);
     uv.push_back(0);

     /*2*/position.push_back(0.5);
     position.push_back(0);
     position.push_back(0.5);
     normals.push_back(0);
     normals.push_back(1);
     normals.push_back(0);
     uv.push_back(1);
     uv.push_back(0);

     /*3*/position.push_back(0.5);
     position.push_back(0);
     position.push_back(-0.5);
     normals.push_back(0);
     normals.push_back(1);
     normals.push_back(0);
     uv.push_back(1);
     uv.push_back(1);

     /*4*/position.push_back(-0.5);
     position.push_back(0);
     position.push_back(-0.5);
     normals.push_back(0);
     normals.push_back(1);
     normals.push_back(0);
     uv.push_back(0);
     uv.push_back(1);

     // send position data down to the buffer
     s->glBindBuffer(GL_ARRAY_BUFFER, posBuffer);
     s->glBufferData(GL_ARRAY_BUFFER,
                     position.size() * sizeof(float),
                     &position[0],
             GL_STATIC_DRAW);

     // send normal data down to the buffer
     s->glBindBuffer(GL_ARRAY_BUFFER, normBuffer);
     s->glBufferData(GL_ARRAY_BUFFER,
                     normals.size() * sizeof(float),
                     &normals[0],
             GL_STATIC_DRAW);
     // send position data down to the buffer
     s->glBindBuffer(GL_ARRAY_BUFFER, posBuffer);
     s->glBufferData(GL_ARRAY_BUFFER,
                     position.size() * sizeof(float),
                     &position[0],
             GL_STATIC_DRAW);

     // send uv data down to the buffer
     s->glBindBuffer(GL_ARRAY_BUFFER, texBuffer);
     s->glBufferData(GL_ARRAY_BUFFER,
                     uv.size() * sizeof(float),
                     &uv[0],
             GL_STATIC_DRAW);
}

void GroundPlane::draw()
{
    glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
}

void GroundPlane::bindNormalBuffer()
{
    s->glBindBuffer(GL_ARRAY_BUFFER, normBuffer);
}

void GroundPlane::bindPositionBuffer()
{
    s->glBindBuffer(GL_ARRAY_BUFFER, posBuffer);
}

void GroundPlane::bindUVBuffer()
{
    s->glBindBuffer(GL_ARRAY_BUFFER, texBuffer);
}
