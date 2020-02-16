#include "exlabel.h"

exlabel::exlabel(QWidget *parent) : QLabel(parent)
{

}

/**
 * @brief exlabel::mouseReleaseEvent
 * @param ev
 */
void exlabel::mouseReleaseEvent(QMouseEvent *ev)
{
    emit clicked(ev);
}

/**
 * @brief exlabel::enterEvent
 * @param e
 */
void exlabel::enterEvent(QEvent *e)
{
    Q_UNUSED(e)
    setStyleSheet("exlabel {background-color: "
                  "qlineargradient(spread:pad, x1:1, y1:0, x2:0, y2:0, "
                  "stop:0 rgba(0, 0, 0, 255), stop:1 rgba(0, 0, 0, 127));}");
}

/**
 * @brief exlabel::leaveEvent
 * @param e
 */
void exlabel::leaveEvent(QEvent *e)
{
    Q_UNUSED(e)
    setStyleSheet("exlabel {background-color: "
                  "qlineargradient(spread:pad, x1:1, y1:0, x2:0, y2:0, "
                  "stop:0 rgba(0, 0, 0, 255), stop:1 rgba(0, 0, 0, 0));}");
}
