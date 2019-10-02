import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JLabel;
import java.awt.Font;
import javax.swing.SwingConstants;
import javax.swing.JTextField;
import javax.swing.JButton;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.awt.Color;

public class Frame1test {

	private JFrame frame;
	private JTextField txtDfsa;
	String checkResult;
	JButton btnResultButton;
	
	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					Frame1test window = new Frame1test();
					window.frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the application.
	 */
	public Frame1test() {
		initialize();
	}

	/**
	 * Initialize the contents of the frame.
	 */
	private void initialize() {
		frame = new JFrame();
		frame.getContentPane().setBackground(Color.LIGHT_GRAY);
		frame.setBounds(100, 100, 450, 300);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.getContentPane().setLayout(null);
		
		JLabel lblBracketsBalanceCheck = new JLabel("Brackets Balance Check");
		lblBracketsBalanceCheck.setHorizontalAlignment(SwingConstants.CENTER);
		lblBracketsBalanceCheck.setFont(new Font("Dialog", Font.BOLD, 18));
		lblBracketsBalanceCheck.setBounds(80, 38, 270, 30);
		frame.getContentPane().add(lblBracketsBalanceCheck);
		
		JLabel lblTypeInA = new JLabel("Type in a string with brackets:");
		lblTypeInA.setFont(new Font("Dialog", Font.PLAIN, 12));
		lblTypeInA.setBounds(60, 91, 228, 15);
		frame.getContentPane().add(lblTypeInA);
		
		txtDfsa = new JTextField();
		txtDfsa.setToolTipText("");
		txtDfsa.setBounds(60, 106, 250, 64);
		frame.getContentPane().add(txtDfsa);
		txtDfsa.setColumns(10);
	
		JLabel lblResult = new JLabel("Result:");
		lblResult.setFont(new Font("Dialog", Font.PLAIN, 12));
		lblResult.setBounds(60, 194, 66, 15);
		frame.getContentPane().add(lblResult);

		/*JButton*/ btnResultButton = new JButton("");
 btnResultButton.setFont(new Font("Dialog", Font.PLAIN, 12));
		btnResultButton.setBackground(Color.LIGHT_GRAY);
		
		JButton btnRunButton = new JButton("Run");
		btnRunButton.setFont(new Font("Dialog", Font.PLAIN, 11));
/*
		btnRunButton.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				String userTypedString = txtDfsa.getText();	     // user clicked run, we get the user string from text field
				BracketsBalance brkBalance = new BracketsBalance();
				checkResult = brkBalance.checkBalance(userTypedString);
				btnResultButton.setText(checkResult);
			}
		});
*/
		btnRunButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				//btnResultButton.setText(" Reach here 11111111111111111");
				String userTypedString = txtDfsa.getText();	     // user clicked run, we get the user string from text field
				if(userTypedString.isEmpty())
				{
					btnResultButton.setText("You forgot to type in a string with brackets! Try again.");
				}
				else
				{
					BracketsBalance brkBalance = new BracketsBalance();
					checkResult = brkBalance.checkBalance(userTypedString);
					btnResultButton.setText(checkResult);
				}
			}
		});
		
		btnRunButton.setBounds(332, 106, 66, 25);
		frame.getContentPane().add(btnRunButton);
/*
		JLabel lblResult = new JLabel("Result:");
		lblResult.setBounds(80, 168, 66, 15);
		frame.getContentPane().add(lblResult);
		
		JButton btnResultButton = new JButton("");
		btnResultButton.setBackground(Color.LIGHT_GRAY);*/
		/*btnResultButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
			}
		});*/
		btnResultButton.setBounds(64, 209, 246, 25);
		frame.getContentPane().add(btnResultButton);
		
		JButton btnClean = new JButton("Clean");
		btnClean.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				btnResultButton.setText("");
				txtDfsa.setText("");
			}
		});
		btnClean.setFont(new Font("Dialog", Font.PLAIN, 11));
		btnClean.setBounds(332, 143, 66, 25);
		frame.getContentPane().add(btnClean);
		
		//btnResultButton.setText(checkResult);
	}
}
