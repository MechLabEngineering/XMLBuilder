#include <QtGui>
#include "DrawOnImageLayout.h"

DrawOnImageLayout::DrawOnImageLayout(QWidget *parent)
    : QWidget(parent)
{
   setBackgroundRole(QPalette::Base);
   x1 = x2 = y1 = y2 = lm = 0;
   setAttribute(Qt::WA_OpaquePaintEvent);
   //pixmap = new QPixmap("C:/Users/Administrator/Documents/QT/Beispiele/Bildbearbeitung/images/bild.png");
   pixmap = new QPixmap(QDir::currentPath()+"/StartImage.png");
}

void DrawOnImageLayout::mousePressEvent(QMouseEvent *event) {
   if (event->button() == Qt::LeftButton) {
      x1 = event->x();
      y1 = event->y();
      lm = Qt::LeftButton;
      update();
   }
   if (event->button() == Qt::RightButton) {
      x2 = event->x();
      y2 = event->y();
      lm = Qt::RightButton;
      update();
   }
}

void DrawOnImageLayout::paintEvent ( QPaintEvent * event ) {
   QPainter painter(this);

   if( lm == Qt::LeftButton )
   {
       painter.setPen( QPen(Qt::red, 3) );
       x2 = y2 = 0;
   }
   else
      painter.setPen( QPen(Qt::yellow, 3) );

   painter.drawPixmap( 0, 0, pixmap->width(), pixmap->height(), *pixmap );
   painter.drawPoint(x1,y1);
   if(x2 > x1 && y2 > y1)
        painter.drawRect(x1, y1, x2-x1, y2-y1 );
   //painter.setPen( QPen(Qt::green, 2) );
   //painter.drawText( 5, 180,
      //tr("Linke oder rechte Maustaste drücken") );

}
