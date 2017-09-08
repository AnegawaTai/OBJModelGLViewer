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

#include <iostream>
#include <QtGui>
#include <QBoxLayout>
#include <QLabel>
#include <QSplitter>
#include <QMenuBar>
#include <QMenu>
#include <QFileDialog>

#include "window.h"


MyWindow::MyWindow()
{
    glWidget = new Widget;

    createMenu();

    QSplitter* hsplitter = new QSplitter(Qt::Horizontal);

    setCentralWidget(hsplitter);

    // add GL Viewer as left widget
    hsplitter->addWidget(glWidget);

    QSplitter* vsplitter = new QSplitter(Qt::Vertical);

    // Create Control Panel (right)
    QWidget* buttonWidget = new QWidget();
    buttonWidget->setFixedSize(QSize(450,300));


    // Create Labels
    const char *vinit[] = {"Zoom in","Zoom out", "Up", "Down", "Left", "Right", "Forward", "Backward"};
    const char *label_texts[] = {"Scale", "Translation", "Rotation", "X", "Y","Z", "X", "Y","Z"};

    std::vector<QString> button_texts (vinit, vinit+sizeof(*vinit));
    std::vector<QLabel*> Labels;

    for(int i = 0; i < sizeof(*label_texts) + 1; i++)
    {
        QLabel *currentLabel = new  QLabel(tr(label_texts[i]));

        currentLabel->setFont(QFont("Times", 18, QFont::Bold));

        Labels.push_back(currentLabel);
    }

    // Create Buttons
    for(int i = 0; i < button_texts.size(); i++)
    {
        QPushButton *currentButton = new QPushButton(button_texts[i]);
        currentButton->setFixedSize(QSize(90,60));
        currentButton->setFont(QFont("Times", 14, QFont::Normal));
        Buttons.push_back(currentButton);
    }

    QObject::connect(Buttons[0], SIGNAL (released()), glWidget, SLOT (handleZoomInButton()));
    QObject::connect(Buttons[1], SIGNAL (released()), glWidget, SLOT (handleZoomOutButton()));
    QObject::connect(Buttons[2], SIGNAL (released()), glWidget, SLOT (handleUpButton()));
    QObject::connect(Buttons[3], SIGNAL (released()), glWidget, SLOT (handleDownButton()));
    QObject::connect(Buttons[4], SIGNAL (released()), glWidget, SLOT (handleLeftButton()));
    QObject::connect(Buttons[5], SIGNAL (released()), glWidget, SLOT (handleRightButton()));
    QObject::connect(Buttons[6], SIGNAL (released()), glWidget, SLOT (handleForwardButton()));
    QObject::connect(Buttons[7], SIGNAL (released()), glWidget, SLOT (handleBackwardButton()));

    // Create Rotation Sliders
    xSlider = createSlider();
    ySlider = createSlider();
    zSlider = createSlider();

    xSlider->setValue(0);
    ySlider->setValue(0);
    zSlider->setValue(0);

    QObject::connect(xSlider, SIGNAL(valueChanged(int)), glWidget, SLOT(setXRotation(int)));
    QObject::connect(ySlider, SIGNAL(valueChanged(int)), glWidget, SLOT(setYRotation(int)));
    QObject::connect(zSlider, SIGNAL(valueChanged(int)), glWidget, SLOT(setZRotation(int)));

    QObject::connect(xSlider, SIGNAL(valueChanged(int)), this, SLOT(setXRotation(int)));
    QObject::connect(ySlider, SIGNAL(valueChanged(int)), this, SLOT(setYRotation(int)));
    QObject::connect(zSlider, SIGNAL(valueChanged(int)), this, SLOT(setZRotation(int)));


    // set up the layout of GUI
    QGridLayout *buttonLayout = new QGridLayout;
    buttonLayout->setColumnStretch(4,1);
    {   /// scale

        buttonLayout->addWidget(Labels[0],0,0,Qt::AlignLeft);   // "Scale" label
        scaleEdit = new QLineEdit("1.0");
        scaleEdit->setFixedSize(QSize(60,30));
        buttonLayout->addWidget(scaleEdit,0,1,Qt::AlignHCenter);
        buttonLayout->addWidget(Buttons[0],0,2);
        buttonLayout->addWidget(Buttons[1],0,3);

        QObject::connect(scaleEdit, SIGNAL(textChanged(QString)), glWidget, SLOT(setScale(QString)));
        QObject::connect(glWidget, SIGNAL(scaleChanged(float)), this, SLOT(setScale(float)));

    }


    {   /// translation
        buttonLayout->addWidget(Labels[1],1,0,Qt::AlignLeft);    // "Translation" label
        buttonLayout->addWidget(Labels[3],2,0,Qt::AlignRight);       // "X"
        buttonLayout->addWidget(Labels[4],3,0,Qt::AlignRight);       // "Y"
        buttonLayout->addWidget(Labels[5],4,0,Qt::AlignRight);       // "Z"
        t_xEdit = new QLineEdit("0.0");
        t_xEdit->setFixedSize(QSize(60,30));
        buttonLayout->addWidget(t_xEdit,2,1,Qt::AlignHCenter);
        t_yEdit = new QLineEdit("0.0");
        t_yEdit->setFixedSize(QSize(60,30));
        buttonLayout->addWidget(t_yEdit,3,1,Qt::AlignHCenter);
        t_zEdit = new QLineEdit("0.0");
        t_zEdit->setFixedSize(QSize(60,30));
        buttonLayout->addWidget(t_zEdit,4,1,Qt::AlignHCenter);

        QObject::connect(t_xEdit, SIGNAL(textChanged(QString)), glWidget, SLOT(setXTranslation(QString)));
        QObject::connect(t_yEdit, SIGNAL(textChanged(QString)), glWidget, SLOT(setYTranslation(QString)));
        QObject::connect(t_zEdit, SIGNAL(textChanged(QString)), glWidget, SLOT(setZTranslation(QString)));


        buttonLayout->addWidget(Buttons[4],2,2);    // left
        buttonLayout->addWidget(Buttons[5],2,3);    // right

        buttonLayout->addWidget(Buttons[2],3,2);    // up
        buttonLayout->addWidget(Buttons[3],3,3);    // down

        buttonLayout->addWidget(Buttons[6],4,2);    // forward
        buttonLayout->addWidget(Buttons[7],4,3);    // backward

        QObject::connect(glWidget, SIGNAL(xTranslationChanged(float)), this, SLOT(setXTranslation(float)));
        QObject::connect(glWidget, SIGNAL(yTranslationChanged(float)), this, SLOT(setYTranslation(float)));
        QObject::connect(glWidget, SIGNAL(zTranslationChanged(float)), this, SLOT(setZTranslation(float)));

    }

    buttonWidget->setLayout(buttonLayout);
    vsplitter->addWidget(buttonWidget);

    QWidget* sliderWidget = new QWidget();
    QGridLayout *sliderLayout = new QGridLayout;
    sliderWidget->setFixedSize(QSize(450,200));

    {   /// rotation
    sliderLayout->addWidget(Labels[2],0,0,Qt::AlignLeft);
    sliderLayout->addWidget(Labels[6],1,0,Qt::AlignRight);
    sliderLayout->addWidget(Labels[7],2,0,Qt::AlignRight);
    sliderLayout->addWidget(Labels[8],3,0,Qt::AlignRight);
    r_xEdit = new QLineEdit("0");
    r_xEdit->setFixedSize(QSize(60,30));
    sliderLayout->addWidget(r_xEdit,1,1,Qt::AlignHCenter);

    r_yEdit = new QLineEdit("0");
    r_yEdit->setFixedSize(QSize(60,30));
    sliderLayout->addWidget(r_yEdit,2,1,Qt::AlignHCenter);

    r_zEdit = new QLineEdit("0");
    r_zEdit->setFixedSize(QSize(60,30));
    sliderLayout->addWidget(r_zEdit,3,1,Qt::AlignHCenter);

    QObject::connect(r_xEdit, SIGNAL(textChanged(QString)), this, SLOT(xRotationChanged(QString)));
    QObject::connect(r_yEdit, SIGNAL(textChanged(QString)), this, SLOT(yRotationChanged(QString)));
    QObject::connect(r_zEdit, SIGNAL(textChanged(QString)), this, SLOT(zRotationChanged(QString)));

    sliderLayout->addWidget(xSlider,1,2,1,3);
    sliderLayout->addWidget(ySlider,2,2,1,3);
    sliderLayout->addWidget(zSlider,3,2,1,3);
    }

    sliderWidget->setLayout(sliderLayout);
    vsplitter->addWidget(sliderWidget);
    vsplitter->addWidget(new QWidget());

    hsplitter->addWidget(vsplitter);

    setWindowTitle(tr("OBJ GL Viewer"));
    checkAvailability();
}

