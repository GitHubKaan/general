package main;

import javax.swing.JFrame;

public class main {
	public static void main(String[] args) 	{
		JFrame frame = new JFrame ("Dots V2");
		frame.setDefaultCloseOperation (JFrame.EXIT_ON_CLOSE);

		frame.getContentPane().add (new DotsPanelV2());

		frame.pack();
		frame.setLocationRelativeTo(null);
		
		frame.setVisible(true);
	}
}
