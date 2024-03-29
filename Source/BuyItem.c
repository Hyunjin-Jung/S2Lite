#include "BuyItem.h"
int price[6] = { 400,300,700,4000,100, 0 };
int Select_Buy_Chioce = 0;

int movecnt = 0;

void startBuyItem()
{
    Select_Buy_Chioce = 0;
    Choice_Status = HP;
    Choice_Status_Before = HP;

    Select = C_WHITE;
    SelectBUY = 0;

    system("cls");

    num = 0;
    total = 0;

    state = 0;
    DrawItmeFirst();

    while (STATE != START_TOWN) {
        DrawBOX(Select, C_BLACK);

        if (Select == C_GREEN_)
        {
            Buttons();
            while (!DrawBuyItem());
            movecnt = 0;
        }

        while (1)
        {
            if (Select == C_WHITE) {
                if (DrawChoiceItem()) break;
                movecnt = 0;
            }

            if (Select == C_GREEN_)
            {
                if (DrawUpDown()) break;
                //movecnt = 0;

            }
        }

    }

}
void DrawItmeFirst()
{
    DrawHPPortion(C_GREEN_, C_BLACK);
    DrawMPPortion(C_WHITE, C_BLACK);
    DrawALLPortion(C_WHITE, C_BLACK);
    DrawEXPPortion(C_WHITE, C_BLACK);
    DrawGOLDBOX(C_WHITE, C_BLACK);
    DrawLEAVE(C_WHITE, C_BLACK);

    for (int y = 0; y < 50; y++)
    {
        gotoxy(120, y);
        printf("弛");
    }

    drawInventory();
}

void drawInventory()
{
    for (int y = 2; y < 50; y++)
    {
        gotoxy(130, y);
        for (int x = 130; x < 150; x++)
            printf(" ");
    }

    gotoxy(136, 12);
    printf("<檣漸饜葬>");
    gotoxy(132, 15);
    printf("絲 : %d 錳", money);
    gotoxy(128, 18);
    printf("ж晝 鬼�倣� 給 : %d 偃", enhancementStone1);
    gotoxy(128, 20);
    printf("醞晝 鬼�倣� 給 : %d 偃", enhancementStone2);
    gotoxy(128, 22);
    printf("鼻晝 鬼�倣� 給 : %d 偃", enhancementStone3);
    gotoxy(130, 24);
    printf("羹溘 ん暮 : %d 偃", healingPotion);
    gotoxy(130, 27);
    printf("葆釭 ん暮 : %d 偃", manaPotion);
    gotoxy(128, 29);
    printf("羹溘/葆釭 ん暮 : %d 偃", allPotion);
    gotoxy(130, 31);
    printf("唳я纂 ん暮 : %d 偃", expPotion);
}

int CheckMoney(int num)
{
    for (int x = 60; x < 90; x++) {
        for (int y = 22; y < 23; y++) {
            gotoxy(x, y);
            printf(" ");
        }
    }
    int sum = price[Choice_Status];

    sum *= num;
    if ((sum < 0 || (money < sum && num == 1)) || (level == 16 && Choice_Status == EXP))
    {
        gotoxy(60, 22);
        setcolor(C_RED_, C_BLACK);
        printf("掘衙陛 碳陛棟м棲棻.");
        setcolor(C_WHITE, C_BLACK);

        return -1;
    }
    else if (sum > money)
    {

        gotoxy(60, 22);
        setcolor(C_GREEN_, C_BLACK);
        printf("譆渠 熱榆縑 紫殖ц蝗棲棻");
        setcolor(C_WHITE, C_BLACK);

        return 1;
    }
    else
    {
        gotoxy(60, 22);
        setcolor(C_GREEN_, C_BLACK);
        printf("掘衙陛 陛棟м棲棻.");
        setcolor(C_WHITE, C_BLACK);

        return 0;
    }
}

int MoneyGacha()
{
    int ran = rand() % 100 + 1;

    if (ran <= 20)
    {
        gotoxy(50, 39);
        printf("∞ 寡た 旎擋 虜躑 橢戲樟蝗棲棻.");
        return -1;
    }
    else if (ran > 60)
    {
        gotoxy(50, 39);
        printf("﹤ 寡た 旎擋 虜躑 檠戲樟蝗棲棻.");
        return 1;
    }
    else
    {
        gotoxy(50, 39);
        printf("﹦ 模嶸 旎擋 滲翕檜 橈蝗棲棻.");
        return 0;
    }
}

