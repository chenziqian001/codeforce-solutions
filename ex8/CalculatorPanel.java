import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.text.DecimalFormat;
public class CalculatorPanel extends JPanel implements ActionListener {
    private JTextField displayField; 
    private String input = ""; 
    private DecimalFormat df = new DecimalFormat("0.0000"); 
    private String[] buttons = {
        "7", "8", "9", "÷",
        "4", "5", "6", "×",
        "2", "3", "1", "-",
        "0", "π", "e", "+",
        "%", "C", "(", ")",
        "sqr", "", "", "="
    };

    public CalculatorPanel() {
        setLayout(new BorderLayout(10, 10));
        setBorder(BorderFactory.createEmptyBorder(10, 10, 10, 10));
        displayField = new JTextField("0.0");
        displayField.setEditable(false); // 禁止手动输入
        displayField.setFont(new Font("宋体", Font.PLAIN, 24));
        displayField.setHorizontalAlignment(JTextField.RIGHT); // 右对齐显示
        add(displayField, BorderLayout.NORTH);
        JPanel buttonPanel = new JPanel(new GridLayout(6, 4, 10, 10));
        for (String text : buttons) {
            JButton button = new JButton(text);
            button.setFont(new Font("宋体", Font.PLAIN, 18));
            button.addActionListener(this);
            if (text.isEmpty()) {
                button.setEnabled(false);
            }
            buttonPanel.add(button);
        }
        add(buttonPanel, BorderLayout.CENTER);
    }
    @Override
    public void actionPerformed(ActionEvent e) {
        String command = e.getActionCommand();

        switch (command) {
            case "C": 
                input = "";
                displayField.setText("0.0");
                break;
            case "=": 
                try {
                    String expr = input.replace("×", "*")
                                      .replace("÷", "/")
                                      .replace("π", String.valueOf(Math.PI))
                                      .replace("e", String.valueOf(Math.E));
                   
                    expr = expr.replaceAll("(\\d+(\\.\\d+)?)sqr", "$1*$1");
            
                    expr = handleSqrt(expr);
                    double result = (double) new javax.script.ScriptEngineManager()
                            .getEngineByName("JavaScript")
                            .eval(expr);
                    displayField.setText(df.format(result));
                    input = String.valueOf(result); // 结果作为下一次输入的起始
                } catch (Exception ex) {
                    displayField.setText("错误");
                    input = "";
                }
                break;
            case "sqr": // 平方标识（暂存输入）
                input += command;
                displayField.setText(input);
                break;
            default: // 数字、运算符、括号、常量
                input += command;
                displayField.setText(input);
                break;
        }
    }
    private String handleSqrt(String expr) {
        return expr;
    }
}