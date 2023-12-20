// Written by https://stackoverflow.com/users/2868335/armatita

#ifndef SWITCHBUTTON_HPP
#define SWITCHBUTTON_HPP

#include <QLabel>
#include <QPropertyAnimation>
#include <QWidget>

class SwitchButton : public QWidget {
    Q_OBJECT
    Q_DISABLE_COPY(SwitchButton)

public:
    enum Style { YESNO, ONOFF, BOOL, EMPTY };

    explicit SwitchButton(QWidget* parent = nullptr, Style style = Style::ONOFF);
    ~SwitchButton() override;

    //-- QWidget methods
    void mousePressEvent(QMouseEvent*) override;
    void paintEvent(QPaintEvent* event) override;
    void enable(bool);

    //-- Setters
    void setDuration(int);
    void setValue(bool);

    //-- Getters
    [[nodiscard]] bool value() const;

signals:
    void valueChanged(bool newvalue);

private:
    class SwitchCircle;
    class SwitchBackground;
    void _update() const;

    bool _value;
    int _duration;

    QLinearGradient _lg;
    QLinearGradient _lg2;
    QLinearGradient _lg_disabled;

    QColor _pencolor;
    QColor _offcolor;
    QColor _oncolor;
    int _tol;
    int _borderradius;

    // This order for definition is important (these widgets overlap)
    QLabel* _labeloff;
    SwitchBackground* _background;
    QLabel* _labelon;
    SwitchCircle* _circle;

    bool _enabled;

    QPropertyAnimation* _btn_move;
    QPropertyAnimation* _back_move;
};

class SwitchButton::SwitchBackground : public QWidget {
    Q_OBJECT
    Q_DISABLE_COPY(SwitchBackground)

public:
    explicit SwitchBackground(QWidget* parent = nullptr, QColor color = QColor(154, 205, 50), bool rect = false);
    ~SwitchBackground() override = default;

    //-- QWidget methods
    void paintEvent(QPaintEvent* event) override;
    void enable(bool);

private:
    bool _rect;
    int _borderradius;
    QColor _color;
    QColor _pencolor;
    QLinearGradient _lg;
    QLinearGradient _lg_disabled;

    bool _enabled;
};


class SwitchButton::SwitchCircle : public QWidget {
    Q_OBJECT
    Q_DISABLE_COPY(SwitchCircle)

public:
    explicit SwitchCircle(QWidget* parent = nullptr, QColor color = QColor(255, 255, 255), bool rect = false);
    ~SwitchCircle() override = default;

    //-- QWidget methods
    void paintEvent(QPaintEvent* event) override;
    void enable(bool);

private:
    bool _rect;
    int _borderradius;
    QColor _color;
    QColor _pencolor;
    QRadialGradient _rg;
    QLinearGradient _lg;
    QLinearGradient _lg_disabled;

    bool _enabled;
};

#endif// !SWITCHBUTTON_HPP