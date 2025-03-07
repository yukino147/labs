import javax.swing.*;
import javax.tools.DocumentationTool.Location;

import java.awt.*;

public class Main extends JFrame{
    public static void main(String[] args) {
        Main frame = new Main();
        
        frame.setBounds(10,10,1200,900);
        frame.setDefaultCloseOperation(2);
        frame.setVisible(true);
    }

    @Override
    public void paint(Graphics g){
        super.paint(g);
        g.setColor(Color.RED);
        g.setFont(new Font("Serif",Font.BOLD,32));
        g.drawString("Аргунов Владимир ИВТ-23-1",200, 100);

        int[] red = new int[] {255,0,0,255,0};
        int[] green = new int[] {0,255,0,255,255};
        int[] blue = new int[] {0,0,255,0,255};
        int x=0;
        int y=0;
        for(int i=0; i < 5; i++){
            g.setColor(Color.BLUE);
            g.fillRect(100+x,300+y,100,100);

            g.drawLine(100+x,300+y,50+x,350+y);
            g.drawLine(200+x,300+y,250+x,350+y);
            g.drawLine(120+x, 400+y, 100+x, 500+y);
            g.drawLine(180+x, 400+y, 180+x, 500+y);

            g.setColor(new Color(234, 182, 118));
            g.fillOval(100+x, 200+y, 100, 100);
            g.setColor(new Color(red[i],green[i],blue[i]));
            g.fillArc(100+x, 200+y, 100, 100, -30, 180);
            g.drawLine(62+x, 200+y, 238+x, 300+y);
            x+=230;
            y+=30;
        }
    }
}