int DrawChoiceItem() {

    for (int i = 0; i < 100; i++) {
        if (_kbhit() != 0) {
            int key = _getch();
            switch (key) {
            case UP:
                RemoveItemInstructions();

                if (Choice_Status != HP) {
                    Choice_Status_Before = Choice_Status;
                    Choice_Status--;
                    DrawSelect(Choice_Status_Before, Choice_Status);
                }

                DrawItemInstructions();

                break;
            case DOWN:
                RemoveItemInstructions();

                if (Choice_Status != LEAVE) {
                    Choice_Status_Before = Choice_Status;
                    Choice_Status++;
                    DrawSelect(Choice_Status_Before, Choice_Status);
                }

                DrawItemInstructions();

                break;

            case ENTER:
                if (Choice_Status == LEAVE)
                {
                    RemoveItemInstructions();
                    STATE = START_TOWN;
                    return 1;
                }
                if (Select == C_WHITE) {
                    if (!CheckMoney(1)) {
                        Select = C_GREEN_;
                        gotoxy(60, 22);
                        printf("                ");
                        DrawBOX(Select, C_BLACK);
                        return 1;
                    }
                }
                break;
            }
        }
    }
    return 0;
}


int DrawUpDown() {

    for (int i = 0; i < 100; i++) {
        if (_kbhit() != 0) {
            int key = _getch();
            switch (key) {
            case UP:

                SelectUP();
                num++;
                if (CheckMoney(num) == 1) num -= 1;

                gotoxy(60, 29);  printf("         ");
                gotoxy(60, 29);  printf("掘衙 : %d偃", num);
                gotoxy(60, 31);  printf("                   ");
                gotoxy(60, 31);  printf("識 旎擋: %d", price[Choice_Status] * num);
                break;

            case DOWN:

                SelectDOWN();
                num--;
                if (CheckMoney(num) == -1)num = 0;

                gotoxy(60, 29);  printf("         ");
                gotoxy(60, 29);  printf("掘衙 : %d偃", num);
                gotoxy(60, 31);  printf("                   ");
                gotoxy(60, 31);  printf("識 旎擋: %d", price[Choice_Status] * num);
                break;
            case LEFT:
                if (Select_Buy_Chioce) {
                    SelectBUYItem_Choice();
                    Select_Buy_Chioce = 1;
                }
                break;
            case RIGHT:

                if (Select_Buy_Chioce) {
                    ReturnBUYItem_Choice();
                    Select_Buy_Chioce = 2;
                }
                break;
            case ENTER:
                if (movecnt)
                {
                    if (!Select_Buy_Chioce) {
                        Select_Buy_Chioce = 1;
                        Show_Choice();
                        movecnt = 0;
                    }
                    else if (Select_Buy_Chioce) {
                        if (movecnt)
                        {
                            if (Select_Buy_Chioce == 2) {
                                Select = C_WHITE;
                                num = 0;
                                Select_Buy_Chioce = 0;
                            }
                            else {
                                total = price[Choice_Status] * num;
                                if (Choice_Status == GOLD)
                                    total *= MoneyGacha(num);
                                Calculate();
                                Sleep(1000);
                                if (Choice_Status == EXP)
                                {
                                    UsingEXPPortion();

                                }
                                SetZero();
                                Select_Buy_Chioce = 0;
                            }
                            gotoxy(60, 22);
                            printf("                ");
                            return 1;
                        }

                    }
                }

                break;

            }
        }
    }
    return 0;

}
void Box(int color, int bgcolor)
{
    setcolor(color, bgcolor);
    gotoxy(30, 5); printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬");//0
    gotoxy(30, 6); printf("早                                                                           早");//1
    gotoxy(30, 7); printf("早                                                                           早");//1
    gotoxy(30, 8); printf("早                                                                           早");//1
    gotoxy(30, 9); printf("早                                                                           早");//1
    gotoxy(30, 10); printf("早                                                                           早");//1
    gotoxy(30, 11); printf("早                                                                           早");//1
    gotoxy(30, 12); printf("早                                                                           早");//1
    gotoxy(30, 13); printf("早                                                                           早");//1
    gotoxy(30, 14); printf("早                                                                           早");//1
    gotoxy(30, 15); printf("早                                                                           早");//1
    gotoxy(30, 16); printf("早                                                                           早");//1
    gotoxy(30, 17); printf("早                                                                           早");//1
    gotoxy(30, 18); printf("早                                                                           早");//1
    gotoxy(30, 19); printf("早                                                                           早");//1
    gotoxy(30, 20); printf("早                                                                           早");//1
    gotoxy(30, 21); printf("早                                                                           早");//1
    gotoxy(30, 22); printf("早                                                                           早");//1
    gotoxy(30, 23); printf("早                                                                           早");//1
    gotoxy(30, 24); printf("早                                                                           早");//1
    gotoxy(30, 25); printf("早                                                                           早");//1
    gotoxy(30, 26); printf("早                                                                           早");//1
    gotoxy(30, 27); printf("早                                                                           早");//1
    gotoxy(30, 28); printf("早                                                                           早");//1
    gotoxy(30, 29); printf("早                                                                           早");//1
    gotoxy(30, 30); printf("早                                                                           早");//1
    gotoxy(30, 31); printf("早                                                                           早");//1
    gotoxy(30, 32); printf("早                                                                           早");//1
    gotoxy(30, 33); printf("早                                                                           早");//1
    gotoxy(30, 34); printf("早                                                                           早");//1
    gotoxy(30, 35); printf("早                                                                           早");//1
    gotoxy(30, 36); printf("早                                                                           早");//1
    gotoxy(30, 37); printf("早                                                                           早");//1
    gotoxy(30, 38); printf("早                                                                           早");//1
    gotoxy(30, 39); printf("早                                                                           早");//1
    gotoxy(30, 40); printf("早                                                                           早");//1
    gotoxy(30, 41); printf("早                                                                           早");//1
    gotoxy(30, 42); printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭");
    setcolor(C_WHITE, C_BLACK);
}
void SetEXP()
{
    system("cls");
    DrawHPPortion(C_WHITE, C_BLACK);
    DrawMPPortion(C_WHITE, C_BLACK);
    DrawALLPortion(C_WHITE, C_BLACK);
    DrawEXPPortion(C_GREEN_, C_BLACK);
    DrawGOLDBOX(C_WHITE, C_BLACK);
    DrawLEAVE(C_WHITE, C_BLACK);

    for (int y = 0; y < 50; y++)
    {
        gotoxy(120, y);
        printf("弛");
    }

    drawInventory();

    Box(C_GREEN_, C_BLACK);
}

