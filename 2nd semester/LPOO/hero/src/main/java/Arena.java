import com.googlecode.lanterna.TerminalPosition;
import com.googlecode.lanterna.TerminalSize;
import com.googlecode.lanterna.TextColor;
import com.googlecode.lanterna.graphics.TextGraphics;
import com.googlecode.lanterna.input.KeyStroke;
import com.googlecode.lanterna.screen.Screen;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class Arena {
    private int width;
    private int height;

    private Hero hero;
    private List<Wall> walls;
    private List<Coin> coins;

    public Arena(int width, int height){
        this.width = width;
        this.height = height;
        this.hero = new Hero(10, 10);
        this.walls = createWalls();
        this.coins = createCoins();
    }

    private List<Wall> createWalls() {
        List<Wall> walls = new ArrayList<>();

        for (int c = 0; c < width*2; c++) {
            walls.add(new Wall(c, 0));
            walls.add(new Wall(c, height*2 - 1));
        }

        for (int r = 1; r < height*2 - 1; r++) {
            walls.add(new Wall(0, r));
            walls.add(new Wall(width*2 - 1, r));
        }

        return walls;
    }

    private List<Coin> createCoins(){
        Random random = new Random();
        ArrayList<Coin> coins = new ArrayList<>();
        for (int i = 0; i < 10; i++) {
            Coin coin = new Coin(random.nextInt(width*2 - 2) + 1, random.nextInt(height*2 - 2) + 1);
            while(coin.getPosition().equals(hero.getPosition())) // falta ver se já coincide com alguma outra coin da List
                coin = new Coin(random.nextInt(width*2 - 2) + 1, random.nextInt(height*2 - 2) + 1);

            coins.add(coin);
        }
        return coins;
    }

    public void processKey(KeyStroke key, Screen screen) throws IOException {
        switch (key.getKeyType()){
            case ArrowUp:
                moveHero(hero.moveUp()); break;
            case ArrowDown:
                moveHero(hero.moveDown()); break;
            case ArrowLeft:
                moveHero(hero.moveLeft()); break;
            case ArrowRight:
                moveHero(hero.moveRight()); break;
            case Character:
                if(key.getCharacter() == 'q') screen.close(); break;
        }
    }

    private boolean canHeroMove(Position position){
//        if (position.getX() <= 0 || position.getX() >= width - 1) return false;
//        if (position.getY() <= 0 || position.getY() >= height - 1) return false;

        for (Wall wall : walls){
            if (wall.getPosition().equals(position)) return false;
            else continue;
        }

        return true;
    }

    public void moveHero(Position position){
        if (canHeroMove(position)){
            hero.setPosition(position);
            retrieveCoins();
        }
    }

    public void retrieveCoins(){
        for (Coin coin : coins)
            if (hero.getPosition().equals(coin.getPosition())){
                coins.remove(coin);
                break;
            }
    }

    public void draw(TextGraphics graphics) throws IOException {
        // setting background
        graphics.setBackgroundColor(TextColor.Factory.fromString("#488AD7"));
        graphics.fillRectangle(new TerminalPosition(0, 0), new TerminalSize(width * 2, height * 2), ' ');

        // drawing components
        hero.draw(graphics);
        for(Wall wall : walls) wall.draw(graphics);
        for(Coin coin : coins) coin.draw(graphics);
    }

}
