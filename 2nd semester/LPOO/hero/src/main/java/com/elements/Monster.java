package com.elements;

import com.position.*;

public abstract class Monster extends Element {
    public Monster(int x, int y){
        super(x, y);
    }

    public void setPosition(Position position){
        this.position = position;
    }

    @Override
    public Position getPosition(){
        return position;
    }

    public abstract Position move();

}
