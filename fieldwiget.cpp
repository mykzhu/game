#include "fieldwiget.h"
#include <QOpenGLFunctions>

float project_scale = 100;

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

    //create buffers
    GroundPlane::createBuffers(this);

    glEnable(GL_TEXTURE_2D);

    initTextures();

    glEnable(GL_DEPTH_TEST);
    startTimer(10);
}

void FieldWiget::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);

    glViewport(0, 0, w, h);

    perspective.setToIdentity();

    perspective.perspective(35, w / (float)h, 1, 160*project_scale);
}

void FieldWiget::paintGL()
{

}

void FieldWiget::initTextures()
{
    std::vector<QString> textureFiles;
    textureFiles.push_back("../Textures/botmars1.jpg");      // 0 ground 0
    textureFiles.push_back("../Textures/steelcrate.jpg");    // 1 boxes
    textureFiles.push_back("../Textures/tankbody.jpg");      // 2 tank armor sphere
    textureFiles.push_back("../Textures/tankbody.jpg");      // 3 tank armor box
    textureFiles.push_back("../Textures/bullet.jpg");        // 4 bullet
    textureFiles.push_back("../Textures/tanktrackfull.png"); // 5 tank tracks
    textureFiles.push_back("../Textures/backmars1.jpg");     // 6 back
    textureFiles.push_back("../Textures/frontmars1.jpg");    // 7 front
    textureFiles.push_back("../Textures/leftmars1.jpg");     // 8 left
    textureFiles.push_back("../Textures/rightmars1.jpg");    // 9 right
    textureFiles.push_back("../Textures/topmars1.jpg");      // 10 top
    textureFiles.push_back("../Textures/tankarmor.jpg");     // 11 armor cylinder

    for (uint i = 0; i < textureFiles.size(); i++) {
        textureHandles.push_back(bindTexture(QPixmap(textureFiles[i])));
    }

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glGenerateMipmap(GL_TEXTURE_2D);
}


void FieldWiget::createScene()
{

}
