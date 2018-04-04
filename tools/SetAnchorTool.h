// -------------------------------------------------------------------------------------------------------------------
//  ******************** S.Q.U.A.D. coding ********************
//  File: SetAnchorTool.h
//
//
//
//  Author: Ronnie
//
// -------------------------------------------------------------------------------------------------------------------

#ifndef SETANCHORTOOL_H
#define SETANCHORTOOL_H

#include "AbstractTool.h"

/**
 * The SetAnchorTool class is a tool used for setting anchor points by clicking on the minimap.
 *
 * It reacts to the clicked() event.
 * When clicked() is called, the anchor position is calculated based on the click position, and the tool finishes right away.
 * @see AbstractTool
 */
class SetAnchorTool : public AbstractTool
{
    Q_OBJECT
public:
    explicit SetAnchorTool(QObject *parent = 0);
    virtual ~SetAnchorTool() {}

    virtual QCursor cursor();

    /**
     * Handle mouse clicks.
     * This function calculate the new origin point based on \a scenePos, and updates it with the new value.
     * The tool then emits the done() signal.
     *
     * @param scenePos the position of the click in scene coordinates.
     */
    virtual void clicked(const QPointF &scenePos);
    double getXPosition();
    double getYPosition();

signals:
    void minimapClicked();

public slots:
    virtual void cancel();

private:
    double px;
    double py;
};

#endif // SETANCHORTOOL_H
// ********************* S.Q.U.A.D. end **********************
