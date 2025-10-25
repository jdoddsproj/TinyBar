#pragma once

#include <QWidget>
#include <QSlider>

class VolumeSlider : public QSlider {
    Q_OBJECT
public:
    explicit VolumeSlider(QWidget* parent = nullptr);
};
