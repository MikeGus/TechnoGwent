#ifndef VISUALROW_H
#define VISUALROW_H

#include "visualcomponent.h"
<<<<<<< HEAD
#include "core/row.h"
=======
#include "row.h"
>>>>>>> 4026af8d9d5bd45dac1fd64a2de95be8ce04a6ca

class VisualRow : public VisualComponent
{
public:
    explicit VisualRow(QWidget *parent = 0, enum Row row = Row::melee);
    explicit VisualRow(const VisualRow &other) = delete;// TODO: maybe make a copy constructor for prototyping
    ~VisualRow() = default;

    void draw() override;
    Row getRow();

private:
    Row rowType;

};

#endif // VISUALROW_H
