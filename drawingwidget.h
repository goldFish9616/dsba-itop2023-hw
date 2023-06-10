#ifndef DRAWINGWIDGET_H
#define DRAWINGWIDGET_H

#include <QApplication>
#include <QHBoxLayout>
#include <QWidget>
#include <QPainter>
#include <QTextEdit>

class DrawingWidget : public QWidget
{
public:
    DrawingWidget(QWidget* parent = nullptr) : QWidget(parent) {}

protected:
    void paintEvent(QPaintEvent* event);
};

#endif // DRAWINGWIDGET_H
