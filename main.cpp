#include "TXLib.h"

bool click_answer(int y)
{
    return(txMouseButtons() == 1 &&
           txMouseX() >= 150 &&
           txMouseY() >= y   &&
           txMouseX() <= 200 &&
           txMouseY() <= y+50);
}

struct Form
{
    string text_question;
    string text_answer1;
    int cost_answer1;
    string text_answer2;
    int cost_answer2;
    string text_answer3;
    int cost_answer3;
};

void draw_answer(int y, string text)
{
    Win32::RoundRect(txDC(), 150, y, 200, y+50, 30, 30);
    txTextOut (250, y, text.c_str());
}

int main()
{
    txCreateWindow (800, 600);
    txTextCursor (false);

    HDC gal = txLoadImage("Картинки/Зеленая_галочка.bmp");

    int n_question = 1;
    int kol_question = 5;
    int result = 0;

    Form form;

    Form form_list[5];
    form_list[0] = {"Сколько планет в Солнечной системе?",
                    "8", 1, "6", 0, "12", 0};
    form_list[1] = {"Какая звезда ближе всех к Земле?",
                    "Альфа Центавра", 0, "Солнце", 1, "Альфа Гончих псов", 0};
    form_list[2] = {"Самая маленькая планета в Солнечной системе",
                    "Земля", 0, "Венера", 0 ,"Меркурий", 1};
    form_list[3] = {"Самая большая планета в Солнечной системе",
                    "Юпитер", 1, "Сатурн", 0, "Марс", 0};
    form_list[4] = {"Период обращения Земли вокруг Солнца",
                    "24 часа", 1, "12 часов", 0, "48 часов", 0};

    while(n_question <= kol_question)
    {
        txBegin();
        txSetFillColor(TX_BLACK);
        txClear();

        form = form_list[n_question - 1];

        txSetColor(TX_WHITE);
        txSetFillColor(TX_WHITE);
        txSelectFont("Arial", 40);

        txDrawText(50, 50, 750, 250, form.text_question.c_str());
        draw_answer(250, form.text_answer1);
        draw_answer(350, form.text_answer2);
        draw_answer(450, form.text_answer3);

        char str[10];
        sprintf(str, "Вопрос %d/%d", n_question, kol_question);
        txDrawText(50, 0, 750, 50, str);

        //Клик на ответ 1
        if(click_answer(250))
        {
            txSleep(500);
            n_question++;
            result = result + form.cost_answer1;
            if(form.cost_answer1 == 1)
            {
                txBitBlt(txDC(), 150, 250, 50, 50, gal);
                txSleep(500);
            }
        }
        //Клик на ответ 2
        if(click_answer(350))
        {
            txSleep(500);
            n_question++;
            result = result + form.cost_answer2;
            if(form.cost_answer2 == 1)
            {
                txBitBlt(txDC(), 150, 350, 50, 50, gal);
                txSleep(500);
            }
        }
        //Клик на ответ 3
        if(click_answer(450))
        {
            txSleep(500);
            n_question++;
            result = result + form.cost_answer3;
            if(form.cost_answer3 == 1)
            {
                txBitBlt(txDC(), 150, 450, 50, 50, gal);
                txSleep(500);
            }
        }

        txSleep(50);
        txEnd();
    }

    txSetFillColor(TX_BLACK);
    txClear();
    txDrawText(50, 50, 750, 250, "ВАШ РЕЗУЛЬТАТ");
    char str[10];
    sprintf(str, "%d", result);
    txDrawText(50, 150, 750, 350, str);

    if (result<3)
    txDrawText(50, 350, 750, 550, "Ты двоечник");
    else if(3 <= result <= 4)
    txDrawText(50, 350, 750, 550, "Ты троечник");
    else if(result > 4)
    txDrawText(50, 350, 750, 550, "Ты отличник");

    return 0;
}

