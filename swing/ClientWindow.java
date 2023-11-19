import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

public class ClientWindow extends JFrame implements ActionListener {
    private static final long serialVersionUID = 1L;
    JTextArea textArea;
    JButton button1, button2, button3;

    public ClientWindow() {
        super("Client Window");
        setLayout(new BorderLayout());
        textArea = new JTextArea(20, 40);

        JPanel buttonPanel = new JPanel();
        
        JScrollPane scrollPane = new JScrollPane(textArea);
        scrollPane.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_ALWAYS);
        scrollPane.setHorizontalScrollBarPolicy(JScrollPane.HORIZONTAL_SCROLLBAR_NEVER);
        add(scrollPane, BorderLayout.CENTER);

        button1 = new JButton("Button 1");
        button1.addActionListener(this);
        buttonPanel.add(button1);
        
        button2 = new JButton("Button 2");
        button2.addActionListener(this);
        buttonPanel.add(button2);

        button3 = new JButton("Button 3");
        button3.addActionListener(this);
        buttonPanel.add(button3);

        add(buttonPanel, BorderLayout.NORTH);
        
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        pack();
        setVisible(true);
    }

    public static void main(String[] args) {
        new ClientWindow();
    }

    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == button1) {
            textArea.append("Button 1 was pressed\n");
        } else if (e.getSource() == button2) {
            textArea.append("Button 2 was pressed\n");
        } else if (e.getSource() == button3) {
            textArea.append("Button 3 was pressed\n");
        }
    }
}