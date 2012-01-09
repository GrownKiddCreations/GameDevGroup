import javax.swing.JFrame;

public class Frame 
{
	public static void main(String[] args)
	{
		JFrame frame = new JFrame("2d Side Scroller");
		
		frame.add(new Board());
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setSize(800, 450);
		frame.setVisible(true);
	}
}