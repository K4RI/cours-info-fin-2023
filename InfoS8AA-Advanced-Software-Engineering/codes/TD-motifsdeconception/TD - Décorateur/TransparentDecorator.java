/*
 * Created on 9 janv. 2004
 *
 * To change the template for this generated file go to
 * Window&gt;Preferences&gt;Java&gt;Code Generation&gt;Code and Comments
 */

/**
 * @author ciarlett
 *
 * To change the template for this generated type comment go to
 * Window&gt;Preferences&gt;Java&gt;Code Generation&gt;Code and Comments
 */

import javax.swing.JComponent;
import java.awt.Graphics;
import java.awt.Color;
import java.awt.BorderLayout;
public class TransparentDecorator extends JComponent {
	//protected JComponent child1;
	private JComponent child1;
	private Color myColor = new Color(255, 125, 10, 200);
	public TransparentDecorator(JComponent component) {
		child1 = component;
		child1.setBackground(myColor);
		this.setLayout(new BorderLayout());
		this.add(child1);
	}

	public void paint(Graphics g) {
		super.paint(g);
		g.setColor(myColor);
		int height = this.getHeight();
		int width = this.getWidth();
		g.fillRect(1,1,width-2,height-2);
	}
}
