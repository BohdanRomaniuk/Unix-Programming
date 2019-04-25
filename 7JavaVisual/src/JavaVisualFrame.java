import java.awt.BorderLayout;
import java.awt.Dimension;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.BorderFactory;
import javax.swing.JButton;
import javax.swing.JFileChooser;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JTabbedPane;
import javax.swing.JTextField;
import javax.swing.border.Border;

public class JavaVisualFrame extends JFrame implements ActionListener
{
	private	JPanel	tab1;
	private	JPanel	tab2;
	
	//First
	private JLabel selectDirectoryLabel1 = new JLabel("Select directory"); 
	private JTextField selectedDirectory1 = new JTextField("/home/bohdan/first/");
	private JButton chooseDirectoryButton1 = new JButton("Choose directory");
	
	private JButton searchButton = new JButton("Search for oldest directory");
	private JButton runFirstTests = new JButton("Run Tests");
	
	private JLabel searchResultLabel = new JLabel("Oldest directory:"); 
	private JTextField oldestDirectory = new JTextField("");
	
	//Selected
	private JLabel selectDirectoryLabel2 = new JLabel("Select directory"); 
	private JTextField selectedDirectory2 = new JTextField("/home/bohdan/second/");
	private JButton chooseDirectoryButton2 = new JButton("Choose directory");
	
	private JLabel allowedExtensionLabel = new JLabel("Allowed extension:"); 
	private JTextField allowedExtension = new JTextField(".cpp");
	
	private JButton removeButton = new JButton("Remove similar files");
	private JButton runSecondTests = new JButton("Run Tests");
	

	public JavaVisualFrame() 
	{
		super("Unix Programming");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(new Dimension(500, 230));
        setResizable(false);
        setLayout(new BorderLayout(100, 100));
		
		JPanel mainPanel = new JPanel();
		mainPanel.setLayout(new BorderLayout(100,100));
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
		tab1 = new JPanel(new GridLayout(3, 1, 10, 10));
		
		JPanel selectDirPanel = new JPanel(new BorderLayout(10, 10));
		Border southBorder = BorderFactory.createTitledBorder("Select directory:");
		selectDirPanel.setBorder(southBorder);
		selectDirPanel.add(selectDirectoryLabel1, BorderLayout.WEST);
		selectDirPanel.add(selectedDirectory1, BorderLayout.CENTER);
		chooseDirectoryButton1.addActionListener(this);
		selectDirPanel.add(chooseDirectoryButton1, BorderLayout.EAST);
		
		JPanel functionsPanel = new JPanel(new BorderLayout(10,10));
		Border functionsBorder = BorderFactory.createTitledBorder("Functions:");
		functionsPanel.setBorder(functionsBorder);
		runFirstTests.addActionListener(this);
		functionsPanel.add(runFirstTests, BorderLayout.WEST);
		searchButton.addActionListener(this);
		functionsPanel.add(searchButton, BorderLayout.EAST);
        
        JPanel resultPanel = new JPanel(new BorderLayout(10, 10));
		Border centerBorder = BorderFactory.createTitledBorder("Searching result:");
		resultPanel.setBorder(centerBorder);
		resultPanel.add(searchResultLabel, BorderLayout.WEST);
		resultPanel.add(oldestDirectory, BorderLayout.CENTER);
		
		tab1.add(selectDirPanel);
		tab1.add(functionsPanel);
		tab1.add(resultPanel);
	}

	public void loadTab2()
	{
		tab2 = new JPanel(new GridLayout(3, 1, 10, 10));
		
		JPanel selectDirPanel = new JPanel(new BorderLayout(10, 10));
		Border southBorder = BorderFactory.createTitledBorder("Select directory:");
		selectDirPanel.setBorder(southBorder);
		selectDirPanel.add(selectDirectoryLabel2, BorderLayout.WEST);
		selectDirPanel.add(selectedDirectory2, BorderLayout.CENTER);
		chooseDirectoryButton2.addActionListener(this);
		selectDirPanel.add(chooseDirectoryButton2, BorderLayout.EAST);
		
		JPanel allowedExtPanel = new JPanel(new BorderLayout(10, 10));
		Border centerBorder = BorderFactory.createTitledBorder("Allowed extension:");
		allowedExtPanel.setBorder(centerBorder);
		allowedExtPanel.add(allowedExtensionLabel, BorderLayout.WEST);
		allowedExtPanel.add(allowedExtension, BorderLayout.CENTER);
		
		JPanel functionsPanel = new JPanel(new BorderLayout(10,10));
		Border functionsBorder = BorderFactory.createTitledBorder("Functions:");
		functionsPanel.setBorder(functionsBorder);
		runSecondTests.addActionListener(this);
		functionsPanel.add(runSecondTests, BorderLayout.WEST);
		removeButton.addActionListener(this);
		functionsPanel.add(removeButton, BorderLayout.EAST);
		
		tab2.add(selectDirPanel);
		tab2.add(allowedExtPanel);
		tab2.add(functionsPanel);
	}
	
	public void actionPerformed(ActionEvent e)
    {
        if(e.getSource() == chooseDirectoryButton1)
        {
        	JFileChooser f = new JFileChooser();
        	f.setFileSelectionMode(JFileChooser.DIRECTORIES_ONLY); 
        	f.showOpenDialog(null);
        	selectedDirectory1.setText(f.getSelectedFile().toString());
        }
        else if(e.getSource() == searchButton)
        {
        	String directory = selectedDirectory1.getText();
			OldestFolderSearcher searcher = new OldestFolderSearcher();
			String oldestDir = searcher.FindOldestDir(directory);
			oldestDirectory.setText(oldestDir);
        }
        else if(e.getSource() == runFirstTests)
        {
        	String infoMessage = "";
        	infoMessage += "Test 1.1: " + (Tests.Test1_1() ? "passed" : "failed")+"\n";
        	infoMessage += "Test 1.2: " + (Tests.Test1_2() ? "passed" : "failed")+"\n";
        	infoMessage += "Test 1.3: " + (Tests.Test1_3() ? "passed" : "failed");
        	JOptionPane.showMessageDialog(null, infoMessage, "First tests", JOptionPane.INFORMATION_MESSAGE);
        }
        else if(e.getSource() == chooseDirectoryButton2)
        {
        	JFileChooser f = new JFileChooser();
        	f.setFileSelectionMode(JFileChooser.DIRECTORIES_ONLY); 
        	f.showOpenDialog(null);
        	selectedDirectory2.setText(f.getSelectedFile().toString());
        }
        else if(e.getSource() == removeButton)
        {
        	String directory = selectedDirectory2.getText();
			String allowedExt = allowedExtension.getText();
			RepeatingFilesRemover remover = new RepeatingFilesRemover();
			int removedCount = remover.RemoveRepeatingFiles(directory, allowedExt);
			JOptionPane.showMessageDialog(null, "Removed: " + removedCount + " files", "First tests", JOptionPane.INFORMATION_MESSAGE);
        }
        else if(e.getSource() == runSecondTests)
        {
        	String infoMessage = "";
        	infoMessage += "Test 2.1: " + (Tests.Test2_1() ? "passed" : "failed")+"\n";
        	infoMessage += "Test 2.2: " + (Tests.Test2_2() ? "passed" : "failed")+"\n";
        	infoMessage += "Test 2.3: " + (Tests.Test2_3() ? "passed" : "failed");
        	JOptionPane.showMessageDialog(null, infoMessage, "Second tests", JOptionPane.INFORMATION_MESSAGE);
        }
    }
}