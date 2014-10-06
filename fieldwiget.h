#ifndef FIELDWIGET_H
#define FIELDWIGET_H

#include <QGLWidget>
#include <QOpenGLFunctions>

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

signals:

public slots:

};

#endif // FIELDWIGET_H
