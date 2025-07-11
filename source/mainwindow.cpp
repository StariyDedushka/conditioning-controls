#include "include/mainwindow.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initMenu();
    initGraphics();
    this->setWindowTitle("Система кондиционирования");
    connect(action_quit, &QAction::triggered, this, &QMainWindow::close);
    connect(action_settings, &QAction::triggered, this, &MainWindow::slot_openSettings);
    connect(action_simulator, &QAction::triggered, this, &MainWindow::slot_openSimulator);
    connect(this, &MainWindow::signal_switch_pressed, this, &MainWindow::slot_cond_setColor);
    connect(StyleManager::instance(), &StyleManager::signal_styleChanged, this, &MainWindow::slot_updateStyle);

    slot_updateStyle(StyleManager::instance()->currentStyle());
}

MainWindow::~MainWindow()
{
    delete ui;
    delete scene;
}

void MainWindow::slot_updateStyle(const QString &newStyle)
{
    setStyleSheet(newStyle);
}

void MainWindow::initGraphics()
{
    scene = new QGraphicsScene();

    rect1 = new ColorRectItem(QRectF(30, 20, 120, 90));
    rect2 = new ColorRectItem(QRectF(180, 20, 120, 90));
    rect3 = new ColorRectItem(QRectF(105, 140, 120, 90));
    scene->addItem(rect1);
    scene->addItem(rect2);
    scene->addItem(rect3);

    ui->graphicsView->setScene(scene);
}

void MainWindow::slot_cond_setColor(const QColor &color)
{
    rect1->setColor(color);
    rect2->setColor(color);
    rect3->setColor(color);
}

void MainWindow::on_dial_temperature_valueChanged(int value)
{
    ui->display_temp->display(value);
    emit signal_dial_temp_changed(value);
}


void MainWindow::on_dial_angle_valueChanged(int angle)
{
    ui->display_angle->display(angle);
    emit signal_dial_direction_changed(angle);
}


void MainWindow::on_btn_switch_clicked()
{
    if(ui->btn_switch->isChecked())
    {
        ui->btn_switch->setText("Выключить");
        emit signal_switch_pressed(Qt::green);
    }
    else {
        ui->btn_switch->setText("Включить");
        emit signal_switch_pressed(Qt::gray);
    }
}

void MainWindow::initMenu()
{
    menu = ui->menubar->addMenu("Меню");
    action_quit = new QAction (menu);
    action_settings = new QAction(menu);
    action_simulator = new QAction(menu);

    action_quit->setText("Выход");
    action_simulator->setText("Симулятор");
    action_settings->setText("Настройки");

    menu->addAction(action_settings);
    menu->addAction(action_simulator);
    menu->addAction(action_quit);

}

void MainWindow::slot_tempMode(qint32 mode)
{
    QString modeText;
    static_cast<tempMode> (mode);
    switch(mode)
    {
    case celsius:
        modeText = "°C";
        break;
    case fahrenheit:
        modeText = "°F";
        break;
    case kelvin:
        modeText = "K";
        break;
    }

    ui->label_temperature->setText(modeText);
}


void MainWindow::slot_pressureMode(qint32 mode)
{
    QString modeText;
    static_cast<pressureMode> (mode);
    switch(mode)
    {
    case millimeters:
        modeText = "мм. рт. столба";
        break;
    case pascals:
        modeText = "KПа";
        break;
    }
    ui->label_pressure->setText(modeText);
}
void MainWindow::slot_openSettings()
{
    emit signal_openSettings();
}

void MainWindow::slot_openSimulator()
{
    emit signal_openSim();
}


void MainWindow::slot_tempRecalc(double temperature, qint32 dialMin, qint32 dialMax)
{
    ui->dial_temperature->setMinimum(dialMin);
    ui->dial_temperature->setMaximum(dialMax);
    ui->dial_temperature->setValue(temperature);
    ui->display_temp->display(qRound(temperature));
}

void MainWindow::slot_pressureRecalc(double pressure)
{
    ui->display_pressure->display(pressure);

}


void MainWindow::slot_loadSettings(tempMode currentTemperatureMode, pressureMode currentPressureMode, quint32 direction)
{
    qDebug() << "Direction:" << direction;
    ui->dial_angle->setValue(direction);
    ui->display_angle->display(static_cast<double>(direction));
}

void MainWindow::slot_humidityChanged(quint16 humidity)
{
    ui->display_humidity->display(humidity);
}
