package com.elements;

import com.googlecode.lanterna.graphics.TextGraphics;

import java.io.IOException;
import com.position.*;

public abstract class Element {
    protected Position position;

    public Element(int x, int y){
        this.position = new Position(x, y);
    }

    public abstract Position getPosition();
    public abstract void draw(TextGraphics graphics) throws IOException;
}
