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
    printf("Create buffers \n");
}
