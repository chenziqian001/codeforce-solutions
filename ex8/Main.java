import javax.swing.*;
import java.awt.*;

public class Main {
    public static void main(String[] args) {
        // 1. 创建框架窗口
        JFrame frame = new JFrame("综合实验 - 计算器与小游戏");
        frame.setSize(400, 600); // 设置窗口大小
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); // 关闭窗口退出程序
        frame.setLocationRelativeTo(null); // 窗口居中显示
        frame.setLayout(new BorderLayout()); // 设置布局管理器

        // 2. 添加菜单系统
        MenuBar menuBar = new MenuBar(frame);
        frame.setJMenuBar(menuBar.createMenuBar());

        // 3. 添加计算器面板
        CalculatorPanel calculatorPanel = new CalculatorPanel();
        frame.add(calculatorPanel, BorderLayout.CENTER);

        // 4. 显示窗口
        frame.setVisible(true);
    }
}