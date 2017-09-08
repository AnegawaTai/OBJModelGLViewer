#ifndef WIDGET_H
#define WIDGET_H

#include <QtGui>
#include <QGLWidget>
#include "glm.h"
#include "glmint.h"


typedef struct{
    int xRot,yRot,zRot;
    float xTra, yTra, zTra;
}ModelPose;

/// the Class of OpenGL Viewer
class Widget : public QGLWidget
{
    Q_OBJECT
public:
    explicit Widget(QGLWidget *parent = 0);

    bool is_model_loaded;

    QSize minimumSizeHint() const;
    QSize sizeHint() const;

public slots:
    void setXRotation(int angle);
    void setYRotation(int angle);
    void setZRotation(int angle);

    void setXTranslation(QString value);
    void setYTranslation(QString value);
    void setZTranslation(QString value);

    void setScale(QString value);

    void loadModel(QString filename);

signals:
    void xTranslationChanged(float value);
    void yTranslationChanged(float value);
    void zTranslationChanged(float value);

    void scaleChanged(float value);


protected:
    void paintGL();
    void resizeGL(int width,int height);
    void initializeGL(); 
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void wheelEvent(QWheelEvent *event);
    void mouseDoubleClickEvent(QMouseEvent *event);

private slots:
    void handleUpButton();
    void handleDownButton();
    void handleLeftButton();
    void handleRightButton();
    void handleForwardButton();
    void handleBackwardButton();
    void handleZoomInButton();
    void handleZoomOutButton();

private:
    void drawAxes(float scale, float thickness = 1.0);
    void setPosition(ModelPose& modelpose);
    void setModelPosition(ModelPose& modelpose);

    void setInitionPose(ModelPose& modelpose, bool isbase = true);
    void setRotation(int angle, int axis, ModelPose& modelpose);

    std::vector<GLMmodel*> obj_models;

    ModelPose base_scene_pose;   // background coordinate axes
    ModelPose obj_model_pose;

    float fov;
    float rotation_stepping;
    QPoint lastPos;
    float trans_interval, initialZ;
    float scale;

};

#endif // WIDGET_H