void MyWindow::setXTranslation(float value)
{
    t_xEdit->setText(QString::number(value));
}

void MyWindow::setYTranslation(float value)
{
    t_yEdit->setText(QString::number(value));
}

void MyWindow::setZTranslation(float value)
{
    t_zEdit->setText(QString::number(value));
}

void MyWindow::setScale(float value)
{
    scaleEdit->setText(QString::number(value));
}


void MyWindow::setXRotation(int value)
{
    r_xEdit->setText(QString::number(value / 16));
}

void MyWindow::setYRotation(int value)
{
    r_yEdit->setText(QString::number(value / 16));
}

void MyWindow::setZRotation(int value)
{
    r_zEdit->setText(QString::number(value / 16));
}

void MyWindow::xRotationChanged(QString value)
{
    int angle = value.split(".")[0].toInt();

    angle = angle * 16;

    while (angle < 0)
        angle += 360 * 16;
    while (angle > 360 * 16)
        angle -= 360 * 16;

    xSlider->setValue(angle);
}

void MyWindow::yRotationChanged(QString value)
{
    int angle = value.split(".")[0].toInt();

    angle = angle * 16;

    while (angle < 0)
        angle += 360 * 16;
    while (angle > 360 * 16)
        angle -= 360 * 16;

    ySlider->setValue(angle);
}

