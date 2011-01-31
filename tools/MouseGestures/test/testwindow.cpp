#include "testwindow.h"
#include "ui_testwindow.h"
#include "multistrokeRecognizers/multistrokeGesturesManagers.h"
#include "xmlparser.h"
#include "adopter.h"
#include <QFileDialog>

//todo::rename
const QString levPictureAlgorithm = "levenshtein dist and picture sorting";
const QString levCurveAlgorithm = "levenshtein dist and curve sorting";
const QString curvePictureAlgorithm = "curve dist and picture sorting";
const QString curveDistCurveSortAlgorithm = "curve dist and curve sorting";

TestWindow::TestWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::TestWindow)
{
    ui->setupUi(this);
    ui->cbAlgorithm->addItem(levPictureAlgorithm, QVariant());
    ui->cbAlgorithm->addItem(levCurveAlgorithm, QVariant());
    ui->cbAlgorithm->addItem(curvePictureAlgorithm, QVariant());
    ui->cbAlgorithm->addItem(curveDistCurveSortAlgorithm, QVariant());
    connect(ui->bTest, SIGNAL(clicked()), this, SLOT(test()));
    ui->pbTested->setValue(0);
}

void TestWindow::test()
{
    ui->pbTested->setValue(0);
    GesturesManager * gesturesManager = getGesturesManager();
    QMap<QString, UsersGestures> usersGestures = XmlParser::parseXml();
    QList<Entity> entities;
    int objectsNum = usersGestures.keys().size();
    foreach (QString key, usersGestures.keys())
    {
        PathVector path;
        path.push_back(usersGestures[key].first);
        entities.push_back(QPair<QString, PathVector>(key, path));
    }
    AbstractRecognizer * recognizer = new AbstractRecognizer(gesturesManager, entities);
    int all = 0;
    int recognized = 0;
    int notRecognized = 0;
    int checkedObjects = 0;
    foreach (QString object, usersGestures.keys())
    {
        foreach (QString pathStr, usersGestures[object].second)
        {
            all ++;
            QList<QPoint> path = Adopter::stringToPath(pathStr);
            if (object == recognizer->recognizeObject(path))
                recognized ++;
            else
                notRecognized ++;
        }
        checkedObjects ++;
        ui->pbTested->setValue(100 * checkedObjects / objectsNum);
    }
    ui->teAll->setText(QString::number(all));
    ui->teRecognized->setText(QString::number(recognized));
    ui->teNotRecognized->setText(QString::number(notRecognized));
}

GesturesManager * TestWindow::getGesturesManager()
{
    QString name = ui->cbAlgorithm->currentText();
    if (name == levPictureAlgorithm)
        return new LevPictureGesturesManager();
    else if (name == levCurveAlgorithm)
        return new LevCurveGesturesManager();
    else if (name == curvePictureAlgorithm)
        return new CurvePictureGesturesManager();
    else return new CurveDistCurveSortGesturesManager();
}

TestWindow::~TestWindow()
{
    delete ui;
}