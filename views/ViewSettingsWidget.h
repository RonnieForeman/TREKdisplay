// -------------------------------------------------------------------------------------------------------------------
//
//  File: ViewSettingsWidget.h
//
//  Copyright 2016 (c) Decawave Ltd, Dublin, Ireland.
//
//  All rights reserved.
//
//  Author:
//
// -------------------------------------------------------------------------------------------------------------------

#ifndef VIEWSETTINGSWIDGET_H
#define VIEWSETTINGSWIDGET_H

#include <QWidget>

// ******************** S.Q.U.A.D. coding ********************
#include "SetAnchorTool.h"
#include <QDebug>
#include "RTLSDisplayApplication.h"
// ********************* S.Q.U.A.D. end **********************

namespace Ui {
class ViewSettingsWidget;
}

class ViewSettingsWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ViewSettingsWidget(QWidget *parent = 0);
    ~ViewSettingsWidget();

    int applyFloorPlanPic(const QString &path);


signals:
    void saveViewSettings(void);
    // ******************** S.Q.U.A.D. coding ********************
    void updateAnchorXY(int id, int x, double value);
    void deleteSetAnchorTool();
    // ********************* S.Q.U.A.D. end **********************

protected slots:
    void onReady();

    void floorplanOpenClicked();
    void updateLocationFilter(int index);
    void enableFiltering(void);
    void originClicked();
    void scaleClicked();

    void gridShowClicked();
    void originShowClicked();
    void tagHistoryShowClicked();

    void saveFPClicked();
    void tagAncTableShowClicked();
    void useAutoPosClicked();
    void showGeoFencingModeClicked();
    void showNavigationModeClicked();
    void alarmSetClicked();

    void zone1ValueChanged(double);
    void zone2ValueChanged(double);
    void zone1EditFinished(void);
    void zone2EditFinished(void);
    void tagHistoryNumberValueChanged(int);

    void showOriginGrid(bool orig, bool grid);
    void getFloorPlanPic(void);
    void showSave(bool);

    void setTagHistory(int h);
    void loggingClicked(void);

    // ******************** S.Q.U.A.D. coding ********************
    void anchorSelectComboBoxChanged(int);
    void dropPenPushButtonPressed();
    void viewUpdateAnchorXY();
    // ********************* S.Q.U.A.D. end **********************
private:
    Ui::ViewSettingsWidget *ui;

    bool _logging ;
    bool _floorplanOpen ;

    // ******************** S.Q.U.A.D. coding ********************
    int m_iAnchor;
    double xPosition;
    double yPosition;
    bool m_bSetAnchor;
    SetAnchorTool *tool;
    RTLSDisplayApplication *RTLSDisplay;
    // ********************* S.Q.U.A.D. end **********************
};

#endif // VIEWSETTINGSWIDGET_H
