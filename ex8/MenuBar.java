import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class MenuBar {
    private JFrame parentFrame;

    public MenuBar(JFrame frame) {
        this.parentFrame = frame;
    }

    // 创建完整菜单条
    public JMenuBar createMenuBar() {
        JMenuBar menuBar = new JMenuBar();

        // （1）文件菜单
        JMenu fileMenu = new JMenu("文件");
        JMenuItem newItem = new JMenuItem("新建");
        JMenuItem openItem = new JMenuItem("打开");
        JMenuItem saveItem = new JMenuItem("保存(Ctrl+S)");
        // 保存快捷键设置
        saveItem.setAccelerator(KeyStroke.getKeyStroke("ctrl S"));

        // 文件菜单事件处理
        newItem.addActionListener(e -> JOptionPane.showMessageDialog(parentFrame, "新建功能已触发"));
        openItem.addActionListener(e -> JOptionPane.showMessageDialog(parentFrame, "打开功能已触发"));
        saveItem.addActionListener(e -> JOptionPane.showMessageDialog(parentFrame, "保存成功（模拟）"));

        fileMenu.add(newItem);
        fileMenu.add(openItem);
        fileMenu.add(saveItem);
        JMenu fontMenu = new JMenu("字体");
        JMenuItem colorItem = new JMenuItem("颜色");
        JMenuItem sizeItem = new JMenuItem("字号");
        JMenuItem styleItem = new JMenuItem("字体样式");
        colorItem.addActionListener(e -> {
            Color color = JColorChooser.showDialog(parentFrame, "选择字体颜色", Color.BLACK);
        });
        sizeItem.addActionListener(e -> JOptionPane.showMessageDialog(parentFrame, "支持12/14/16号字体（模拟）"));
        styleItem.addActionListener(e -> JOptionPane.showMessageDialog(parentFrame, "支持宋体/黑体/楷体（模拟）"));
        fontMenu.add(colorItem);
        fontMenu.add(sizeItem);
        fontMenu.add(styleItem);
        JMenu gameMenu = new JMenu("小游戏");
        JMenuItem snakeItem = new JMenuItem("贪吃蛇");
        JMenuItem guessItem = new JMenuItem("猜字");

        snakeItem.addActionListener(e -> {
            new SnakeGame(); 
        });
        guessItem.addActionListener(e -> {
            new GuessWordGame(); 
        });
        gameMenu.add(snakeItem);
        gameMenu.add(guessItem);
        JMenuItem exitItem = new JMenuItem("退出");
        exitItem.addActionListener(e -> System.exit(0));
        menuBar.add(fileMenu);
        menuBar.add(fontMenu);
        menuBar.add(gameMenu);
        menuBar.add(Box.createHorizontalGlue());
        menuBar.add(exitItem);

        return menuBar;
    }
}