#ifndef VISUALNULLROW_H
#define VISUALNULLROW_H

#include "visualrow.h"

class VisualNullRow: public VisualRow
{
public:
    explicit VisualNullRow(QWidget *parent = nullptr);
    explicit VisualNullRow(const VisualNullRow &other) = delete;// TODO: maybe make a copy constructor for prototyping
    ~VisualNullRow() = default;

    void draw() override; // Empty drawer: not drawing anythin, the object is null
};

#endif // VISUALNULLROW_H
