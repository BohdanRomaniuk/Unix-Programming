import java.awt.BorderLayout;
import java.awt.Dimension;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JTabbedPane;

public class JavaVisualFrame extends JFrame 
{
	private	JPanel	tab1;
	private	JPanel	tab2;

	public JavaVisualFrame() 
	{
		super("Unix Programming");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(new Dimension(600, 400));
        setResizable(false);
        setLayout(new BorderLayout(10, 10));
		
		JPanel mainPanel = new JPanel();
		mainPanel.setLayout(new BorderLayout());
		getContentPane().add(mainPanel);
		
		loadTab1();
		loadTab2();

		JTabbedPane tabPane = new JTabbedPane();
		tabPane.addTab("Find oldest directory", tab1);
		tabPane.addTab("Remove repeating files", tab2);
		mainPanel.add(tabPane);
	}
	
	public void loadTab1()
	{
		tab1 = new JPanel();
		tab1.setLayout(null);
		
		JButton btn1 = new JButton("Button 1");
		btn1.setBounds(10, 11, 89, 23);
		tab1.add(btn1);
		
		JButton btn2 = new JButton("Button 2");
		btn2.setBounds(10, 45, 89, 23);
		tab1.add(btn2);
	}

	public void loadTab2()
	{
		tab2 = new JPanel();
		tab2.setLayout(null);
		
		JButton btn3 = new JButton("Button 3");
		btn3.setBounds(10, 11, 89, 23);
		tab2.add(btn3);
		
		JButton btn4 = new JButton("Button 4");
		btn4.setBounds(10, 45, 89, 23);
		tab2.add(btn4);	
	}
}