void drawPlusEXP(double plus)
{
    // 唳я纂 轎溘

    RemoveItemInstructions();
    drawInventory();

    int ratioExp = pcExp / (maxExp / 60.0f);
    int exRatio = ratioExp;
    char str[50];

    gotoxy(49, 7); printf("<     唳 я 纂   僭 擒   餌 辨 ж 晦    >"); Sleep(100);
    gotoxy(49, 10); printf("  瞳辨 瞪 :  Lv. %d    唳я纂 (%6d/%6d)", level, pcExp, maxExp); Sleep(100);
    gotoxy(33, 14); printf("exp ");
    setcolor(C_WHITE, C_GREEN);
    for (int i = 0; i < ratioExp; i++)
        printf(" ");
    setcolor(C_WHITE, C_GRAY);
    for (int i = ratioExp; i < 60; i++)
        printf(" ");
    setcolor(C_WHITE, C_BLACK);

    Sleep(1000);

    plus *= maxExp;

    if (level == 15)
    {
        if (pcExp + plus > pcStatTable[5][level])
        {
            plus = pcStatTable[5][level] - pcExp;
        }
    }

    pcExp += plus;

    while (pcStatTable[5][level] <= pcExp) {
        pcExp -= pcStatTable[5][level];
        pcLevelUp();
        if (level == 5 || level == 9 || level == 13)
        {
            selectSkill();
            SetEXP();
            gotoxy(49, 7); printf("<     唳 я 纂   僭 擒   餌 辨 ж 晦    >"); Sleep(100);
            gotoxy(49, 10); printf("  瞳辨 瞪 :  Lv. %d    唳я纂 (%6d/%6d)", level, pcExp, maxExp); Sleep(100);
            gotoxy(33, 14); printf("exp ");
            setcolor(C_WHITE, C_GREEN);
            for (int i = 0; i < exRatio; i++)
                printf(" ");
            setcolor(C_WHITE, C_GRAY);
            for (int i = exRatio; i < 60; i++)
                printf(" ");
            setcolor(C_WHITE, C_BLACK);
        }
    }

    ratioExp = pcExp / (maxExp / 50.0f);

    gotoxy(49, 17); printf("                  早  早                  "); Sleep(100);
    gotoxy(49, 18); printf("                  早  早                  "); Sleep(100);
    gotoxy(49, 19); printf("                  早  早                  "); Sleep(100);
    gotoxy(49, 20); printf("                  早  早                  "); Sleep(100);
    gotoxy(49, 21); printf("                                          "); Sleep(100);
    gotoxy(49, 22); printf("         唳я纂 %.2lf蒂 橢歷蝗棲棻.       ", plus); Sleep(100);
    gotoxy(49, 23); printf("                                          "); Sleep(100);
    gotoxy(49, 24); printf("                  早  早                  "); Sleep(100);
    gotoxy(49, 25); printf("                  早  早                  "); Sleep(100);
    gotoxy(49, 26); printf("                  早  早                  "); Sleep(100);
    gotoxy(49, 27); printf("               ___早  早___               "); Sleep(100);
    gotoxy(49, 28); printf("               ′       /                 "); Sleep(100);
    gotoxy(49, 29); printf("                 ′    /                  "); Sleep(100);
    gotoxy(49, 30); printf("                   ′ /                   "); Sleep(100);
    gotoxy(49, 31); printf("                     ╡                   "); Sleep(100);

    gotoxy(49, 34); printf("  瞳辨 �� :  Lv. %d    唳я纂 (%6d/%6d)", level, pcExp, maxExp);//1
    gotoxy(33, 37); printf("exp ");
    setcolor(C_WHITE, C_GREEN);
    for (int i = 0; i < ratioExp; i++)
        printf(" ");
    setcolor(C_WHITE, C_GRAY);
    for (int i = ratioExp; i < 60; i++)
        printf(" ");
    setcolor(C_WHITE, C_BLACK);

    Sleep(1000);
}


