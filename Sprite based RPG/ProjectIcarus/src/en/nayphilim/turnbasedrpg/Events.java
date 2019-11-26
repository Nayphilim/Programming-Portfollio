package en.nayphilim.turnbasedrpg;

//handles all inputs received by the player that cause events

import en.nayphilim.turnbasedrpg.entities.Player;
import en.nayphilim.turnbasedrpg.gfx.Font;
import en.nayphilim.turnbasedrpg.gfx.Screen;
import en.nayphilim.turnbasedrpg.level.Level;




public class Events {
	
	public static void renderPlayerEvents(Screen screen, int x, int y, InputHandler input, Player player, Level level, String username){
	if (Player.triggeredDoor == true) {  
		Font.render("ENTER", screen, x + 100 , y + 45, en.nayphilim.turnbasedrpg.gfx.Colours.get(-1, -1, -1, 555), 1);
		if (input.enter.isPressed()) {
			Game.startNextLevel("/levels/level2.png", 0, 0, username);
			
		}
	}
	}
}


