package main;

import java.awt.Color;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.Point;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.util.ArrayList;
import java.util.concurrent.TimeUnit;

import javax.swing.JButton;
import javax.swing.JPanel;


public class DotsPanelV2 extends JPanel
{
	static Point p1; //p1 erster punkt p2 release punkt	
	static Point p2;
	static int firstopener = 0;
	
	private static final long serialVersionUID = 1L;

	private final int SIZE = 0;  // radius of each dot

	private ArrayList<Point> pointList;

	private JButton remove;
	private JButton clear;

	//-----------------------------------------------------------------
	//  Constructor: Sets up this panel to listen for mouse events.
	//-----------------------------------------------------------------
	public DotsPanelV2()
	{
		pointList = new ArrayList<Point>();

		addMouseListener (new DotsListener());

		setPreferredSize (new Dimension(500, 500));

		

	}

	//-----------------------------------------------------------------
	//  Draws all of the dots stored in the list.
	//-----------------------------------------------------------------
	ArrayList<Integer> psaver = new ArrayList<Integer>();
	
	public void paintComponent (Graphics page)
	{
		super.paintComponent(page);

		page.setColor (Color.BLACK);

		for (Point spot : pointList)
			page.fillOval (spot.x-SIZE, spot.y-SIZE, SIZE*2, SIZE*2);
		
		
		
		
		//hier ist was ich hinzugefügt habe
		if (firstopener == 2) {
			psaver.add((int) p1.getX());
			psaver.add((int) p1.getY());
			psaver.add((int) p2.getX());
			psaver.add((int) p2.getY());
			
			int counter = 0;
			for (int i = 0; i < psaver.size()/4; i++) {
				
				
				page.drawLine(psaver.get(counter), psaver.get(counter+1), psaver.get(counter+2), psaver.get(counter+3));
				counter += 4;
				
			}
			
			firstopener = 0;
		}
		
	}

	//*****************************************************************
	//  Represents the listener for mouse events.
	//*****************************************************************
	private class DotsListener implements MouseListener
	{

		
		public void mousePressed (MouseEvent event)
		{
			firstopener += 1;
			p1 = event.getPoint();
			

		}

		public void mouseClicked (MouseEvent event) {}
		public void mouseReleased (MouseEvent event) {
			firstopener += 1;
			p2 = event.getPoint();
			
			
			repaint(); //nur hier repaint sonst blinkt alles
		}
		public void mouseEntered (MouseEvent event) {}
		public void mouseExited (MouseEvent event) {}
	}

	public void paintComponent1(Graphics g) {
		
	}
	
	private class RemoveActionListener implements ActionListener {

		@Override
		public void actionPerformed(ActionEvent arg0) {
			
			if (pointList.size()==1) {
				pointList.remove(pointList.size()-1);

			}else if (pointList.size() >= 1){
				pointList.remove(pointList.size()-1);
				
			}
			repaint();
		}

	}

	private class ClearActionListener implements ActionListener {

		@Override
		public void actionPerformed(ActionEvent arg0) {
			
			// TODO Auto-generated method stub
			pointList = new ArrayList<Point>();
			remove.setEnabled(false);
			clear.setEnabled(false);
			repaint();
		}

	}

}
