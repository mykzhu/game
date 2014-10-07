#ifndef FIELDWIGET_H
#define FIELDWIGET_H

#include <QGLWidget>
#include <QOpenGLFunctions>
#include <QMatrix4x4>

#include "GroundPlane.h"

class FieldWiget : public QGLWidget, protected QOpenGLFunctions
{
    FieldWiget();
    ~FieldWiget();

    Q_OBJECT
public:
    explicit FieldWiget(QWidget *parent = 0);

    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();

    void initTextures();

    void createScene();

signals:

public slots:

private:
    QMatrix4x4 perspective;

    std::vector<GLuint> textureHandles;

};

#endif // FIELDWIGET_H
