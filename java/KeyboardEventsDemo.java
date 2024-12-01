import java.awt.*;
import java.awt.event.*;

public class KeyboardEventsDemo extends Frame implements KeyListener {
    public KeyboardEventsDemo() {
        addKeyListener(this);
        setSize(400, 400);
        setVisible(true);
    }

    public void keyPressed(KeyEvent e) {
        System.out.println("Key pressed: " + e.getKeyChar());
    }

    public void keyReleased(KeyEvent e) {
        System.out.println("Key released: " + e.getKeyChar());
    }

    public void keyTyped(KeyEvent e) {
        System.out.println("Key typed: " + e.getKeyChar());
    }

    public static void main(String[] args) {
        new KeyboardEventsDemo();
    }
}