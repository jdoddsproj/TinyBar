#pragma once

#include <QDebug>
#include <QFileSystemWatcher>
#include <QFileInfo>
#include <QDir>
#include <QFile>
#include <QGuiApplication>
#include <QHBoxLayout>
#include <QLabel>
#include <QTimer>
#include <QDateTime>
#include <QLabel>
#include <QFont>
#include <QIcon>
#include <QFile>
#include <QPushButton>
#include <QSpacerItem>
#include <LayerShellQt/window.h>
#include "widgets/Clock.h"
#include "sockets/HyprListener.h"

using namespace LayerShellQt;

const auto BAR_STYLE_SHEET = R"(
    color: white; 
    background-color: #303030;
)";

class Taskbar : public QWidget {
public:
    explicit Taskbar(QWidget* parent = nullptr);

private:
    void initConnections();
    void initLayout();

    QWidget* m_leftArea, *m_centerArea, *m_rightArea;
    QHBoxLayout *m_leftLayout, *m_centerLayout, *m_rightLayout;

    HyprListener* m_listener = nullptr;
    
    QLabel* m_currentWorkspace = nullptr;
    QLabel* m_numActiveWorkspaces = nullptr; 
};
