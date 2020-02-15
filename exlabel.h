#ifndef EXLABEL_H
#define EXLABEL_H

#include <QObject>
#include <QWidget>
#include <QLabel>

class exlabel : public QLabel
{
    Q_OBJECT
public:
    explicit exlabel(QWidget *parent = nullptr);

signals:
    void clicked(QMouseEvent *ev);

protected:
    void mouseReleaseEvent(QMouseEvent *ev);
    void enterEvent(QEvent*);
    void leaveEvent(QEvent*);

};

#endif // EXLABEL_H
