#include "drawingwidget.h"

void DrawingWidget::paintEvent(QPaintEvent* event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    QPen pen(Qt::black, 2, Qt::SolidLine);
    painter.setPen(pen);

    QBrush brush(Qt::yellow, Qt::SolidPattern);
    QBrush brush2(Qt::green, Qt::SolidPattern);
    painter.setBrush(brush);

    QFont font;
    font.setPointSize(15);

    painter.drawRect(50, 50, 100, 100);
    painter.drawEllipse(100, 100, 100, 100);
    painter.setBrush(brush2);
    painter.drawEllipse(150, 150, 150, 150);
    painter.setFont(font);
    painter.drawText(80, 100, "H");
    painter.drawText(150, 160, "S");
    painter.drawText(230, 230, "E");
}
