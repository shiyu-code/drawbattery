#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("电池绘制");
#if 0
    void setValue(int value);           // 设置当前值
    void setMinValue(int min);          // 设置最小值
    void setMaxValue(int max);          // 设置最大值
    void setRange(int min,int max);     // 设置数值范围
    void setBorderWidth(int width);     // 设置边框宽度
    void setBorderRadio(int radio);     // 设置外边框圆角
    void setInRadio(int radio);         // 设置内部绘制区域圆角
    void setAlarmValue(int alarm);      // 设置警告值
    void setBorderColor(QColor color);  // 设置边框颜色
    int getValue();                     // 获取当前值
    int getMinValue();                  // 获取当前最小值
    int getMaxValue();                  // 获取当前最大值
    int getAlarmValue();                // 获取告警值
#endif
}

MainWindow::~MainWindow()
{
    delete ui;
}

// 改变数值
void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    ui->widget->setValue(value);
}