void UsingEXPPortion()
{
    SetEXP();

    double tmp = 0.f;

    while (1)
    {
        if (expPotion == 0) break;
        if (level < 16)
        {
            tmp = ((rand() % 51) + 10) * 1.0 / 100;

            drawPlusEXP(tmp);

            expPotion--;

        }
        else
        {
            money += expPotion * price[EXP];
            expPotion = 0;

        }

    }

}

void Show_Choice()
{
    for (int x = 50; x < 70; x++) {
        for (int y = 35; y < 40; y++) {
            gotoxy(x, y);
            printf(" ");
        }
    }
    setcolor(C_WHITE, C_BLACK);
    gotoxy(50, 35); printf("旨收收收收收收收收收收收收收收旬");//0
    gotoxy(50, 36); printf("早   掘衙ж晦   早");//1
    gotoxy(50, 37); printf("曲收收收收收收收收收收收收收收旭");

    for (int x = 70; x < 90; x++) {
        for (int y = 35; y < 40; y++) {
            gotoxy(x, y);
            printf(" ");
        }
    }
    setcolor(C_WHITE, C_BLACK);

    gotoxy(70, 35); printf("旨收收收收收收收收收收收收收收旬");//0
    gotoxy(70, 36); printf("早  嬴檜蠱 摹鷗 早");//1
    gotoxy(70, 37); printf("曲收收收收收收收收收收收收收收旭");
}
void ReturnBUYItem_Choice()
{
    movecnt++;

    for (int x = 50; x < 65; x++) {
        for (int y = 35; y < 40; y++) {
            gotoxy(x, y);
            printf(" ");
        }
    }
    setcolor(C_WHITE, C_BLACK);
    gotoxy(50, 35); printf("旨收收收收收收收收收收收收收收旬");//0
    gotoxy(50, 36); printf("早   掘衙ж晦   早");//1
    gotoxy(50, 37); printf("曲收收收收收收收收收收收收收收旭");

    for (int x = 70; x < 90; x++) {
        for (int y = 35; y < 40; y++) {
            gotoxy(x, y);
            printf(" ");
        }
    }
    setcolor(C_GREEN_, C_BLACK);

    gotoxy(70, 35); printf("旨收收收收收收收收收收收收收收旬");//0
    gotoxy(70, 36); printf("早  嬴檜蠱 摹鷗 早");//1
    gotoxy(70, 37); printf("曲收收收收收收收收收收收收收收旭");
}
void SelectBUYItem_Choice()
{
    movecnt++;

    for (int x = 50; x < 65; x++) {
        for (int y = 35; y < 40; y++) {
            gotoxy(x, y);
            printf(" ");
        }
    }
    setcolor(C_GREEN_, C_BLACK);
    gotoxy(50, 35); printf("旨收收收收收收收收收收收收收收旬");//0
    gotoxy(50, 36); printf("早   掘衙ж晦   早");//1
    gotoxy(50, 37); printf("曲收收收收收收收收收收收收收收旭");

    for (int x = 70; x < 90; x++) {
        for (int y = 35; y < 40; y++) {
            gotoxy(x, y);
            printf(" ");
        }
    }
    setcolor(C_WHITE, C_BLACK);

    gotoxy(70, 35); printf("旨收收收收收收收收收收收收收收旬");//0
    gotoxy(70, 36); printf("早  嬴檜蠱 摹鷗 早");//1
    gotoxy(70, 37); printf("曲收收收收收收收收收收收收收收旭");
}

