import java.awt.*;
import java.awt.event.*;
import javax.Swing.*;

public class Ex13_1{
    public static void main(String[] args){
        JFrame frame=new frame("FrameDemon");
        frame.setSize(200,300);
        frame.setVisible(true);
    }
}





import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
public class JPanelClass extends JPanel{
    JLabel nameLabel,phoneLabel;
    JTextField name;
    JTextField phone;
    JButton LoginButton,CancelButton;

    public JPanelClass(){
        nameLabel=new JLabel("User");
        phoneLabel=new JLabel("phone");
        name=new JTextField(13);
        phone=new JTextField(13);
        LoginButton=new JButton("Summit");
        CancelButton=new JButton("cancel");
        add(nameLabel);
        add(name);
        add(phoneLabel);
        add(phone);
        add(LoginButton);
        add(CancelButton); 
    }
}

import javax.swing.JFrame;
public class SimpleJFrameClass extends JFrame {
    JPanelClass panel;
    public SimpleJFrameClass(){
        setSize(320,120);
        this.setTitle("Login GUI");
        panel=new JPanelClass();
        this.add(panel);
        this.setVisible(true);
        this.setResizable(false);
    }
}
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.JFrame;
public class Ex13_2 {
public static void main(String[] args) {
SimpleJFrameClass frame=new SimpleJFrameClass();
frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
}
}