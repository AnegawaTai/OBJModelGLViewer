#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include <math.h>

#include <QTimer>
#include <QApplication>
#include <iostream>

#include "widget.h"

Widget::Widget(QGLWidget *parent) :
    QGLWidget(parent)
{
    rotation_stepping = 1.0;
    fov=(100.0/180.0*M_PI);
    initialZ = -50;
    trans_interval = 0.5;

    scale = 1.0;
    is_model_loaded = false;

    setInitionPose(base_scene_pose);
    setInitionPose(obj_model_pose, false);
}

void Widget::setInitionPose(ModelPose &modelpose, bool isbase)
{
    modelpose.xRot = 0;
    modelpose.yRot = 0;
    modelpose.zRot = 0;
    modelpose.xTra = 0;
    modelpose.yTra = 0;
    if(isbase)
        modelpose.zTra = initialZ;// The initial position of observer is (0,0,50), face to the direction of -z
    else
        modelpose.zTra = 0;
}

QSize Widget::minimumSizeHint() const
{
    return QSize(50, 50);
}

QSize Widget::sizeHint() const
{
    return QSize(640, 480);
}

static void qNormalizeAngle(int &angle)
{
    while (angle < 0)
        angle += 360 * 16;
    while (angle > 360 * 16)
        angle -= 360 * 16;
}

void Widget::setRotation(int angle, int axis, ModelPose &modelpose)
{
    qNormalizeAngle(angle);

    switch(axis)
    {
    case 0:
        modelpose.xRot = angle;
        break;
    case 1:
        modelpose.yRot = angle;
        break;
    case 2:
        modelpose.zRot = angle;
        break;
    }
}

void Widget::setXRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != obj_model_pose.xRot) {
        obj_model_pose.xRot = angle;
        update();
    }
}

void Widget::setYRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != obj_model_pose.yRot) {
        obj_model_pose.yRot = angle;
        update();
    }
}

void Widget::setZRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != obj_model_pose.zRot) {
        obj_model_pose.zRot = angle;
        update();
    }
}

void Widget::setXTranslation(QString value)
{
    obj_model_pose.xTra = value.toFloat();
    update();
}

void Widget::setYTranslation(QString value)
{
    obj_model_pose.yTra = value.toFloat();
    update();
}

void Widget::setZTranslation(QString value)
{
    obj_model_pose.zTra = value.toFloat();
    update();
}

void Widget::setScale(QString value)
{
    scale = value.toFloat();
    update();
}

void Widget::initializeGL()
{

    // black background
    glClearColor(0.0,0.0,0.0,0.0);
    glClearDepth(1.0);


    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT,GL_NICEST);
}


void Widget::resizeGL(int width, int height)
{
    if(height == 0){
        height = 1;
    }
    glViewport(0,0,(GLint)width,(GLint)height);

    // Reset
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(fov,(GLfloat)width/(GLfloat)height,0.1,1e9);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void Widget::setPosition(ModelPose& modelpose)
{
    // !Default glMatrixMode is GL_MODELVIEW
    glLoadIdentity();
    //Camera transformation
    glTranslatef(modelpose.xTra, modelpose.yTra, modelpose.zTra);  //defaluts: (0, 0, -50)

    // R_Mat = X*Y*Z

    int z_steps = (modelpose.zRot / 16.0)/rotation_stepping;
    glRotatef(z_steps*rotation_stepping, 0.0, 0.0, 1.0);

    int y_steps = (modelpose.yRot / 16.0)/rotation_stepping;
    glRotatef(y_steps*rotation_stepping, 0.0, 1.0, 0.0);

    int x_steps = (modelpose.xRot / 16.0)/rotation_stepping;
    glRotatef(x_steps*rotation_stepping, 1.0, 0.0, 0.0);
}

void Widget::setModelPosition(ModelPose& modelpose)
{

    glTranslatef(modelpose.xTra, modelpose.yTra, modelpose.zTra);

    // R_Mat = X*Y*Z

    int z_steps = (modelpose.zRot / 16.0)/rotation_stepping;
    glRotatef(z_steps*rotation_stepping, 0.0, 0.0, 1.0);

    int y_steps = (modelpose.yRot / 16.0)/rotation_stepping;
    glRotatef(y_steps*rotation_stepping, 0.0, 1.0, 0.0);

    int x_steps = (modelpose.xRot / 16.0)/rotation_stepping;
    glRotatef(x_steps*rotation_stepping, 1.0, 0.0, 0.0);



    glScalef(scale, scale, scale);
}

void Widget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


    setPosition(base_scene_pose);
    glPushMatrix();

    drawAxes(100,20);
    glColor4f (1.0, 1.0, 1.0, 1.0);


    if(obj_models.size() > 0)
    {
        setModelPosition(obj_model_pose);
        glmDraw(obj_models[0],GLM_TEXTURE|GLM_MATERIAL);
    }

    glPopMatrix();

}

