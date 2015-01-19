/********************************************************************************
** Form generated from reading UI file 'gglarddos.ui'
**
** Created
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GGLARDDOS_H
#define UI_GGLARDDOS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDateTimeEdit>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QStatusBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GGlaRDDOS
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_Wolf;
    QLineEdit *lineEdit_Wolf;
    QSpinBox *spinBox_Wolf;
    QCheckBox *checkBox_Wolf;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_Greg;
    QLineEdit *lineEdit_Greg;
    QSpinBox *spinBox_Greg;
    QCheckBox *checkBox_Greg;
    QHBoxLayout *horizontalLayout_3;
    QCheckBox *checkBox_RdPkt;
    QCheckBox *checkBox_fRST;
    QLabel *label_maxPkts;
    QSpinBox *spinBox_maxPkts;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_Speed;
    QSlider *horizontalSlider_Speed;
    QFrame *line_2;
    QHBoxLayout *horizontalLayout_4;
    QCheckBox *checkBox_Horde;
    QFrame *line;
    QLabel *label_Portal;
    QLineEdit *lineEdit_Portal;
    QLabel *label_Room;
    QLineEdit *lineEdit_Room;
    QLabel *label_Extension;
    QLineEdit *lineEdit_Extension;
    QFrame *line_3;
    QPushButton *pushButton_cake;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_2;
    QDateTimeEdit *dateTimeEdit;
    QSpacerItem *verticalSpacer;
    QFrame *line_4;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *GGlaRDDOS)
    {
        if (GGlaRDDOS->objectName().isEmpty())
            GGlaRDDOS->setObjectName(QString::fromUtf8("GGlaRDDOS"));
        GGlaRDDOS->resize(640, 480);
        GGlaRDDOS->setCursor(QCursor(Qt::CrossCursor));
        QIcon icon;
        icon.addFile(QString::fromUtf8("portal.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        GGlaRDDOS->setWindowIcon(icon);
        centralwidget = new QWidget(GGlaRDDOS);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_4 = new QVBoxLayout(centralwidget);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_Wolf = new QLabel(centralwidget);
        label_Wolf->setObjectName(QString::fromUtf8("label_Wolf"));

        horizontalLayout->addWidget(label_Wolf);

        lineEdit_Wolf = new QLineEdit(centralwidget);
        lineEdit_Wolf->setObjectName(QString::fromUtf8("lineEdit_Wolf"));

        horizontalLayout->addWidget(lineEdit_Wolf);

        spinBox_Wolf = new QSpinBox(centralwidget);
        spinBox_Wolf->setObjectName(QString::fromUtf8("spinBox_Wolf"));
        spinBox_Wolf->setMinimum(1);
        spinBox_Wolf->setMaximum(65535);
        spinBox_Wolf->setValue(1337);

        horizontalLayout->addWidget(spinBox_Wolf);

        checkBox_Wolf = new QCheckBox(centralwidget);
        checkBox_Wolf->setObjectName(QString::fromUtf8("checkBox_Wolf"));

        horizontalLayout->addWidget(checkBox_Wolf);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_Greg = new QLabel(centralwidget);
        label_Greg->setObjectName(QString::fromUtf8("label_Greg"));

        horizontalLayout_2->addWidget(label_Greg);

        lineEdit_Greg = new QLineEdit(centralwidget);
        lineEdit_Greg->setObjectName(QString::fromUtf8("lineEdit_Greg"));

        horizontalLayout_2->addWidget(lineEdit_Greg);

        spinBox_Greg = new QSpinBox(centralwidget);
        spinBox_Greg->setObjectName(QString::fromUtf8("spinBox_Greg"));
        spinBox_Greg->setMinimum(1);
        spinBox_Greg->setMaximum(65535);
        spinBox_Greg->setValue(1337);

        horizontalLayout_2->addWidget(spinBox_Greg);

        checkBox_Greg = new QCheckBox(centralwidget);
        checkBox_Greg->setObjectName(QString::fromUtf8("checkBox_Greg"));

        horizontalLayout_2->addWidget(checkBox_Greg);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        checkBox_RdPkt = new QCheckBox(centralwidget);
        checkBox_RdPkt->setObjectName(QString::fromUtf8("checkBox_RdPkt"));

        horizontalLayout_3->addWidget(checkBox_RdPkt);

        checkBox_fRST = new QCheckBox(centralwidget);
        checkBox_fRST->setObjectName(QString::fromUtf8("checkBox_fRST"));

        horizontalLayout_3->addWidget(checkBox_fRST);

        label_maxPkts = new QLabel(centralwidget);
        label_maxPkts->setObjectName(QString::fromUtf8("label_maxPkts"));

        horizontalLayout_3->addWidget(label_maxPkts);

        spinBox_maxPkts = new QSpinBox(centralwidget);
        spinBox_maxPkts->setObjectName(QString::fromUtf8("spinBox_maxPkts"));

        horizontalLayout_3->addWidget(spinBox_maxPkts);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_Speed = new QLabel(centralwidget);
        label_Speed->setObjectName(QString::fromUtf8("label_Speed"));

        horizontalLayout_5->addWidget(label_Speed);

        horizontalSlider_Speed = new QSlider(centralwidget);
        horizontalSlider_Speed->setObjectName(QString::fromUtf8("horizontalSlider_Speed"));
        horizontalSlider_Speed->setMinimum(1);
        horizontalSlider_Speed->setMaximum(1000);
        horizontalSlider_Speed->setPageStep(100);
        horizontalSlider_Speed->setSliderPosition(1);
        horizontalSlider_Speed->setOrientation(Qt::Horizontal);
        horizontalSlider_Speed->setTickPosition(QSlider::TicksBelow);
        horizontalSlider_Speed->setTickInterval(50);

        horizontalLayout_5->addWidget(horizontalSlider_Speed);


        verticalLayout_2->addLayout(horizontalLayout_5);

        line_2 = new QFrame(centralwidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        checkBox_Horde = new QCheckBox(centralwidget);
        checkBox_Horde->setObjectName(QString::fromUtf8("checkBox_Horde"));

        horizontalLayout_4->addWidget(checkBox_Horde);

        line = new QFrame(centralwidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout_4->addWidget(line);

        label_Portal = new QLabel(centralwidget);
        label_Portal->setObjectName(QString::fromUtf8("label_Portal"));

        horizontalLayout_4->addWidget(label_Portal);

        lineEdit_Portal = new QLineEdit(centralwidget);
        lineEdit_Portal->setObjectName(QString::fromUtf8("lineEdit_Portal"));
        lineEdit_Portal->setEnabled(false);

        horizontalLayout_4->addWidget(lineEdit_Portal);

        label_Room = new QLabel(centralwidget);
        label_Room->setObjectName(QString::fromUtf8("label_Room"));

        horizontalLayout_4->addWidget(label_Room);

        lineEdit_Room = new QLineEdit(centralwidget);
        lineEdit_Room->setObjectName(QString::fromUtf8("lineEdit_Room"));
        lineEdit_Room->setEnabled(false);

        horizontalLayout_4->addWidget(lineEdit_Room);

        label_Extension = new QLabel(centralwidget);
        label_Extension->setObjectName(QString::fromUtf8("label_Extension"));

        horizontalLayout_4->addWidget(label_Extension);

        lineEdit_Extension = new QLineEdit(centralwidget);
        lineEdit_Extension->setObjectName(QString::fromUtf8("lineEdit_Extension"));
        lineEdit_Extension->setEnabled(false);

        horizontalLayout_4->addWidget(lineEdit_Extension);


        verticalLayout_2->addLayout(horizontalLayout_4);


        verticalLayout_3->addLayout(verticalLayout_2);

        line_3 = new QFrame(centralwidget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout_3->addWidget(line_3);

        pushButton_cake = new QPushButton(centralwidget);
        pushButton_cake->setObjectName(QString::fromUtf8("pushButton_cake"));

        verticalLayout_3->addWidget(pushButton_cake);


        verticalLayout_4->addLayout(verticalLayout_3);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_6->addWidget(label_2);

        dateTimeEdit = new QDateTimeEdit(centralwidget);
        dateTimeEdit->setObjectName(QString::fromUtf8("dateTimeEdit"));
        dateTimeEdit->setReadOnly(true);

        horizontalLayout_6->addWidget(dateTimeEdit);


        verticalLayout_4->addLayout(horizontalLayout_6);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);

        line_4 = new QFrame(centralwidget);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        verticalLayout_4->addWidget(line_4);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_4->addWidget(label);

        GGlaRDDOS->setCentralWidget(centralwidget);
        menubar = new QMenuBar(GGlaRDDOS);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 640, 22));
        GGlaRDDOS->setMenuBar(menubar);
        statusbar = new QStatusBar(GGlaRDDOS);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        GGlaRDDOS->setStatusBar(statusbar);
#ifndef QT_NO_SHORTCUT
        label_Wolf->setBuddy(lineEdit_Wolf);
        label_Greg->setBuddy(lineEdit_Greg);
        label_maxPkts->setBuddy(spinBox_maxPkts);
        label_Speed->setBuddy(horizontalSlider_Speed);
        label_Portal->setBuddy(lineEdit_Portal);
        label_Room->setBuddy(lineEdit_Room);
        label_Extension->setBuddy(lineEdit_Extension);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(lineEdit_Wolf, lineEdit_Greg);
        QWidget::setTabOrder(lineEdit_Greg, spinBox_Wolf);
        QWidget::setTabOrder(spinBox_Wolf, spinBox_Greg);
        QWidget::setTabOrder(spinBox_Greg, checkBox_Wolf);
        QWidget::setTabOrder(checkBox_Wolf, checkBox_Greg);
        QWidget::setTabOrder(checkBox_Greg, checkBox_RdPkt);
        QWidget::setTabOrder(checkBox_RdPkt, checkBox_fRST);
        QWidget::setTabOrder(checkBox_fRST, spinBox_maxPkts);
        QWidget::setTabOrder(spinBox_maxPkts, horizontalSlider_Speed);
        QWidget::setTabOrder(horizontalSlider_Speed, pushButton_cake);
        QWidget::setTabOrder(pushButton_cake, checkBox_Horde);
        QWidget::setTabOrder(checkBox_Horde, lineEdit_Portal);
        QWidget::setTabOrder(lineEdit_Portal, lineEdit_Room);
        QWidget::setTabOrder(lineEdit_Room, lineEdit_Extension);
        QWidget::setTabOrder(lineEdit_Extension, dateTimeEdit);

        retranslateUi(GGlaRDDOS);

        QMetaObject::connectSlotsByName(GGlaRDDOS);
    } // setupUi

    void retranslateUi(QMainWindow *GGlaRDDOS)
    {
        GGlaRDDOS->setWindowTitle(QApplication::translate("GGlaRDDOS", "GLaRDDOS", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        label_Wolf->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        label_Wolf->setText(QApplication::translate("GGlaRDDOS", "Wolf", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        lineEdit_Wolf->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        checkBox_Wolf->setText(QApplication::translate("GGlaRDDOS", "Random port", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        label_Greg->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        label_Greg->setText(QApplication::translate("GGlaRDDOS", "Greg", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        lineEdit_Greg->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        lineEdit_Greg->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_ACCESSIBILITY
        lineEdit_Greg->setAccessibleName(QString());
#endif // QT_NO_ACCESSIBILITY
#ifndef QT_NO_ACCESSIBILITY
        lineEdit_Greg->setAccessibleDescription(QString());
#endif // QT_NO_ACCESSIBILITY
        checkBox_Greg->setText(QApplication::translate("GGlaRDDOS", "Random port", 0, QApplication::UnicodeUTF8));
        checkBox_RdPkt->setText(QApplication::translate("GGlaRDDOS", "Random packet", 0, QApplication::UnicodeUTF8));
        checkBox_fRST->setText(QApplication::translate("GGlaRDDOS", "Force TCP RST", 0, QApplication::UnicodeUTF8));
        label_maxPkts->setText(QApplication::translate("GGlaRDDOS", "Pkts per combination", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        spinBox_maxPkts->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        label_Speed->setText(QApplication::translate("GGlaRDDOS", "Speed (pkts/s)", 0, QApplication::UnicodeUTF8));
        checkBox_Horde->setText(QApplication::translate("GGlaRDDOS", "Horde", 0, QApplication::UnicodeUTF8));
        label_Portal->setText(QApplication::translate("GGlaRDDOS", "Portal", 0, QApplication::UnicodeUTF8));
        label_Room->setText(QApplication::translate("GGlaRDDOS", "Room", 0, QApplication::UnicodeUTF8));
        label_Extension->setText(QApplication::translate("GGlaRDDOS", "Extension", 0, QApplication::UnicodeUTF8));
        pushButton_cake->setText(QApplication::translate("GGlaRDDOS", "Bake the cake", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("GGlaRDDOS", "This cake has been baking since", 0, QApplication::UnicodeUTF8));
        dateTimeEdit->setDisplayFormat(QApplication::translate("GGlaRDDOS", "dd.MM.yyyy hh:mm", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("GGlaRDDOS", "Greetz to Good guy Greg, Insanity Wolf, Mitchunderstood and the guy who combines all three, DSK.", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class GGlaRDDOS: public Ui_GGlaRDDOS {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GGLARDDOS_H
