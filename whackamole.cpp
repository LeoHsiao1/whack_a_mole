#include "whackamole.h"
#include "ui_whackamole.h"
#include "QLabel"
#include "QTime"
#include "QTimer"
#include "QMessageBox"
#include "QMouseEvent"

WhackAMole::WhackAMole(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WhackAMole)
{
    ui->setupUi(this);

    score = 0;
    total_time = 0;
    qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));

    this->setWindowOpacity(1);
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_TranslucentBackground);
}

WhackAMole::~WhackAMole()
{
    delete ui;
}

void WhackAMole::mousePressEvent(QMouseEvent *event){      //设置鼠标可拖动窗口
    if (event->button() == Qt::LeftButton)
    {
        dragPosition = event->globalPos() - frameGeometry().topLeft();
        event->accept();
    }
}

void WhackAMole::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton)
    {
        move(event->globalPos() - dragPosition);
        event->accept();
    }
}

void WhackAMole::timerEvent(QTimerEvent *event)   //处理定时器事件
{

    if(event->timerId() != t1)      //定时器每次溢出时函数timerId()都会响应，返回其id
        return;
    if(total_time == 10)
    {
        QMessageBox::warning(this, "游戏结束","你打中了"+QString::number(score)+"只地鼠，罚款"+QString::number(qrand()%100*score)+"元！",QMessageBox::Yes);
        //killTimer(t1);      //10s时游戏结束，停止定时器
        ++total_time;        //这里不停止定时器，让地鼠继续出现
        return;
    }
    ++total_time;
    if(total_time < 10)
        ui->label->setText("剩余时间："+QString::number(10-total_time)+"秒");   //10秒前正常显示剩余时间
    else
        ui->label->setText("剩余时间：∞秒");   //10秒后显示的剩余时间为无穷大
    ui->pushButton->move(qrand()%640+20,qrand()%270);               //把按钮移动到一个随机位置
    ui->pushButton_2->move(qrand()%640+20,qrand()%270);
    ui->pushButton_3->move(qrand()%640+20,qrand()%270);
    ui->pushButton->show();      //因为每次点击后按钮被hide了，所以隔1秒就重新显示
    ui->pushButton_2->show();
    ui->pushButton_3->show();
}

void WhackAMole::show_score()
{
    ui->label_2->setText("命中："+QString::number(score)+"只");
}

void WhackAMole::on_pushButton_4_clicked()
{
    t1 = startTimer(1000);       //开启一个定时器t1，定时为1000ms即1s
}


void WhackAMole::on_pushButton_clicked()
{
    ++score;
    show_score();
}

void WhackAMole::on_pushButton_2_clicked()
{
    ++score;
    show_score();
}

void WhackAMole::on_pushButton_3_clicked()
{
    ++score;
    show_score();
}
