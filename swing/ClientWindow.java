import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;

public class ClientWindow extends JFrame {
    private static final long serialVersionUID = 1L;
    JTextArea textArea;
    JButton button1, button2, button3;
    JMenuBar menuBar;
    JMenu menu;
    JToolBar toolBar;

    public ClientWindow() {
        super("Client Window");
        setLayout(new BorderLayout());
        textArea = new JTextArea(20, 40);

        menuBar = new JMenuBar();
        menu = new JMenu("Menu");
        setJMenuBar(menuBar);
        menuBar.add(menu);

        // button1 = new JButton("Button 1");
        // button2 = new JButton("Button 2");
        // button3 = new JButton("Exit");

        Action actionButton1 = new ButtonAction("Button 1");
        Action actionButton2 = new ButtonAction("Button 2");
        Action actionButton3 = new ExitAction();

        menu.add(new JMenuItem(actionButton1));
        menu.add(new JMenuItem(actionButton2));
        menu.addSeparator();
        menu.add(new JMenuItem(actionButton3));

        toolBar = new JToolBar();
        toolBar.add(new JButton(actionButton1));
        toolBar.add(new JButton(actionButton2));
        toolBar.add(new JButton(actionButton3));
        add(toolBar, BorderLayout.NORTH);

        JScrollPane scrollPane = new JScrollPane(textArea);
        scrollPane.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_ALWAYS);
        scrollPane.setHorizontalScrollBarPolicy(JScrollPane.HORIZONTAL_SCROLLBAR_NEVER);
        add(scrollPane, BorderLayout.CENTER);

        setDefaultCloseOperation(EXIT_ON_CLOSE);
        pack();
        setVisible(true);
    }

    private class ButtonAction extends AbstractAction {
        public ButtonAction(String name) {
            super(name);
        }

        @Override
        public void actionPerformed(ActionEvent e) {
            textArea.append(getValue(NAME) + " was pressed\n");
        }
    }

    private class ExitAction extends AbstractAction {
        public ExitAction() {
            super("Exit");
        }

        @Override
        public void actionPerformed(ActionEvent e) {
            System.exit(0);
        }
    }

    public static void main(String[] args) {
        new ClientWindow();
    }
}
