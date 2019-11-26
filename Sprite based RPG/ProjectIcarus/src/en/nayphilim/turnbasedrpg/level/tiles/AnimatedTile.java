package en.nayphilim.turnbasedrpg.level.tiles;

//this class is the base design for any animated tile


public class AnimatedTile extends BasicTile {

    private int[][] animationTileCoords; // this is an example of a multidimensional array
    private int currentAnimationIndex;
    private long lastIterationTime;
    private int animationSwitchDelay;

    public AnimatedTile(int id, int[][] animationCoords, int tileColour, int levelColour, int animationSwitchDelay) {
    	super(id, animationCoords[0][0], animationCoords[0][1], tileColour, levelColour);
        this.animationTileCoords = animationCoords;
        this.currentAnimationIndex = 0;
        this.lastIterationTime = System.currentTimeMillis();
        this.animationSwitchDelay = animationSwitchDelay;
    }

    public void tick() {
        if ((System.currentTimeMillis() - lastIterationTime) >= (animationSwitchDelay)) { //determines if it has been long enough after the last animation switch to switch again
            lastIterationTime = System.currentTimeMillis();
            currentAnimationIndex = (currentAnimationIndex + 1) % animationTileCoords.length; // increments the position value in the 2d array to change which iteration of the tile we are on
            this.tileId = (animationTileCoords[currentAnimationIndex][0] + (animationTileCoords[currentAnimationIndex][1] * 32)); // updates the tile id of the water with the new value
        }
    }
}