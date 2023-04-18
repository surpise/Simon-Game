#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <time.h>
#include "button.h"
#include "buttonPlay.h"

using namespace sf;
using namespace std;

int main()
{
    int number;
    cout << "사용할 버튼의 개수를 입력하세요. (최대 10개): ";
    cin >> number;
    cout << "게임을 시작하려면 마우스 오른쪽 버튼을 누르세요";
     
    RenderWindow window(VideoMode(750, 600), "Simon Game");
    window.setFramerateLimit(60);

    unsigned int timer = 0, delay = 180;
    unsigned int level = 1, missionNum = 0;
    vector<int>mission;
    SoundBuffer buf;
    Sound correct;

    if (!buf.loadFromFile("correct.wav"))
    {
        exit(1);
    }
    correct.setBuffer(buf);
    buttonPlay boxes(number);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case Event::Closed:
                window.close();
                break;
            case Event::MouseButtonPressed:
                if (Mouse::isButtonPressed(Mouse::Right) == true)
                {
                    boxes.playerTurn = false;
                    timer = 0;
                }
                else if (Mouse::isButtonPressed(Mouse::Left) == true)
                {
                    if ((boxes.playerTurn == true) && (!mission.empty()))
                    {
                        Vector2f mousePos = static_cast<Vector2f>(Mouse::getPosition(window));

                        if (boxes.checkCorrect(mission[missionNum], mousePos))
                        {
                            window.clear();
                            correct.play();
                            for (int i = 0; i < 60; i++)
                            {
                                boxes.levelPlay(mission[missionNum], true);
                                boxes.draw(window);
                                window.display();
                            }
                            boxes.levelPlay(mission[missionNum], false);

                            missionNum += 1;
                            if (missionNum == level)
                            {
                                boxes.playerTurn = false;
                                missionNum = 0;
                                level += 1;
                                delay -= 30;
                                if (delay < 30)
                                {
                                    delay = 30;
                                }
                                timer = 0;
                            }
                        }
                        else
                        {
                            window.close();
                        }
                    }
                    else
                    {
                        continue;
                    }
                }
            default:
                break;
            }
        }

        if (boxes.playerTurn == false)
        {
            if (level > mission.size())
            {
                boxes.makeMission(mission);
                timer = 0;
            }

            if (timer < delay)
            {
                if (timer <= 1)
                {
                    boxes.sound.play();
                }
                boxes.levelPlay(mission[missionNum], true);
            }

            else
            {
                boxes.levelPlay(mission[missionNum], false);
                missionNum += 1;
                if (level == missionNum)
                {
                    missionNum = 0;
                    boxes.playerTurn = true;
                }
                timer = 0;
            }
        }
        timer += 1;

        window.clear();

        boxes.draw(window);

        window.display();
    }

    return 0;
}
