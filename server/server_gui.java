/*
 * GUI for the server.
 * 
 * Created by Kyler Smith, 2017
 */
import javax.swing.*;
import java.awt.*;
import java.util.*;

public class server_gui extends JFrame {
	
	/** Constants */
	private final String SERVER_NAME = "IRC SERVER";
	
	/**
	 * Constructor
	 */
	public server_gui() {
		setup();
	}
	
	/**
	 * Sets up the GUI for the server.
	 */
	private void setup() {
		JTextArea jta = new JTextArea();
		setLayout(new BorderLayout());
		add(new JScrollPane(jta), BorderLayout.CENTER);
		setTitle(SERVER_NAME);
		jta.setEditable(false);
		setSize(500, 300);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setVisible(true);
		jta.append(new Date().toString());
	}
	
	/**
	 * Entry point for the program
	 */
	public static void main(String[] args) {
		server_gui s_gui = new server_gui();
	}

}





