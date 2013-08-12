#ifndef DRAWONIMAGELAYOUT_H
#define DRAWONIMAGELAYOUT_H

#include <QWidget>

class DrawOnImageLayout : public QWidget
{
    Q_OBJECT
public:
   DrawOnImageLayout(QWidget *parent);
   void setImage(const QString& s){pixmap->load(s); update();}
   int getImageWidth() {return pixmap->width();}
   int getImageHeight() {return pixmap->height();}
   int getRoiX() {return x1;}
   int getRoiY() {return y1;}
   int getRoiWidth() {return x2-x1;}
   int getRoiHeight() {return y2-y1;}
protected:
   void mousePressEvent( QMouseEvent* event);
   void paintEvent(QPaintEvent *event);
private:
   QPixmap *pixmap;
   int x1, x2, y1, y2, lm;
};

#endif // DRAWONIMAGELAYOUT_H
