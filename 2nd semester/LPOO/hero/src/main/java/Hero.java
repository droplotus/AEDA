import com.googlecode.lanterna.TextCharacter;
import com.googlecode.lanterna.screen.Screen;

import java.io.IOException;

public class Hero {
    private int x;
    private int y;

    public Hero(int x, int y){
        this.x = x;
        this.y = y;
    }

    public void draw(Screen screen) throws IOException {
        screen.setCursorPosition(null);   // we don't need a cursor
        screen.startScreen();             // screens must be started
        screen.doResizeIfNecessary();     // resize screen if necessary

        screen.setCharacter(this.x, this.y, TextCharacter.fromCharacter('X')[0]);
    }

    public void moveUp(){
        this.y--;
    }

    public void moveDown(){
        this.y++;
    }

    public void moveRight(){
        this.x++;
    }

    public void moveLeft(){
        this.x--;
    }

    public int getX() {
        return x;
    }

    public int getY() {
        return y;
    }

    public void setX(int x) {
        this.x = x;
    }

    public void setY(int y) {
        this.y = y;
    }
}
