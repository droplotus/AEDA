import com.googlecode.lanterna.SGR;
import com.googlecode.lanterna.TerminalPosition;
import com.googlecode.lanterna.TextColor;
import com.googlecode.lanterna.graphics.TextGraphics;

import java.util.Random;

public class Monster extends Element{
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

    @Override
    public void draw(TextGraphics graphics){
        graphics.setForegroundColor(TextColor.Factory.fromString("#0DD506"));
        graphics.enableModifiers(SGR.BOLD);
        graphics.putString(new TerminalPosition(position.getX(), position.getY()), "O");
    }

    public Position move(){
        Random random = new Random();
        Position p;
        int choice = random.nextInt(4);

        switch (choice){
            case 0: // right
                p = new Position(position.getX() + 1, position.getY()); break;
            case 1: // left
                p = new Position(position.getX() - 1, position.getY()); break;
            case 2: // up
                p = new Position(position.getX(), position.getY() - 1); break;
            case 3: // down
                p = new Position(position.getX(), position.getY() + 1); break;
            default:
                throw new IllegalStateException("Unexpected value: " + choice);
        }
        return p;
    }
}
