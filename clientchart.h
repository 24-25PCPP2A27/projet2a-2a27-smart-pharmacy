#ifndef BARCHARTWIDGET_H
#define BARCHARTWIDGET_H

#include <QWidget>
#include <QMap>
#include <QString>

class clientchart : public QWidget {
    Q_OBJECT

public:
    explicit clientchart(const QMap<QString, int> &stats, QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    QMap<QString, int> stats;  // Data for the chart
};

#endif // BARCHARTWIDGET_H
