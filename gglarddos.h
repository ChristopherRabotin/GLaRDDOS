#ifndef GGLARDDOS_H
#define GGLARDDOS_H
#include "backbone.h"
#include "socketplant.h"
#include "hordefactory.h"
#include <QtConcurrentRun>
#include <QMainWindow>
#include <QMessageBox>

namespace Ui {
    class GGlaRDDOS;
}

class GGlaRDDOS : public QMainWindow
{
    Q_OBJECT

public:
    explicit GGlaRDDOS(QWidget *parent = 0);
    ~GGlaRDDOS();

private:
    Ui::GGlaRDDOS *ui;
    bool bakingTheCake;
    void toggleBaking();
    QString initialStatusMsg;
    HordeFactory *hrd;

private slots:
    void toggleHordeMode();
    void cakeIsMitchunderstood();
    void bakeDatCake(QStringList aaargh);
};

#endif // GGLARDDOS_H
