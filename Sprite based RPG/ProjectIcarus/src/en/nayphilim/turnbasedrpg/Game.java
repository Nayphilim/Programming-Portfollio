package en.nayphilim.turnbasedrpg;

import java.awt.Canvas;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.image.BufferStrategy;
import java.awt.image.BufferedImage;
import java.awt.image.DataBufferInt;

import javax.swing.ImageIcon;
import javax.swing.JFrame;
import javax.swing.JOptionPane;

import en.nayphilim.turnbasedrpg.entities.Player;
import en.nayphilim.turnbasedrpg.entities.PlayerMP;
import en.nayphilim.turnbasedrpg.gfx.Screen;
import en.nayphilim.turnbasedrpg.gfx.SpriteSheet;
import en.nayphilim.turnbasedrpg.level.Level;
import en.nayphilim.turnbasedrpg.net.GameClient;
import en.nayphilim.turnbasedrpg.net.GameServer;
import en.nayphilim.turnbasedrpg.net.packets.Packet00Login;

//this is an example of interfaces

public class Game extends Canvas implements Runnable {

	private static final long serialVersionUID = 1L;

	public static final short windowWidth = 160;
	public static final short windowHeight = windowWidth / 16 * 9;
	public static final byte windowScale = 5;
	public static final String NAME = "Game";
	public static final Dimension windowDimensions = new Dimension(windowWidth * windowScale, windowHeight * windowScale);
	public static Game game;
	
	

	public static ImageIcon icon = new ImageIcon("res/ProjectIcarusIcon.png"); //this is an example of reading from a file


	public JFrame frame;

	private Thread thread;

	public boolean running = false;
	public int tickCount = 0;

	private BufferedImage image = new BufferedImage(windowWidth, windowHeight, BufferedImage.TYPE_INT_RGB);
	private int[] pixels = ((DataBufferInt) image.getRaster().getDataBuffer()).getData();
	private int[] colours = new int[6 * 6 * 6];

	private static Screen screen;
	public static InputHandler input;
	public WindowHandler window;
	public static Level level;
	public static Player player;
	public static Events events;

	public GameClient socketClient;
	public GameServer socketServer;

	public boolean debug = true;
	public boolean isApplet = false;

	public void init() {
		frame.setIconImage(icon.getImage());
		game = this;
		//this is an example of a user defined subroutine
		int index = 0;
		for (int r = 0; r < 6; r++) {
			for (int g = 0; g < 6; g++) {
				for (int b = 0; b < 6; b++) {
					int rr = (r * 255 / 5);
					int gg = (g * 255 / 5);
					int bb = (b * 255 / 5);
					//this is an example of recursion
					colours[index++] = rr << 16 | gg << 8 | bb;
				}
			}
		}
		
		
		// this is an example of reading from a file
		screen = new Screen(windowWidth, windowHeight, new SpriteSheet("/sprite_sheet.png")); 
		input = new InputHandler(this);
		startLevel("/levels/level1.png", 0, 0);
		
		
		if (!isApplet) {
			Packet00Login loginPacket = new Packet00Login(player.getUsername(), player.x, player.y);
			if (socketServer != null) {
				socketServer.addConnection((PlayerMP) player, loginPacket);
			}
			loginPacket.writeData(socketClient);
		}
	}
	//intitial level load up
	public static void startLevel(String levelPath, int x, int y){
		level = new Level(levelPath); 
		player = new PlayerMP(level, 100, 100, input, JOptionPane.showInputDialog(game, "Please enter a username"),
				null, -1);
		level.addEntity(player);
		events = new Events();
	}
	
	//next level load load up
	public static void startNextLevel(String levelPath, int x, int y, String username){
		
		level = new Level(levelPath);    
		Player player = new Player(level, x, y, input, username);
		level.addEntity(player);
		events = new Events();
	}
	

	public synchronized void start() {
		running = true;

		thread = new Thread(this, NAME + "_main");
		thread.start();
		if (!isApplet) {
			if (JOptionPane.showConfirmDialog(this, "Do you want to run the server") == 0) {
				socketServer = new GameServer(this);
				socketServer.start();
			}

			socketClient = new GameClient(this, "localhost");
			socketClient.start();
		}
	}

	public synchronized void stop() {
		running = false;

		try {
			thread.join();
		} catch (InterruptedException e) {
			e.printStackTrace();
		}
	}

	//first subroutine to run when the program starts
	//sets up tick and render function
	public void run() {
		
		long lastTime = System.nanoTime();
		double nsPerTick = 1000000000D / 60D;

		int ticks = 0;
		int frames = 0;

		long lastTimer = System.currentTimeMillis();
		double delta = 0;

		init();

		while (running) {
			long now = System.nanoTime();
			delta += (now - lastTime) / nsPerTick;
			lastTime = now;
			boolean shouldRender = true;

			while (delta >= 1) {
				ticks++;
				tick();
				delta -= 1;
				shouldRender = true;
			}

			try {
				Thread.sleep(2);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}

			if (shouldRender) {
				frames++;
				render();
			}

			if (System.currentTimeMillis() - lastTimer >= 1000) {
				lastTimer += 1000;
				
				frame.setTitle("Project Icarus  |  " + ticks + " ticks " + frames + " frames");
				debug(DebugLevel.INFO, ticks + " ticks, " + frames + " frames");
				frames = 0;
				ticks = 0;
			}
		}
	}

	public void tick() {
		tickCount++;
		level.tick();
	}

	public void render() {
		BufferStrategy bs = getBufferStrategy();
		if (bs == null) {
			createBufferStrategy(3);
			return;
		}

		int xOffset = player.x - (screen.screenWidth / 2);
		int yOffset = player.y - (screen.screenHeight / 2);

		level.renderTiles(screen, xOffset, yOffset);
		level.renderEntities(screen);
		Events.renderPlayerEvents(screen, xOffset, yOffset, input, player, level, player.getUsername());

		for (int y = 0; y < screen.screenHeight; y++) {
			for (int x = 0; x < screen.screenWidth; x++) {
				int colourCode = screen.pixels[x + y * screen.screenWidth];
				if (colourCode < 255)
					pixels[x + y * windowWidth] = colours[colourCode];
			}
		}

		Graphics g = bs.getDrawGraphics();
		g.drawImage(image, 0, 0, getWidth(), getHeight(), null);
		g.dispose();
		bs.show();
	}

	public static long fact(int n) {
		if (n <= 1) {
			return 1;
		} else {
			return n * fact(n - 1);
		}
	}

	public void debug(DebugLevel level, String msg) {
		switch (level) {
		default:
		case INFO:
			if (debug) {
				System.out.println("[" + NAME + "] " + msg);
			}
			break;
		case WARNING:
			System.out.println("[" + NAME + "] [WARNING] " + msg);
			break;
		case SEVERE:
			System.out.println("[" + NAME + "] [SEVERE]" + msg);
			this.stop();
			break;
		}
	}

	public static enum DebugLevel {
		INFO, WARNING, SEVERE;
	}
}
