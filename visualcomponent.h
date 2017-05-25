#ifndef VISUALCOMPONENT_H
#define VISUALCOMPONENT_H

#include <QWidget>

class VisualComponent : public QWidget
{
    Q_OBJECT

public:
    explicit VisualComponent(QWidget *parent = 0);
    explicit VisualComponent(const VisualComponent &other);
    virtual ~VisualComponent();

    virtual void draw();
    void show();

protected:
    QPixmap *buffer; // Is used for everything we draw

    void drawBuffer(); // Outputs buffer onto widget

    void paintEvent(QPaintEvent *pe) override; // Copying image from buffer onto the widget
    void resizeEvent(QResizeEvent *re) override; // Resizing buffer to fit the widget
};

#endif // VISUALCOMPONENT_H
