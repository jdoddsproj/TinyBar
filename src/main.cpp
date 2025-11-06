#include <QApplication>
#include <QScreen>
#include <QFont>
#include "Taskbar.h"

using namespace std;

inline const int BAR_HEIGHT = 48;

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QFont appFont = QFont("Mono Roboto", 16);
    app.setFont(appFont);

    // Bar widget setup
    Taskbar bar;
    bar.createWinId();
    bar.setMinimumHeight(BAR_HEIGHT);
    bar.setMaximumHeight(BAR_HEIGHT);
    bar.resize(QGuiApplication::primaryScreen()->size().width(), BAR_HEIGHT);
    bar.setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);

    // LayerShell setup
    QWindow* window = bar.windowHandle(); 
    Window* lsWindow = Window::get(window);

    using Anchor = Window::Anchor;
    using Anchors = Window::Anchors;
    Anchors anchors = Anchors(Anchor::AnchorTop) | Anchor::AnchorLeft | Anchor::AnchorRight;
    
    lsWindow->setAnchors(anchors);
    lsWindow->setExclusiveZone(BAR_HEIGHT);
    lsWindow->setLayer(Window::LayerTop);
    lsWindow->setKeyboardInteractivity(Window::KeyboardInteractivityNone); 

    bar.show();
    // Use for memory testing with Valgrind
    //QTimer::singleShot(30000, &app, &QApplication::quit);
    return app.exec();
}
