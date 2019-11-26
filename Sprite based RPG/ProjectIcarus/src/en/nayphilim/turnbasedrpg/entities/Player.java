package en.nayphilim.turnbasedrpg.entities;

//basic design for player including swimming animation settings and collision box

import en.nayphilim.turnbasedrpg.Game;
import en.nayphilim.turnbasedrpg.InputHandler;
import en.nayphilim.turnbasedrpg.gfx.Colours;
import en.nayphilim.turnbasedrpg.gfx.Font;
import en.nayphilim.turnbasedrpg.gfx.Screen;
import en.nayphilim.turnbasedrpg.level.Level;
import en.nayphilim.turnbasedrpg.net.packets.Packet02Move;

public class Player extends Mob {

    private InputHandler input;
    private int colour = Colours.get(-1, 111, 512, 543);
    private int scale = 1;
    protected boolean isSwimming = false;
    private int tickCount = 0;
    private String username;
    public static boolean triggeredDoor = false;

    public Player(Level level, int x, int y, InputHandler input, String username) {
        super(level, "Player", x, y, 1);
        this.input = input;
        this.username = username;
    }
    
   

    public void tick() {
    	int speed = 1;
        int xa = 0;
        int ya = 0;
        if (input != null) {
            if (input.up.isPressed()) {
               ya = ya - speed;
            }
            if (input.down.isPressed()) {
              ya = ya + speed;
            }
            if (input.left.isPressed()) {
                xa = xa - speed;
            }
            if (input.right.isPressed()) {
               xa = xa + speed;
            }
        }
        if (xa != 0 || ya != 0) {
            move(xa, ya);
            isMoving = true;

            Packet02Move packet = new Packet02Move(this.getUsername(), this.x, this.y, this.numSteps, this.isMoving,
                    this.movingDir);
            packet.writeData(Game.game.socketClient);
        } else {
            isMoving = false;
        }
        if (level.getTile(this.x >> 3, this.y >> 3).getId() == 3) { // tests if the tile the player is on is a the water tile
            isSwimming = true;
        }
        if (isSwimming && level.getTile(this.x >> 3, this.y >> 3).getId() != 3) {
            isSwimming = false;
        }
        tickCount++;
        
        if(level.getTile(this.x >> 3,  this.y >> 3).getId() == 4) {
			triggeredDoor = true;
		}
		if (level.getTile(this.x >> 3, this.y >> 3 ).getId() != 4) {
			triggeredDoor = false;
		}
    }
    
    public boolean hasCollided(int xa, int ya) {
        int xMin = 0; //these values designate the hit box around the player
        int xMax = 7;
        int yMin = 3;//this value is not at zero as we want the hit box to be more around the players legs
        int yMax = 7;
        for (int x = xMin; x < xMax; x++) {
            if (isSolidTile(xa, ya, x, yMin)) {
                return true; //returns true to has collided if the tile has come into contact with any of the values within the hit box and is a solid tile
            }
        }
        for (int x = xMin; x < xMax; x++) {
            if (isSolidTile(xa, ya, x, yMax)) { // solid tile must be tested twice for x and y for min and max values
                return true;
            }
        }
        for (int y = yMin; y < yMax; y++) {
            if (isSolidTile(xa, ya, xMin, y)) {
                return true;
            }
        }
        for (int y = yMin; y < yMax; y++) {
            if (isSolidTile(xa, ya, xMax, y)) {
                return true;
            }
        }
        return false; //returns false if it is not a solid tile
    }

    public void render(Screen screen) {
        int xTile = 0;
        int yTile = 28;
        byte walkingSpeed = 4;
        int flipTop = (numSteps >> walkingSpeed) & 1;
        int flipBottom = (numSteps >> walkingSpeed) & 1;

        if (movingDir == 1) {
            xTile += 2;
        } else if (movingDir > 1) {
            xTile += 4 + ((numSteps >> walkingSpeed) & 1) * 2;
            flipTop = (movingDir - 1) % 2;
            flipBottom = (movingDir-1)%2;
        }

        int modifier = 8 * scale;
        int xOffset = x - modifier / 2;
        int yOffset = y - modifier / 2 - 4;
        if (isSwimming) {
            int waterColour = 0;
            yOffset += 4;
            if (tickCount % 60 < 15) {
                waterColour = Colours.get(-1, -1, 225, -1);
            } else if (15 <= tickCount % 60 && tickCount % 60 < 30) {
                yOffset -= 1;
                waterColour = Colours.get(-1, 225, 115, -1);
            } else if (30 <= tickCount % 60 && tickCount % 60 < 45) {
                waterColour = Colours.get(-1, 115, -1, 225);
            } else {
                yOffset -= 1;
                waterColour = Colours.get(-1, 225, 115, -1);
            }
            screen.render(xOffset, yOffset + 3, 0 + 27 * 32, waterColour, 0x00, 1);
            screen.render(xOffset + 8, yOffset + 3, 0 + 27 * 32, waterColour, 0x01, 1);
        }
        screen.render(xOffset + (modifier * flipTop), yOffset, xTile + yTile * 32, colour, flipTop, scale);
        screen.render(xOffset + modifier - (modifier * flipTop), yOffset, (xTile + 1) + yTile * 32, colour, flipTop,
                scale);

        if (!isSwimming) {
        	screen.render(xOffset + (modifier * flipBottom), yOffset + modifier, xTile + (yTile + 1) * 32, colour,
                    flipBottom, scale);
            screen.render(xOffset + modifier - (modifier * flipBottom), yOffset + modifier, (xTile + 1) + (yTile + 1)
                    * 32, colour, flipBottom, scale);
        }
        if (username != null) {
            Font.render(username, screen, xOffset - ((username.length() - 1) / 2 * 8), yOffset - 10,
                    Colours.get(-1, -1, -1, 555), 1);
        }
    }

    

    public String getUsername() {
        return this.username;
    }

	
	
}