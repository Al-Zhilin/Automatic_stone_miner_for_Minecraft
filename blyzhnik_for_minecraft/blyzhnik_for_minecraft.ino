// +- июнь 2023го
// для автоматической добычи блыжника (ха-ха, БЛЫжник) на ферме блы..(ахахаахахаа) блыжника.
// все прекрасно работает как минимум на версии майна 1.7.10
// ставишь курсор на блыжник, втыкаем плату в юсб порт компа, и кайфуешь, когда светодиод загорится, вытыкаешь плату и все, чиби-брики, blyznik's stonks так сказать)

#include <EasyHID.h>            //библиотечка от Гайвера, смотри видео на YouTube (если к твоему времени его не заблочат)
byte slot = 1;                  //начальный слот, первый
unsigned long del_slot = 0;     //пеерменная для таймера на millis()

long timer = 220000;            //время, требуемое для того, чтобы новая каменная кирка полностью сломалась (для других кирок время подбирай сам)(мс)
  
void setup() {
HID.begin();                    //подключаем, собственно, библиотеку
pinMode(7,OUTPUT);              //на седьмом контакте будет светодиод, загорающийся при окончании всех кирок

}

void loop() {
HID.tick();                     //чтобы библиотека работала корректно, нужно чтобы эта функция вызывалась не реже, чем раз в 10 мс (не используй delay)

Mouse.press(MOUSE_LEFT);        //постоянно жмем левую кнопку мыши (ломаем блыжник)

if (millis() - del_slot >= timer) {     //жесткий таймер на millis()
slot++;
del_slot = millis();

switch (slot) {
  case 2: Keyboard.press(KEY_2);
  break;

  case 3: Keyboard.press(KEY_3);
  break;

  case 4: Keyboard.press(KEY_4);
  break;

  case 5: Keyboard.press(KEY_5);        //меняем слот, если пришло время
  break;

  case 6: Keyboard.press(KEY_6);
  break;

  case 7: Keyboard.press(KEY_7);
  break;

  case 8: Keyboard.press(KEY_8);
  break;

  case 9: Keyboard.press(KEY_9);
  break;
}
}

if (slot == 10) {
Mouse.releaseAll();                     //если слоты закончились - отжимаем все клавиши, зажигаем светодиод и уходим в вечный цикл
Keyboard.releaseAll();
digitalWrite(7, HIGH);
while(1) {;}
}
}
