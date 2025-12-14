import javax.swing.*;
import java.awt.*;

public class SnakeGame {
    public SnakeGame() {
        // 创建贪吃蛇游戏窗口
        JFrame gameFrame = new JFrame("贪吃蛇游戏");
        gameFrame.setSize(400, 400);
        gameFrame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE); // 关闭窗口不退出整个程序
        gameFrame.setLocationRelativeTo(null); // 窗口居中
        
        // 添加提示标签
        JLabel tipLabel = new JLabel("贪吃蛇游戏（待实现）", SwingConstants.CENTER);
        tipLabel.setFont(new Font("宋体", Font.PLAIN, 20));
        gameFrame.add(tipLabel);
        
        gameFrame.setVisible(true);
    }
}