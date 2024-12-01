import java.awt.*;
import java.awt.event.*;

public class MouseEventsDemo extends Frame implements MouseListener, MouseMotionListener {
    public MouseEventsDemo() {
        addMouseListener(this);
        addMouseMotionListener(this);
        setSize(400, 400);
        setVisible(true);
    }

    public void mouseClicked(MouseEvent e) {
        System.out.println("Mouse clicked");
    }

    public void mouseEntered(MouseEvent e) {
        System.out.println("Mouse entered");
    }

    public void mouseExited(MouseEvent e) {
        System.out.println("Mouse exited");
    }

    public void mousePressed(MouseEvent e) {
        System.out.println("Mouse pressed");
    }

    public void mouseReleased(MouseEvent e) {
        System.out.println("Mouse released");
    }

    public void mouseDragged(MouseEvent e) {
        System.out.println("Mouse dragged");
    }

    public void mouseMoved(MouseEvent e) {
        System.out.println("Mouse moved");
    }

    public static void main(String[] args) {
        new MouseEventsDemo();
    }
}