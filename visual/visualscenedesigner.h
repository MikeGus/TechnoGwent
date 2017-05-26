#ifndef VISUALSCENEDESIGNER_H
#define VISUALSCENEDESIGNER_H

#include "visualscenebuilder.h"
#include "gamewindow.h"

class VisualSceneDesigner
{
public:
    VisualSceneDesigner(VisualSceneBuilder *_builder); // Building any kind of level simply by specifying different subclasses
    virtual ~VisualSceneDesigner();

    virtual GameWindow *getWindow(int width, int height);

protected:
    VisualSceneBuilder *builder; // In case we wanna change designer in subclasses
};

#endif // VISUALSCENEDESIGNER_H