int DrawBuyItem() {

    for (int i = 0; i < 100; i++) {
        if (_kbhit() != 0) {
            int key = _getch();
            switch (key) {
            case LEFT:
                if (!Select_Buy_Chioce) {
                    SelectBUYItem();
                }
                break;
            case RIGHT:
                if (!Select_Buy_Chioce) {
                    ReturnSelectItem();
                }
                break;
            case ENTER:
                if (Choice_Status == LEAVE)
                {
                    STATE = START_TOWN;
                    return 1;
                }
                if (movecnt)
                {
                    if (!SelectBUY) {
                        gotoxy(60, 22);
                        printf("                ");
                        DrawBOX(Select, C_BLACK);
                        Select = C_GREEN_;
                        state = 1;
                        UPandDOWN();
                        return 1;
                    }
                    else {
                        Select = C_WHITE;
                        num = 0;
                        gotoxy(60, 22);
                        printf("                ");
                        RemoveItemInstructions();
                        DrawBOX(Select, C_BLACK);
                        return 1;
                    }
                }
                break;
            }
        }
    }
    return 0;
}

void SelectDOWN()
{
    movecnt++;

    for (int x = 80; x < 90; x++) {
        for (int y = 26; y < 29; y++) {
            gotoxy(x, y);
            printf(" ");
        }
    }
    setcolor(C_WHITE, C_BLACK);
    gotoxy(80, 26); printf("旨收旬");//0
    gotoxy(80, 27); printf(" ∟");//1
    gotoxy(80, 28); printf("曲收旭");

    for (int x = 80; x < 90; x++) {
        for (int y = 30; y < 33; y++) {
            gotoxy(x, y);
            printf(" ");
        }
    }
    setcolor(C_GREEN_, C_BLACK);

    gotoxy(80, 30); printf("旨收旬");//0
    gotoxy(80, 31); printf(" ⊿");//1
    gotoxy(80, 32); printf("曲收旭");


}

