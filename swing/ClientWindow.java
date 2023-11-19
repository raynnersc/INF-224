import java.awt.BorderLayout;
import java.awt.event.ActionEvent;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.net.Socket;
import java.net.UnknownHostException;

import javax.swing.AbstractAction;
import javax.swing.Action;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.JTextField;
import javax.swing.JToolBar;

public class ClientWindow extends JFrame {
    private static final long serialVersionUID = 1L;
    JTextArea textArea;
    // JButton button1, button2, button3;
    JMenuBar menuBar;
    JMenu menu;
    JToolBar toolBar;
    JTextField textField;
    JLabel label;
    JPanel panel;

    static final String DEFAULT_HOST = "localhost";
    static final int DEFAULT_PORT = 3331;
    static String host = DEFAULT_HOST;
    static int port = DEFAULT_PORT;
    static Client client = null;

    public ClientWindow() {
        super("Client Window");
        setLayout(new BorderLayout());
        textArea = new JTextArea(20, 60);
        
        panel = new JPanel(new BorderLayout());
        label = new JLabel("Enter your media/group name:");
        textField = new JTextField(60);
        panel.add(label, BorderLayout.NORTH);
        panel.add(textField, BorderLayout.SOUTH);
        add(panel, BorderLayout.SOUTH);

        menuBar = new JMenuBar();
        menu = new JMenu("Menu");
        setJMenuBar(menuBar);
        menuBar.add(menu);

        // button1 = new JButton("Button 1");
        // button2 = new JButton("Button 2");
        // button3 = new JButton("Exit");

        Action actionButton1 = new ConnectAction();
        Action actionButton2 = new FindAction();
        Action actionButton3 = new DisplayMediaAction();
        Action actionButton4 = new DisplayGroupAction();
        Action actionButton5 = new ReproduceAction();
        Action actionButton6 = new ExitAction();

        menu.add(new JMenuItem(actionButton1));
        menu.add(new JMenuItem(actionButton2));
        menu.add(new JMenuItem(actionButton3));
        menu.add(new JMenuItem(actionButton4));
        menu.add(new JMenuItem(actionButton5));
        menu.addSeparator();
        menu.add(new JMenuItem(actionButton6));

        toolBar = new JToolBar();
        toolBar.add(new JButton(actionButton1));
        toolBar.add(new JButton(actionButton2));
        toolBar.add(new JButton(actionButton3));
        toolBar.add(new JButton(actionButton4));
        toolBar.add(new JButton(actionButton5));
        toolBar.addSeparator();
        toolBar.add(new JButton(actionButton6));
        add(toolBar, BorderLayout.NORTH);

        JScrollPane scrollPane = new JScrollPane(textArea);
        scrollPane.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_ALWAYS);
        scrollPane.setHorizontalScrollBarPolicy(JScrollPane.HORIZONTAL_SCROLLBAR_NEVER);
        add(scrollPane, BorderLayout.CENTER);

        setDefaultCloseOperation(EXIT_ON_CLOSE);
        pack();
        setVisible(true);
    }

    private class ConnectAction extends AbstractAction {
        public ConnectAction() {
            super("Connect");
        }

        @Override
        public void actionPerformed(ActionEvent e) {
            if (client != null && client.isConnected()) {
                System.out.println("Client already connected to " + host + ":" + port);
                textArea.append("Client already connected to " + host + ":" + port + "\n");
                return;
            }
            try {
                client = new Client(host, port);
                System.out.println("Client connected to " + host + ":" + port);
                textArea.append("Client connected to " + host + ":" + port + "\n");
              }
              catch (Exception ex) {
                System.err.println("Client: Couldn't connect to "+host+":"+port);
                textArea.append("Client: Couldn't connect to "+host+":"+port+"\n");
                // System.exit(1);
              }
        }
    }

    private class FindAction extends AbstractAction {
        public FindAction() {
            super("Find");
        }

        @Override
        public void actionPerformed(ActionEvent e) {
            String request = "find " + textField.getText();
            String response = client.send(request);
            textArea.append(client.handleResponse(response));
        }
    }

    private class DisplayGroupAction extends AbstractAction {
        public DisplayGroupAction() {
            super("Display Group");
        }

        @Override
        public void actionPerformed(ActionEvent e) {
            String request = "displayGroup " + textField.getText();
            String response = client.send(request);
            textArea.append(client.handleResponse(response));
        }
    }

    private class DisplayMediaAction extends AbstractAction {
        public DisplayMediaAction() {
            super("Display Media");
        }

        @Override
        public void actionPerformed(ActionEvent e) {
            String request = "displayMedia " + textField.getText();
            String response = client.send(request);
            textArea.append(client.handleResponse(response));
        }
    }

    private class ReproduceAction extends AbstractAction {
        public ReproduceAction() {
            super("Reproduce");
        }

        @Override
        public void actionPerformed(ActionEvent e) {
            String request = "reproduce " + textField.getText();
            String response = client.send(request);
            textArea.append(client.handleResponse(response));
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

        if (args.length >= 1)
            host = args[0];
        if (args.length >= 2)
            port = Integer.parseInt(args[1]);

        new ClientWindow();
    }

    private static class Client {
        private Socket sock;
        private BufferedReader input;
        private BufferedWriter output;

        public Client(String host, int port) throws UnknownHostException, IOException {
            try {
                sock = new java.net.Socket(host, port);
            } catch (java.net.UnknownHostException e) {
                System.err.println("Client: Couldn't find host " + host + ":" + port);
                throw e;
            } catch (java.io.IOException e) {
                System.err.println("Client: Couldn't reach host " + host + ":" + port);
                throw e;
            }

            try {
                input = new BufferedReader(new InputStreamReader(sock.getInputStream()));
                output = new BufferedWriter(new OutputStreamWriter(sock.getOutputStream()));
            } catch (java.io.IOException e) {
                System.err.println("Client: Couldn't open input or output streams");
                throw e;
            }
        }

        public String send(String request) {
            // Envoyer la requete au serveur
            try {
                request += "\n"; // ajouter le separateur de lignes
                output.write(request, 0, request.length());
                output.flush();
            } catch (java.io.IOException e) {
                System.err.println("Client: Couldn't send message: " + e);
                return null;
            }

            // Recuperer le resultat envoye par le serveur
            try {
                return input.readLine();
            } catch (java.io.IOException e) {
                System.err.println("Client: Couldn't receive message: " + e);
                return null;
            }
        }

        public String handleResponse(String response) {
            if (response != null) {
                response = response.replace("/end/", "\n");
            }
            return response;
        }

        public boolean isConnected() {
            return sock != null && sock.isConnected() && !sock.isClosed();
        }
    }
}
