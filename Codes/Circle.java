import java.awt.*;
import java.awt.event.*;
import java.awt.geom.AffineTransform;
import java.util.ArrayList;

import javax.swing.*;

public class Circle implements MouseWheelListener, MouseListener, MouseMotionListener {

    static int interval = 20;
    static int a, b, c, m, n, p;
    private GridPanel panel;
    Color gridColor;

    private double fontSize = 10;

    private double zoomFactor = 1;
    private double prevZoomFactor = 1;
    private boolean zoomer;
    private boolean dragger;
    private boolean released;
    private double xOffset = 0;
    private double yOffset = 0;
    private int xDiff;
    private int yDiff;
    private Point startPoint;

    private int originX;
    private int originY;
    private int width;
    private int height;

    public class Line {
        public int x1, y1, x2, y2;

        Line(int x1, int y1, int x2, int y2) {
            this.x1 = x1;
            this.y1 = y1;
            this.x2 = x2;
            this.y2 = y2;
        }
    }

    private ArrayList<ArrayList<Integer>> coords = new ArrayList<ArrayList<Integer>>();

    private ArrayList<Line> lines = new ArrayList<Line>();

    public Circle() {

        panel = new GridPanel();
        JFrame f = new JFrame("CIRCLE");

        panel.addMouseWheelListener(this);
        panel.addMouseMotionListener(this);
        panel.addMouseListener(this);

        JMenuBar mb = new JMenuBar();

        JMenu m1 = new JMenu("Options");

        JMenu m2 = new JMenu("Insert");

        JMenuItem op1 = new JMenuItem(new AbstractAction("Change Background Color") {
            public void actionPerformed(ActionEvent e) {
                JFrame frame = new JFrame("Choose Background Color");
                Color color = JColorChooser.showDialog(frame, "Choose a color", Color.BLACK);
                panel.setBackground(color);
            }
        });
        JMenuItem op2 = new JMenuItem(new AbstractAction("Change Grid Color") {
            public void actionPerformed(ActionEvent e) {
                JFrame frame = new JFrame("Choose Grid Color");
                Color color = JColorChooser.showDialog(frame, "Choose a color", Color.BLACK);
                gridColor = color;
                panel.repaint();
            }
        });

        JMenuItem ed1 = new JMenuItem(new AbstractAction("Add a point") {
            public void actionPerformed(ActionEvent e) {
                JPanel p = new JPanel(new GridLayout(0, 1));
                JTextField x = new JTextField(2);
                JTextField y = new JTextField(2);

                p.add(new JLabel("X coordinate: "));
                p.add(x);
                p.add(new JLabel("Y coordinate: "));
                p.add(y);

                int result = JOptionPane.showConfirmDialog(null, p, "Add a Point", JOptionPane.OK_CANCEL_OPTION,
                        JOptionPane.PLAIN_MESSAGE);

                if (result == JOptionPane.OK_OPTION && x.getText().length() > 0 && y.getText().length() > 0) {

                    int xCoord = Integer.parseInt(x.getText());
                    int yCoord = Integer.parseInt(y.getText());
                    int minX = (width - originX) / interval;
                    int minY = (height - originY) / interval;
                    if (Math.abs(xCoord) <= minX && Math.abs(yCoord) <= minY) {
                        coords.add(new ArrayList<Integer>() {
                            {
                                add(xCoord);
                                add(yCoord);
                            }
                        });
                        panel.repaint();
                    }
                }
            }
        });

        JMenuItem ed2 = new JMenuItem(new AbstractAction("Draw a line") {
            public void actionPerformed(ActionEvent e) {
                JPanel p = new JPanel(new GridLayout(0, 1));
                JTextField x1 = new JTextField(2);
                JTextField y1 = new JTextField(2);
                JTextField x2 = new JTextField(2);
                JTextField y2 = new JTextField(2);

                p.add(new JLabel("Starting point coordinates: "));
                p.add(new JLabel("X1: "));
                p.add(x1);
                p.add(new JLabel("Y1: "));
                p.add(y1);
                p.add(new JLabel("Ending point coordinates: "));
                p.add(new JLabel("X2: "));
                p.add(x2);
                p.add(new JLabel("Y2: "));
                p.add(y2);

                int result = JOptionPane.showConfirmDialog(null, p, "Draw a line", JOptionPane.OK_CANCEL_OPTION,
                        JOptionPane.PLAIN_MESSAGE);
                if (result == JOptionPane.OK_OPTION && x1.getText().length() > 0 && y1.getText().length() > 0
                        && x2.getText().length() > 0 && y2.getText().length() > 0) {
                    int x1Coord = Integer.parseInt(x1.getText());
                    int y1Coord = Integer.parseInt(y1.getText());
                    int x2Coord = Integer.parseInt(x2.getText());
                    int y2Coord = Integer.parseInt(y2.getText());
                    int minX = (width - originX) / interval;
                    int minY = (height - originY) / interval;
                    if (Math.abs(x1Coord) <= minX && Math.abs(y1Coord) <= minY && Math.abs(x2Coord) <= minX
                            && Math.abs(y2Coord) <= minY) {
                        lines.add(new Line(x1Coord, y1Coord, x2Coord, y2Coord));
                    }
                    panel.repaint();
                }
            }
        });

        m1.add(op1);
        m1.add(op2);

        m2.add(ed1);
        m2.add(ed2);

        mb.add(m1);
        mb.add(m2);

        f.setJMenuBar(mb);
        f.add(panel);
        f.setSize(800, 800);
        // f.setLayout(null);
        f.setVisible(true);
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

    @Override
    public void mouseWheelMoved(MouseWheelEvent e) {
        // System.out.println("Mouse moved!");
        zoomer = true;

        // Zoom in
        if (e.getWheelRotation() < 0) {
            zoomFactor *= 1.1;
            fontSize /= 1.1;
            fontSize = Math.max(fontSize, 5);
            panel.repaint();
        }
        // Zoom out
        if (e.getWheelRotation() > 0) {
            zoomFactor /= 1.1;
            fontSize *= 1.1;
            fontSize = Math.min(fontSize, 10);
            panel.repaint();
        }
    }

    @Override
    public void mouseDragged(MouseEvent e) {
        Point curPoint = e.getLocationOnScreen();
        xDiff = curPoint.x - startPoint.x;
        yDiff = curPoint.y - startPoint.y;

        dragger = true;
        panel.repaint();

    }

    @Override
    public void mouseMoved(MouseEvent e) {
    }

    @Override
    public void mouseClicked(MouseEvent e) {

    }

    @Override
    public void mousePressed(MouseEvent e) {
        released = false;
        startPoint = MouseInfo.getPointerInfo().getLocation();
    }

    @Override
    public void mouseReleased(MouseEvent e) {
        released = true;
        panel.repaint();
    }

    @Override
    public void mouseEntered(MouseEvent e) {

    }

    @Override
    public void mouseExited(MouseEvent e) {

    }

    public static void main(String[] args) {
        Circle g = new Circle();
    }

    public class GridPanel extends Canvas {

        @Override
        public void paint(Graphics g) {
            super.paint(g);
            originX = (getX() + getWidth()) / 2;
            originY = (getY() + getHeight()) / 2;

            width = getWidth();
            height = getHeight();
            Font stringFont = new Font("Times New Roman", 4, (int) fontSize);
            g.setFont(stringFont);
            g.setColor(gridColor);

            Graphics2D g2 = (Graphics2D) g;

            if (zoomer) {
                AffineTransform at = new AffineTransform();

                double xRel = MouseInfo.getPointerInfo().getLocation().getX() - getLocationOnScreen().getX();
                double yRel = MouseInfo.getPointerInfo().getLocation().getY() - getLocationOnScreen().getY();

                double zoomDiv = zoomFactor / prevZoomFactor;

                xOffset = (zoomDiv) * (xOffset) + (1 - zoomDiv) * xRel;
                yOffset = (zoomDiv) * (yOffset) + (1 - zoomDiv) * yRel;

                at.translate(xOffset, yOffset);
                at.scale(zoomFactor, zoomFactor);
                prevZoomFactor = zoomFactor;
                g2.transform(at);
                zoomer = false;
            }

            if (dragger) {
                AffineTransform at = new AffineTransform();
                at.translate(xOffset + xDiff, yOffset + yDiff);
                at.scale(zoomFactor, zoomFactor);
                g2.transform(at);

                if (released) {
                    xOffset += xDiff;
                    yOffset += yDiff;
                    dragger = false;
                }

            }

            for (int i = originX; i < width; i += interval) {

                g.drawLine(i, originY - height / 2, i, originY + height / 2);
                g.drawString("" + ((i - originX) / interval), i + 2, originY + 12);
            }
            for (int i = originX; i > 0; i -= interval) {
                g.drawLine(i, originY - height / 2, i, originY + height / 2);
                g.drawString("" + ((i - originX) / interval), i + 2, originY + 12);
            }

            for (int i = originY; i < height; i += interval) {
                g.drawLine(originX - width / 2, i, originX + width / 2, i);
                g.drawString("" + (-1 * (i - originY) / interval), originX + 2, i + 12);

            }
            for (int i = originY; i > 0; i -= interval) {
                g.drawLine(originX - width / 2, i, originX + width / 2, i);
                g.drawString("" + (-1 * (i - originY) / interval), originX + 2, i + 12);
            }

            // g.drawLine(originX + 1, originY - height / 2, originX + 1, originY + height /
            // 2);
            g.drawLine(originX - 1, originY - height / 2, originX - 1, originY + height / 2);

            g.drawLine(originX - width / 2, originY + 1, originX + width / 2, originY + 1);
            // g.drawLine(originX - width / 2, originY - 1, originX + width / 2, originY -
            // 1);

            g.fillOval(originX - 4, originY - 3, 6, 6);

            for (int i = 0; i < coords.size(); i++) {
                addPoint(g, coords.get(i).get(0), coords.get(i).get(1));
            }

            for (Line l : lines) {
                dda(g, l.x1,l.y1,l.x2,l.y2);
            }
            g.setColor(Color.red);
            midPointCircleDraw(g,0,0,5);
            //bresenham(g,-1,-1,-7,-11);
            //dda(g, 4,5,8,10);

            // g.fillRect(originX, originY, interval, interval);
        }

        void addPoint(Graphics g, int x, int y) {
            int minX = (width - originX) / interval;
            int minY = (height - originY) / interval;
            if (Math.abs(x) <= minX && Math.abs(y) <= minY) {
                g.fillOval(originX + x * interval - 5, originY - y * interval - 5, 10, 10);
            }
        }
        void midPointCircleDraw(Graphics g,int x_centre, int y_centre, int r)
        {
            int x = r, y = 0;

            // Printing the initial point
            // on the axes after translation
            System.out.print("(" + (x + x_centre) + ", " + (y + y_centre) + ")");
            addPoint(g,x+ x_centre,y+y_centre);
            // When radius is zero only a single
            // point will be printed
            if (r > 0) {

                System.out.print("(" + (x + x_centre) + ", " + (-y + y_centre) + ")");
                addPoint(g,x+ x_centre,-y+y_centre);

                System.out.print("(" + (y + x_centre) + ", " + (x + y_centre) + ")");
                addPoint(g,y+ x_centre,x+y_centre);

                System.out.println("(" + (-y + x_centre) + ", " + (x + y_centre) + ")");
                addPoint(g,-y+ x_centre,x+y_centre);
            }

            // Initialising the value of P
            int P = 1 - r;
            while (x > y) {

                y++;

                // Mid-point is inside or on the perimeter
                if (P <= 0)
                    P = P + 2 * y + 1;

                    // Mid-point is outside the perimeter
                else {
                    x--;
                    P = P + 2 * y - 2 * x + 1;
                }

                // All the perimeter points have already
                // been printed
                if (x < y)
                    break;

                // Printing the generated point and its
                // reflection in the other octants after
                // translation
                System.out.print("(" + (x + x_centre) + ", " + (y + y_centre) + ")");
                addPoint(g,x+ x_centre,y+y_centre);

                System.out.print("(" + (-x + x_centre) + ", " + (y + y_centre) + ")");
                addPoint(g,-x+ x_centre,y+y_centre);

                System.out.print("(" + (x + x_centre) + ", " + (-y + y_centre) + ")");
                addPoint(g,x+ x_centre,-y+y_centre);

                System.out.println("(" + (-x + x_centre) + ", " + (-y + y_centre) + ")");
                addPoint(g,-x+ x_centre,-y+y_centre);

                // If the generated point is on the
                // line x = y then the perimeter points
                // have already been printed
                if (x != y) {

                    System.out.print("(" + (y + x_centre) + ", " + (x + y_centre) + ")");
                    addPoint(g,y+ x_centre,x+y_centre);

                    System.out.print("(" + (-y + x_centre) + ", " + (x + y_centre) + ")");
                    addPoint(g,-y+ x_centre,x+y_centre);

                    System.out.print("(" + (y + x_centre) + ", " + (-x + y_centre) + ")");
                    addPoint(g,y+ x_centre,-x+y_centre);

                    System.out.println("(" + (-y + x_centre) + ", " + (-x + y_centre) +")");
                    addPoint(g,-y+ x_centre,-x+y_centre);
                }
            }
        }


        void bresenham(Graphics g, int x0,int y0,int x1,int y1) {
            var dx = Math.abs(x1 - x0);
            var dy = Math.abs(y1 - y0);
            var sx = (x0 < x1) ? 1 : -1;
            var sy = (y0 < y1) ? 1 : -1;
            var err = dx - dy;

            while(true) {
                addPoint(g,x0,y0);// Do what you need to for this

                if ((x0 == x1) && (y0 == y1)) break;
                int e2 = 2*err;
                if (e2 > -dy) { err -= dy; x0  += sx; }
                if (e2 < dx) { err += dx; y0  += sy; }
            }
        }

        void dda(Graphics g,int x0,int y0,int x1,int y1){
            int dx = x1 - x0;
            int dy = y1 - y0;

            int steps = Math.max(Math.abs(dx),Math.abs(dy));
            double xinc = dx * 1.0 / steps;
            double yinc = dy * 1.0 / steps;
            double x = x0,y = y0;

            for(int i = 1;i <= steps;i++){
                addPoint(g,(int)x,(int)y);
                x = x + xinc;
                y = y + yinc;
            }
        }
    }
}