void SelectUP()
{
    movecnt++;
    for (int x = 80; x < 90; x++) {
        for (int y = 26; y < 29; y++) {
            gotoxy(x, y);
            printf(" ");
        }
    }
    setcolor(C_GREEN_, C_BLACK);
    gotoxy(80, 26); printf("旨收旬");//0
    gotoxy(80, 27); printf(" ∟");//1
    gotoxy(80, 28); printf("曲收旭");

    for (int x = 80; x < 90; x++) {
        for (int y = 30; y < 33; y++) {
            gotoxy(x, y);
            printf(" ");
        }
    }
    setcolor(C_WHITE, C_BLACK);

    gotoxy(80, 30); printf("旨收旬");//0
    gotoxy(80, 31); printf(" ⊿");//1
    gotoxy(80, 32); printf("曲收旭");
}

void UPandDOWN() {

    setcolor(C_WHITE, C_BLACK);

    gotoxy(60, 29);  printf("         ");
    gotoxy(60, 29);  printf("掘衙 : %d偃", num);
    gotoxy(60, 31);  printf("                   ");
    gotoxy(60, 31);  printf("識 旎擋: %d", price[Choice_Status] * num);

    gotoxy(80, 26); printf("旨收旬");//0
    gotoxy(80, 27); printf(" ∟");//1
    gotoxy(80, 28); printf("曲收旭");
    gotoxy(80, 30); printf("旨收旬");//0
    gotoxy(80, 31); printf(" ⊿");//1
    gotoxy(80, 32); printf("曲收旭");
}


void SelectBUYItem()
{
    SelectBUY = 0;
    movecnt++;
    for (int x = 50; x < 90; x++) {
        for (int y = 20; y < 27; y++) {
            gotoxy(x, y);
            printf(" ");
        }
    }
    setcolor(C_GREEN_, C_BLACK);
    gotoxy(50, 20); printf("旨收收收收收收收收收收收收收收旬");//0
    gotoxy(50, 21); printf("早   掘衙ж晦   早");//1
    gotoxy(50, 22); printf("曲收收收收收收收收收收收收收收旭");

    setcolor(C_WHITE, C_BLACK);

    gotoxy(70, 20); printf("旨收收收收收收收收收收收收收收旬");//0
    gotoxy(70, 21); printf("早  嬴檜蠱 摹鷗 早");//1
    gotoxy(70, 22); printf("曲收收收收收收收收收收收收收收旭");
}

void ReturnSelectItem()
{
    SelectBUY = 1;
    movecnt++;
    setcolor(C_WHITE, C_BLACK);
    for (int x = 50; x < 90; x++) {
        for (int y = 20; y < 27; y++) {
            gotoxy(x, y);
            printf(" ");
        }
    }
    gotoxy(50, 20); printf("旨收收收收收收收收收收收收收收旬");//0
    gotoxy(50, 21); printf("早   掘衙ж晦   早");//1
    gotoxy(50, 22); printf("曲收收收收收收收收收收收收收收旭");

    setcolor(C_GREEN_, C_BLACK);
    gotoxy(70, 20); printf("旨收收收收收收收收收收收收收收旬");//0
    gotoxy(70, 21); printf("早  嬴檜蠱 摹鷗 早");//1
    gotoxy(70, 22); printf("曲收收收收收收收收收收收收收收旭");
}

void Buttons() {

    setcolor(C_WHITE, C_BLACK);
    for (int x = 50; x < 90; x++) {
        for (int y = 20; y < 27; y++) {
            gotoxy(x, y);
            printf(" ");
        }
    }
    gotoxy(50, 20); printf("旨收收收收收收收收收收收收收收旬");//0
    gotoxy(50, 21); printf("早   掘衙ж晦   早");//1
    gotoxy(50, 22); printf("曲收收收收收收收收收收收收收收旭");

    gotoxy(70, 20); printf("旨收收收收收收收收收收收收收收旬");//0
    gotoxy(70, 21); printf("早  嬴檜蠱 摹鷗 早");//1
    gotoxy(70, 22); printf("曲收收收收收收收收收收收收收收旭");
}

void SetZero()
{
    Choice_Status = HP;
    Choice_Status_Before = HP;

    Select = C_WHITE;
    SelectBUY = 0;

    system("cls");

    num = 0;
    total = 0;

    DrawItmeFirst();
}
void Calculate()
{

    switch (Choice_Status)
    {
    case HP:
        healingPotion += num; //HP
        money -= total;

        break;
    case MP:
        manaPotion += num;//MP
        money -= total;

        break;
    case EXP:
        expPotion += num;//EXP
        money -= total;
        break;
    case ALL:
        allPotion += num;//ALL
        money -= total;

        break;
    case GOLD:
        money -= total;
        total *= -1;
    default:
        break;
    }
    gotoxy(60, 41); printf("識 旎擋 : %d 錳", total);


}



