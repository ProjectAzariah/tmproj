#include "sound.h"

sound::sound()
{
    jump.setSource(QUrl("qrc:/ogg_file.wav"));
    shoot.setSource(QUrl("qrc:/shoot.wav"));
}
