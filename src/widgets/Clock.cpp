#include "Clock.h"

TinyClock::TinyClock(QWidget* parent)
    : QWidget(parent)
    , layout(new QVBoxLayout(this))
    , timeDisplay(new QLabel(this))
    , dateDisplay(new QLabel(this))
{   
    QTimer* timer = new QTimer(this);
    
    connect(timer, &QTimer::timeout, timeDisplay, [this]() {
        timeDisplay->setText(QDateTime::currentDateTime().toString(TIME_FORMAT));
    });
    connect(timer, &QTimer::timeout, dateDisplay, [this]() {
        dateDisplay->setText(QDateTime::currentDateTime().toString(DATE_FORMAT));
    });
    
    timer->start(1000);
    timeDisplay->setText(QDateTime::currentDateTime().toString(TIME_FORMAT));
    dateDisplay->setText(QDateTime::currentDateTime().toString(DATE_FORMAT)); 

    layout->setSpacing(0);
    layout->setContentsMargins(0, 7, 0, 3); 
    layout->addWidget(timeDisplay, 0, Qt::AlignRight);     
    layout->addWidget(dateDisplay, 0, Qt::AlignRight);
   
    setFontSize(timeDisplay, 14);
    setFontSize(dateDisplay, 13);
}

void TinyClock::setFontSize(QLabel* label, int new_size) {
    QFont font = label->font();
    font.setPointSize(new_size);
    label->setFont(font);
}
