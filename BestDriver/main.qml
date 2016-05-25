import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Controls 1.4;
import QtQuick.Controls.Styles 1.4

Window {
    visible: true

    property int year: __ui__year;
    property int month: __ui__month;
    property int day: __ui__day;

    property int calCellWidth: width/7;
    property int calCellHeight: height/8;
    property int scrWidth: Screen.width; //500;
    property int scrHeight: Screen.height; //800;

    width: scrWidth;
    height: scrHeight;

    property bool group1Visible: false;
    property bool group2Visible: false;
    property bool group3Visible: false;
    property bool group4Visible: false;
    property bool group5Visible: false;
    property int colSpacing: scrHeight * 0.01;
    property int rowSpacing: scrWidth * 0.02;

    signal sigCheckGroup(int group, int val);
    id: m_mainWindow;
    Calendar {
        id: m_cal;
        width: scrWidth;
        height: scrHeight*0.8;
        style: CalendarStyle {
            dayDelegate: Item {
                readonly property int groupColorWidth: width;
                readonly property int groupColorHeight: height/3;
                readonly property int groupColorMargin: 6;
                readonly property color invalidDatecolor: "#dddddd";
                readonly property color sameMonthDateTextColor: "#444";
                readonly property color differentMonthDateTextColor: "#bbb";

                Rectangle {
                    id: m_day;
                    anchors.fill: parent;
                    border.width: 4;
                    border.color: styleData.date !== undefined &&
                              styleData.selected ?
                                  "red" : "white";
                    clip: true;
                    Column {
                        Row {
                            Label {
                                width: groupColorWidth;
                                height: groupColorHeight;
                                id: m_dayDelegateText
                                text: {
                                    return styleData.date.getDate();
                                }
                                font.pixelSize: groupColorHeight * 0.6;
                                color: {
                                    var color = invalidDatecolor;
                                    if (styleData.valid) {
                                        // Date is within the valid range.
                                        if(styleData.visibleMonth) { //?
                                            if(calendarModel.getHoliday(styleData.date)) {
                                                color = "#ff0000";
                                            } else {
                                                color = sameMonthDateTextColor;
                                            }
                                        } else {
                                            color = differentMonthDateTextColor;
                                        }
                                    }
                                    color;
                                }
                            }
                        }
                        Rectangle {
                            visible: group1Visible
                                    && calendarModel.getEventForDate(0, styleData.date);
                            width: groupColorWidth;
                            height: groupColorHeight;
                            color: "#64dd0000";
                            Text {
                                anchors.fill: parent;
                                anchors.leftMargin: groupColorMargin;
                                text: "가";
                                font.bold: true;
                                font.pixelSize: groupColorHeight * 0.5;
                                verticalAlignment: Text.AlignVCenter;
                            }
                        }
                        Rectangle {
                            visible: group2Visible
                                    && calendarModel.getEventForDate(1, styleData.date);
                            width: groupColorWidth;
                            height: groupColorHeight;
                            color: "#6400dd00";
                            Text {
                                anchors.fill: parent;
                                anchors.leftMargin: groupColorMargin;
                                text: "나";
                                font.bold: true;
                                font.pixelSize: groupColorHeight * 0.5;
                                verticalAlignment: Text.AlignVCenter;
                            }
                        }
                        Rectangle {
                            visible: group3Visible
                                    && calendarModel.getEventForDate(2, styleData.date);
                            width: groupColorWidth;
                            height: groupColorHeight;
                            color: "#640000dd";
                            Text {
                                anchors.fill: parent;
                                anchors.leftMargin: groupColorMargin;
                                text: "다";
                                font.bold: true;
                                font.pixelSize: groupColorHeight * 0.5;
                                verticalAlignment: Text.AlignVCenter;
                            }
                        }
                        Rectangle {
                            visible: group4Visible
                                    && calendarModel.getEventForDate(3, styleData.date);
                            width: groupColorWidth;
                            height: groupColorHeight;
                            color: "#64dddd00";
                            Text {
                                anchors.fill: parent;
                                anchors.leftMargin: groupColorMargin;
                                text: "라(홀)";
                                font.bold: true;
                                font.pixelSize: groupColorHeight * 0.5;
                                verticalAlignment: Text.AlignVCenter;
                            }
                        }
                        Rectangle {
                            visible: group5Visible
                                    && calendarModel.getEventForDate(4, styleData.date);
                            width: groupColorWidth;
                            height: groupColorHeight;
                            color: "#6400dddd";
                            Text {
                                anchors.fill: parent;
                                anchors.leftMargin: groupColorMargin;
                                text: "라(짝)";
                                font.bold: true;
                                font.pixelSize: groupColorHeight * 0.5;
                                verticalAlignment: Text.AlignVCenter;
                            }
                        }
                    }
                }
            }
        }
    }

    property color colorChk1: "#4bd8b1";
    property color colorChk1p: "#517bd2"
    property color colorChk2: "#4bd8b1";
    property color colorChk2p: "#517bd2"
    property color colorChk3: "#4bd8b1";
    property color colorChk3p: "#517bd2"
    property color colorChk4: "#4bd8b1";
    property color colorChk4p: "#517bd2"
    property color colorChk5: "#4bd8b1";
    property color colorChk5p: "#517bd2"
    Rectangle {
        id: m_check1
        x: rowSpacing;
        anchors.top: m_cal.bottom;
        anchors.topMargin: colSpacing;
        width: (scrWidth-50)/3;
        height: scrHeight * 0.05;
        Text {
            id: m_check1txt
            anchors.fill: parent;
            text: "가";
            font.pixelSize: height * 0.5;
            font.bold: true;
            verticalAlignment: Text.AlignVCenter;
            horizontalAlignment: Text.AlignHCenter;
        }
        color: colorChk1;
        MouseArea {
            anchors.fill: parent;
            onPressed: {
                if(m_check1.color == colorChk1) {
                    m_check1.color = colorChk1p;
                    m_check1txt.text = "가(*)";
                    group1Visible = true;
                    sigCheckGroup(1, 1);
                } else {
                    m_check1.color = colorChk1;
                    m_check1txt.text = "가";
                    group1Visible = false;
                    sigCheckGroup(1, 0);
                }
            }
        }
    }
    Rectangle {
        id: m_check2;
        anchors.left: m_check1.right
        anchors.leftMargin: rowSpacing;
        anchors.top: m_cal.bottom;
        anchors.topMargin: colSpacing;
        width: (scrWidth-50)/3;
        height: scrHeight * 0.05;
        Text {
            id: m_check2txt;
            anchors.fill: parent;
            text: "나";
            font.pixelSize: height * 0.5;
            font.bold: true;
            verticalAlignment: Text.AlignVCenter;
            horizontalAlignment: Text.AlignHCenter;
        }
        color: colorChk2;
        MouseArea {
            anchors.fill: parent;
            onPressed: {
                if(m_check2.color == colorChk1) {
                    m_check2.color = colorChk1p;
                    m_check2txt.text = "나(*)";
                    group2Visible = true;
                    sigCheckGroup(2, 1);
                } else {
                    m_check2.color = colorChk1;
                    m_check2txt.text = "나";
                    group2Visible = false;
                    sigCheckGroup(2, 0);
                }
            }
        }
    }
    Rectangle {
        id: m_check3;
        anchors.left: m_check2.right
        anchors.leftMargin: rowSpacing;
        anchors.top: m_cal.bottom;
        anchors.topMargin: colSpacing;
        width: (scrWidth-50)/3;
        height: scrHeight * 0.05;
        Text {
            id: m_check3txt;
            anchors.fill: parent;
            text: "다";
            font.pixelSize: height * 0.5;
            font.bold: true;
            verticalAlignment: Text.AlignVCenter;
            horizontalAlignment: Text.AlignHCenter;
        }
        color: colorChk3;
        MouseArea {
            anchors.fill: parent;
            onPressed: {
                if(m_check3.color == colorChk1) {
                    m_check3.color = colorChk1p;
                    m_check3txt.text = "다(*)";
                    group3Visible = true;
                    sigCheckGroup(3, 1);
                } else {
                    m_check3.color = colorChk1;
                    m_check3txt.text = "다";
                    group3Visible = false;
                    sigCheckGroup(3, 0);
                }
            }
        }
    }

    Rectangle {
        id: m_check4
        x: rowSpacing;
        anchors.top: m_check1.bottom;
        anchors.topMargin: colSpacing;
        width: (scrWidth-50)/3;
        height: scrHeight * 0.05;
        Text {
            id: m_check4txt;
            anchors.fill: parent;
            text: "라(홀)";
            font.pixelSize: height * 0.5;
            font.bold: true;
            verticalAlignment: Text.AlignVCenter;
            horizontalAlignment: Text.AlignHCenter;
        }
        color: colorChk4;
        MouseArea {
            anchors.fill: parent;
            onPressed: {
                if(m_check4.color == colorChk1) {
                    m_check4.color = colorChk1p;
                    m_check4txt.text = "라(홀)(*)";
                    group4Visible = true;
                    sigCheckGroup(4, 1);
                } else {
                    m_check4.color = colorChk1;
                    m_check4txt.text = "라(홀)";
                    group4Visible = false;
                    sigCheckGroup(4, 0);
                }
            }
        }
    }
    Rectangle {
        id: m_check5;
        anchors.left: m_check4.right
        anchors.leftMargin: rowSpacing;
        anchors.top: m_check2.bottom;
        anchors.topMargin: colSpacing;
        width: (scrWidth-50)/3;
        height: scrHeight * 0.05;
        Text {
            id: m_check5txt;
            anchors.fill: parent;
            text: "라(짝)";
            font.pixelSize: height * 0.5;
            font.bold: true;
            verticalAlignment: Text.AlignVCenter;
            horizontalAlignment: Text.AlignHCenter;
        }
        color: colorChk5;
        MouseArea {
            anchors.fill: parent;
            onPressed: {
                if(m_check5.color == colorChk1) {
                    m_check5.color = colorChk1p;
                    m_check5txt.text = "라(짝)(*)";
                    group5Visible = true;
                    sigCheckGroup(5, 1);
                } else {
                    m_check5.color = colorChk1;
                    m_check5txt.text = "라(짝)";
                    group5Visible = false;
                    sigCheckGroup(5, 0);
                }
            }
        }
    }
}
