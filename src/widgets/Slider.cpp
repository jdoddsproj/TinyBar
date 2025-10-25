#include "Slider.h"

VolumeSlider::VolumeSlider(QWidget* parent) 
    : QSlider(Qt::Horizontal, parent) {
    setFixedSize(100, 20);
};

