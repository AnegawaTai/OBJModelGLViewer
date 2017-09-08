/****************************************************************************
**
** Copyright (C) 2015 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>
#include <QSlider>
#include <QLineEdit>
#include <QPushButton>
#include <vector>

#include"widget.h"

class QSlider;

/// App window
class MyWindow : public QMainWindow
{
    Q_OBJECT

public:
    MyWindow();

signals:
void openOBJFiles(QString filename);

public slots:
    void setXTranslation(float value);
    void setYTranslation(float value);
    void setZTranslation(float value);

    void setScale(float value);

protected:
    void keyPressEvent(QKeyEvent *event);

private slots:
    void xRotationChanged(QString);
    void yRotationChanged(QString);
    void zRotationChanged(QString);

    void setXRotation(int angle);
    void setYRotation(int angle);
    void setZRotation(int angle);

    void openOBJFilesDialog();

private:
    QSlider *createSlider();
    void createMenu();
    void checkAvailability();
    void resetControlPanel();

    Widget *glWidget;

    std::vector<QPushButton *> Buttons;

//    QPushButton *upButton;
//    QPushButton *leftButton;
//    QPushButton *rightButton;
//    QPushButton *downButton;
//    QPushButton *zoomInButton;
//    QPushButton *zoomOutButton;

    QSlider *xSlider;
    QSlider *ySlider;
    QSlider *zSlider;


    QLineEdit *scaleEdit;
    QLineEdit *t_xEdit;
    QLineEdit *t_yEdit;
    QLineEdit *t_zEdit;
    QLineEdit *r_xEdit;
    QLineEdit *r_yEdit;
    QLineEdit *r_zEdit;
};

#endif
