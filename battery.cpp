#include "battery.h"

Battery::Battery(QWidget *parent) : QWidget(parent)
{
    setContentsMargins(0,0,0,0);
    borderWidth = 4;
    headWidth = 20;
    value = 50;
    minValue = 0;
    maxValue = 100;
    alarmValue = 20;
    borderRadio = 5;
    drawInRadio = 3;
    borderColor = QColor(0, 102, 255);
}

void Battery::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);
    drawBorder(&painter);
    drawRightHead(&painter);
    drawBackground(&painter);
    drawText(&painter);
}

// 画边框
void Battery::drawBorder(QPainter *painter)
{
    painter->save();
    painter->setPen(QPen(borderColor,borderWidth));
    borderRect = QRect(borderWidth,borderWidth,width()-2*borderWidth-headWidth,height()-2*borderWidth);
    painter->drawRoundedRect(borderRect,borderRadio,borderRadio);
    painter->restore();
}

// 画右边电池头部
void Battery::drawRightHead(QPainter *painter)
{
    painter->save();
    double headHeight = height()/2;
    painter->setPen(Qt::NoPen);
    painter->setBrush(QColor(251, 1, 26));
    QRectF headRect = QRectF(width()-headWidth-borderWidth/2,height()/2-headHeight/2,headWidth,headHeight);
    painter->drawRect(headRect);
    painter->restore();
}

// 画数值对应颜色
void Battery::drawBackground(QPainter *painter)
{
    painter->save();
    double batteryWidth = width()-headWidth-3*borderWidth;                // 电池宽度
    double bgWidth= value * batteryWidth / (maxValue-minValue);           // 背景绘制宽度
    QLinearGradient batteryGradient(QPointF(0, 0), QPointF(borderWidth+bgWidth,height()));
    if (value <= alarmValue) {
        batteryGradient.setColorAt(0.0, QColor(255, 26, 0));
        batteryGradient.setColorAt(1.0, QColor(255, 0, 102));
    } else {
        batteryGradient.setColorAt(0.0, QColor(0, 255, 26));
        batteryGradient.setColorAt(1.0, QColor(102, 255, 0));
    }
    painter->setBrush(QBrush(batteryGradient));
    painter->setPen(Qt::NoPen);
    QRectF rectBg = QRectF(borderWidth+borderWidth/2,borderWidth+borderWidth/2,bgWidth,height()-3*borderWidth);
    painter->drawRoundedRect(rectBg,drawInRadio,drawInRadio);
    painter->restore();
}

// 画百分比数值
void Battery::drawText(QPainter *painter)
{
    painter->save();
    QString value_str = QString("%1%").arg(value);
    painter->setPen(QPen(QColor(Qt::black)));
    double w = qMin(borderRect.width(),borderRect.height());
    // 文字大小自适应   90为控件初始高度，30位字体默认大小
    int fontSize = 30 * w / 90;
    painter->setFont(QFont("Microsoft YaHei UI",fontSize));
    painter->drawText(borderRect,value_str,QTextOption(Qt::AlignHCenter | Qt::AlignVCenter));
    painter->restore();
}

// 设置当前值
void Battery::setValue(int value)
{
    this->value = value;
    update();
}

void Battery::setMinValue(int min)
{
    minValue = min;
    update();
}

void Battery::setMaxValue(int max)
{
    maxValue = max;
    update();
}

void Battery::setRange(int min, int max)
{
    minValue = min;
    maxValue = max;
    update();
}

void Battery::setBorderWidth(int width)
{
    borderWidth = width;
    update();
}

void Battery::setBorderRadio(int radio)
{
    borderRadio = radio;
    update();
}

void Battery::setInRadio(int radio)
{
    drawInRadio = radio;
    update();
}

void Battery::setAlarmValue(int alarm)
{
    alarmValue = alarm;
    update();
}

void Battery::setBorderColor(QColor color)
{
    borderColor = color;
    update();
}

int Battery::getValue()
{
    return  value;
}

int Battery::getMinValue()
{
    return  minValue;
}

int Battery::getMaxValue()
{
    return  maxValue;
}

int Battery::getAlarmValue()
{
    return  alarmValue;
}
