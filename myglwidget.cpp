#include <QtWidgets>
#include <QtGui>
#include <QColor>
#include "myglwidget.h"

MyGLWidget::MyGLWidget(QWidget *parent) :
    QGLWidget(parent)
{

}

MyGLWidget::~MyGLWidget()
{

}

void MyGLWidget::keyPressEvent(QKeyEvent *e)
{
    if (e->key() == Qt::Key_Escape)
        close();
    else
        QWidget::keyPressEvent(e);
}

void MyGLWidget::initializeGL()
{
    glEnable(GL_MULTISAMPLE);
}

void MyGLWidget::resizeGL(int width, int height)
{
    int side = qMin(width, height);
    glViewport((width - side) / 2, (height - side) / 2, side, side);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
#ifdef QT_OPENGL_ES_1
    glOrthof(-2, +2, -2, +2, 1.0, 15.0);
#else
    glOrtho(-2, +2, -2, +2, 1.0, 15.0);
#endif
    glMatrixMode(GL_MODELVIEW);
}

void drawBubble(QPainter *painter)
{
    int radius = 20;

    QColor innerColor = QColor(255, 255, 0, 255);
    QColor outerColor = QColor(255, 0, 255, 255);

    QRadialGradient gradient(QPointF(radius, radius), radius,
                                 QPointF(radius*0.5, radius*0.5));

        gradient.setColorAt(0, QColor(255, 255, 255, 255));
        gradient.setColorAt(0.25, innerColor);
        gradient.setColorAt(1, outerColor);
       QBrush brush = QBrush(gradient);

    painter->save();
    painter->translate(300 - radius, 300 - radius);
    painter->setBrush(brush);
    painter->drawEllipse(0, 0, int(2*radius), int(2*radius));
    painter->restore();
}

void MyGLWidget::paintGL()
{
    QPainter painter(this);
    drawBubble(&painter);
}