void MyWindow::zRotationChanged(QString value)
{
    int angle = value.split(".")[0].toInt();

    angle = angle * 16;

    while (angle < 0)
        angle += 360 * 16;
    while (angle > 360 * 16)
        angle -= 360 * 16;

    zSlider->setValue(angle);
}

QSlider *MyWindow::createSlider()
{
    QSlider *slider = new QSlider(Qt::Horizontal);
    slider->setRange(0, 360 * 16);
    slider->setSingleStep(16);
    slider->setPageStep(15 * 16);
    return slider;
}

void MyWindow::createMenu()
{
    QMenu *dataMenu = menuBar()->addMenu(tr("&I/O"));
    QAction *openOBJFilesAct = new QAction(tr("&Open OBJ file"), this);
    QObject::connect(openOBJFilesAct, SIGNAL(triggered()), this, SLOT(openOBJFilesDialog()));
    dataMenu->addAction(openOBJFilesAct);
    this->addAction(openOBJFilesAct);


    QObject::connect(this, SIGNAL (openOBJFiles(QString)), glWidget, SLOT (loadModel(QString)));
}

void MyWindow::openOBJFilesDialog()
{
    QString filename = QFileDialog::getOpenFileName(this, "Open OBJ Files", "", tr("OBJ (*.obj)"));
    if(!filename.isEmpty())
    {
        Q_EMIT openOBJFiles(filename);
        resetControlPanel();
        checkAvailability();
    }

}

void MyWindow::checkAvailability()
{
    bool availability = glWidget->is_model_loaded;

    xSlider->setEnabled(availability);
    ySlider->setEnabled(availability);
    zSlider->setEnabled(availability);

    foreach (QPushButton *button, Buttons)
    {
        button->setEnabled(availability);
    }

    scaleEdit->setEnabled(availability);
    t_xEdit->setEnabled(availability);
    t_yEdit->setEnabled(availability);
    t_zEdit->setEnabled(availability);
    r_xEdit->setEnabled(availability);
    r_yEdit->setEnabled(availability);
    r_zEdit->setEnabled(availability);

//    if(!availability)
//        openOBJFilesDialog();
}

void MyWindow::resetControlPanel()
{
    xSlider->setValue(0);
    ySlider->setValue(0);
    zSlider->setValue(0);

    scaleEdit->setText("1.0");
    t_xEdit->setText("0.0");
    t_yEdit->setText("0.0");
    t_zEdit->setText("0.0");
    r_xEdit->setText("0.0");
    r_yEdit->setText("0.0");
    r_zEdit->setText("0.0");
}


void MyWindow::keyPressEvent(QKeyEvent *e)
{
    if (e->key() == Qt::Key_Escape)
        close();
    else
        QWidget::keyPressEvent(e);
}
