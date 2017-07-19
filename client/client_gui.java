/*
 * GUI for the client.
 * 
 * Created by Kyler Smith, 2017
 */
import javax.swing.*;
import java.awt.*;
import java.util.*;

public class client_gui extends JFrame {
	
	/** Constants */
	private final String CLIENT_NAME = "IRC CLIENT";
	private final int WIDTH = 500, HEIGHT = 300;
	private JFrame frame;
	private JTextField textField;
	private JTextArea textArea;
	
	/**
	 * Constructor
	 */
	public client_gui() {
		//setup();
		setup();
	}
	
	/**
	 * Sets up the GUI for the server.
	 */
	private void setup() {
		
		frame = new JFrame();
		textField = new JTextField();
		textField.setBounds(0, 255, WIDTH - 75, 20);
		frame.add(textField);
		frame.setSize(WIDTH, HEIGHT);
		frame.setLayout(null);
		frame.setVisible(true);
	}
	
	/**
	 * Entry point for the program
	 */
	public static void main(String[] args) {
		client_gui c_gui = new client_gui();
	}
}





