package com.elements;

import com.elements.Element;
import com.googlecode.lanterna.SGR;
import com.googlecode.lanterna.TerminalPosition;
import com.googlecode.lanterna.TextColor;
import com.googlecode.lanterna.graphics.TextGraphics;

import com.position.Position;

public class Hero extends Element {
    private int energy = 100;
    public Hero(int x, int y){
        super(x, y);
    }

    @Override
    public Position getPosition() {
        return position;
    }

    @Override
    public void draw(TextGraphics graphics){
        graphics.setForegroundColor(TextColor.Factory.fromString("#D2D201"));
        graphics.enableModifiers(SGR.BOLD);
        graphics.putString(new TerminalPosition(position.getX(), position.getY()), "X");
    }

    public void setPosition(Position position){
        this.position = position;
    }

    public Position moveUp(){
        return new Position(position.getX(), position.getY() - 1);
    }

    public Position moveDown(){
        return new Position(position.getX(), position.getY() + 1);
    }

    public Position moveRight(){
        return new Position(position.getX() + 1, position.getY());
    }

    public Position moveLeft(){
        return new Position(position.getX() -1, position.getY());
    }

    public int getEnergy(){ return energy; }

    public void drainEvergy(){ energy -= 50; }

}
