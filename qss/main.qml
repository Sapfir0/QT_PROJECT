import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import QtQuick.Dialogs 1.2

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World") // Ну как же без Приветствия Миру
    color: "white"

    /* С помощью объекта Connections
     * Устанавливаем соединение с классом ядра приложения
     * */
    Connections {
        target: appCore // Указываем целевое соединение
        /* Объявляем и реализуем функцию, как параметр
         * объекта и с имененем похожим на название сигнала
         * Разница в том, что добавляем в начале on и далее пишем
         * с заглавной буквы
         * */
        onSendToQml: {
            labelCount.text = count // Устанавливаем счётчик в текстовый лейбл
        }
    }

    MainForm {
        // Растягиваем объект главного окна по всему родительскому элементу
        anchors.fill: parent

        // Создадим текстовый лейбл
        Text {
            id: labelCount
            // А также установим его визуальные параметры
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: parent.top
            height: 300
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            // Первым текстом будет традиционный Хеллоу Ворлд!
            text: "Hello, World !!!"
        }

        // Стилизуем первую кнопку
        button1.style: ButtonStyle {
            // Программный код из предыдущего урока
        }

        // Стилизуем вторую кнопку
        button2.style: ButtonStyle {
            // Программный код из предыдущего урока
        }

        // Запускаем диалог по нажатию любой из кнопок в главном окне
        button1.onClicked: dialogAndroid.open();
        button2.onClicked: dialogAndroid.open();

        // Создаём объект диалогового окна
        Dialog {
            id: dialogAndroid
            /* Когда деплоите под Android-устройства,
             * обязательно закоментируйте эти две строки,
             * иначе словите глюки в работе устройства
             */
            width: 600  // Задаём ширину диалога, работает на десктопе, но на Android не сработает
            height: 500 // Задаём высоту диалога, работает на декстопе, но на Android не сработает

            // Создаём содержимое диалогового окна
            contentItem: Rectangle {
                width: 600          // Устанавливаем ширину, необходимо для Android-устройства
                height: 500         // Устанавливаем высоту, необходимо для Android-устройства
                color: "#f7f7f7"    // Задаём цвет

                // Область для сообщения диалогового окна
                Rectangle {
                    // Программный код из предыдущего урока
                }

                // Создаём горизонтальный разделитель с помощью Rectangle
                Rectangle {
                    id: dividerHorizontal
                    // Программный код из предыдущего урока
                }

                /* Создаём подложку для кнопок в виде объекта Строки
                 * В данном объекте для объектов детей не работают некоторые параметры
                 * anchors, кроме параметров anchors.top и anchors.bottom
                 */
                Row {
                    id: row
                    // Программный код из предыдущего урока

                    Button {
                        id: dialogButtonCancel

                        // Программный код из предыдущего урока

                        // По нажатию кнопки закрываем диалог
                        onClicked: dialogAndroid.close()
                    }

                    // Создаём разделитель между кнопками шириной в 2 пикселя
                    Rectangle {
                        id: dividerVertical
                        // Программный код из предыдущего урока
                    }

                    Button {
                        id: dialogButtonOk

                        // Программный код из предыдущего урока

                        // По нажатию кнопки закрываем диалог
                        onClicked: {
                            /* Прежде, чем закрывать диалог по OK кнопке,
                             * отправим данные в слот ядра приложения
                             * */
                            appCore.receiveFromQml()
                            // А потом и закроем диалог
                            dialogAndroid.close()
                        }
                    }
                }
            }
        }
    }
}
