package com.elements;

import com.googlecode.lanterna.SGR;
import com.googlecode.lanterna.TerminalPosition;
import com.googlecode.lanterna.TextColor;
import com.googlecode.lanterna.graphics.TextGraphics;
import com.position.Position;

import java.io.IOException;


public class Door extends Element{
    private boolean opened = false;

    public Door(int x, int y) {
        super(x, y);
    }

    public void open(){
        this.opened = true;
    }

    public boolean isOpen(){
        return opened;
    }

    @Override
    public Position getPosition() {
        return position;
    }

    @Override
    public void draw(TextGraphics graphics) throws IOException {
        if(opened) graphics.setBackgroundColor(TextColor.Factory.fromString("#944000"));
        else graphics.setBackgroundColor(TextColor.Factory.fromString("#4D2100"));
        graphics.putString(new TerminalPosition(position.getX(), position.getY()), " ");
    }
}
