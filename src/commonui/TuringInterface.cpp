#include "TuringInterface.h"
#include "ui_TuringInterface.h"
#include <QDebug>

// #define nodeStatus CNode*

using std::set;
using std::map;
using std::string;
using std::pair;


struct TuringMachine     //  图灵机的后端运算处理
{
    Ui::TuringInterface *ui;                            //  对接图灵机前端交互

    nodeStatus qStart;                                  //  开始状态
    nodeStatus qAccept;                                 //  结束状态
    set<nodeStatus> nodeStatusSet;                      //  全部状态集合
    string tapeString = "";                                  //  要处理的纸带字符串
    map<pair<nodeStatus, char>,
        pair<nodeStatus, string>> transferMap;          //  状态转移方程

    int moveHead(string nextAction)    //  读写头移动规则
    {
        if(nextAction[1] == 'L')
            return -1;
        else if(nextAction[1] == 'R')
            return 1;
        else
        {
            ui->consoleDisplay->append("Error: Wrong move!");
            return 0;
        }
    }

    bool TuringSimulator()
    {
        ui->consoleDisplay->clear();    //  清空显示区域

        nodeStatus curnodeStatus = qStart;

        // 待补充使 curnodeStatus 可视化的代码
        int diff = 0;

        for(auto i = tapeString.begin(); i != tapeString.end(); i += diff)     // 约束条件, 两侧不能越界
        {
            /*
            ui->consoleDisplay->append(
                        std::string(tapeString.begin(),i)
                        + curnodeStatus->getId()
                        + tapeString.mid(i, tapeString.length()-i-1))
                        );  // 这 QTL 的报错都啥玩意啊 ???
            */

            qDebug() << "current status = " << curnodeStatus->getId();

            ui->consoleDisplay->append(
                         (string(tapeString.begin(), i) +
                          curnodeStatus->getId().toStdString() +
                          string(i, tapeString.end()) ).c_str()
            );    // 展示运行状态

            string action = "";
            action += transferMap[{curnodeStatus, *i}].second;
            qDebug() << "Action = " << transferMap[{curnodeStatus, *i}].second.data();

            curnodeStatus = transferMap[{curnodeStatus, *i}].first;
            qDebug() << "next status = " << curnodeStatus->getId();

            qDebug() << "Tape = " << tapeString.data();

            // 待补充使 curnodeStatus 可视化的代码

            if(curnodeStatus == qAccept)
            {
                qDebug() << "Reach qAccept status! Success.";
                ui->consoleDisplay->append(
                             (string(tapeString.begin(), tapeString.end()) +
                              curnodeStatus->getId().toStdString()
                              ).c_str());
                return true;
            }

            *i = action[0];
            diff = moveHead(action);
        }
        return false;
    }
};

TuringInterface::TuringInterface(QWidget *parent) :
    QDockWidget(parent),
    ui(new Ui::TuringInterface)
{
    ui->setupUi(this);
    this->show();
}

TuringInterface::~TuringInterface()
{
    delete ui;
}

void TuringInterface::on_pushButton_clicked()
{
    string tapeString = "";
    tapeString += ui->tapeString->text().toStdString();
    string qStart = "";
    qStart += ui->qStart->text().toStdString();
    string qAccept = "";
    qAccept += ui->qAccept->text().toStdString();

    ui->consoleDisplay->setText((string("Input parameters:\n    "
                                         + tapeString + "\n" +
                                + "    " + qStart + "\n" +
                                + "    " + qAccept + "\nClick the Execute button to start the simulation. \n")
                                 ).c_str());
}

void TuringInterface::on_executeButton_clicked()
{
    TuringMachine turing {ui};       //  传入 ui 参数

    turing.tapeString += ui->tapeString->text().toStdString();
    string qStartName = "";
    qStartName += ui->qStart->text().toStdString();
    string qAcceptName = "";
    qAcceptName += ui->qAccept->text().toStdString();

    for(const auto node: graphFromScene->getItems<CNode>())
    {
        // nodeID = "qacc"
        string nodeID = "";
        nodeID += node->getId().toStdString();
        if(nodeID == qStartName)
        {
            turing.qStart = node;
            turing.nodeStatusSet.insert(node);  // 添加到状态集合

        }
        else if(nodeID == qAcceptName)
        {
            turing.qAccept = node;
            turing.nodeStatusSet.insert(node);
        }
        else
        {
            turing.nodeStatusSet.insert(node);
        }
    }

    for(const auto edge: graphFromScene->getItems<CEdge>())
    {
        // edgeID = "a/aR"
        string edgeID = "";
        edgeID += edge->getId().toStdString();
        turing.transferMap[{edge->firstNode(), edgeID[0]}]    // Key
                         = {edge->lastNode(), edgeID.substr(2, 2)};   // value
    }

    turing.TuringSimulator();
}
