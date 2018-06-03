import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4

SecondwindowForm {
    visible: true
    width: 1640
    height: 480
    title: qsTr("Hello World") // Ну как же без Приветствия Миру


        // Растягиваем объект главного окна по всему родительскому элементу
        anchors.fill: parent

        // Стилизуем первую кнопку
        button1.style: ButtonStyle {
            // Стилизуем внешний вид кнопки
            background: Rectangle {
                /* Если кнопка нажата, то она будет красного цвета
                 * с черным ободком со скруглёнными краями,
                 * в противном случае она будет черного цвета с красным ободком
                 */
                color: control.pressed ? "red" : "black"
                border.color: control.pressed ? "black" : "red"
                border.width: 2
                radius: 5

            }

            // Стилизуем цвет текста кнопки
            label: Text {
                /* Если кнопка нажата, то цвет будет черным
                 * в противном случае красным
                 */
                text: qsTr("Press Me 1")
                color: control.pressed ? "black" : "red"
            }
        }

        // Стилизуем вторую кнопку
        button2.style: ButtonStyle {
            // Стилизуем внешний вид кнопки
            background: Rectangle {
                /* аналогично, что и для первой кнопки,
                 * но в противоположном порядке
                 */
                color: control.pressed ? "black" : "red"
                border.color: control.pressed ? "red" : "black"
                border.width: 2
                radius: 5
            }
            // Стилизуем цвет кнопки
            label: Text {
                /* аналогично, что и для первой кнопки,
                 * но в противоположном порядке
                 */
                text: qsTr("Press Me 2")
                color: control.pressed ? "red" : "black"
            }
        }
    }

