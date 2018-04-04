// -------------------------------------------------------------------------------------------------------------------
//  ******************** S.Q.U.A.D. coding ********************
//  File: SetAnchorTool.cpp
//
//
//
//  Author: Ronnie Foreman
//
// -------------------------------------------------------------------------------------------------------------------

#include "SetAnchorTool.h"

#include "ViewSettings.h"
#include "RTLSDisplayApplication.h"
#include "GraphicsView.h"
#include "GraphicsWidget.h"

#include <QCursor>
#include <QDebug>


SetAnchorTool::SetAnchorTool(QObject *parent) :
    AbstractTool(parent)
{
    px = 0.0;
    py = 0.0;
}

QCursor SetAnchorTool::cursor()
{
    return Qt::CrossCursor;
}

void SetAnchorTool::clicked(const QPointF &scenePos)
{
    QPointF b = scenePos;

    // Set x
    px = b.x();

    // Set y
    py = b.y();

    emit minimapClicked();
}

void SetAnchorTool::cancel()
{
    AbstractTool::cancel();
}

double SetAnchorTool::getXPosition()
{
    return px;
}
double SetAnchorTool::getYPosition()
{
    return py;
}
// ********************* S.Q.U.A.D. end **********************
