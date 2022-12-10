#ifndef TURINGINTERFACE_H
#define TURINGINTERFACE_H

#include <QDockWidget>
#include <map>
#include <set>
#include <CNodeEditorUIController.h>
#include <qvge/CNodeEditorScene.h>
#include <qvge/CNode.h>
#include <qvge/CEdge.h>

#define nodeStatus CNode*

namespace Ui
{
    class TuringInterface;
}

class TuringInterface : public QDockWidget  //  图灵机的前端交互页面
{
    Q_OBJECT

public:
    CNodeEditorScene *graphFromScene;       // 保存实时界面的图信息

public:
    explicit TuringInterface(QWidget *parent = nullptr);
    ~TuringInterface();

private slots:
    void on_pushButton_clicked();

    void on_executeButton_clicked();

private:
    Ui::TuringInterface *ui;
};



#endif // TURINGINTERFACE_H
