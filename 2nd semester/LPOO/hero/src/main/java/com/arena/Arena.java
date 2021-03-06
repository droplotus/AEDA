package com.arena;

import com.elements.*;
import com.googlecode.lanterna.SGR;
import com.googlecode.lanterna.TerminalPosition;
import com.googlecode.lanterna.TerminalSize;
import com.googlecode.lanterna.TextColor;
import com.googlecode.lanterna.graphics.TextGraphics;
import com.googlecode.lanterna.input.KeyStroke;
import com.googlecode.lanterna.screen.Screen;
import com.position.Position;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Arena {
    private int width;
    private int height;
    private boolean finished = false;

    private Hero hero;

    private int map_it = 0;
    private List<String> maps = new ArrayList<>(Arrays.asList(
            "C:\\Users\\Droplotus\\Desktop\\FAC\\2nd semester\\LPOO\\hero\\src\\main\\java\\com\\arena\\map_1.txt",
            "C:\\Users\\Droplotus\\Desktop\\FAC\\2nd semester\\LPOO\\hero\\src\\main\\java\\com\\arena\\map_2.txt",
            "C:\\Users\\Droplotus\\Desktop\\FAC\\2nd semester\\LPOO\\hero\\src\\main\\java\\com\\arena\\map_3.txt"
    ));

    private List<Wall> walls = new ArrayList<>();
    private List<Coin> coins = new ArrayList<>();
    private List<Monster> monsters = new ArrayList<>();
    private Door door;

    public Arena(int width, int height){
        this.width = width;
        this.height = height;
        this.hero = new Hero(10, 10);
        loadMap(maps.get(map_it++));
    }

    private void loadMap(String map){
        BufferedReader reader;
        walls.clear();
        coins.clear();
        monsters.clear();
        try {
            reader = new BufferedReader(new FileReader(map));
            String line = reader.readLine();
            int y = 0;
            while(line!=null){
                for(int x = 0; x < line.length(); x++){
                    switch (line.charAt(x)){
                        case '0':
                            continue;
                        case '1':
                            this.walls.add(new Wall(x, y)); break;
                        case '2':
                            this.coins.add(new Coin(x, y)); break;
                        case '3':
                            this.monsters.add(new Org(x, y)); break;
                        case '4':
                            this.monsters.add(new Elf(x, y)); break;
                        case '5':
                            this.door = new Door(x, y); break;
                        default:
                            System.out.println(line.charAt(x));
                    }
                }
                y++;
                line = reader.readLine();
            }
        }catch (IOException e){
            e.printStackTrace();
        }
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
            case Enter:
                hero.revive();
                map_it = 0;
                loadMap(maps.get(map_it++));
            case Character:
                if(key.getCharacter() == 'q') screen.close(); break;
        }
        for (int i = monsters.size()-1; i>=0; i--){
            moveMonster(monsters.get(i).move(), monsters.get(i));
        }
        monsters.remove(verifyMonsterCollisions());
    }

    private boolean canMonsterMove(Position position, Monster m){
        for (Wall wall : walls){
            if (wall.getPosition().equals(position) && m instanceof Org){
                return false;
            }
            else if (wall.getPosition().equals(position) && m instanceof Elf){
                ((Elf) m).setDirection();
                return false;
            }
            else continue;
        }
        return true;
    }

    public void moveMonster(Position position, Monster m){
        if (canMonsterMove(position, m)){
            m.setPosition(position);
        }
    }

    private boolean canHeroMove(Position position){

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
            if(coins.size() <= 0) door.open();
            if(door.isOpen() && hero.getPosition().equals(door.getPosition())){
                if(map_it == maps.size()-1){
                    finished = true;
                    return;
                }
                loadMap(maps.get(map_it++));
            }
        }
    }

    public void retrieveCoins(){
        for (Coin coin : coins)
            if (hero.getPosition().equals(coin.getPosition())){
                hero.incrementScore();
                coins.remove(coin);
                break;
            }
    }

    public Monster verifyMonsterCollisions(){
        for (Monster m : monsters)
            if (hero.getPosition().equals(m.getPosition())){
                hero.drainEvergy();
                System.out.println(hero.getEnergy());
                return m;
            }
        return null;
    }

    private void drawEndGameScreen(TextGraphics graphics){
        graphics.setBackgroundColor(TextColor.Factory.fromString("#488AD7"));
        graphics.fillRectangle(new TerminalPosition(0, 0), new TerminalSize(width * 2, height * 2 + 3), ' ');
        graphics.setForegroundColor(TextColor.Factory.fromString("#000000"));
        graphics.putString(new TerminalPosition(33, 21), "CONGRATULATIONS!");
        graphics.putString(new TerminalPosition(37, 22), "YOU WON!");
        graphics.putString(new TerminalPosition(37, 24), "score: " + hero.getScore());
    }

    private void drawDeadScreen(TextGraphics graphics){
        graphics.setBackgroundColor(TextColor.Factory.fromString("#488AD7"));
        graphics.fillRectangle(new TerminalPosition(0, 0), new TerminalSize(width * 2, height * 2 + 3), ' ');
        graphics.setForegroundColor(TextColor.Factory.fromString("#000000"));
        graphics.putString(new TerminalPosition(30, 21), "BETTER LUCK NEXT TIME!");
        graphics.putString(new TerminalPosition(36, 22), "YOU LOST!");
        graphics.putString(new TerminalPosition(36, 24), "score: " + hero.getScore());
        graphics.putString(new TerminalPosition(30, 26), "press [ENTER] to retry");
    }

    public void draw(TextGraphics graphics) throws IOException {


        // drawing the health and score bar
        graphics.setBackgroundColor(TextColor.Factory.fromString("#FFFFFF"));
        graphics.fillRectangle(new TerminalPosition(0, 40), new TerminalSize(80, 3), ' ');

        // setting background
        graphics.setBackgroundColor(TextColor.Factory.fromString("#488AD7"));
        graphics.fillRectangle(new TerminalPosition(0, 0), new TerminalSize(width * 2, height * 2), ' ');

        // score and health text
        graphics.setForegroundColor(TextColor.Factory.fromString("#000000"));
        graphics.setBackgroundColor(TextColor.Factory.fromString("#FFFFFF"));
        graphics.enableModifiers(SGR.BOLD);
        graphics.putString(new TerminalPosition(15, 41), "score: " + hero.getScore());
        graphics.putString(new TerminalPosition(55, 41), "health: " + hero.getEnergy());

        // drawing components
        hero.draw(graphics);
        for(Wall wall : walls) wall.draw(graphics);
        for(Coin coin : coins) coin.draw(graphics);
        for(Monster monster : monsters) monster.draw(graphics);
        door.draw(graphics);

        // shows endgame screen
        if(finished) drawEndGameScreen(graphics);

        // shows dead screen
        if(hero.getEnergy() <= 0) drawDeadScreen(graphics);
    }

}
