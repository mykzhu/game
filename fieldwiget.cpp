#include "fieldwiget.h"
#include <QOpenGLFunctions>

FieldWiget::FieldWiget(QWidget *parent) :
    QGLWidget(parent)
{
}

FieldWiget::~FieldWiget()
{
}

void FieldWiget::initializeGL()
{
    // initialize
    initializeOpenGLFunctions();

    qglClearColor(Qt::black);
}

void FieldWiget::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);
}

void FieldWiget::paintGL()
{

}