void DrawBOX(int color, int bgcolor)
{
    Box(color, bgcolor);

    if (Choice_Status != LEAVE) DrawItemInstructions();
}


void DrawItemInstructions()
{
    switch (Choice_Status)
    {
    case HP:
        gotoxy(49, 7); printf("<      嬴  檜  蠱     撮  睡  薑  爾    >");//1
        gotoxy(49, 11); printf("                                         ");//1
        gotoxy(49, 12); printf("        ****** H P ん 暮 ******          ");//1
        gotoxy(49, 13); printf("                                         ");//1
        gotoxy(49, 14); printf("           陛問 : 400 錳                 ");//1
        gotoxy(49, 15); printf("                                         ");//1
        gotoxy(49, 16); printf("           �膩�                          ");//1
        gotoxy(49, 17); printf("           - 譆渠 羹溘曖 30%% �蛹�       ");//1
        gotoxy(49, 18); printf("                                         ");//1
        break;
    case MP:
        gotoxy(49, 7); printf("<      嬴  檜  蠱     撮  睡  薑  爾    >");//1
        gotoxy(49, 11); printf("                                         ");//1
        gotoxy(49, 12); printf("        ****** M P ん 暮 ******          ");//1
        gotoxy(49, 13); printf("                                         ");//1
        gotoxy(49, 14); printf("           陛問 : 300 錳                 ");//1
        gotoxy(49, 15); printf("                                         ");//1
        gotoxy(49, 16); printf("           �膩�                          ");//1
        gotoxy(49, 17); printf("           - 譆渠 葆釭曖 30%% �蛹�       ");//1
        gotoxy(49, 18); printf("                                         ");//1
        break;

    case ALL:
        gotoxy(49, 7); printf("<      嬴  檜  蠱     撮  睡  薑  爾    >");//1
        gotoxy(49, 11); printf("                                         ");//1
        gotoxy(49, 12); printf("        ****** ALL ん 暮 ******          ");//1
        gotoxy(49, 13); printf("                                         ");//1
        gotoxy(49, 14); printf("           陛問 : 700 錳                 ");//1
        gotoxy(49, 15); printf("                                         ");//1
        gotoxy(49, 16); printf("           �膩�                          ");//1
        gotoxy(49, 17); printf("           - 譆渠 葆釭諦 羹溘曖          ");//1
        gotoxy(49, 18); printf("             30%%蒂 �蛹�                 ");//1
        break;

    case EXP:
        gotoxy(49, 7); printf("<      嬴  檜  蠱     撮  睡  薑  爾    >");//1
        gotoxy(49, 11); printf("                                         ");//1
        gotoxy(49, 12); printf("        ****** EXP ん 暮 ******          ");//1
        gotoxy(49, 13); printf("                                         ");//1
        gotoxy(49, 14); printf("           陛問 : 4000 錳                ");//1
        gotoxy(49, 15); printf("                                         ");//1
        gotoxy(49, 16); printf("           �膩�                          ");//1
        gotoxy(49, 17); printf("           - 譆渠 唳я纂曖 10 ~ 60%%蒂   ");//1
        gotoxy(49, 18); printf("             楠渾戲煎 睡罹               ");//1
        break;

    case GOLD:
        gotoxy(49, 7); printf("<      嬴  檜  蠱     撮  睡  薑  爾    >");//1
        gotoxy(49, 11); printf("        ****** 埤萄 夢蝶 ******          ");//1
        gotoxy(49, 12); printf("                                         ");//1
        gotoxy(49, 13); printf("            陛問 : 寡た旎擋              ");//1
        gotoxy(49, 14); printf("     幗が и廓 援蒂陽 葆棻 100錳噶 隸馬  ");//1
        gotoxy(49, 15); printf("                                         ");//1
        gotoxy(49, 16); printf("     - ∞(20%%) : (漆た旎擋) 虜躑 嫡晦   ");//1
        gotoxy(49, 17); printf("     - ﹦(40%%) : (漆た旎擋) 給溥 嫡晦   ");//1
        gotoxy(49, 18); printf("     - ﹤(40%%) : (漆た旎擋) 虜躑 檠晦   ");//1
        break;

    default:
        break;
    }
}

