package com.elements;

import com.elements.Element;
import com.googlecode.lanterna.TerminalPosition;
import com.googlecode.lanterna.TextColor;
import com.googlecode.lanterna.graphics.TextGraphics;
import com.position.Position;

public class Wall extends Element {
    public Wall(int x, int y){
        super(x, y);
    }

    @Override
    public Position getPosition(){
        return position;
    }

    @Override
    public void draw(TextGraphics graphics){
        graphics.setForegroundColor(TextColor.Factory.fromString("#000000"));
        graphics.setBackgroundColor(TextColor.Factory.fromString("#488AD7"));
        graphics.putString(new TerminalPosition(position.getX(), position.getY()), "@");
    }

}
