/********************************************************************************
** Form generated from reading UI file 'twoDModelWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.15
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TWODMODELWIDGET_H
#define UI_TWODMODELWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qrutils/graphicsUtils/abstractItem.h"
#include "qrutils/graphicsUtils/abstractItemView.h"
#include "src/engine/view/parts/detailsTab.h"
#include "src/engine/view/parts/gridParameters.h"
#include "src/engine/view/parts/palette.h"
#include "src/engine/view/parts/ruler.h"

QT_BEGIN_NAMESPACE

class Ui_TwoDModelWidget
{
public:
    QGridLayout *gridLayout;
    QWidget *toolbarWidget;
    QGridLayout *gridLayout_7;
    QWidget *mainTabBarWidget;
    QHBoxLayout *horizontalLayout;
    twoDModel::view::Palette *palette;
    QPushButton *runButton;
    QPushButton *stopButton;
    QPushButton *initialStateButton;
    QPushButton *trainingModeButton;
    QWidget *sceneWidget;
    QGridLayout *gridLayout_6;
    QWidget *sceneHeaderWidget;
    QHBoxLayout *horizontalLayout_3;
    twoDModel::view::GridParameters *gridParametersBox;
    QPushButton *speedDownButton;
    QDoubleSpinBox *timelineBox;
    QPushButton *speedUpButton;
    twoDModel::view::Ruler *horizontalRuler;
    twoDModel::view::Ruler *verticalRuler;
    QFrame *detailsPanel;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *toggleDetailsButton;
    QFrame *detailsContainer;
    QVBoxLayout *verticalLayout_2;
    twoDModel::view::DetailsTab *detailsTab;
    QFrame *portsFrame;
    QFormLayout *portsFormLayout;
    QFrame *motorsFrame;
    QVBoxLayout *verticalLayout_3;
    QLabel *leftWheelLabel;
    QComboBox *leftWheelComboBox;
    QLabel *rightWheelLabel;
    QComboBox *rightWheelComboBox;
    QFrame *physicsFrame;
    QVBoxLayout *verticalLayout;
    QCheckBox *realisticPhysicsCheckBox;
    QCheckBox *enableSensorNoiseCheckBox;
    QCheckBox *enableMotorNoiseCheckBox;
    QFrame *physicsParamsFrame;
    QFormLayout *formLayout;
    QLabel *wheelDiameter;
    QDoubleSpinBox *wheelDiamInCm;
    QLabel *robotHeight;
    QLabel *robotMass;
    QLabel *robotWidth;
    QDoubleSpinBox *robotHeightInCm;
    QDoubleSpinBox *robotWidthInCm;
    QDoubleSpinBox *robotMassInGr;
    QDoubleSpinBox *robotTrackInCm;
    QLabel *robotTrack;
    graphicsUtils::AbstractView *graphicsView;

    void setupUi(QWidget *TwoDModelWidget)
    {
        if (TwoDModelWidget->objectName().isEmpty())
            TwoDModelWidget->setObjectName(QString::fromUtf8("TwoDModelWidget"));
        TwoDModelWidget->resize(988, 669);
        gridLayout = new QGridLayout(TwoDModelWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        toolbarWidget = new QWidget(TwoDModelWidget);
        toolbarWidget->setObjectName(QString::fromUtf8("toolbarWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(toolbarWidget->sizePolicy().hasHeightForWidth());
        toolbarWidget->setSizePolicy(sizePolicy);
        gridLayout_7 = new QGridLayout(toolbarWidget);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout_7->setHorizontalSpacing(6);
        gridLayout_7->setContentsMargins(0, 0, 0, 0);
        mainTabBarWidget = new QWidget(toolbarWidget);
        mainTabBarWidget->setObjectName(QString::fromUtf8("mainTabBarWidget"));
        sizePolicy.setHeightForWidth(mainTabBarWidget->sizePolicy().hasHeightForWidth());
        mainTabBarWidget->setSizePolicy(sizePolicy);
        horizontalLayout = new QHBoxLayout(mainTabBarWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        palette = new twoDModel::view::Palette(mainTabBarWidget);
        palette->setObjectName(QString::fromUtf8("palette"));

        horizontalLayout->addWidget(palette);


        gridLayout_7->addWidget(mainTabBarWidget, 0, 0, 1, 2);

        runButton = new QPushButton(toolbarWidget);
        runButton->setObjectName(QString::fromUtf8("runButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(runButton->sizePolicy().hasHeightForWidth());
        runButton->setSizePolicy(sizePolicy1);
        runButton->setMinimumSize(QSize(44, 44));
        runButton->setMaximumSize(QSize(44, 44));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/2d_run.png"), QSize(), QIcon::Normal, QIcon::Off);
        runButton->setIcon(icon);
        runButton->setIconSize(QSize(44, 44));
        runButton->setFlat(true);

        gridLayout_7->addWidget(runButton, 3, 0, 1, 2);

        stopButton = new QPushButton(toolbarWidget);
        stopButton->setObjectName(QString::fromUtf8("stopButton"));
        sizePolicy1.setHeightForWidth(stopButton->sizePolicy().hasHeightForWidth());
        stopButton->setSizePolicy(sizePolicy1);
        stopButton->setMinimumSize(QSize(44, 44));
        stopButton->setMaximumSize(QSize(44, 44));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/2d_stop.png"), QSize(), QIcon::Normal, QIcon::Off);
        stopButton->setIcon(icon1);
        stopButton->setIconSize(QSize(44, 44));
        stopButton->setFlat(true);

        gridLayout_7->addWidget(stopButton, 4, 0, 1, 2);

        initialStateButton = new QPushButton(toolbarWidget);
        initialStateButton->setObjectName(QString::fromUtf8("initialStateButton"));
        QIcon icon2 = graphicsUtils::AbstractItem::loadTextColorIcon(":/icons/2d_robot_back.png");
        initialStateButton->setIcon(icon2);
        initialStateButton->setFlat(true);

        gridLayout_7->addWidget(initialStateButton, 2, 0, 1, 1);

        trainingModeButton = new QPushButton(toolbarWidget);
        trainingModeButton->setObjectName(QString::fromUtf8("trainingModeButton"));
        QIcon icon3 = graphicsUtils::AbstractItem::loadTextColorIcon(":/icons/2d_training.svg");
        trainingModeButton->setIcon(icon3);
        trainingModeButton->setCheckable(true);
        trainingModeButton->setFlat(true);

        gridLayout_7->addWidget(trainingModeButton, 1, 0, 1, 1);


        gridLayout->addWidget(toolbarWidget, 0, 1, 7, 1);

        sceneWidget = new QWidget(TwoDModelWidget);
        sceneWidget->setObjectName(QString::fromUtf8("sceneWidget"));
        gridLayout_6 = new QGridLayout(sceneWidget);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        sceneHeaderWidget = new QWidget(sceneWidget);
        sceneHeaderWidget->setObjectName(QString::fromUtf8("sceneHeaderWidget"));
        horizontalLayout_3 = new QHBoxLayout(sceneHeaderWidget);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        gridParametersBox = new twoDModel::view::GridParameters(sceneHeaderWidget);
        gridParametersBox->setObjectName(QString::fromUtf8("gridParametersBox"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(gridParametersBox->sizePolicy().hasHeightForWidth());
        gridParametersBox->setSizePolicy(sizePolicy2);

        horizontalLayout_3->addWidget(gridParametersBox);

        speedDownButton = new QPushButton(sceneHeaderWidget);
        speedDownButton->setObjectName(QString::fromUtf8("speedDownButton"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(speedDownButton->sizePolicy().hasHeightForWidth());
        speedDownButton->setSizePolicy(sizePolicy3);
        speedDownButton->setMaximumSize(QSize(16, 16));
        speedDownButton->setFocusPolicy(Qt::NoFocus);
        QIcon icon4 = graphicsUtils::AbstractItem::loadTextColorIcon(":/icons/2d_minus.svg");
        speedDownButton->setIcon(icon4);
        speedDownButton->setAutoRepeat(true);
        speedDownButton->setFlat(true);

        horizontalLayout_3->addWidget(speedDownButton);

        timelineBox = new QDoubleSpinBox(sceneHeaderWidget);
        timelineBox->setObjectName(QString::fromUtf8("timelineBox"));
        timelineBox->setEnabled(false);
        sizePolicy3.setHeightForWidth(timelineBox->sizePolicy().hasHeightForWidth());
        timelineBox->setSizePolicy(sizePolicy3);
        timelineBox->setMaximumSize(QSize(100, 16777215));
        timelineBox->setFocusPolicy(Qt::NoFocus);
        timelineBox->setContextMenuPolicy(Qt::NoContextMenu);
        timelineBox->setReadOnly(true);
        timelineBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
        timelineBox->setDecimals(3);
        timelineBox->setMaximum(2000000000.000000000000000);

        horizontalLayout_3->addWidget(timelineBox);

        speedUpButton = new QPushButton(sceneHeaderWidget);
        speedUpButton->setObjectName(QString::fromUtf8("speedUpButton"));
        sizePolicy3.setHeightForWidth(speedUpButton->sizePolicy().hasHeightForWidth());
        speedUpButton->setSizePolicy(sizePolicy3);
        speedUpButton->setMaximumSize(QSize(16, 16));
        speedUpButton->setFocusPolicy(Qt::NoFocus);
        QIcon icon5 = graphicsUtils::AbstractItem::loadTextColorIcon(":/icons/2d_plus.svg");
        speedUpButton->setIcon(icon5);
        speedUpButton->setAutoRepeat(true);
        speedUpButton->setFlat(true);

        horizontalLayout_3->addWidget(speedUpButton);


        gridLayout_6->addWidget(sceneHeaderWidget, 1, 1, 1, 3);

        horizontalRuler = new twoDModel::view::Ruler(sceneWidget);
        horizontalRuler->setObjectName(QString::fromUtf8("horizontalRuler"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(horizontalRuler->sizePolicy().hasHeightForWidth());
        horizontalRuler->setSizePolicy(sizePolicy4);
        horizontalRuler->setMinimumSize(QSize(0, 20));
        horizontalRuler->setMaximumSize(QSize(16777215, 20));
        horizontalRuler->setFrameShape(QFrame::Panel);
        horizontalRuler->setFrameShadow(QFrame::Sunken);
        horizontalRuler->setProperty("orientation", QVariant(1));

        gridLayout_6->addWidget(horizontalRuler, 2, 1, 1, 1);

        verticalRuler = new twoDModel::view::Ruler(sceneWidget);
        verticalRuler->setObjectName(QString::fromUtf8("verticalRuler"));
        verticalRuler->setMinimumSize(QSize(20, 0));
        verticalRuler->setMaximumSize(QSize(20, 16777215));
        verticalRuler->setFrameShape(QFrame::Panel);
        verticalRuler->setFrameShadow(QFrame::Sunken);
        verticalRuler->setProperty("orientation", QVariant(2));

        gridLayout_6->addWidget(verticalRuler, 3, 0, 1, 1);

        detailsPanel = new QFrame(sceneWidget);
        detailsPanel->setObjectName(QString::fromUtf8("detailsPanel"));
        QSizePolicy sizePolicy5(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(detailsPanel->sizePolicy().hasHeightForWidth());
        detailsPanel->setSizePolicy(sizePolicy5);
        detailsPanel->setFrameShape(QFrame::StyledPanel);
        detailsPanel->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(detailsPanel);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        toggleDetailsButton = new QPushButton(detailsPanel);
        toggleDetailsButton->setObjectName(QString::fromUtf8("toggleDetailsButton"));
        QSizePolicy sizePolicy6(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(toggleDetailsButton->sizePolicy().hasHeightForWidth());
        toggleDetailsButton->setSizePolicy(sizePolicy6);
        QIcon icon6 = graphicsUtils::AbstractItem::loadTextColorIcon(":/icons/2d_left.png");
        toggleDetailsButton->setIcon(icon6);

        horizontalLayout_2->addWidget(toggleDetailsButton);

        detailsContainer = new QFrame(detailsPanel);
        detailsContainer->setObjectName(QString::fromUtf8("detailsContainer"));
        sizePolicy5.setHeightForWidth(detailsContainer->sizePolicy().hasHeightForWidth());
        detailsContainer->setSizePolicy(sizePolicy5);
        detailsContainer->setFrameShape(QFrame::StyledPanel);
        verticalLayout_2 = new QVBoxLayout(detailsContainer);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(-1, 0, 0, 0);
        detailsTab = new twoDModel::view::DetailsTab(detailsContainer);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        detailsTab->setHeaderItem(__qtreewidgetitem);
        detailsTab->setObjectName(QString::fromUtf8("detailsTab"));
        detailsTab->setFocusPolicy(Qt::NoFocus);
        detailsTab->setFrameShape(QFrame::StyledPanel);
        detailsTab->setFrameShadow(QFrame::Plain);
        detailsTab->setProperty("showDropIndicator", QVariant(false));
        detailsTab->setSelectionMode(QAbstractItemView::NoSelection);
        detailsTab->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        detailsTab->setIndentation(10);
        detailsTab->setHeaderHidden(true);

        verticalLayout_2->addWidget(detailsTab);

        portsFrame = new QFrame(detailsContainer);
        portsFrame->setObjectName(QString::fromUtf8("portsFrame"));
        portsFrame->setFrameShape(QFrame::NoFrame);
        portsFormLayout = new QFormLayout(portsFrame);
        portsFormLayout->setObjectName(QString::fromUtf8("portsFormLayout"));
        portsFormLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        portsFormLayout->setHorizontalSpacing(0);
        portsFormLayout->setVerticalSpacing(0);
        portsFormLayout->setContentsMargins(-1, 0, -1, 0);

        verticalLayout_2->addWidget(portsFrame);

        motorsFrame = new QFrame(detailsContainer);
        motorsFrame->setObjectName(QString::fromUtf8("motorsFrame"));
        verticalLayout_3 = new QVBoxLayout(motorsFrame);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, -1, 0);
        leftWheelLabel = new QLabel(motorsFrame);
        leftWheelLabel->setObjectName(QString::fromUtf8("leftWheelLabel"));

        verticalLayout_3->addWidget(leftWheelLabel);

        leftWheelComboBox = new QComboBox(motorsFrame);
        leftWheelComboBox->setObjectName(QString::fromUtf8("leftWheelComboBox"));

        verticalLayout_3->addWidget(leftWheelComboBox);

        rightWheelLabel = new QLabel(motorsFrame);
        rightWheelLabel->setObjectName(QString::fromUtf8("rightWheelLabel"));

        verticalLayout_3->addWidget(rightWheelLabel);

        rightWheelComboBox = new QComboBox(motorsFrame);
        rightWheelComboBox->setObjectName(QString::fromUtf8("rightWheelComboBox"));

        verticalLayout_3->addWidget(rightWheelComboBox);


        verticalLayout_2->addWidget(motorsFrame);

        physicsFrame = new QFrame(detailsContainer);
        physicsFrame->setObjectName(QString::fromUtf8("physicsFrame"));
        verticalLayout = new QVBoxLayout(physicsFrame);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(-1, 0, -1, 0);
        realisticPhysicsCheckBox = new QCheckBox(physicsFrame);
        realisticPhysicsCheckBox->setObjectName(QString::fromUtf8("realisticPhysicsCheckBox"));

        verticalLayout->addWidget(realisticPhysicsCheckBox);

        enableSensorNoiseCheckBox = new QCheckBox(physicsFrame);
        enableSensorNoiseCheckBox->setObjectName(QString::fromUtf8("enableSensorNoiseCheckBox"));

        verticalLayout->addWidget(enableSensorNoiseCheckBox);

        enableMotorNoiseCheckBox = new QCheckBox(physicsFrame);
        enableMotorNoiseCheckBox->setObjectName(QString::fromUtf8("enableMotorNoiseCheckBox"));

        verticalLayout->addWidget(enableMotorNoiseCheckBox);


        verticalLayout_2->addWidget(physicsFrame);

        physicsParamsFrame = new QFrame(detailsContainer);
        physicsParamsFrame->setObjectName(QString::fromUtf8("physicsParamsFrame"));
        QSizePolicy sizePolicy7(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(physicsParamsFrame->sizePolicy().hasHeightForWidth());
        physicsParamsFrame->setSizePolicy(sizePolicy7);
        formLayout = new QFormLayout(physicsParamsFrame);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setSizeConstraint(QLayout::SetFixedSize);
        formLayout->setContentsMargins(-1, 0, -1, 0);
        wheelDiameter = new QLabel(physicsParamsFrame);
        wheelDiameter->setObjectName(QString::fromUtf8("wheelDiameter"));
        QSizePolicy sizePolicy8(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy8.setHorizontalStretch(0);
        sizePolicy8.setVerticalStretch(0);
        sizePolicy8.setHeightForWidth(wheelDiameter->sizePolicy().hasHeightForWidth());
        wheelDiameter->setSizePolicy(sizePolicy8);

        formLayout->setWidget(0, QFormLayout::LabelRole, wheelDiameter);

        wheelDiamInCm = new QDoubleSpinBox(physicsParamsFrame);
        wheelDiamInCm->setObjectName(QString::fromUtf8("wheelDiamInCm"));
        wheelDiamInCm->setReadOnly(true);

        formLayout->setWidget(0, QFormLayout::FieldRole, wheelDiamInCm);

        robotHeight = new QLabel(physicsParamsFrame);
        robotHeight->setObjectName(QString::fromUtf8("robotHeight"));
        sizePolicy8.setHeightForWidth(robotHeight->sizePolicy().hasHeightForWidth());
        robotHeight->setSizePolicy(sizePolicy8);

        formLayout->setWidget(1, QFormLayout::LabelRole, robotHeight);

        robotMass = new QLabel(physicsParamsFrame);
        robotMass->setObjectName(QString::fromUtf8("robotMass"));
        sizePolicy8.setHeightForWidth(robotMass->sizePolicy().hasHeightForWidth());
        robotMass->setSizePolicy(sizePolicy8);

        formLayout->setWidget(3, QFormLayout::LabelRole, robotMass);

        robotWidth = new QLabel(physicsParamsFrame);
        robotWidth->setObjectName(QString::fromUtf8("robotWidth"));
        sizePolicy8.setHeightForWidth(robotWidth->sizePolicy().hasHeightForWidth());
        robotWidth->setSizePolicy(sizePolicy8);

        formLayout->setWidget(2, QFormLayout::LabelRole, robotWidth);

        robotHeightInCm = new QDoubleSpinBox(physicsParamsFrame);
        robotHeightInCm->setObjectName(QString::fromUtf8("robotHeightInCm"));
        robotHeightInCm->setReadOnly(true);

        formLayout->setWidget(1, QFormLayout::FieldRole, robotHeightInCm);

        robotWidthInCm = new QDoubleSpinBox(physicsParamsFrame);
        robotWidthInCm->setObjectName(QString::fromUtf8("robotWidthInCm"));
        robotWidthInCm->setReadOnly(true);

        formLayout->setWidget(2, QFormLayout::FieldRole, robotWidthInCm);

        robotMassInGr = new QDoubleSpinBox(physicsParamsFrame);
        robotMassInGr->setObjectName(QString::fromUtf8("robotMassInGr"));
        robotMassInGr->setReadOnly(true);
        robotMassInGr->setMaximum(2000.000000000000000);

        formLayout->setWidget(3, QFormLayout::FieldRole, robotMassInGr);

        robotTrackInCm = new QDoubleSpinBox(physicsParamsFrame);
        robotTrackInCm->setObjectName(QString::fromUtf8("robotTrackInCm"));
        robotTrackInCm->setReadOnly(true);

        formLayout->setWidget(4, QFormLayout::FieldRole, robotTrackInCm);

        robotTrack = new QLabel(physicsParamsFrame);
        robotTrack->setObjectName(QString::fromUtf8("robotTrack"));
        sizePolicy8.setHeightForWidth(robotTrack->sizePolicy().hasHeightForWidth());
        robotTrack->setSizePolicy(sizePolicy8);

        formLayout->setWidget(4, QFormLayout::LabelRole, robotTrack);


        verticalLayout_2->addWidget(physicsParamsFrame);


        horizontalLayout_2->addWidget(detailsContainer);


        gridLayout_6->addWidget(detailsPanel, 2, 2, 2, 1);

        graphicsView = new graphicsUtils::AbstractView(sceneWidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        QSizePolicy sizePolicy9(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy9.setHorizontalStretch(1);
        sizePolicy9.setVerticalStretch(1);
        sizePolicy9.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy9);

        gridLayout_6->addWidget(graphicsView, 3, 1, 1, 1);


        gridLayout->addWidget(sceneWidget, 0, 4, 7, 1);


        retranslateUi(TwoDModelWidget);

        QMetaObject::connectSlotsByName(TwoDModelWidget);
    } // setupUi

    void retranslateUi(QWidget *TwoDModelWidget)
    {
        TwoDModelWidget->setWindowTitle(QCoreApplication::translate("TwoDModelWidget", "2D Robot Model", nullptr));
#if QT_CONFIG(tooltip)
        runButton->setToolTip(QCoreApplication::translate("TwoDModelWidget", "Run program", nullptr));
#endif // QT_CONFIG(tooltip)
        runButton->setText(QString());
#if QT_CONFIG(tooltip)
        stopButton->setToolTip(QCoreApplication::translate("TwoDModelWidget", "Stop program", nullptr));
#endif // QT_CONFIG(tooltip)
        stopButton->setText(QString());
        initialStateButton->setText(QString());
        trainingModeButton->setText(QString());
#if QT_CONFIG(tooltip)
        speedDownButton->setToolTip(QCoreApplication::translate("TwoDModelWidget", "Decrease speed", nullptr));
#endif // QT_CONFIG(tooltip)
        speedDownButton->setText(QString());
#if QT_CONFIG(tooltip)
        timelineBox->setToolTip(QCoreApplication::translate("TwoDModelWidget", "Time in 2D model", nullptr));
#endif // QT_CONFIG(tooltip)
        timelineBox->setSuffix(QCoreApplication::translate("TwoDModelWidget", " sec.", nullptr));
#if QT_CONFIG(tooltip)
        speedUpButton->setToolTip(QCoreApplication::translate("TwoDModelWidget", "Increase speed", nullptr));
#endif // QT_CONFIG(tooltip)
        speedUpButton->setText(QString());
        toggleDetailsButton->setText(QString());
        leftWheelLabel->setText(QCoreApplication::translate("TwoDModelWidget", "Left wheel:", nullptr));
        rightWheelLabel->setText(QCoreApplication::translate("TwoDModelWidget", "Right wheel:", nullptr));
        realisticPhysicsCheckBox->setText(QCoreApplication::translate("TwoDModelWidget", "Realistic physics", nullptr));
        enableSensorNoiseCheckBox->setText(QCoreApplication::translate("TwoDModelWidget", "Realistic sensors", nullptr));
        enableMotorNoiseCheckBox->setText(QCoreApplication::translate("TwoDModelWidget", "Realistic engines", nullptr));
        wheelDiameter->setText(QCoreApplication::translate("TwoDModelWidget", "Wheel diameter:", nullptr));
        robotHeight->setText(QCoreApplication::translate("TwoDModelWidget", "Robot height:", nullptr));
        robotMass->setText(QCoreApplication::translate("TwoDModelWidget", "Robot mass:", nullptr));
        robotWidth->setText(QCoreApplication::translate("TwoDModelWidget", "Robot width:", nullptr));
        robotTrack->setText(QCoreApplication::translate("TwoDModelWidget", "Robot track:", nullptr));
#if QT_CONFIG(tooltip)
        graphicsView->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
    } // retranslateUi

};

namespace Ui {
    class TwoDModelWidget: public Ui_TwoDModelWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TWODMODELWIDGET_H
