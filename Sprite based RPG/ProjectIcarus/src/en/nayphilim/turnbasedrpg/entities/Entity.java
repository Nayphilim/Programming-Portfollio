package en.nayphilim.turnbasedrpg.entities;

//this class is the base design for all things within the class
//this is an example of inheritance


import en.nayphilim.turnbasedrpg.gfx.Screen;
import en.nayphilim.turnbasedrpg.level.Level;

public abstract class Entity {

	public int x, y;
	protected static Level level;
	
	public Entity(Level level){
		init(level);
	}
	
	public final void init(Level level){
		this.level = level;
	}
	
	public abstract void tick();
	
	public abstract void render(Screen screen);
}
