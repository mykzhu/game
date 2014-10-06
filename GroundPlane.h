#ifndef GROUNDPLANE_H
#define GROUNDPLANE_H

#include <QOpenGLFunctions>
#include <QGLWidget>

namespace GroundPlane
{
void createBuffers(QOpenGLFunctions* s);
void draw();
void freeBuffers();
void bindNormalBuffer();
void bindPositionBuffer();
void bindUVBuffer();
}

#endif // GROUNDPLANE_H
