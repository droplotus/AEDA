package com.elements;

import com.googlecode.lanterna.SGR;
import com.googlecode.lanterna.TerminalPosition;
import com.googlecode.lanterna.TextColor;
import com.googlecode.lanterna.graphics.TextGraphics;

import com.position.Position;

import java.io.IOException;

public class Elf extends Monster {
    private int direction = 1;

    public Elf(int x, int y) {
        super(x, y);
    }

    @Override
    public void draw(TextGraphics graphics) throws IOException {
        graphics.setForegroundColor(TextColor.Factory.fromString("#ABAC8D"));
        graphics.setBackgroundColor(TextColor.Factory.fromString("#488AD7"));
        graphics.enableModifiers(SGR.BOLD);
        graphics.putString(new TerminalPosition(position.getX(), position.getY()), "E");
    }

    @Override
    public Position move() {
        return new Position(position.getX() + direction, position.getY());
    }

    public void setDirection() {
        this.direction *= -1;
    }
}
