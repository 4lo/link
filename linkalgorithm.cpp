#include "linkalgorithm.h"

//连连看的主要算法
bool linkAlgorithm::link(button *buttonPushed, Game game){
    if(buttonPushed != nullptr){
        if(game.getPictureSelected() == buttonPushed->objectName()){
            //点的就是上次点的图片
            buttonPushed->setChecked(false);
            game.setPictureSelected("");
            return false;
        }else if (game.getPictureSelected() == ""){
            //未点击图片
            game.setPictureSelected(buttonPushed->objectName());
            return false;
        }else if (game.couldBeLinked(game.getPictureSelected(), buttonPushed->objectName())){
            return true;
        }
    }
}