void Widget::mousePressEvent(QMouseEvent *event)
{
    lastPos = event->pos();
}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    int dx = event->x() - lastPos.x();
    int dy = event->y() - lastPos.y();

    if (event->buttons() & Qt::LeftButton) {
        switch (QApplication::keyboardModifiers())
        {
        case Qt::NoModifier:
            setRotation(base_scene_pose.xRot - 8 * dy, 0, base_scene_pose);
            setRotation(base_scene_pose.yRot + 8 * dx, 1, base_scene_pose);
            break;
        case Qt::ControlModifier:
            setRotation(base_scene_pose.xRot - 8 * dy, 0, base_scene_pose);
            setRotation(base_scene_pose.zRot + 8 * dx, 2, base_scene_pose);
            break;
        case Qt::ShiftModifier:
            base_scene_pose.xTra += (-base_scene_pose.zTra/50.0)*dx/200.0;
            base_scene_pose.yTra -= (-base_scene_pose.zTra/50.0)*dy/200.0;

        }
        update();
    }
    lastPos = event->pos();
}


void Widget::wheelEvent(QWheelEvent *event)
{
    base_scene_pose.zTra += (-base_scene_pose.zTra/50.0)*((float)event->delta())/25.0;
    update();
}

// reset to the initial viewpoint
void Widget::mouseDoubleClickEvent(QMouseEvent *event)
{
    setInitionPose(base_scene_pose);
    update();
}


void Widget::handleUpButton()
{
    obj_model_pose.yTra+=trans_interval;
    update();
    emit yTranslationChanged(obj_model_pose.yTra);
}

void Widget::handleDownButton()
{
    obj_model_pose.yTra-=trans_interval;
    update();
    emit yTranslationChanged(obj_model_pose.yTra);
}
void Widget::handleLeftButton()
{
    obj_model_pose.xTra-=trans_interval;
    update();
    emit xTranslationChanged(obj_model_pose.xTra);
}
void Widget::handleRightButton()
{
    obj_model_pose.xTra+=trans_interval;
    update();
    emit xTranslationChanged(obj_model_pose.xTra);
}
void Widget::handleForwardButton()
{
    obj_model_pose.zTra+=trans_interval;
    update();
    emit zTranslationChanged(obj_model_pose.zTra);
}
void Widget::handleBackwardButton()
{
    obj_model_pose.zTra-=trans_interval;
    update();
    emit zTranslationChanged(obj_model_pose.zTra);
}
void Widget::handleZoomInButton()
{
    scale *= pow(2,1);
    update();
    emit scaleChanged(scale);
}
void Widget::handleZoomOutButton()
{
    scale *= pow(2,-1);
    update();
    emit scaleChanged(scale);
}

void Widget::drawAxes(float scale, float thickness)
{
    glEnable(GL_BLEND);
    glDisable(GL_TEXTURE_2D);       // important! For drawing line in the specficed color instead the darken one
    glBegin(GL_LINES);
    glLineWidth(thickness);

    glColor4f (0.9, 0, 0, 1.0);
    glVertex3f(0, 0, 0);
    glVertex3f(scale, 0, 0);

    glColor4f (0, 0.9, 0, 1.0);
    glVertex3f(0, 0, 0);
    glVertex3f(0, scale, 0);

    glColor4f (0, 0, 0.9, 1.0);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 0, scale);
    glEnable(GL_TEXTURE_2D);

    glEnd();
}

void Widget::loadModel(QString filename)
{
    if(!filename.isEmpty())
    {
        is_model_loaded = true;
        obj_models.resize(1);
        QByteArray ba = filename.toLatin1();
        const char *fn = ba.data();
        obj_models[0] = glmReadOBJ(fn);

        setInitionPose(base_scene_pose);
        setInitionPose(obj_model_pose, false);
        update();
    }


}
