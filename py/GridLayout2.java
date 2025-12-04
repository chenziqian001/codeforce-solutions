import java.awt.*;
import javax.swing.JFrame;

public class Gridlayout2 {
    public static void main(String[] args) {
        JFrame f = new JFrame("计算器界面");
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        f.setBounds(100, 100, 200, 200);
        NumPanel np = new NumPanel();
        f.add(np);
        f.setVisible(true);
    }
}

class NumPanel extends Panel {
    public NumPanel() {
        this.setBounds(0, 0, 200, 180);
        GridLayout gl = new GridLayout(4, 5, 5, 5);
        this.setLayout(gl);
        Button buttons[] = new Button[20];
        buttons[0] = new Button("7");
        buttons[1] = new Button("8");
        buttons[2] = new Button("9");
        buttons[3] = new Button("/");
        buttons[4] = new Button("sqrt");
        buttons[5] = new Button("4");
        buttons[6] = new Button("5");
        buttons[7] = new Button("6");
        buttons[8] = new Button("*");
        buttons[9] = new Button("%");
        buttons[10] = new Button("1");
        buttons[11] = new Button("2");
        buttons[12] = new Button("3");
        buttons[13] = new Button("-");
        buttons[14] = new Button("1/x");
        buttons[15] = new Button("0");
        buttons[16] = new Button("+/-");
        buttons[17] = new Button(".");
        buttons[18] = new Button("+");
        buttons[19] = new Button("=");
        
        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 5; j++) {
                this.add(buttons[i * 5 + j]);
            }
        }
    }
}
