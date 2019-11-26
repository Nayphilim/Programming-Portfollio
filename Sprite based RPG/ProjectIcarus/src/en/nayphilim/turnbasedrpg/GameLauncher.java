package en.nayphilim.turnbasedrpg;

//handles launching the game in either applet or application format

import java.applet.Applet;
import java.awt.BorderLayout;

import javax.swing.JFrame;

@SuppressWarnings("serial")
public class GameLauncher extends Applet {

    private static Game game = new Game();
    public static final boolean DEBUG = false;

    @Override
    public void init() {
        setLayout(new BorderLayout());
        add(game, BorderLayout.CENTER);
        setMaximumSize(Game.windowDimensions);
        setMinimumSize(Game.windowDimensions);
        setPreferredSize(Game.windowDimensions);
        game.debug = DEBUG;
        game.isApplet = true;
    }

    @Override
    public void start() {
        game.start();
    }

    @Override
    public void stop() {
        game.stop();
    }

    public static void main(String[] args) {
        game.setMinimumSize(Game.windowDimensions);
        game.setMaximumSize(Game.windowDimensions);
        game.setPreferredSize(Game.windowDimensions);

        game.frame = new JFrame(Game.NAME);

        game.frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        game.frame.setLayout(new BorderLayout());

        game.frame.add(game, BorderLayout.CENTER);
        game.frame.pack();

        game.frame.setResizable(false);
        game.frame.setLocationRelativeTo(null);
        game.frame.setVisible(true);

        game.window = new WindowHandler(game);
        game.debug = DEBUG;

        game.start();
    }
}
