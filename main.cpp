#include "TXLib.h"

int main()
{
    txCreateWindow (800, 600);
    txTextCursor (false);

    HDC gal = txLoadImage("Картинки/Зеленая_галочка.bmp");

    int n_question = 1;
    int kol_question = 2;
    string text_question;
    string text_answer1;
    string text_answer2;
    string text_answer3;


    while(n_question <= kol_question)
    {
        txBegin();
        txSetFillColor(TX_BLACK);
        txClear();


        if(n_question == 1)
        {
            //Вопрос1
            text_question = "Сколько планет в Солнечной системе?";
            //Ответы2
            text_answer1 = "8";
            text_answer2 = "6";
            text_answer3 = "12";

            //Клик на ответ 1
            if(txMouseButtons() == 1 &&
               txMouseX() >= 150 &&
               txMouseY() >= 250 &&
               txMouseX() <= 200 &&
               txMouseY() <= 300)
            {
                txBitBlt(txDC(), 150, 250, 50, 50, gal);
                txSleep(1000);
                n_question++;
            }
        }
        if(n_question == 2)
        {
            //Вопрос2
            text_question = "Какая звезда ближе всех к Земле?";
            //Ответы2
            text_answer1 = "Альфа Центавра";
            text_answer2 = "Солнце";
            text_answer3 = "Альфа Гончих псов";

            //Клик на ответ 1
            if(txMouseButtons() == 1 &&
               txMouseX() >= 150 &&
               txMouseY() >= 350 &&
               txMouseX() <= 200 &&
               txMouseY() <= 400)
            {
                txBitBlt(txDC(), 150, 350, 50, 50, gal);
                txSleep(1000);
                n_question++;
            }
        }
        txSetColor(TX_WHITE);
        txSetFillColor(TX_WHITE);
        txSelectFont("Arial", 40);
        txDrawText(50, 50, 750, 250, text_question.c_str());
        Win32::RoundRect(txDC(), 150, 250, 200, 300, 30, 30);
        txTextOut (250, 250, text_answer1.c_str());
        Win32::RoundRect(txDC(), 150, 350, 200, 400, 30, 30);
        txTextOut (250, 350, text_answer2.c_str());
        Win32::RoundRect(txDC(), 150, 450, 200, 500, 30, 30);
        txTextOut (250, 450, text_answer3.c_str());

        txSleep(50);
        txEnd();

    }

    txSetFillColor(TX_BLACK);
    txClear();
    txDrawText(50, 50, 750, 250, "РЕЗУЛЬТАТ");

    return 0;
}

