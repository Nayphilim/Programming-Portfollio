package en.nayphilim.turnbasedrpg.gfx;

//this class manages all the colouring of sprites
//this is an example of a user defined subroutine

public class Colours {
	
	public static int get(int colour1,int colour2,int colour3,int colour4){
		return (get(colour4) << 24)+ (get(colour3) << 16) + (get(colour2) << 8) + get(colour1);
	}

	private static int get(int colour){
		if(colour<0)return 255;
			int r = colour/100%10;
			int g = colour/10%10;
			int b = colour%10;
		
		return r*36 + g*6 + b;
	}
	
	static{
		Colours.get(555, 543, 542, 123); // in order (white, light grey, dark grey, black)
	}
}

