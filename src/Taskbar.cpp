#include "Taskbar.h"

Taskbar::Taskbar(QWidget* parent) 
    : QWidget(parent)
    , m_leftArea(new QWidget)
    , m_centerArea(new QWidget)
    , m_rightArea(new QWidget)
    , m_leftLayout(new QHBoxLayout(m_leftArea))
    , m_centerLayout(new QHBoxLayout(m_centerArea))
    , m_rightLayout(new QHBoxLayout(m_rightArea))
    , m_listener(new HyprListener(this))
    , m_currentWorkspace(new QLabel(this))
    , m_numActiveWorkspaces(new QLabel(this))
{         
    this->setStyleSheet(BAR_STYLE_SHEET);
 
    initConnections();
    initLayout();
}


void Taskbar::initConnections() {
    QObject::connect(m_listener, &HyprListener::workspaceChanged, m_currentWorkspace, &QLabel::setText);
    QObject::connect(m_listener, &HyprListener::focusedWorkspaceChanged, m_currentWorkspace, &QLabel::setText);

    QObject::connect(m_listener, &HyprListener::activeWorkspacesChanged, m_numActiveWorkspaces, &QLabel::setText); 
}


void Taskbar::initLayout() {
    QHBoxLayout* mainLayout = new QHBoxLayout(this);

    mainLayout->setContentsMargins(5, 0, 5, 0);

    m_leftLayout->setContentsMargins(0, 0, 0, 0);
    m_centerLayout->setContentsMargins(0, 0, 0, 0);
    m_rightLayout->setContentsMargins(0, 0, 0, 0);

    m_leftLayout->addWidget(m_currentWorkspace);
    m_leftLayout->addWidget(m_numActiveWorkspaces, 1);

    m_rightLayout->addWidget(new TinyClock(this), 0, Qt::AlignRight); 

    mainLayout->addWidget(m_leftArea);
    mainLayout->addWidget(m_centerArea);
    mainLayout->addWidget(m_rightArea);

    mainLayout->setStretch(0, 1);
    mainLayout->setStretch(1, 1);
    mainLayout->setStretch(2, 1);
    
    setLayout(mainLayout);
}
