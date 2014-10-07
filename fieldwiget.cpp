#include "fieldwiget.h"
#include <QOpenGLFunctions>

float project_scale = 100;

float edge_scale = 120*project_scale;

float wall_shift_y = 1*project_scale;

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

    // Create the shader program
    // Add both parts of the shader
    program.addShaderFromSourceFile(QOpenGLShader::Vertex, "TankVert.vert");
    program.addShaderFromSourceFile(QOpenGLShader::Fragment, "TankFrag.frag");

    // Compile the shader program
    program.link();

    uvAttribute = program.attributeLocation("texCoords");
    textureID  = program.uniformLocation("sampler");

    // Set attributes for each shape
    // Find Variable Locations
    posAttribute = program.attributeLocation("position");
    normAttribute = program.attributeLocation("normal");
    pvMatrixUniform = program.uniformLocation("pvMatrix");
    mMatrixUniform = program.uniformLocation("mMatrix");
    colorUniform = program.uniformLocation("color");
    shadowColorUniform = program.uniformLocation("shadowColor");
    lightPosUniform = program.uniformLocation("lightPos");

    // Enable the 2 vertex attribute arrays
    glEnableVertexAttribArray(posAttribute);
    glEnableVertexAttribArray(normAttribute);
    glEnableVertexAttribArray(uvAttribute);

    program.bind();
    program.setUniformValue(lightPosUniform, QVector3D(0, 5.0, -5));

    glClearColor(0.88, 0.88, 0.88, 1.0);

    glEnable(GL_DEPTH_TEST);
    startTimer(10);
}

void FieldWiget::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);

    perspective.setToIdentity();

    perspective.perspective(35, w / (float)h, 1, 160*project_scale);
}

void FieldWiget::paintGL()
{
    view.setToIdentity();
    view.translate(0, -0.5*project_scale, zoom);
    view.rotate(viewRotateVert, 1, 0, 0);
    view.rotate(viewRotatey, 0, 1 ,0);


    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //draw surroundings
    glActiveTexture(GL_TEXTURE0);
    createScene();
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
    GroundPlane::bindPositionBuffer();
    glVertexAttribPointer(posAttribute, 3, GL_FLOAT, GL_FALSE, 0, 0 );
    GroundPlane::bindNormalBuffer();
    glVertexAttribPointer(normAttribute, 3, GL_FLOAT, GL_FALSE, 0, 0);
    GroundPlane::bindUVBuffer();
    glVertexAttribPointer(uvAttribute, 2, GL_FLOAT, GL_FALSE, 0, 0);
    //ground
    glBindTexture(GL_TEXTURE_2D, textureHandles[0]);
    mStack.push_back(model);
    model.scale(edge_scale);
    program.setUniformValue(pvMatrixUniform, perspective * view);
    program.setUniformValue(mMatrixUniform, model);
    program.setUniformValue(colorUniform, QVector3D(0.2, 0.6, 1.0));
    program.setUniformValue(shadowColorUniform, QVector3D(0.2, 0.6, 1.0));
    GroundPlane::draw();
    model = mStack.back();
    mStack.pop_back();
    //front
    glBindTexture(GL_TEXTURE_2D, textureHandles[7]);
    mStack.push_back(model);
    model.translate(0, wall_shift_y, -edge_scale/2);
    model.rotate(90, 1, 0, 0);
    model.scale(edge_scale, edge_scale, edge_scale/2);
    program.setUniformValue(pvMatrixUniform, perspective * view);
    program.setUniformValue(mMatrixUniform, model);
    program.setUniformValue(colorUniform, QVector3D(0.2, 0.6, 1.0));
    program.setUniformValue(shadowColorUniform, QVector3D(0.2, 0.6, 1.0));
    GroundPlane::draw();
    model = mStack.back();
    mStack.pop_back();

}
