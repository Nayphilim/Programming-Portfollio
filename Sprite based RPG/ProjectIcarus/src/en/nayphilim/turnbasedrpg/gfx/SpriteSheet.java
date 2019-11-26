package en.nayphilim.turnbasedrpg.gfx;

//this class reads the image file of the spritesheet and converts it into small chunks which can be specified as an individual entity

import java.awt.image.BufferedImage;
import java.io.IOException;

import javax.imageio.ImageIO;

public class SpriteSheet {

    public String path;
    public int width;
    public int height;

    public int[] pixels;

    public SpriteSheet(String path) {
        BufferedImage image = null;
        try {
        	//loads image of spritesheet
        	//this is an example of reading from files
            image = ImageIO.read(SpriteSheet.class.getResourceAsStream(path)); 
        } catch (IOException e) {
            e.printStackTrace();
        }

        if (image == null) { return; }

        this.path = path;
        this.width = image.getWidth();
        this.height = image.getHeight();

        pixels = image.getRGB(0, 0, width, height, null, 0, width); //determines the RGB values of the spritesheet

        for (int i = 0; i < pixels.length; i++) {
            pixels[i] = (pixels[i] & 0xff) / 64;  //converts the RGB values into a simple format for us to change colours for each shade
        }
    }
}