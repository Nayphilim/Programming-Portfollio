package en.nayphilim.turnbasedrpg.level.tiles;

//this class is the basic design for all tiles
//this is an example of inheritance


import en.nayphilim.turnbasedrpg.gfx.Colours;
import en.nayphilim.turnbasedrpg.gfx.Screen;
import en.nayphilim.turnbasedrpg.level.Level;


public abstract class Tile {

    public static final Tile[] tiles = new Tile[256];
   
    //all different types of tiles that are usable in levels
    public static final Tile VOID = new BasicSolidTile(0, 0, 0, Colours.get(000, -1, -1, -1), 0xFF000000); // colours to use on level creator is what follows 0xFF so for this it would be 000000 etc
    public static final Tile STONE = new BasicSolidTile(1, 1, 0, Colours.get(-1, 333, 222, 121), 0xFF555555);
    public static final Tile GRASS = new BasicTile(2, 2, 0, Colours.get(-1, 131, 141, -1), 0xFF00FF00);
    public static final Tile WATER = new AnimatedTile(3, new int[][] { { 0, 5 }, { 1, 5 }, { 2, 5 }, { 1, 5 } },
            Colours.get(-1, 004, 115, -1), 0xFF0000FF, 1000);
    public static final Tile DOOR_ENTER = new BasicTile(4, 3, 0, Colours.get(321, 000, 444, 542), 0x0FF666666);
    public static final Tile GRASS_FLOWERS_MAGENTA = new BasicTile(5, 4, 0, Colours.get(-1, 131, 141, 403), 0xFF00a400);
    public static final Tile GRASS_FLOWERS_WHITE = new BasicTile(6, 5, 0, Colours.get(-1, 131, 141, 555), 0xFFd2ffd2);
    public static final Tile GRASS_STEPPING_STONE = new BasicTile(7, 6, 0, Colours.get(-1, 131, 141, 222), 0xFF343e35);
    
    
    protected byte id;
    protected boolean solid;
    protected boolean emitter;
    private int levelColour;

    public Tile(int id, boolean isSolid, boolean isEmitter, int levelColour) {
        this.id = (byte) id;
        if (tiles[id] != null)
            throw new RuntimeException("Duplicate tile id on " + id);
        this.solid = isSolid;
        this.emitter = isEmitter;
        this.levelColour = levelColour;
        tiles[id] = this;
    }

    public byte getId() {
        return id;
    }

    public boolean isSolid() {
        return solid;
    }

    public boolean isEmitter() {
        return emitter;
    }

    public int getLevelColour() {
        return levelColour;
    }

    public abstract void tick();

    public abstract void render(Screen screen, Level level, int x, int y);
}
