#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include <QGLWidget>

class MyGLWidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit MyGLWidget(QWidget *parent = 0);
    ~MyGLWidget();

protected:
    void keyPressEvent(QKeyEvent *event);
    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);

private:

};

#endif // MYGLWIDGET_H
