

import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Image;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;

import javax.swing.ImageIcon;
import javax.swing.JPanel;
import javax.swing.Timer;

public class Board extends JPanel implements ActionListener
{
	
	Dude character;
	Image img;
	Timer time;
	
	public Board()
	{
		character = new Dude();
		
		addKeyListener(new AL());
		
		setFocusable(true);
		
		ImageIcon i = new ImageIcon("img/skyline_bg.jpg");
		
		img = i.getImage();
		
		time = new Timer(5, this);
		time.start();
	}

	@Override
	public void actionPerformed(ActionEvent e) 
	{
		character.move();
		repaint();
	}
	
	public void paint(Graphics g)
	{
		super.paint(g);
		Graphics2D g2d = (Graphics2D) g;
		
		g2d.drawImage(img,0,0,null);
		g2d.drawImage(character.getImage(), character.getX(), character.y, null);
	}
	
	private class AL extends KeyAdapter
	{
		public void keyReleased(KeyEvent e)
		{
			character.keyReleased(e);
		}
		
		public void keyPressed(KeyEvent e)
		{
			character.keyPressed(e);
		}
	}
	
}
