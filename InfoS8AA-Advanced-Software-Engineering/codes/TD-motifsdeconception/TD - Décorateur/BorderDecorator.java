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
public class BorderDecorator extends JComponent {
	//protected JComponent child;
	private JComponent child;

	public BorderDecorator(JComponent component) {
		child = component;
		this.setLayout(new BorderLayout());
		this.add(child);
	}

	public void paint(Graphics g) {
		super.paint(g);
		g.setColor(Color.red);
		int height = this.getHeight();
		int width = this.getWidth();
		g.drawRect(0, 0, width - 1, height - 1);
	}
}
