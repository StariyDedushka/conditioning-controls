#include "include/stylemanager.h"

StyleManager* StyleManager::instance() {
    static StyleManager instance;
    return &instance;
}

StyleManager::StyleManager(QObject *parent) : QObject(parent) {
    m_styleDarkMode = QString("QMainWindow { background: rgb(80, 80, 80); }"
    "QGraphicsView { background: rgb(60, 60, 60); } "

    "QLabel { color: white; }"

    "QGroupBox { color: white; }"

    "QLCDNumber { color: white; border: white; }"

    "QDial { color:white; background: rgb(60, 60, 60); }"

  "QPushButton{ color:white; background: rgb(60,60,60);}"
  ".QWidget { background: rgb(80, 80, 80);} "
  "QCheckBox { color: white;}"
                              "QComboBox { color: white; background-color: rgb(80, 80, 80);}"
                              "QMenuBar { background: rgb(60, 60, 60); color: white; }"
                              "QMenu { background: rgb(60,60,60); } "
                              "QMenu::item { color: white; background-color: transparent; }"
                              "Settings { background: rgb(80, 80, 80); }"
                              "Simulator { background: rgb(80, 80, 80); }"
                              );
}

QString StyleManager::currentStyle() const
{
    return m_currentStyle;
}

void StyleManager::setStyleDark(bool isDark)
{
    if(isDark)
    {
        emit signal_styleChanged(m_styleDarkMode);  // Оповещаем всех подписчиков
    } else {
        emit signal_styleChanged(m_styleLightMode);
    }
}
