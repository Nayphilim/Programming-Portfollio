package en.nayphilim.turnbasedrpg.gfx;

//handles all messages printed wihtin screen

public class Font {

	private static String chars = ""+
			 "ABCDEFGHIJKLMNOPQRSTUVWXYZ      "+
			"0123456789.,:;'\"!?$%()-=+/      ";
	
	public static void render(String msg, Screen screen, int x, int y, int colour,int scale){
		msg = msg.toUpperCase();
		
		for(int i = 0; i<msg.length(); i++){ //loop that runs through all the letters in the message and finds the sprite version of the character that matches
			int charIndex = chars.indexOf(msg.charAt(i));
			if(charIndex >=0){
				screen.render(x + (i * 8), y, charIndex + 30 * 32, colour, 0x00, scale);
			}
		}
	}
}
