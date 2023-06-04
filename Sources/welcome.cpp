
/**
 * @file welcome.cpp
 * @author 杜忠璠
 * @date 2023/6/1
 * @brief 实现欢迎界面
 *
 */
#include "welcome.h"
#include "ui_welcome.h"

/**
 * @brief Welcome类的构造函数，用于初始化显示的内容
 */
Welcome::Welcome(QWidget *parent) : QDialog(parent),
                                    ui(new Ui::Welcome)
{
    ui->setupUi(this);
    ui->label->setText("欢迎使用本生日聚会计划便签");
    this->setAutoFillBackground(true);
    QPalette p = this->palette();
    QPixmap pix(":/R-C.jpg");
    QPixmap temp(pix.size());
    temp.fill(Qt::transparent); // 用透明色填充
    QPainter pp(&temp);
    pp.setCompositionMode(QPainter::CompositionMode_Source);        // 设置画笔的组合模式
    pp.drawPixmap(0, 0, pix);                                       // 绘制原图
    pp.setCompositionMode(QPainter::CompositionMode_DestinationIn); // 设置画笔的组合模式
    pp.fillRect(temp.rect(), QColor(0, 0, 0, 150));                 // 第四个参数为改透明度
    pp.end();
    pix = temp;
    p.setBrush(QPalette::Window, QBrush(pix)); // 设置画刷
    this->setPalette(p);
    setWindowTitle("欢迎");
}

/**
 * @brief Welcome类的析构函数，用于关闭窗口
 */
Welcome::~Welcome()
{
    delete ui;
}

/**
 * @brief 鼠标按下事件
 * @param event 事件
 */
void Welcome::mousePressEvent(QMouseEvent *event)
{
    Welcome::~Welcome(); // 关闭欢迎界面
}

/**
 * @brief 键盘按下事件
 * @param event 事件
 */
void Welcome::keyPressEvent(QKeyEvent *event)
{
    Welcome::~Welcome(); // 关闭欢迎界面
}
