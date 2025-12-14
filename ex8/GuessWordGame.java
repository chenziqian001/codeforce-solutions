import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class GuessWordGame {
    private JFrame gameFrame;
    private JTextField inputField;
    private JLabel tipLabel;
    private String targetWord = "java"; // 目标单词
    private int guessCount = 3; // 猜测次数

    public GuessWordGame() {
        gameFrame = new JFrame("猜字游戏");
        gameFrame.setSize(300, 200);
        gameFrame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        gameFrame.setLocationRelativeTo(null);
        gameFrame.setLayout(new FlowLayout(FlowLayout.CENTER, 20, 30));

        // 提示标签
        tipLabel = new JLabel("猜一个4字母单词（剩余" + guessCount + "次）");
        gameFrame.add(tipLabel);

        // 输入框
        inputField = new JTextField(10);
        gameFrame.add(inputField);

        // 提交按钮
        JButton submitBtn = new JButton("提交");
        submitBtn.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String guess = inputField.getText().trim().toLowerCase();
                if (guess.equals(targetWord)) {
                    JOptionPane.showMessageDialog(gameFrame, "猜对了！");
                    gameFrame.dispose();
                } else {
                    guessCount--;
                    if (guessCount <= 0) {
                        JOptionPane.showMessageDialog(gameFrame, "次数用完！正确答案是：" + targetWord);
                        gameFrame.dispose();
                    } else {
                        tipLabel.setText("猜错了（剩余" + guessCount + "次）");
                        inputField.setText("");
                    }
                }
            }
        });
        gameFrame.add(submitBtn);

        gameFrame.setVisible(true);
    }
}