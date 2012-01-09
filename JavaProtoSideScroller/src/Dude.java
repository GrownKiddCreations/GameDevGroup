import java.awt.Image;
import java.awt.event.KeyEvent;

import javax.swing.ImageIcon;

public class Dude 
{
	int x,y, dx;
	Image still;
	
	public Dude()
	{
		ImageIcon i = new ImageIcon("img/afroDude.png");
		still = i.getImage();
		
		x = 10;
		y = 172;
	}

	public void move()
	{
		x += dx;
	}
	
	public int getX()
	{
		return x;
	}
	
	public int getY()
	{
		return y;
	}
	
	public Image getImage()
	{
		return still;
	}
	
	public void keyPressed(KeyEvent e)
	{
		int key = e.getKeyCode();
		
		if(key == KeyEvent.VK_LEFT)
		{
			dx = -1;
		}
		else if(key == KeyEvent.VK_RIGHT)
		{
			dx = 1;
		}
	}
	
	public void keyReleased(KeyEvent e)
	{
		int key = e.getKeyCode();
		
		if(key == KeyEvent.VK_LEFT)
		{
			dx = 0;
		}
		else if(key == KeyEvent.VK_RIGHT)
		{
			dx = 0;
		}
	}
}
