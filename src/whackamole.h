#ifndef WHACKAMOLE_H
#define WHACKAMOLE_H

#include <QMainWindow>

namespace Ui {
class WhackAMole;
}

class WhackAMole : public QMainWindow
{
    Q_OBJECT

public:
    explicit WhackAMole(QWidget *parent = 0);
    ~WhackAMole();

private:
    Ui::WhackAMole *ui;
    int score,t1,total_time;
    QTimer *timer;
    void show_score();

    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    QPoint dragPosition;

private slots:
    void timerEvent(QTimerEvent *);
    void on_pushButton_4_clicked();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
};

#endif // WHACKAMOLE_H
