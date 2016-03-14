#include "highscore.h"

HighScore::HighScore()
{


}

void testCases(){
    HighScore points("Bob", 40,  3);

    assert(points.getScore() == 40);
    assert(points.getName() == "Bob");
    assert(points.getDate() == 3);
}
