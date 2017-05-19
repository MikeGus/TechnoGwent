#ifndef VISUALSCENEDESIGNER_H
#define VISUALSCENEDESIGNER_H

#include "visualscenebuilder.h"
#include "gamewindow.h"

class VisualSceneDesigner
{
public:
    VisualSceneDesigner(VisualSceneBuilder *_builder); // Передавая указатель на дочерник классы, мы можем строить любой уровень
    virtual ~VisualSceneDesigner();

    virtual GameWindow *getWindow(int width, int height);

protected:
    VisualSceneBuilder *builder; // На случай, если мы захотим переписать дезигнер в дочерних классах
};

#endif // VISUALSCENEDESIGNER_H