//蟾晦��
void RemoveItemInstructions()
{
    for (int y = 7; y < 40; y++)
    {
        for (int x = 32; x <= 105; x++)
        {
            gotoxy(x, y);
            printf(" ");
        }
    }
}

void DrawSelect(int before, int after)
{

    switch (before)
    {
    case HP:
        DrawHPPortion(C_WHITE, C_BLACK);
        break;
    case MP:
        DrawMPPortion(C_WHITE, C_BLACK);
        break;
    case ALL:
        DrawALLPortion(C_WHITE, C_BLACK);
        break;
    case EXP:
        DrawEXPPortion(C_WHITE, C_BLACK);
        break;
    case GOLD:
        DrawGOLDBOX(C_WHITE, C_BLACK);
        break;
    case LEAVE:
        DrawLEAVE(C_WHITE, C_BLACK);
        break;
    }
    switch (after)
    {
    case HP:
        DrawHPPortion(C_GREEN_, C_BLACK);
        break;
    case MP:
        DrawMPPortion(C_GREEN_, C_BLACK);
        break;
    case ALL:
        DrawALLPortion(C_GREEN_, C_BLACK);
        break;
    case EXP:
        DrawEXPPortion(C_GREEN_, C_BLACK);
        break;
    case GOLD:
        DrawGOLDBOX(C_GREEN_, C_BLACK);
        break;
    case LEAVE:
        DrawLEAVE(C_GREEN_, C_BLACK);
        break;
    }
}

void DrawHPPortion(int color, int bgcolor)
{
    setcolor(color, bgcolor);
    gotoxy(10, 5); printf("旨收收收收收收收收收收收旬");//0
    gotoxy(10, 6); printf("早  H P ん暮 早");//1
    gotoxy(10, 7); printf("曲收收收收收收收收收收收旭");
    setcolor(C_WHITE, C_BLACK);
}
void DrawMPPortion(int color, int bgcolor)
{
    setcolor(color, bgcolor);
    gotoxy(10, 12); printf("旨收收收收收收收收收收收旬");
    gotoxy(10, 13); printf("早  M P ん暮 早");//1
    gotoxy(10, 14); printf("曲收收收收收收收收收收收旭");
    setcolor(C_WHITE, C_BLACK);
}
void DrawALLPortion(int color, int bgcolor)
{
    setcolor(color, bgcolor);
    gotoxy(10, 19); printf("旨收收收收收收收收收收收旬");
    gotoxy(10, 20); printf("早  ALL ん暮 早");
    gotoxy(10, 21); printf("曲收收收收收收收收收收收旭");
    setcolor(C_WHITE, C_BLACK);
}

void DrawEXPPortion(int color, int bgcolor)
{
    setcolor(color, bgcolor);
    gotoxy(10, 26); printf("旨收收收收收收收收收收收旬");
    gotoxy(10, 27); printf("早  EXP ん暮 早");
    gotoxy(10, 28); printf("曲收收收收收收收收收收收旭");
    setcolor(C_WHITE, C_BLACK);
}

void DrawGOLDBOX(int color, int bgcolor)
{
    setcolor(color, bgcolor);

    gotoxy(10, 33); printf("旨收收收收收收收收收收收旬");
    gotoxy(10, 34); printf("早  埤萄夢蝶 早");
    gotoxy(10, 35); printf("曲收收收收收收收收收收收旭");;
    setcolor(C_WHITE, C_BLACK);
}

void DrawLEAVE(int color, int bgcolor)
{
    setcolor(color, bgcolor);
    gotoxy(10, 40); printf("旨收收收收收收收收收收收旬");
    gotoxy(10, 41); printf("早  釭 陛 晦 早");
    gotoxy(10, 42); printf("曲收收收收收收收收收收收旭");
    setcolor(C_WHITE, C_BLACK);
}