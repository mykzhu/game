#ifndef FIELDWIGET_H
#define FIELDWIGET_H

#include <QGLWidget>
#include <QOpenGLFunctions>
#include <QMatrix4x4>
#include <QOpenGLShaderProgram>

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
    QOpenGLShaderProgram program;
    GLuint posAttribute;
    GLuint normAttribute;
    GLuint uvAttribute;
    GLuint mMatrixUniform;
    GLuint pvMatrixUniform;
    GLuint colorUniform;
    GLuint shadowColorUniform;
    GLuint lightPosUniform;
    GLuint textureID;
    QMatrix4x4 perspective;
    QMatrix4x4 model;
    QMatrix4x4 view;
    std::list<QMatrix4x4> mStack;

    std::vector<GLuint> textureHandles;

    float zoom;
    float viewRotatey;
    float viewRotateVert;

};

#endif // FIELDWIGET_H
