#pragma once

#include <QLabel>
#include <QTimer>
#include <QDateTime>
#include <QString>
#include <QWidget>
#include <QVBoxLayout>
#include <QFont>
#include <QPushButton>

inline const QString TIME_FORMAT = "h:mm AP";
inline const QString DATE_FORMAT = "MM/dd/yyyy";

class TinyClock : public QWidget {
public:
    explicit TinyClock(QWidget* parent = nullptr);
    void setFontSize(QLabel* label, int new_size); 

private:
    QVBoxLayout* layout = nullptr;
    QLabel* timeDisplay = nullptr;
    QLabel* dateDisplay = nullptr;
};
