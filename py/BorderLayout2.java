import javax.swing.*;
import java.awt.*;

public class BorderLayout2 {
    public static void main(String[] args) {
        // 创建一个 JFrame 容器
        JFrame frame = new JFrame("BorderLayout 示例");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        
        // 设置布局管理器为 BorderLayout
        frame.setLayout(new BorderLayout());
        
        // 创建五个按钮
        frame.add(new JButton("North"), BorderLayout.NORTH);
        frame.add(new JButton("South"), BorderLayout.SOUTH);
        frame.add(new JButton("East"), BorderLayout.EAST);
        frame.add(new JButton("West"), BorderLayout.WEST);
        frame.add(new JButton("Center"), BorderLayout.CENTER);
        
        frame.setSize(400, 300);
        frame.setVisible(true);
    } // 确保这个花括号存在
} // 确保这个花括号存在

