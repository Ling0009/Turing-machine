/********************************************************************************
** Form generated from reading UI file 'TuringInterface.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TURINGINTERFACE_H
#define UI_TURINGINTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TuringInterface
{
public:
    QWidget *dockWidgetContents;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label_5;
    QLabel *label;
    QLineEdit *tapeString;
    QLabel *label_2;
    QLineEdit *qStart;
    QLabel *label_3;
    QLineEdit *qAccept;
    QFrame *line;
    QLabel *label_4;
    QTextEdit *consoleDisplay;
    QGroupBox *horizontalGroupBox;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *executeButton;

    void setupUi(QDockWidget *TuringInterface)
    {
        if (TuringInterface->objectName().isEmpty())
            TuringInterface->setObjectName(QString::fromUtf8("TuringInterface"));
        TuringInterface->resize(370, 378);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QString::fromUtf8("dockWidgetContents"));
        verticalLayout_2 = new QVBoxLayout(dockWidgetContents);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_5 = new QLabel(dockWidgetContents);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        QFont font;
        font.setPointSize(10);
        label_5->setFont(font);

        verticalLayout->addWidget(label_5);

        label = new QLabel(dockWidgetContents);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        tapeString = new QLineEdit(dockWidgetContents);
        tapeString->setObjectName(QString::fromUtf8("tapeString"));

        verticalLayout->addWidget(tapeString);

        label_2 = new QLabel(dockWidgetContents);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        qStart = new QLineEdit(dockWidgetContents);
        qStart->setObjectName(QString::fromUtf8("qStart"));

        verticalLayout->addWidget(qStart);

        label_3 = new QLabel(dockWidgetContents);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout->addWidget(label_3);

        qAccept = new QLineEdit(dockWidgetContents);
        qAccept->setObjectName(QString::fromUtf8("qAccept"));

        verticalLayout->addWidget(qAccept);

        line = new QFrame(dockWidgetContents);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        label_4 = new QLabel(dockWidgetContents);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);

        verticalLayout->addWidget(label_4);

        consoleDisplay = new QTextEdit(dockWidgetContents);
        consoleDisplay->setObjectName(QString::fromUtf8("consoleDisplay"));
        consoleDisplay->setReadOnly(true);

        verticalLayout->addWidget(consoleDisplay);

        horizontalGroupBox = new QGroupBox(dockWidgetContents);
        horizontalGroupBox->setObjectName(QString::fromUtf8("horizontalGroupBox"));
        horizontalLayout = new QHBoxLayout(horizontalGroupBox);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton = new QPushButton(horizontalGroupBox);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);

        executeButton = new QPushButton(horizontalGroupBox);
        executeButton->setObjectName(QString::fromUtf8("executeButton"));

        horizontalLayout->addWidget(executeButton);


        verticalLayout->addWidget(horizontalGroupBox);


        verticalLayout_2->addLayout(verticalLayout);

        TuringInterface->setWidget(dockWidgetContents);

        retranslateUi(TuringInterface);

        QMetaObject::connectSlotsByName(TuringInterface);
    } // setupUi

    void retranslateUi(QDockWidget *TuringInterface)
    {
        TuringInterface->setWindowTitle(QCoreApplication::translate("TuringInterface", "Turing Machine Interface", nullptr));
        label_5->setText(QCoreApplication::translate("TuringInterface", "Please enter the following parameters:", nullptr));
        label->setText(QCoreApplication::translate("TuringInterface", "Tape String", nullptr));
        tapeString->setText(QCoreApplication::translate("TuringInterface", "aab#aab ", nullptr));
        label_2->setText(QCoreApplication::translate("TuringInterface", "Qstart", nullptr));
        qStart->setText(QCoreApplication::translate("TuringInterface", "q0", nullptr));
        label_3->setText(QCoreApplication::translate("TuringInterface", "Qaccept", nullptr));
        qAccept->setText(QCoreApplication::translate("TuringInterface", "qacc", nullptr));
        label_4->setText(QCoreApplication::translate("TuringInterface", "Console:", nullptr));
        pushButton->setText(QCoreApplication::translate("TuringInterface", "Push", nullptr));
        executeButton->setText(QCoreApplication::translate("TuringInterface", "Execute", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TuringInterface: public Ui_TuringInterface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TURINGINTERFACE_H
