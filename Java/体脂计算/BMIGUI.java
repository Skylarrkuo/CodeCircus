import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class BMIGUI extends JFrame {
    private JTextField heightField;
    private JTextField weightField;
    private JRadioButton maleButton;
    private JRadioButton femaleButton;
    private JLabel resultLabel;

    public BMIGUI() {
        setTitle("体重指数计算器");
        setSize(400, 300);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);
        
        // 创建组件
        JLabel heightLabel = new JLabel("身高 (厘米):");
        heightField = new JTextField(10);
        
        JLabel weightLabel = new JLabel("体重 (公斤):");
        weightField = new JTextField(10);
        
        JLabel genderLabel = new JLabel("性别:");
        maleButton = new JRadioButton("男");
        femaleButton = new JRadioButton("女");
        
        // 将单选按钮分组
        ButtonGroup genderGroup = new ButtonGroup();
        genderGroup.add(maleButton);
        genderGroup.add(femaleButton);

        JButton calculateButton = new JButton("计算BMI");
        resultLabel = new JLabel("结果: ");
        
        // 设置布局
        setLayout(new GridBagLayout());
        GridBagConstraints gbc = new GridBagConstraints();
        gbc.insets = new Insets(5, 5, 5, 5);
        
        // 添加组件到窗口
        gbc.gridx = 0;
        gbc.gridy = 0;
        add(heightLabel, gbc);
        
        gbc.gridx = 1;
        add(heightField, gbc);
        
        gbc.gridx = 0;
        gbc.gridy = 1;
        add(weightLabel, gbc);
        
        gbc.gridx = 1;
        add(weightField, gbc);
        
        gbc.gridx = 0;
        gbc.gridy = 2;
        add(genderLabel, gbc);
        
        gbc.gridx = 1;
        add(maleButton, gbc);
        
        gbc.gridx = 2;
        add(femaleButton, gbc);
        
        gbc.gridx = 1;
        gbc.gridy = 3;
        add(calculateButton, gbc);
        
        gbc.gridx = 1;
        gbc.gridy = 4;
        add(resultLabel, gbc);
        
        // 处理按钮事件
        calculateButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                calculateBMI();
            }
        });
    }

    private void calculateBMI() {
        try {
            double heightCm = Double.parseDouble(heightField.getText());
            double weight = Double.parseDouble(weightField.getText());
            // 将身高从厘米转换为米
            double height = heightCm / 100;
            
            // Debug 输出
            System.out.println("Height in meters: " + height);
            System.out.println("Weight: " + weight);
            
            double bmi = weight / (height * height);
            // Debug 输出
            System.out.println("BMI: " + bmi);
            
            String result = String.format("BMI: %.2f - ", bmi);
            if (bmi > 24) {
                result += "偏胖";
            } else {
                result += "正常";
            }
            resultLabel.setText(result);
        } catch (NumberFormatException e) {
            resultLabel.setText("输入有误，请输入数字！");
        }
    }
}
